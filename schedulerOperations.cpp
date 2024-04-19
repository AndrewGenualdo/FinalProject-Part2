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

void addAppointment(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{

}

void displaySchedule(int doctorIndex, Patient ***&scheduler)
{

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
    return 0;
}

void schedulerOperations(Patient **&patients, Doctor *doctors, int numberOfDoctor, Patient ***&scheduler)
{

}

void storeSchedule(Patient ***&scheduler, int numberOfDoctors)
{

}

void viewSchedule(Doctor *doctors, int numberOfDoctors, Patient ***&scheduler)
{

}
