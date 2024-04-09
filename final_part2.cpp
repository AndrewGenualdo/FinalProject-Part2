/*
 * Author: Drew Genualdo
 * Class: CSI-240-04
 * Assignment: Final Project Part 2
 * Date Assigned: Unknown
 * Due Date: Apr 12, 2024 @ 1pm
 *
 * Description:
 * A system to store doctors
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
#include <fstream>
#include "doctor.h"
using namespace std;

int main()
{
    ofstream out("output.txt");
    if(!out.is_open() || !out.good()) return -1;

    Doctor doctor = Doctor();
    out << doctor; // should write somebody with no name, no id, index of 0, and 0 patients

    doctor.setName("Joe Biden");
    doctor.setId("389575982525");
    doctor.setIndex(1);
    doctor.setNumberOfPatient(5);
    out << doctor; //should write Joe Biden with id 389575982525, index 1, and 5 patients

    doctor = Doctor("254-64-8736", "Bob Marley", "73 Bulivard Road", "875-564-3959", 1, 32);
    out << doctor; // should write Bob Marley with ID 254-64-8736, index 1, and 32 patients

    Doctor doctor2 = Doctor(doctor);
    out << doctor2; //should write a second Bob Marley with same id, index, and patient count

    cout << doctor.getIndex() << " " << doctor.getNumberOfPatient() << endl; //should print 1 32

    doctor.display(); //should display Bob Marley the doctor with all relevant info in console

    cout << doctor.getNumberOfPatient() << endl; //should be 32

    doctor++;
    cout << doctor.getNumberOfPatient() << endl; //should be 33

    doctor--;
    doctor--;
    cout << doctor.getNumberOfPatient() << endl; //should be 31



    ifstream in("input.txt"); //or whatever input file you want
    if(!in.is_open() || !in.good()) return -1;

    int doctorCount;
    int i = 0;
    string tmp;
    getline(in, tmp);
    doctorCount = stoi(tmp);

    //load all doctors in file into a dynamic array
    Doctor* doctors = new Doctor[doctorCount];
    while(!in.eof() && i < doctorCount) {
        in >> doctors[i];
        i++;
    }


    cout << "--------------------------------" << endl;
    //This should display all patients that were in the input file
    for(i=0;i<doctorCount;i++) {
        doctors[i].display();
        cout << "--------------------------------" << endl;
    }
    delete [] doctors;

    return 0;
}
