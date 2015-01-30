#include "UI.h"


UI::UI() {
	terminate = false;
}
UI::~UI() {

}
void UI::run() {
	cout << "Welcome to the Guildhall Resource Manager!" << endl;
	outputOptions();
	while (!terminate) { }
}

void UI::outputOptions() {
	string input;

	cout << endl << "Please choose an option (Type corresponding number and hit enter): " << endl;
	cout << "1. Load from file" << endl;
	cout << "2. Add Node to graph" << endl;
	cout << "3. Add Link to node" << endl;
	cout << "4. Display graph" << endl;
	cout << "5. End progarm" << endl;

	cin >> input;

	takeInput(stoi(input));
}
void UI::askForFile() {
	string fileName;
	fstream file;

	cout << endl << "Please input the name of the file you would like to load. Type 'q' to go back:" << endl;
	cin >> fileName;
	if (fileName == "q")
		outputOptions();
	else {
		file.open(fileName.c_str(), fstream::in);
		if (file.is_open()) {
			//load file contents into string
			string str((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
			NodeList.loadFromFile(str);

			cout << endl << "Graph loaded successfully." << endl;
			file.close();
			outputOptions();
		}
		else {
			cout << "File not found. Please try again" << endl;
			askForFile();
		}
	}
	
}

void UI::loadFromFile(string fileName) {

}

void UI::takeInput(int inp) {
	if (inp == 1) { //Load from file
		askForFile();
	}
	else if (inp == 2) { //Add node
		cout << "do some shiz" << endl;
		outputOptions();
	}
	else if (inp == 3) { //Add link
		cout << "do some shiz" << endl;
		outputOptions();
	}
	else if (inp == 4) { //Display graph
		NodeList.displayGraph();
		outputOptions();
	}
	else if (inp == 5) { //Quit
		terminate = true;
	}
	else {
		cout << "Incorrect command given. Please try again";
		outputOptions();
	}
		

}