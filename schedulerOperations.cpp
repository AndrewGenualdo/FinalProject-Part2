/*
 * Author: Drew Genualdo
 * Class: CSI-240-04
 * Assignment: Final Project Part 5
 * Date Assigned: Unknown
 * Due Date: Apr 26, 2024 @ 1pm
 *
 * Description:
 * A system to store doctors and patients and deal with them and their schedules
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

#include "schedulerOperations.h"
#include "doctorOperations.h"
#include "header.h"

/*
    Pre: patients, doctors, numberOfDoctor, and scheduler need to be loaded with their respective values from file
   Post: scheduler will be modified to replace an empty time-slot with a filled one.
Purpose: To add a patient to a time slot in the schedule
*********************************************************************************/
void addAppointment(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{
    cout << "Please enter the doctor's name:" << endl;
    string doctorName;
    int doctorIndex = -1;
    while(doctorIndex == -1) {
        getline(cin, doctorName);
        doctorIndex = getDoctorIndex(doctors, numberOfDoctor, doctorName);
        if(doctorIndex == -1) {
            cout << "That doctor doesn't exist!" << endl;
        }
    }

    cout << "What is the patient's ID?" << endl;
    string patientId;
    int patientIndex = -1;
    while(patientIndex == -1) {
        getline(cin, patientId);
        for(int i=0;i<doctors[doctorIndex].getNumberOfPatient();i++) {
            if(patients[doctorIndex][i] == patientId) {
                patientIndex = i;
                break;
            }
        }
        if(patientIndex == -1) {
            cout << "That patient doesn't exist for that doctor!" << endl;
        }
    }
    cout << "Found patient: " << patients[doctorIndex][patientIndex].getName() << endl;

    int dayIndex;
    cout << "Please select the day of the week you wish to add an appointment to:" << endl;
    for(int i=0;i<DAY_COUNT;i++) {
        cout << (i + 1) << " - " << DAYS_OF_THE_WEEK[i+1] << endl;
    }
    string tmp;
    getline(cin, tmp);
    dayIndex = stoi(tmp);
    while(dayIndex < 1 || dayIndex > DAY_COUNT) {
        cout << "Please enter a valid day of the week." << endl;
        cout << "Please select the day of the week you wish to add an appointment to:" << endl;
        for(int i=0;i<DAY_COUNT;i++) {
            cout << (i + 1) << " - " << DAYS_OF_THE_WEEK[i+1] << endl;
        }
        getline(cin, tmp);
        dayIndex = stoi(tmp);
    }


    cout << "Here are the available time slots for Dr. " << doctors[doctorIndex].getName() << " on " << DAYS_OF_THE_WEEK[dayIndex] << ":" << endl;
    dayIndex--;
    bool isAnySlotAvailable = false;
    for(int j=0;j<TIME_SLOT_COUNT;j++) {
        Patient timeSlot = scheduler[dayIndex][j][doctorIndex];
        if(timeSlot == "") {
            cout << j << " - " << timeIndexToDisplay(j) << endl;
            isAnySlotAvailable = true;
        }
    }

    if(!isAnySlotAvailable) {
        cout << "Dr. " << doctors[doctorIndex].getName() << " is fully booked!" << endl;
        return;
    }

    int timeIndex;
    bool invalidTimeSlot = true;
    while(invalidTimeSlot) {
        getline(cin, tmp);
        timeIndex = stoi(tmp);
        invalidTimeSlot = timeIndex == -1 || scheduler[dayIndex][timeIndex][doctorIndex] != "";
        if(invalidTimeSlot) {
            cout << "That isn't a valid time slot!" << endl;
        }
    }

    scheduler[dayIndex][timeIndex][doctorIndex] = patients[doctorIndex][patientIndex];
    cout << "An appointment for " << patients[doctorIndex][patientIndex].getName() << " has been made on " << DAYS_OF_THE_WEEK[dayIndex+1] << " @ " << timeIndexToDisplay(timeIndex) << endl;

}

/*
    Pre: scheduler must be loaded with values from file
   Post: None
Purpose: Display the schedule for a specific doctor
*********************************************************************************/
void displaySchedule(int doctorIndex, Patient ***&scheduler)
{
    for(int i=0;i<DAY_COUNT;i++) {
        for(int j=0;j<TIME_SLOT_COUNT;j++) {
            Patient appointment = scheduler[i][j][doctorIndex];
            cout << DAYS_OF_THE_WEEK[i+1] << " @ ";
            cout << timeIndexToDisplay(j);
            if(appointment != "") {
                cout << " | " << appointment.getName() << endl;
            } else {
                cout << " | AVAILABLE" << endl;
            }

        }
    }
}

/*
    Pre: scheduler doctor and numberOfDoctors need to be initialized
   Post: scheduler will be initialized
Purpose: Load the schedule from file
  Notes: scheduler[day][timeSlot][doctor]
*********************************************************************************/
void loadSchedule(Patient ***&scheduler, Doctor *doctor, int numberOfDoctors)
{
    ifstream scheduleStream(SCHEDULE_FILE);
    if(scheduleStream.is_open() && scheduleStream.good()) {
        for(int i=0;i<DAY_COUNT;i++) { //0 = Monday, 4 = Friday
            for(int j=0; j < TIME_SLOT_COUNT; j++) { //0 is 9am, 1 is 9:15am, etc. up to 31 is 4:45pm
                for(int k=0;k<numberOfDoctors;k++) {
                    scheduleStream >> scheduler[i][j][k];
                }
            }
        }
        scheduleStream.close();
    }
}

/*
    Pre: patients, scheduler, doctors, and numberOfDoctors need to be initialized
   Post: an patient in scheduler will be replaced with the default constructor patient
Purpose: remove a patient from the schedule
*********************************************************************************/
void removeAppointment(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{
    cout << "Please enter the doctor's name:" << endl;
    string doctorName;
    int doctorIndex = -1;
    while(doctorIndex == -1) {
        getline(cin, doctorName);
        doctorIndex = getDoctorIndex(doctors, numberOfDoctor, doctorName);
        if(doctorIndex == -1) {
            cout << "That doctor doesn't exist!" << endl;
        }
    }

    int dayIndex;
    cout << "Please select the day of the week you wish to remove an appointment from:" << endl;
    for(int i=0;i<DAY_COUNT;i++) {
        cout << (i + 1) << " - " << DAYS_OF_THE_WEEK[i+1] << endl;
    }
    string tmp;
    getline(cin, tmp);
    dayIndex = stoi(tmp);
    while(dayIndex < 1 || dayIndex > DAY_COUNT) {
        cout << "Please enter a valid day of the week." << endl;
        cout << "Please select the day of the week you wish to add an appointment to:" << endl;
        for(int i=0;i<DAY_COUNT;i++) {
            cout << (i + 1) << " - " << DAYS_OF_THE_WEEK[i+1] << endl;
        }
        getline(cin, tmp);
        dayIndex = stoi(tmp);
    }
    cout << "Here is a list of all filled time-slots for Dr. " << doctors[doctorIndex].getName() << " on " << DAYS_OF_THE_WEEK[dayIndex] << endl;
    dayIndex--;
    bool isAnySlotTaken = false;
    for(int i=0;i<TIME_SLOT_COUNT;i++) {
        Patient timeSlot = scheduler[dayIndex][i][doctorIndex];
        if(timeSlot != "") {
            cout << i << " - " << timeIndexToDisplay(i) << " | " << timeSlot.getName() << endl;
            isAnySlotTaken = true;
        }
    }
    if(!isAnySlotTaken) {
        cout << "Dr. " << doctors[doctorIndex].getName() << " has nobody in his schedule!" << endl;
        return;
    }
    int timeIndex;
    bool invalidTimeSlot = true;
    while(invalidTimeSlot) {
        getline(cin, tmp);
        timeIndex = stoi(tmp);
        invalidTimeSlot = timeIndex == -1 || scheduler[dayIndex][timeIndex][doctorIndex] == "";
        if(invalidTimeSlot) {
            cout << "That isn't a valid time slot!" << endl;
        }
    }


    cout << "Successfully removed the appointment at " << timeIndexToDisplay(timeIndex) << " on " << DAYS_OF_THE_WEEK[dayIndex+1] << endl;
    scheduler[dayIndex][timeIndex][doctorIndex] = Patient();
}

/*
    Pre: None
   Post: Returns index of the user's choice
Purpose: Choose an operation type
*********************************************************************************/
int schedulerMenu()
{
    int action = 0;
    while(action < 1 || action > 4) {
        cout << "Please choose your action:" << endl
             << "1 - Patient operations" << endl
             << "2 - Doctor operations" << endl
             << "3 - Schedule operations" << endl
             << "4 - Exit program" << endl;
        string tmp;
        getline(cin, tmp);
        action = stoi(tmp);
    }
    return action;
}

/*
    Pre: patients, doctors, numberOfDoctor, and scheduler
   Post: The user can control all aspects of scheduler
Purpose: Choose the actions for scheduler operations and execute them
*********************************************************************************/
void schedulerOperations(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{
    int choice = 0;
    while(choice < 1 || choice > 4) {
        cout << "Schedule Management Operations:" << endl
             << "1 - Display the schedule for a specific doctor" << endl
             << "2 - Display the schedule for all doctors" << endl
             << "3 - Add an appointment at an available time-slot" << endl
             << "4 - Remove an appointment from a filled time-slot" << endl;
        string tmp;
        getline(cin, tmp);
        choice = stoi(tmp);
    }
    switch(choice) {
        case 1:
        {
            int doctorIndex = -1;
            while(doctorIndex == -1) { //-1 indicates no doctor has been found for the specified name
                cout << "Please enter the name of the doctor you would like to see the schedule of (or type 'cancel' to cancel):" << endl;
                string doctorName;
                getline(cin, doctorName);
                if(doctorName == "cancel") {
                    doctorIndex = -2;
                    break;
                }
                doctorIndex = getDoctorIndex(doctors, numberOfDoctor, doctorName);
            }
            if(doctorIndex != -2) { //-2 indicates the operation has been cancelled
                displaySchedule(doctorIndex, scheduler);
            }
            break;
        }
        case 2:
        {
            viewSchedule(doctors, numberOfDoctor, scheduler);
            break;
        }

        case 3:
        {
            addAppointment(patients, doctors, numberOfDoctor, scheduler);
            break;
        }

        case 4:
        {
            removeAppointment(patients, doctors, numberOfDoctor, scheduler);
            break;
        }
    }
}

/*
    Pre: scheduler and numberOfDoctors must be initialized
   Post: scheduler will be stored to file
Purpose: Store scheduler to file
*********************************************************************************/
void storeSchedule(Patient ***&scheduler, int numberOfDoctors)
{
    ofstream scheduleStream(SCHEDULE_FILE);
    if(scheduleStream.is_open() && scheduleStream.good()) {
        for(int i=0;i<DAY_COUNT;i++) {
            for(int j=0;j<TIME_SLOT_COUNT;j++) {
                for(int k=0;k<numberOfDoctors;k++) {
                    scheduleStream << scheduler[i][j][k];
                }
            }
        }
    }
    scheduleStream.close();
    cout << "Schedule saved!" << endl;
}

/*
    Pre: doctors, numberOfDoctors, and scheduler must be initialized
   Post: None
Purpose: View the schedule for all doctors
*********************************************************************************/
void viewSchedule(Doctor *doctors, int numberOfDoctors, Patient ***&scheduler)
{
    for(int i=0;i<numberOfDoctors;i++) {
        cout << "---------------------------------" << endl;
        cout << " Appointments for: " << doctors[i].getName()<< endl;
        cout << "---------------------------------" << endl;
        displaySchedule(i, scheduler);
    }
}
