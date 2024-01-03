//
// Created by Mahros on 12/31/2022.
//

#ifndef PROJECT_X_FORMATTING_H
#define PROJECT_X_FORMATTING_H

#include <iostream>
#include <stdlib.h>     // for sleep
#include <chrono>       // std::chrono::microseconds
#include <thread>       // std::this_thread::sleep_for
using namespace std;

namespace Console {
    void getConsoleSize(int &rows, int &cols);
    void sleep(const int& seconds);
    void setCursor(const int& x, const int& y);
    void resetCursor();
}

namespace Text{
    void printCenter(const string& text, const char& endChar = '\n');
    void print(const string& text, const short int& position, const string& endLine = "\n");
    void print(const string& text, const short int& xAlign, const short int& yAlign, const string& endLine = "\n");
    void printLong(const string& text, const short int& xAlign, const short int& yAlign, const string& endLine = "\n");
}
#endif

/* Features:
* Print text in center of x-Axis.
* Print text in center of x-Axis and y-Axis.
*/