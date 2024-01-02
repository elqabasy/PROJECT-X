#include <iostream>
#include <fstream>
#include "lib/drawings.h"
#include "lib/getpass.h"
using namespace std;




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
            // loginScreen();
            signIn();
            break;
        case 2:
            // registerScreen();
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

void signIn(){
    
    string username, password, username_check, password_check;
    
    cout << "\nEnter your username: "; getline(cin, username);
    
    ifstream file("data\\accounts\\" + username + "_account.txt");
    // ifstream file(R"(data\accounts\)" + username + "_account.txt");
    getline(file, username_check);
    getline(file, password_check);
    file.close();
    unsigned short int input;
    if (username != username_check){
        cout << "\n| The username you entered is not valid or does not exist.\n";
        // tryAgainScreen();
        cin >> input;
        switch (input){
            case 1:
                signIn();
                break;
            case 2:
                main();
                break;
        }
    }
    
    password = GetPass("\nEnter your password: ", '*');

    if (password != password_check){
        cout << "\n| Wrong password!\n";
        // tryAgainScreen();
        cin >> input;
        switch (input){
            case 1:
                signIn();
                break;
            case 2:
                main();
                break;
        }
    }
}

void signUp(){
    string username, password, c_password; //Confirmation Password Input Variable

    cout << "\nCreate your username: "; getline(cin, username);
    password = GetPass("Create a password: ", '*');
    c_password = GetPass("Confirm your password: ", '*');

    if (c_password != password){
        cout << "\n| Passwords do not match. Please make sure your passwords match and try again.\n";
        signUp();
    }

    // best practice for path formatting is: R"(YOUR_PATH)", etc.
    ofstream account("data\\accounts\\" + username + "_account.txt");
    // ofstream account(R"(data\accounts\)" + username + "_account.txt");
    account << username << '\n' << password;
    account.close();


    cout << "\n| Account created successfully!, You can now log in to your account.\n";
    main();
}