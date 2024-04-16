//
// Created by andrew.genualdo on 4/16/2024.
//

#ifndef FINALPROJECT_PART2_DOCTOROPERATIONS_H
#define FINALPROJECT_PART2_DOCTOROPERATIONS_H


#include "doctor.h"
#include "patient.h"


const string DOCTOR_FILE = "doctors.txt";

int getDoctorIndex(Doctor doctors[], int numberOfDoctor, string doctorName);

bool isDoctorExist(Doctor doctors[], int numberOfDoctor, string doctorName);

int loadDoctor(Doctor *&doctors);

void storeDoctor(Doctor doctors[], int numberOfDoctor);

void doctorOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor);


#endif //FINALPROJECT_PART2_DOCTOROPERATIONS_H
