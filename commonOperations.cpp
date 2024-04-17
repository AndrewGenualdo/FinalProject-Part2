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

#include <cstdlib>
#include "commonOperations.h"

/*
    Pre: None
   Post: The console will be cleared
Purpose: To clear the console
*********************************************************************************/
void clearScreen()
{
    system("cls");
}

/*
    Pre: None
   Post: The program will be paused until a key is pressed
Purpose: To pause the program until a key is pressed
*********************************************************************************/
void pause()
{
    system("pause");
}
