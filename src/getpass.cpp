#include <conio.h>
#include <iostream>
#include "../lib/getpass.h"
using namespace std;


// Function that accepts the password
string getPass(){
    // input
    string password;
    char inputChar;

    // process
    while (true) {
        inputChar = (char) getch();

        // if the inputChar
        if (inputChar == INPUT_ASCII::ENTER) {
            cout << endl;
            return password;
        }
        else if (inputChar == INPUT_ASCII::BACKSPACE && password.length() != 0) {
            password.pop_back();

            // remove the printed character quickly
            cout << "\b \b";

            continue;
        }

        else if (inputChar == INPUT_ASCII::BACKSPACE && password.length() == 0) {
            continue;
        }

        password.push_back(inputChar);
        cout << '*';
    }
}