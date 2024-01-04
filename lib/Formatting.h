//
// Created by Mahros on 12/31/2022.
//

#ifndef PROJECT_X_FORMATTING_H
#define PROJECT_X_FORMATTING_H
#include <iostream>
using namespace std;

namespace Formatting{
    namespace Text{
        void printCenter(const string& text, const char& endChar = '\n');
        void print(const string& text, const short int& position, const string& endLine = "\n");
        void print(const string& text, const short int& xAlign, const short int& yAlign, const string& endLine = "\n");
        void printLong(const string& text, const short int& xAlign, const short int& yAlign, const string& endLine = "\n");
    }
}
#endif

/* Features:
* Print text in center of x-Axis.
* Print text in center of x-Axis and y-Axis.
*/