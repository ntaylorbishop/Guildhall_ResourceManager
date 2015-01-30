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
	virtual ~UI();

	void run();
	void outputOptions();
	void takeInput();
	void takeInput(int inp);

	void askForFile();
	void loadFromFile(string fileName);
private:
	string fileName;
	string fileContents;
	bool terminate;

	List NodeList;
};

