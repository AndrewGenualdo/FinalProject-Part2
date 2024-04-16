//
// Created by andrew.genualdo on 4/16/2024.
//

#include "doctorOperations.h"

int getDoctorIndex(Doctor *doctors, int numberOfDoctor, string doctorName)
{
    for(int i=0;i<numberOfDoctor;i++) {
        if(doctors[i].getName() == doctorName) {
            return i;
        }
    }
    return -1;
}

bool isDoctorExist(Doctor *doctors, int numberOfDoctor, string doctorName)
{
    return getDoctorIndex(doctors, numberOfDoctor, doctorName) != -1;
}

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

void doctorOperations(Patient **&patients, Doctor *doctors, int numberOfDoctor)
{

}
