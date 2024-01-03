// 
// Created by Mahros at 2022/11/25.
//
#include <fstream>
#include "../lib/File.h"
using namespace std;

bool File::exist(const string& fileName){
    fstream FILE(fileName.c_str());
    FILE.close();
    return FILE.good();    
}

bool File::opened(const string& fileName){
    if(File::exist(fileName)){
        
        fstream FILE(fileName.c_str());
        FILE.close();
        return FILE.is_open();
    }else{
        return false;
    }

    /* Next Update
    * Simplify the previuos code.
    */
}

void File::close(const string& fileName){
    if(File::exist(fileName)){
        fstream FILE(fileName.c_str());
        FILE.close();
    }
}

void File::remove(const string& fileName){
    if(File::exist(fileName)){
        fstream FILE(fileName.c_str());
        if(FILE.good()){
            FILE.close();
            remove(fileName.c_str());
        }
    }

    /* Next Update
    * return true if file removed successfully else false
    */
}

fstream File::create(const string& fileName){
    fstream FILE(fileName.c_str());
    FILE.open(fileName.c_str(), std::ios::in | std::ios::out | std::ios::app);
    FILE.close();
    return FILE;  
    /* Next Update
    * Specify file modes and get them from user. like this:
        * fstream FILE(fileName.c_str(), ios::in | ios::out | ios::app);
    * Handle errors like this:
        * Check if file is running by another application.
        * Check if it exist or not
    */ 
}

string File::read(const string& fileName, long long int linesCount, const char& endChar){
    if(File::exist(fileName)){
        // lines count should change during the function
        // read all data from file
        // when lineCount = -1; so the user want all file lines else he want specific lines from 1 to linesCoupnt
        // the linesCount start from 1 is 1-based indexing
        fstream FILE(fileName.c_str());

        // get ACTUAL lines number of file then check if it less than user linesCount or not, if yes then use ACTUAL lines number
        // long long int actualLinesCount = File::lineCount(fileName);
        // if(linesCount > actualLinesCount){
        //     linesCount = actualLinesCount;
        // }

        // simplify previus if
        long long int actualLinesCount = File::lineCount(fileName);
        actualLinesCount < linesCount ? linesCount = actualLinesCount : linesCount;

        string data;
        if(linesCount == -1){
            while (!FILE.eof()){
                string line;
                getline(FILE, line, endChar);
                data += line + "\n";
            }
        }else{
            for (int i = 1; i < linesCount+1; i++){
                string line;
                getline(FILE, line, endChar);
                data += line + "\n";
            }
        }
        data.pop_back(); // i want to remove last "\n" in text for my use
        FILE >> data;
        FILE.close();
        return data;
    }else{
        return "";
    }
}

string File::readLine(const string& fileName, const long long int& lineNumber, const char& endChar){
    string data = "";
    if(File::exist(fileName)){
        fstream FILE(fileName.c_str());
        for (int i = 0; i < lineNumber; i++){
            getline(FILE, data, endChar);
        }
        FILE.close();
    }
    return data;    
}

long long int File::lineCount(const string& fileName){
    if(File::exist(fileName)){
        fstream FILE(fileName.c_str());
        long long int lineCount = 0;
        string line;
        while(getline(FILE, line)){
            lineCount++;
        }
        FILE.close();
        return lineCount;
    }else{
        return 0;
    }
    /* Next Update
    * Reduce time complixty for this function to run as fast as possible.
    */
}

void File::write(const string& fileName, const string& data){
    if(File::exist(fileName)){
        fstream FILE(fileName.c_str());
        FILE << data;
        FILE.close(); 
    }

    /* Next Update
    * Check the File permissions and write permissions.
    */
}

bool File::rename(const string& fileName, const string& newFileName){
    if(File::exist(fileName)){
        int result = std::rename(fileName.c_str(), newFileName.c_str());
        return !(result == 0);
     
    }else{
        return false;
    }
    // if retrun = true, so file renamed successfully else not
}
/* NOTE: DONE */