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

#include <iostream>
#include "doctor.h"
#include "doctorOperations.h"
#include "patientOperations.h"
#include "schedulerOperations.h"
#include "commonOperations.h"
using namespace std;



int main()
{
    //initialize doctors
    Doctor *doctors = nullptr;
    int doctorCount = loadDoctor(doctors);
    //initialize patients
    Patient **patients = new Patient*[doctorCount];
    for(int i=0;i<doctorCount;i++) {
        loadPatient(patients[i], doctors[i]);
    }

    //schedule[DAY][TIME_SLOT][DOCTOR]
    //schedule[2][5][1] is Wednesday @ 10:15am with the 2nd doctor
    //initialize schedule.
    Patient ***schedule = new Patient**[DAY_COUNT];
    for(int i=0;i<DAY_COUNT;i++) {
        schedule[i] = new Patient*[TIME_SLOT_COUNT];
        for(int j=0; j < TIME_SLOT_COUNT; j++) {
            schedule[i][j] = new Patient[doctorCount];
        }
    }
    loadSchedule(schedule, doctors, doctorCount);

    //program stuff here
    int action = 0;
    while(action != 4) {
        action = schedulerMenu();
        switch(action) {
            case 1: {
                patientOperations(patients, doctors, doctorCount);
                break;
            }
            case 2: {
                cout << "Doctor operations are under maintenance! Please try again later..." << endl << endl; //I never did the doctor operations
                doctorOperations(patients, doctors, doctorCount);
                break;
            }
            case 3: {
                schedulerOperations(patients, doctors, doctorCount, schedule);
                break;
            }
            default: {
                cout << "Shutting down..." << endl;
                break;
            }
        }
    }



    //save all data to file before exiting
    for(int i=0;i<doctorCount;i++) {
        storePatient(patients[i], doctors[i]);
    }
    storeDoctor(doctors, doctorCount);
    storeSchedule(schedule, doctorCount);

    //free up allocated memory to the system
    //delete schedule
    for(int i=0;i<DAY_COUNT;i++) {
        for(int j=0; j < TIME_SLOT_COUNT; j++) {
            delete [] schedule[i][j];
        }
        delete [] schedule[i];
    }
    delete [] schedule;
    //delete patients
    for(int i=0;i<doctorCount;i++) {
        delete [] patients[i];
    }
    delete [] patients;
    //delete doctors
    delete [] doctors;

    return 0;
}
