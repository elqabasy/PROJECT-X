//
// Created by Mahros on 12/31/2022.
//

#include <windows.h>
#include <algorithm>
#include "../lib/Formatting.h"

/* Console */
// For console functions: should be seprated in file named: Console.cpp, Console.h
void Console::getConsoleSize(int& rows, int& cols) {
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CSBI);
    rows = CSBI.srWindow.Bottom - CSBI.srWindow.Top + 1;
    cols = CSBI.srWindow.Right - CSBI.srWindow.Left + 1;
}

void Console::setCursor(const int& rowPos, const int& colPos) {
    cout << "\x1b[" << rowPos << ";" << colPos << "H";
}

void Console::resetCursor(){
    cout << "\x1b[" << 0 << ";" << 0 << "H";
}

void Console::sleep(const int& seconds) {
    this_thread::sleep_for(chrono::seconds{seconds}); // got it from internet search
    // chrono::seconds{seconds} return a const value of seconds with type chrono::seconds
}   

/* Text */
void Text::printCenter(const string& text, const char& endChar) {
    // This function is slow and deprecated.
    int rows, cols; Console::getConsoleSize(rows, cols); // save rows and cols to variables: rows, cols
    cols = (cols / 2) - text.size() / 2;
    cout << string(cols, ' ') << text << endChar; // but the time complixty for this function is O(cols);
}

void Text::print(const string& text, const short int& align, const string& endLine){
    // New version of the printCenter()
    int rows, cols; Console::getConsoleSize(rows, cols); // save rows and cols to variables: rows, cols

    // align left
    if(align == -1){ // any negative number
        cout << text << endLine;
        cout << "\x1b[" << 0 << "G" << text << endLine;
    }
    
    // align right
    if(align == 1){
        // cout << string(cols - text.size(), ' ') << text << endLine;
        cout << "\x1b[" << (cols / 2) - (text.size() / 2) << "G" << text << endLine;
    }

    // align center
    if (align == 0){
        cout << "\x1b[" << cols - text.size() << "G" << text << endLine;
    }

    /* First:
    * I got this from internet saerch: cout << "\x1b[10G" << "Your text here";
        * So this syntax will start writing the text from the 10 columns.
        * We will separate it as this: cout << "\x1b[" << (10 = column) << "G" << "Your text here".
    */
}

void Text::print(const string &text, const short int &xAlign, const short int &yAlign, const string &endLine){
    int rows, cols; Console::getConsoleSize(rows, cols); // save rows and cols to variables: rows, cols
    const int length = text.size();
    int colPos = 0, rowPos = 0;

    // align top-left
    switch (xAlign){
        case -1: // left
            colPos = 0;
            break;
        case 0: // center
            colPos = (cols / 2) - (length / 2);
            break;
        case 1: // right
            colPos = cols - length;
            break;
        default:
            break;
    }
    
    switch (yAlign){
        case -1: // left
            rowPos = 0;
            break;
        case 0: // center
            rowPos = (rows / 2) - 1; // because we write horizontal not vertical: we will do this later.
            break;
        case 1: // right
            rowPos = rows - 1;
            break;
        default:
            break;
    }

    Console::setCursor(rowPos, colPos); cout << text << endLine;
    /* And Second:
    * I got this from internet saerch: cout << "\033[" << 10 << ";0H";
        * So this syntax will start writing the text from the row 10.
        * We will separate it as this: cout << cout << "\033[" << 10 << ";0H".
    */
}

void Text::printLong(const string &text, const short int &xAlign, const short int &yAlign, const string &endLine){
    int rows, cols; Console::getConsoleSize(rows, cols); // save rows and cols to variables: rows, cols
    const int length = text.size();
    int colPos = 0, rowPos = 0;
    const int linesCount = count(text.begin(), text.end(), '\n') + 1;
    // string textTokens[]

    // align top-left
    switch (xAlign){
        case -1: // left
            colPos = 0;
            break;
        case 0: // center
            colPos = (cols / 2) - (length / 2);
            break;
        case 1: // right
            colPos = cols - length;
            break;
        default:
            break;
    }
    
    switch (yAlign){
        case -1: // left
            rowPos = 0;
            break;
        case 0: // center
            rowPos = (rows / 2) - 1; // because we write horizontal not vertical: we will do this later.
            break;
        case 1: // right
            rowPos = rows - 1;
            break;
        default:
            break;
    }

    Console::setCursor(rowPos, colPos); cout << text << endLine;
    /* And Second:
    * I got this from internet saerch: cout << "\033[" << 10 << ";0H";
        * So this syntax will start writing the text from the row 10.
        * We will separate it as this: cout << cout << "\033[" << 10 << ";0H".
    */
}

/* Features:
    * Print text in center of screen
*/