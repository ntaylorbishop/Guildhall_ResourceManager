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
	cout << "\t1. Load from file" << endl;
	cout << "\t2. Add Node to graph" << endl;
	cout << "\t3. Add Links to node" << endl;
	cout << "\t4. Display graph" << endl;
	cout << "\t5. Write graph to file" << endl;
	cout << "\t6. End progarm" << endl;

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

void UI::takeInput(int inp) {
	if (inp == 1) { //Load from file
		askForFile();
	}
	else if (inp == 2) { //Add node
		string str;
		cout << endl << "Please input a string of elements, with the root first and each element separated by a single whitespace (Type 'b' to go back):" << endl;
		
		//Wait for input and take in entire line. cin tokenizes with whitespace
		string tmp;
		cin >> tmp;
		getline(cin, str);
		tmp += str;
		str = tmp;
		
		if (str == "b")
			outputOptions();
		else
			NodeList.addNode(str);
		outputOptions();
	}
	else if (inp == 3) { //Add links
		string str;
		cout << endl << "Please input elements, where the first is the node and the rest being the links to add,";
		cout << "separated by a single whitespace (Type 'b' to go back): " << endl;

		//Wait for input and take in entire line. cin tokenizes with whitespace
		string tmp;
		cin >> tmp;
		getline(cin, str);
		tmp += str;
		str = tmp;

		if (str == "b")
			outputOptions();
		else {
			if (NodeList.addLinksToNode(str))
				cout << endl << "Links to node added successfully." << endl;
			else
				cout << endl << "Node does not exist. Please try again." << endl;
		}
		outputOptions();
	}
	else if (inp == 4) { //Display graph
		NodeList.displayGraph();
		outputOptions();
	}
	else if (inp == 5) { //Write graph to file
		NodeList.writeToFile();
		outputOptions();
	}
	else if (inp == 6) { //Quit
		terminate = true;
	}
	else {
		cout << "Incorrect command given. Please try again";
		outputOptions();
	}
		

}