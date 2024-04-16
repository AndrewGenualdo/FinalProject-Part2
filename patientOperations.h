//
// Created by andrew.genualdo on 4/16/2024.
//

#ifndef FINALPROJECT_PART2_PATIENTOPERATIONS_H
#define FINALPROJECT_PART2_PATIENTOPERATIONS_H

#include "doctor.h"
#include "patient.h"


void patientOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor);

void addPatient(Patient **&patients, Doctor doctors[], int numberOfDoctors);

void searchPatient(Patient **patients, Doctor doctors[], int numberOfDoctor);

void getPatientIndex(Patient **patients, Doctor doctors[], int numberOfDoctor, string id, int &patientIndex,
                     int &doctorIndex);

bool isPatientExist(Patient **patients, Doctor doctors[], int numberOfDoctor, string id);

void loadPatient(Patient *&patients, Doctor doctor);

void removePatient(Patient **&patients, Doctor doctors[], int numberOfDoctors);

void storePatient(Patient patients[], Doctor doctors);

void updatePatient(Patient **patients, Doctor doctors[], int numberOfDoctor);


#endif //FINALPROJECT_PART2_PATIENTOPERATIONS_H
