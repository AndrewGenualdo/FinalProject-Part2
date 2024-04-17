/*
 * Author: Drew Genualdo
 * Class: CSI-240-04
 * Assignment: Final Project Part 4
 * Date Assigned: Unknown
 * Due Date: Apr 19, 2024 @ 1pm
 *
 * Description:
 * A system to store doctors and patients and deal with them
 *
 * Certification of Authenticity:
 * I certify that this is entirely my own work, except where I have given
 * fully-documented references to the work of others. I understand the definition and
 * consequences of plagiarism and acknowledge that the assessor of this assignment
 * may, for the purpose of the assessing this assignment:
 * - Reproduce this assignment and provide a copy to another member of academic staff;
 * and/or
 * - Communicate a copy of this assignment to a plagiarism checking service (which may
 * then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
 */

#include "patientOperations.h"
#include "doctorOperations.h"

/*
    Pre: patients doctors, and numberOfDoctor must be initialized
   Post: The user can modify the patient files as they wish
Purpose: To be able to interact with the system of patients
*********************************************************************************/
void patientOperations(Patient **&patients, Doctor *doctors, int numberOfDoctor)
{
    string input;
    while(input != "exit") {
        cout << endl
             << "What would you like to do?" << endl
             << " add - Add a new patient" << endl
             << " search - Search for an existing patient by SSN" << endl
             << " remove - Remove a patient from the system (and the doctor)" << endl
             << " save - Store all doctor's patients data to file" << endl
             << " update - Search and then update the name of specified patient" << endl
             << " exit - Exit this menu" << endl;
        getline(cin, input);

        if(input == "add")
            addPatient(patients, doctors, numberOfDoctor);

        else if(input == "search")
            searchPatient(patients, doctors, numberOfDoctor);

        else if(input == "remove")
            removePatient(patients, doctors, numberOfDoctor);

        else if(input == "save")
            for(int i=0;i<numberOfDoctor;i++)
                storePatient(patients[i], doctors[i]);

        else if(input == "update")
            updatePatient(patients, doctors, numberOfDoctor);

        else if(input != "exit")
            cout << "Invalid command!" << endl;
    }

    for(int i=0;i<numberOfDoctor;i++)
        storePatient(patients[i], doctors[i]);
}

/*
    Pre: patients doctors, and numberOfDoctor must be initialized
   Post: A new patient will be appended to the end of the patients[selectedDoctorWithSSN] array
Purpose: Add a new patient to the system
*********************************************************************************/
void addPatient(Patient **&patients, Doctor *doctors, int numberOfDoctors)
{
    string ssn;
    string name;
    string address;
    string phoneNumber;
    string doctorSSN;
    cout << "You are creating a new patient" << endl
         << "Please enter the patient's SSN:" << endl;
    getline(cin, ssn);
    if(isPatientExist(patients, doctors, numberOfDoctors, ssn)) {
        cout << "A user with that SSN already exists!" << endl;
        addPatient(patients, doctors, numberOfDoctors);
        return;
    }
    cout << "Please enter the patient's full name:" << endl;
    getline(cin, name);
    cout << "Please enter the patient's address:" << endl;
    getline(cin, address);
    cout << "Please enter the patient's phone number:" << endl;
    getline(cin, phoneNumber);
    cout << "Please enter the patient's Doctor's SSN:" << endl;
    getline(cin, doctorSSN);

    int doctorIndex = -1;
    for(int i=0;i<numberOfDoctors;i++) {
        if(doctors[i].getId() == doctorSSN) {
            doctorIndex = i;
            break;
        }
    }
    if(doctorIndex == -1) {
        cout << "That doctor doesn't exist!" << endl;
        addPatient(patients, doctors, numberOfDoctors);
        return;
    }


    //resize the doctor's patients array (increase the size by 1)
    Doctor &patientDoctor = doctors[doctorIndex];
    //allocate memory for new array with 1 more slot in it
    Patient *patientDoctorsPatients = new Patient[patientDoctor.getNumberOfPatient() + 1];
    //copy existing data into the new array
    for(int i=0;i<patientDoctor.getNumberOfPatient();i++) {
        patientDoctorsPatients[i] = patients[doctorIndex][i];
    }
    //delete the old array
    delete [] patients[doctorIndex];
    //assign the old array location to the new array
    patients[doctorIndex] = patientDoctorsPatients;
    //add the new patient the end of the doctor's patient array
    Patient newPatient = Patient(ssn, name, address, phoneNumber, doctorSSN);
    patients[doctorIndex][patientDoctor.getNumberOfPatient()] = newPatient;
    patientDoctor++;

    cout << "Successfully created a new patient!" << endl;
    storeDoctor(doctors, numberOfDoctors);
    storePatient(patients[doctorIndex], patientDoctor);
}

