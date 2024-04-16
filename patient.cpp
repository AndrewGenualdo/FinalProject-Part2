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

#include "patient.h"

/*
Pre: A Patient object is instantiated
Post: The Patient object is initialized
Purpose: Initialize the Patient object
*/
Patient::Patient() {
    setId("");
    mName = "";
    mAddress = "";
    mPhoneNumber = "";
    mDoctorId = "";
}

/*
Pre: ID, name, address, phone number and doctor ID
Post: The Patient object is initialized with the values provided
Purpose: Initialize the Patient object with values provided
*/
Patient::Patient(string id, string name, string address, string phoneNumber, string doctorId) {
    setId(id);
    mName = name;
    mAddress = address;
    mPhoneNumber = phoneNumber;
    mDoctorId = doctorId;
}

/*
Pre: a Patient object
Post: The current Patient object is initialized with the object provided
Purpose: Initialize the Patient object using another Patient object
*/
Patient::Patient(const Patient & obj) {
    setId(obj.getId());
    mName = obj.mName;
    mAddress = obj.mAddress;
    mPhoneNumber = obj.mPhoneNumber;
    mDoctorId = obj.mDoctorId;
}

/*
Pre: A Patient object is instantiated
Post: None
Purpose: This is an empty destructor
*/
Patient::~Patient() {}

/*
Pre: A Patient object is instantiated
Post: The doctor ID is returned
Purpose: Return doctor ID of the patient object
*/
string Patient::getDoctorId() {
    return mDoctorId;
}

/*
Pre: The value for doctor ID
Post: The doctor ID is updated
Purpose: Update the value for doctor ID with the provided value
*/
void Patient::setDoctorId(string id) {
    mDoctorId = id;
}

/*
Pre: The Patient object is instantiated 
Post: Information for the Patient object is displayed on the screen
Purpose: Display the information for the Patient object to the screen
*/
void Patient::display() {
    cout << "ID: " << getId() << "\nName: " << mName << "\nAddress: " << mAddress << "\nPhone Number: " << mPhoneNumber << "\nDoctor ID: " << mDoctorId << "\n";
}

/*
Pre: The istream and Patient objects
Post: Read the Patient object using istream and the istream
      is returned to the caller
Purpose: Read Patient object via the istream
*/
istream & operator >> (istream & input, Patient & obj) {
    string temp;
    getline(input, temp);
    obj.setId(temp);
    getline(input, obj.mName);
    getline(input, obj.mAddress);
    getline(input, obj.mPhoneNumber);
    getline(input, obj.mDoctorId);
    return input;
}

/*
Pre: The ostream and Patient objects
Post: Output the Patient object using ostream and the
      ostream is returned to the caller
Purpose: Output Patient object via the ostream
*/
ostream & operator << (ostream & output, Patient obj) {
    output << obj.getId() << "\n" << obj.mName << "\n" << obj.mAddress << "\n" << obj.mPhoneNumber << "\n" << obj.mDoctorId << "\n";
    return output;
}