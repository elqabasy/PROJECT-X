#include <iostream>
#include <fstream>
#include "lib/drawings.h"
#include "lib/getpass.h"
using namespace std;

//Tasks
//1- Handle Keys
//2- Handle Functions
//3- Branching

//Functions
void signIn();
void signUp();
void selectOption(unsigned short int &input);

int main(){
    homeScreen();
    unsigned short int input;
    cin >> input;
    selectOption(input);
    return 0;
}


void selectOption(unsigned short int &input){
    switch(input){
        case 1:
            loginScreen();
            signIn();
            break;
        case 2:
            registerScreen();
            signUp();
            break;
        case 0:
            cout << "| See you soon!\n";
            return;
            break;
        default:
            cout << "| Invalid Input, Please Try Again!\n";
            selectOption(input);
            break;
    }
}