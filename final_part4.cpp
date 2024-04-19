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
using namespace std;

int main()
{
    Doctor *doctors = nullptr;
    int doctorCount = loadDoctor(doctors);
    Patient **patients = new Patient*[doctorCount];
    for(int i=0;i<doctorCount;i++) {
        loadPatient(patients[i], doctors[i]);
    }
    patientOperations(patients, doctors, doctorCount);

    for(int i=0;i<doctorCount;i++) {
        delete [] patients[i];
    }
    delete [] patients;

    if(doctorCount != -1) { //-1 means it didn't properly open the "doctors.txt" file
        delete [] doctors;
    }

    return 0;
}
