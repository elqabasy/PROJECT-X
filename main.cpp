#include <iostream>
#include <fstream>
#include "lib/drawings.h"
#include "lib/getpass.h"
#include "lib/loginSys.h"
#include "lib/file.h"
using namespace std;

// Tasks
// 1- Handle Keys
// 2- Handle Functions
// 3- Branching



//Functions
inline void clear(){
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}
void selectOption(unsigned short int &input);

int main(){
    clear();
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
            if (signIn()){
                clear();
                startScreen();
                // startProgramme();
                return;
            }
            break;
        case 2:
            clear();
            registerScreen();
            if (signUp()){
                main();
                return;
            }
            break;
        case 0:
            clear();
            cout << "| See you soon!\n";
            return;
            break;
        default:
            cout << "| Invalid Input, Please Try Again!\n";
            selectOption(input);
            return;
            break;
    }
}