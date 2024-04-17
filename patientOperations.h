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

#ifndef FINALPROJECT_PART2_PATIENTOPERATIONS_H
#define FINALPROJECT_PART2_PATIENTOPERATIONS_H

#include "doctor.h"
#include "patient.h"

//the 'driver' for patient 'actions'
void patientOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor);

//'actions' called from the 'driver'
void addPatient(Patient **&patients, Doctor doctors[], int numberOfDoctors);
void removePatient(Patient **&patients, Doctor doctors[], int numberOfDoctor);
void searchPatient(Patient **patients, Doctor doctors[], int numberOfDoctor);
void updatePatient(Patient **patients, Doctor doctors[], int numberOfDoctor);

//utility functions called by 'action' functions
bool isPatientExist(Patient **patients, Doctor doctors[], int numberOfDoctor, string id);
void getPatientIndex(Patient **patients, Doctor doctors[], int numberOfDoctor, string id, int &patientIndex,
                     int &doctorIndex);
void loadPatient(Patient *&patients, Doctor doctor);
void storePatient(Patient patients[], Doctor doctor);


#endif //FINALPROJECT_PART2_PATIENTOPERATIONS_H
