//
// Created by andrew.genualdo on 4/16/2024.
//

#include "patientOperations.h"

void patientOperations(Patient **&patients, Doctor *doctors, int numberOfDoctor)
{

}

void addPatient(Patient **&patients, Doctor *doctors, int numberOfDoctors)
{

}

void searchPatient(Patient **patients, Doctor *doctors, int numberOfDoctor)
{

}

void getPatientIndex(Patient **patients, Doctor *doctors, int numberOfDoctor, string id,
                     int &patientIndex, int &doctorIndex)
{
    for (int i = 0; i < numberOfDoctor; i++)
    {
        int patientCount = doctors[i].getNumberOfPatient();
        for (int j = 0; j < patientCount; j++)
        {
            if (patients[i][j].getId() == id)
            {
                doctorIndex = i;
                patientIndex = j;
                return;
            }
        }
    }
    doctorIndex = -1;
    patientIndex = -1;
}

bool isPatientExist(Patient **patients, Doctor *doctors, int numberOfDoctor, string id)
{
    int temp = 0;
    getPatientIndex(patients, doctors, numberOfDoctor, id, temp, temp);
    return temp != -1;
}

void loadPatient(Patient *&patients, Doctor doctor)
{
    int patientCount = doctor.getNumberOfPatient();
    patients = new Patient[patientCount];
    ifstream patientStream(doctor.getId()+".txt");
    if(patientStream.is_open() && patientStream.good()) {
        for(int i=0;i<patientCount;i++) {
            patientStream >> patients[i];
        }
    }

}

void removePatient(Patient **&patients, Doctor *doctors, int numberOfDoctors)
{

}

void storePatient(Patient *patients, Doctor doctors)
{

}

void updatePatient(Patient **patients, Doctor *doctors, int numberOfDoctor)
{

}
