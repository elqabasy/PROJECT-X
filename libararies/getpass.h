//
// Created by Mahros on 12/31/2023.
//

#ifndef GETPASS_H
#define GETPASS_H

#include <iostream>
using namespace std;


// define the ascii codes
enum INPUT_ASCII {
    BACKSPACE = 8, // ASCII CODE FOR BACKSPACE
    ENTER = 13  // FOR ENTER BUTTON ASCII CODE
};

// Function that receives the password from user using cin
string GetPass(const string& label = "", char securityChar = '*');
#endif