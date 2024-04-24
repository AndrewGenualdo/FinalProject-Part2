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

#include "header.h"

/*
    Pre: timeIndex must be >= 0 and < TIME_SLOT_COUNT
   Post: None
Purpose: Return a viewable version of a timeIndex
*********************************************************************************/
string timeIndexToDisplay(int timeIndex) {
    string out;
    int hour = (timeIndex / SESSIONS_PER_HOUR) + 9; //this could be considered a magic number, but it's just for formatting, so I don't think it counts
    int minute = (timeIndex % SESSIONS_PER_HOUR) * SESSION_MINUTES;
    if(hour < 10) { //same here, technically I could check how many digits are in the number with log, but that's a waste of computing power
        out += "0";
    }
    out += to_string(hour) + ":" + to_string(minute);
    if(minute == 0) { //same here
        out += "0";
    }
    return out;
}