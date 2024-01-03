#include <iostream>
#include <fstream>
#include "../lib/getpass.h"
using namespace std;

const string DATA_PATH = R"(..\data\accounts\)";

void signUp(){
    string username, password, confirmation_password;
    unsigned short int choice;
    
    //Input
    cout << "Create your username: ";
    cin >> username;
    
    cout << "Create your password: ";
    password = getPass();
    
    cout << "Confirm your password: ";
    confirmation_password = getPass();

    //Functions
    if (confirmation_password == password){

        ofstream account(DATA_PATH + username + "_account.txt");
        account << username << '\n' << password;
        account.close();

        cout << "| Account created successfully!, You can now log in to your account.\n";
        return;

    }
    else{
        cout << "| Passwords do not match. Please make sure your passwords match and try again.\n";
        signUp();
        return;
    }
}

void signIn(){
    string username, password, username_check, password_check;
    unsigned short int choice;
    

    ifstream file(DATA_PATH + username + "_account.txt");
    getline(file, username_check);
    getline(file, password_check);
    file.close();


    cout << "Enter your username: ";
    cin >> username;
    if (username != username_check){
        cout << "| The username you entered is not valid or does not exist.\n";
        signIn();
        return;
    }

    cout << "Enter your password: ";
    password = getPass();
    if (password != password_check){
        cout << "| Wrong password!.\n";
        signIn();
        return;
    }
}