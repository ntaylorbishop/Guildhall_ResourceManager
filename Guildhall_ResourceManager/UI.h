#pragma once

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "List.h"

using namespace std;

class UI {
public:
	UI();

	void run();

	void outputOptions();
	void askForFile();

	void loadFromFile(string fileName);

	void takeInput();
	void takeInput(int inp);
private:
	string fileName;
	string fileContents;
	bool terminate;

	List NodeList;
};

