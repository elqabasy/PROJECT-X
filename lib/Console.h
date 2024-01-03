// 
// Created by Mahros on 12/31/2022.
// 

#ifndef PROJECT_X_CONSOLE_H
#define PROJECT_X_CONSOLE_H
#include <iostream>
using namespace std;
namespace Console { 
    void getConsoleSize(int &rows, int &cols);
    void sleep(const int& ms);
    void setCursor(const int& x, const int& y);
    void resetCursor();
}

#endif 