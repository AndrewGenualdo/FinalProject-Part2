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

#include "doctor.h"


/*
    Pre: None
   Post: All members are initialized to default value
Purpose: Default constructor
*********************************************************************************/
Doctor::Doctor()
{
    setId("");
    mName            = "";
    mAddress         = "";
    mPhoneNumber     = "";
    mIndex           = 0;
    mNumberOfPatient = 0;
}

/*
    Pre: None
   Post: All members are initialized to custom values
Purpose: Custom constructor
*********************************************************************************/
Doctor::Doctor(string id, string name, string address, string phoneNumber, int index, int numberOfPatient)
{
    setId(id);
    mName            = name;
    mAddress         = address;
    mPhoneNumber     = phoneNumber;
    mIndex           = index;
    mNumberOfPatient = numberOfPatient;
}

/*
    Pre: None
   Post: All members are set to obj's member's values
Purpose: Copy constructor
*********************************************************************************/
Doctor::Doctor(const Doctor& obj) {
    //ask about how you get the id of obj
    setId(obj.getId());
    mName            = obj.mName;
    mAddress         = obj.mAddress;
    mPhoneNumber     = obj.mPhoneNumber;
    mIndex           = obj.mIndex;
    mNumberOfPatient = obj.mNumberOfPatient;
}

/*
    Pre: Initialized
   Post: this object will be deleted
Purpose: Default destructor
*********************************************************************************/
Doctor::~Doctor()
{
    //useless
}

/*
    Pre: Initialized
   Post: None
Purpose: Get index
*********************************************************************************/
int Doctor::getIndex()
{
    return mIndex;
}

/*
    Pre: Initialized
   Post: None
Purpose: Get patient count
*********************************************************************************/
int Doctor::getNumberOfPatient()
{
    return mNumberOfPatient;
}

/*
    Pre: Initialized
   Post: mIndex will be set to index
Purpose: set the index
*********************************************************************************/
void Doctor::setIndex(int index)
{
    mIndex = index;
}

/*
    Pre: Initialized
   Post: mNumberOfPatient will be set to numberOfPatient
Purpose: set the number of patients
*********************************************************************************/
void Doctor::setNumberOfPatient(int numberOfPatient)
{
    mNumberOfPatient = numberOfPatient;
}

/*
    Pre: Initialized
   Post: None
Purpose: print all relevant data to this object to the console
*********************************************************************************/
void Doctor::display()
{
    cout << "           ID:  " << getId() << endl
         << "         Name:  " << mName << endl
         << "      Address:  " << mAddress << endl
         << " Phone Number:  " << mPhoneNumber << endl
         << "        Index:  " << mIndex << endl
         << "Patient Count:  " << mNumberOfPatient << endl;
}

/*
    Pre: Initialized
   Post: mNumberOfPatient will be incremented by 1
Purpose: increment mNumberOfPatients by 1
*********************************************************************************/
Doctor Doctor::operator++(int)
{
    mNumberOfPatient++;
    return *this;
}

/*
    Pre: Initialized
   Post: mNumberOfPatient will be decremented by 1
Purpose: decrement mNumberOfPatients by 1
*********************************************************************************/
Doctor Doctor::operator--(int)
{
    mNumberOfPatient--;
    return *this;
}

/*
    Pre: Initialized
   Post: obj's members will be populated by the contents of the istream
Purpose: Load a Doctor from an istream
*********************************************************************************/
istream &operator>>(istream &input, Doctor &obj)
{
    getline(input, obj.mName);
    string tmp;
    getline(input, tmp);
    obj.setId(tmp);
    input >> obj.mIndex;
    input >> obj.mNumberOfPatient;
    getline(input, tmp);
    return input;
}

/*
    Pre: Initialized
   Post: None
Purpose: send the members of the Doctor obj to the ostream
*********************************************************************************/
ostream &operator<<(ostream &output, Doctor &obj)
{
    output
    << obj.mName << endl
    << obj.getId() << endl
    << obj.mIndex << " " << obj.mNumberOfPatient << endl;
    return output;
}
