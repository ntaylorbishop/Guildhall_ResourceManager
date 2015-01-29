/* 
 * File:   main.cpp
 * Author: taylor
 *
 * Created on January 15, 2015, 4:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

#include "File_Parser.h"

using namespace std;

int main(int argc, char** argv) {
    File_Parser parser();
    bool run = true;
    cout << "Please enter a file name. Type \"quit\" to quit." << endl;
    
    while(run) {
        string str;
        cin >> str;
        if(str == "quit") {
            return 0;
        }
        else {
            ifstream file;
            file.open(str.c_str());
            if(file.is_open()) {
				string fileName = str;


				file.close();
            }
            else {
                cout << "Something went wrong. File not found." << endl;
                continue;
            }
        }
    }
    
    return 0;
}

