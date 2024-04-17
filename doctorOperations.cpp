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

#include "doctorOperations.h"

/*
    Pre: patients and doctors must be initialized, numberOfDoctor must be the length of doctors
   Post: The user can modify the doctor's patient files as they wish
Purpose: To be able to interact with the system of doctors and patients
*********************************************************************************/
void doctorOperations(Patient **&patients, Doctor *doctors, int numberOfDoctor)
{

}

/*
    Pre: doctors must be initialized
   Post: None
Purpose: Get the index of the doctor with the specified name. If there's no doctor with that name, -1 will be returned
*********************************************************************************/
int getDoctorIndex(Doctor *doctors, int numberOfDoctor, string doctorName)
{
    for(int i=0;i<numberOfDoctor;i++) {
        if(doctors[i].getName() == doctorName) {
            return i;
        }
    }
    return -1;
}

/*
    Pre: doctors must be initialized
   Post: None
Purpose: Check if a doctor with the specified name exists
*********************************************************************************/
bool isDoctorExist(Doctor *doctors, int numberOfDoctor, string doctorName)
{
    return getDoctorIndex(doctors, numberOfDoctor, doctorName) != -1;
}

/*
    Pre: None
   Post: doctors will be loaded from the file DOCTOR_FILE
Purpose: Load the doctors from a file
*********************************************************************************/
int loadDoctor(Doctor *&doctors)
{
    ifstream doctorStream(DOCTOR_FILE);
    if(doctorStream.is_open() && doctorStream.good()) {
        string temp;
        getline(doctorStream, temp);
        int doctorCount = stoi(temp);
        doctors = new Doctor[doctorCount];
        for(int i=0;i<doctorCount;i++) {
            doctorStream >> doctors[i];
        }
        return doctorCount;
    }
    return -1;
}

/*
    Pre: doctors must be initialized
   Post: doctors will be saved to file
Purpose: Save the doctors to file
*********************************************************************************/
void storeDoctor(Doctor *doctors, int numberOfDoctor)
{
    ofstream doctorStream(DOCTOR_FILE);
    if(doctorStream.is_open() && doctorStream.good()) {
        doctorStream << numberOfDoctor << endl;
        for(int i=0;i<numberOfDoctor;i++) {
            doctorStream << doctors[i];
        }
    }
}