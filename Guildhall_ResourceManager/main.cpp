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

#include "UI.h"

using namespace std;

int main(int argc, char** argv) {
	UI engine;
	engine.run();
    
    return 0;
}

/*File_Parser parser();
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
cout << fileName << "Opened successfully." << endl;

file.close();
}
else {
cout << "Something went wrong. File not found." << endl;
continue;
}
}
}*/