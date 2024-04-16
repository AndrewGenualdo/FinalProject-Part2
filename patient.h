/*
Author:  Noah Sheppard
Class:  CSI-240-04
Assignment: Final Project - Part 2
Date Assigned: April 5, 2024
Due Date: April 12, 2024

Description:
  Simulating a database for clinic.

  The purpose of this file is to define the Person class


Disclaimer:
  All comments are removed and please tell me how easy it is to read my code

Certification of Authenticity:
  I certify that this is entirely my own work, except where I have given
  fully-documented references to the work of others.I understand the definition
  and consequences of plagiarism and acknowledge that the assessor of this
  assignment may, for the purpose of assessing this assignment:
  - Reproduce this assignment and provide a copy to another member of academic
    staff; and/or
  - Communicate a copy of this assignment to a plagiarism checking service (which
    may then retain a copy of this assignment on its database for the purpose
    of future plagiarism checking)
*/

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>

#include <fstream>

#include "../../../Downloads/person.h"

using namespace std;

class Patient: public Person {
    private: string mDoctorId;

    public: Patient();
    Patient(string id, string name, string address, string phoneNumber, string doctorId);
    Patient(const Patient & obj);
    ~Patient();

    string getDoctorId();
    void setDoctorId(string id);

    virtual void display();

    friend istream & operator >> (istream & input, Patient & obj);
    friend ostream & operator << (ostream & output, Patient obj);
};

#endif