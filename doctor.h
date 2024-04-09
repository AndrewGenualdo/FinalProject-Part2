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

#ifndef FINALPROJECT_PART2_DOCTOR_H
#define FINALPROJECT_PART2_DOCTOR_H

#include "person.h"

class Doctor : public Person
{
private:
    int mIndex, mNumberOfPatient;

public:
    Doctor();
    Doctor(string id, string name, string address, string phoneNumber, int index, int numberOfPatient);
    Doctor(const Doctor& obj);
    ~Doctor();

    int getIndex();
    int getNumberOfPatient();

    void setIndex(int index);
    void setNumberOfPatient(int numberOfPatient);

    virtual void display();

    Doctor operator++(int);
    Doctor operator--(int);

    friend istream& operator>>(istream& input, Doctor& obj);
    friend ostream& operator<<(ostream& output, Doctor& obj);
};


#endif //FINALPROJECT_PART2_DOCTOR_H
