/*
 * Author: Drew Genualdo
 * Class: CSI-240-04
 * Assignment: Final Project Part 5
 * Date Assigned: Unknown
 * Due Date: Apr 26, 2024 @ 1pm
 *
 * Description:
 * A system to store doctors and patients and deal with them and their schedules
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

#ifndef FINALPROJECT_PART2_SCHEDULEROPERATIONS_H
#define FINALPROJECT_PART2_SCHEDULEROPERATIONS_H

#include "patient.h"
#include "doctor.h"


const string SCHEDULE_FILE = "schedule.txt";
const int DAY_COUNT = 1;
const int WORK_HOURS = 8; //9am to 5pm (8-hour work day)
const int SESSION_MINUTES = 15;
const int SESSIONS_PER_HOUR = 60 / SESSION_MINUTES;
const int TIME_SLOT_COUNT = SESSIONS_PER_HOUR * WORK_HOURS;
const string DAYS_OF_THE_WEEK[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void addAppointment(Patient **&patients, Doctor doctors[], int numberOfDoctor, Patient ***&scheduler);
void displaySchedule(int doctorIndex, Patient ***&scheduler);
void loadSchedule(Patient ***&scheduler, Doctor doctor[], int numberOfDoctors);
void removeAppointment(Patient **&patients, Doctor doctors[], int numberOfDoctor, Patient ***&scheduler);
int schedulerMenu();
void schedulerOperations(Patient **&patients, Doctor doctors[], int numberOfDoctor, Patient ***&scheduler);
void storeSchedule(Patient ***&scheduler, int numberOfDoctors);
void viewSchedule(Doctor doctors[], int numberOfDoctors, Patient ***&scheduler);


#endif //FINALPROJECT_PART2_SCHEDULEROPERATIONS_H
