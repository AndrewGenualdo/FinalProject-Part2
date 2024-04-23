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

void addAppointment(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{

}

void displaySchedule(int doctorIndex, Patient ***&scheduler)
{
    for(int i=0;i<DAY_COUNT;i++) {
        for(int j=0;j<TIME_SLOT_COUNT;j++) {
            Patient appointment = scheduler[i][j][doctorIndex];
            int hour = (j / 4) + 9;
            int minute = (j % 4) * 15;
            cout << DAYS_OF_THE_WEEK[i+1] << " @ ";
            if(hour < 10) {
                cout << "0";
            }
            cout << hour << ":" << minute;
            if(minute == 0) {
                cout << "0";
            }
            if(appointment != "") {
                cout << " | " << appointment.getName() << endl;
            } else {
                cout << " | AVAILABLE" << endl;
            }

        }
    }
}

//Patient[day][timeSlot][doctor]
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

void removeAppointment(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{

}

int schedulerMenu()
{
    int input = 0;
    while(input < 1 || input > 4) {
        cout << "Schedule Management Operations:" << endl
             << "1 - Display the schedule for a specific doctor" << endl
             << "2 - Display the schedule for all doctors" << endl
             << "3 - Add an appointment at an available time-slot" << endl
             << "4 - Remove an appointment from a filled time-slot" << endl;
        cin >> input;
    }
    return input;
}

void schedulerOperations(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{
    int choice = schedulerMenu();
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
            break;
        }

        case 3:
        {
            break;
        }

        case 4:
        {
            break;
        }
        default:
        {
            cout << "How the hell did you get here? This shouldn't be possible..." << endl;
            break;
        }
    }
}

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

void viewSchedule(Doctor *doctors, int numberOfDoctors, Patient ***&scheduler)
{
    for(int i=0;i<numberOfDoctors;i++) {
        cout << "---------------------------------" << endl;
        cout << " Appointments for: " << doctors[i].getName()<< endl;
        cout << "---------------------------------" << endl;
        displaySchedule(i, scheduler);
    }
}