/*
    Pre: patients doctors, and numberOfDoctor must be initialized
   Post: A patient will be removed from the patients[doctorFoundWithPatientSSN] array
Purpose: Remove a patient from the system
*********************************************************************************/
void removePatient(Patient **&patients, Doctor *doctors, int numberOfDoctor)
{
    cout << "Please enter the SSN of the patient you would like to remove (type 'cancel' to cancel)" << endl;
    string ssn;
    while(ssn != "cancel") {
        getline(cin, ssn);
        int patientIndex = -1;
        int doctorIndex = -1;
        getPatientIndex(patients, doctors, numberOfDoctor, ssn, patientIndex, doctorIndex);

        if(patientIndex == -1) {
            cout << "That patient does not exist!" << endl;
            continue;
        }

        //resize the doctor's patients array (decrease the size by 1)
        Doctor &patientDoctor = doctors[doctorIndex];
        //allocate memory for new array with 1 more slot in it
        Patient *doctorsPatients = new Patient[patientDoctor.getNumberOfPatient() - 1];
        //copy existing data into the new array
        int offset = 0;
        for(int i=0;i<patientDoctor.getNumberOfPatient();i++) {
            if(i == patientIndex) { //shift the future patients left by 1 and skip the current patient if it is the patient we are deleting
                offset++;
                continue;
            }
            doctorsPatients[i - offset] = patients[doctorIndex][i];
        }

        cout << "Successfully deleted patient:" << endl << patients[doctorIndex][patientIndex];

        //delete the old array from memory
        delete [] patients[doctorIndex];
        //assign the old array location to the new array
        patients[doctorIndex] = doctorsPatients;
        doctors[doctorIndex]--;
        storePatient(patients[doctorIndex], doctors[doctorIndex]);
        storeDoctor(doctors, numberOfDoctor);

    }
}

/*
    Pre: patients doctors, and numberOfDoctor must be initialized
   Post: None
Purpose: Search for a patient in the system
*********************************************************************************/
void searchPatient(Patient **patients, Doctor *doctors, int numberOfDoctor)
{
    cout << "Please enter the patient's SSN (or type 'cancel' to cancel):" << endl;
    string input;
    while(input != "cancel") {
        getline(cin, input);
        int patientIndex = -1;
        int doctorIndex = -1;
        getPatientIndex(patients, doctors, numberOfDoctor, input, patientIndex, doctorIndex);
        if(patientIndex == -1) {
            cout << "That patient does not exist!" << endl;
            continue;
        }
        Patient &patient = patients[doctorIndex][patientIndex];
        cout << "SSN: " << patient.getId() << endl;
        cout << "Name: " << patient.getName() << endl;
        cout << "Address: " << patient.getAddress() << endl;
        cout << "Phone Number: " << patient.getPhoneNumber() << endl;
        cout << "Doctor: Dr. " << doctors[doctorIndex].getName() << endl;
        break;
    }

}

/*
    Pre: patients doctors, and numberOfDoctor must be initialized
   Post: The patient with the inputted SSN will have their name updated
Purpose: Update a patient's name in the system
*********************************************************************************/
void updatePatient(Patient **patients, Doctor *doctors, int numberOfDoctor)
{
    cout << "Please enter the SSN of the patient you wish to update:" << endl;
    string ssn;
    getline(cin, ssn);
    int patientIndex = -1;
    int doctorIndex = -1;

    getPatientIndex(patients, doctors, numberOfDoctor, ssn, patientIndex, doctorIndex);
    while(doctorIndex == -1) {
        cout << "That patient does not exist!" << endl;
        getline(cin, ssn);
        getPatientIndex(patients, doctors, numberOfDoctor, ssn, patientIndex, doctorIndex);
    }
    cout << "Please enter the new name of the patient:" << endl;
    string newName;
    getline(cin, newName);
    cout << "Changed patient's name from '" << patients[doctorIndex][patientIndex].getName();
    patients[doctorIndex][patientIndex].setName(newName);
    cout << "' to '" << patients[doctorIndex][patientIndex].getName() << "'" << endl;
    storePatient(patients[doctorIndex], doctors[doctorIndex]);
}

/*
    Pre: patients doctors, and numberOfDoctor must be initialized
   Post: None
Purpose: Check if a patient with the specified SSN exists
*********************************************************************************/
bool isPatientExist(Patient **patients, Doctor *doctors, int numberOfDoctor, string id)
{
    int patientIndex = 0;
    int doctorIndex = 0;
    getPatientIndex(patients, doctors, numberOfDoctor, id, patientIndex, doctorIndex);
    return doctorIndex != -1;
}

/*
    Pre: patients doctors, and numberOfDoctor must be initialized
   Post: None
Purpose: Get the patient with the specified SSN's patientIndex and doctorIndex
*********************************************************************************/
void getPatientIndex(Patient **patients, Doctor *doctors, int numberOfDoctor, string id,
                     int &patientIndex, int &doctorIndex)
{
    for (int i = 0; i < numberOfDoctor; i++)
    {
        int patientCount = doctors[i].getNumberOfPatient();
        for (int j = 0; j < patientCount; j++)
        {
            if (patients[i][j].getId() == id)
            {
                doctorIndex = i;
                patientIndex = j;
                return;
            }
        }
    }
    doctorIndex = -1;
    patientIndex = -1;
}

/*
    Pre: doctor must be initialized
   Post: The patient's for the specified doctor will be loaded from file
Purpose: Load the patient's for a specific doctor from file
*********************************************************************************/
void loadPatient(Patient *&patients, Doctor doctor)
{
    int patientCount = doctor.getNumberOfPatient();
    patients = new Patient[patientCount];
    ifstream patientStream(doctor.getId()+".txt");
    if(patientStream.is_open() && patientStream.good()) {
        for(int i=0;i<patientCount;i++) {
            patientStream >> patients[i];
        }
    }

}

/*
    Pre: patients and doctor must be initialized
   Post: The patient's for the specified doctor will be stored to file
Purpose: Store the patient's for a specific doctor to file
*********************************************************************************/
void storePatient(Patient *patients, Doctor doctor)
{
    ofstream patientStream(doctor.getId()+".txt");
    if(patientStream.is_open() && patientStream.good()) {
        for(int i=0;i<doctor.getNumberOfPatient();i++) {
            patientStream << patients[i];
        }
        cout << "Saved Dr. " << doctor.getName() << "'s patients!" << endl;
    }
}
