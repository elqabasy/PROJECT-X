// 
// Created by Mahros on 11/1/2022.
//
#ifndef PROJECT_X_FILE_H
#define PROJECT_X_FILE_H
#include <iostream>
#include <fstream>
using namespace std;
/* Explaination:
    * This file contains all the functions related to file handling
    * like: create, open, read, write, remove, rename
    * and many more
    
    Performance:
    * Used (const string& fileName) instead of (string fileName), etc.
*/
namespace File {
    void close(const string& fileName);
    bool exist(const string& fileName);
    void remove(const string& fileName);
    bool opened(const string& fileName);
    fstream open(const string& fileName); // not initialized
    fstream create(const string& fileName);
    long long int lineCount(const string& fileName);
    void write(const string& fileName, const string& data);
    bool rename(const string& fileName, const string& newFileName);
    string read(const string& fileName, long long int linesCount = -1, const char& endChar = '\n');
    string readLine(const string& fileName, const long long int& lineNumber = 1, const char& endChar = '\n');
}
#endif

/* Next Functions:
    * open: open exist file and return object for access it, or return name of it, blah blah blah
*/
/* NOTE: DONE */