#include <iostream>
using namespace std;




void startProgramme(unsigned short int &input){
    unsigned short int input; cin >> input;
    switch(input){
        case 1:
            // reserveFlight();
            return;
            break;
        case 2:
            // viewReservation();
            return;
            break;
        case 3:
            // logout();
            return;
            break;
        case 0:
            cout << "| See you soon!\n";
            return;
            break;
        default:
            cout << "| Invalid Input, Please Try Again!\n";
            startProgramme(input);
            return;
            break;
    }
}