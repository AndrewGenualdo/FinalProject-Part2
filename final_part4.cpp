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
