/* 
 * File:   List.cpp
 * Author: taylor
 * 
 * Created on January 16, 2015, 3:52 PM
 */

#include "List.h"

List::List() {

}
List::~List() {

}

void List::addNode(string node) {
	stringstream ss(node);
	int counter = 0;
	string str;
	Node newNode;

	while (ss >> str) {
		if (counter == 0)
			newNode.setName(str);
		newNode.addLink(str);
		counter++;
	}
	list.push_back(newNode);
}
bool List::addLinkToNode(string link) {
	bool nodeExists = false;
	int idx;
	stringstream ss(link);
	int counter = 0;
	string str;
	string root; 
	string linkToAdd;

	while (ss >> str) {
		if (counter == 0)
			root = str;
		else
			linkToAdd = str;
		counter++;
	}

	for (int i = 0; i < list.size(); i++) {
		if (list.at(i).getName() == link) {
			nodeExists = true;
			idx = i;
			break;
		}
	}
	if (nodeExists = true)
		list.at(idx).addLink(link);
	return nodeExists;
}
void List::loadFromFile(string fileContents) {
	//cout << endl << fileContents << endl;

	stringstream ss(fileContents);
	string lineToken;

	while (getline(ss, lineToken, '\n')) {
		stringstream lineSS(lineToken);
		string str;
		vector<string> listElem;

		while (lineSS >> str) {
			listElem.push_back(str);
		}

		Node newNode = Node(listElem.at(0));
		for (int i = 1; i < listElem.size(); i++) {
			newNode.addLink(listElem.at(i));
		}
		list.push_back(newNode);
		//cout << endl;
	}
}
void List::displayGraph() {
	cout << endl << "Graph Display:" << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << "\t" << list.at(i).getName() << " --> ";
		for (int j = 0; j < list.at(i).getLinks().size(); j++) {
			if (j == list.at(i).getLinks().size() - 1)
				cout << list.at(i).getLinks().at(j);
			else
				cout << list.at(i).getLinks().at(j) << ", ";
		}
		cout << endl;
	}
}
bool List::isNodeUsable(string nodeName) {
	return true;
}
void List::writeToFile() {
	fstream outputFile;
	outputFile.open("new_list.txt", fstream::out);
	if (outputFile.is_open()) {
		for (int i = 0; i < list.size(); i++) {
			outputFile << list.at(i).getName() << " --> ";
			for (int j = 0; j < list.at(i).getLinks().size(); j++) {
				if (j == list.at(i).getLinks().size() - 1)
					outputFile << list.at(i).getLinks().at(j);
				else
					outputFile << list.at(i).getLinks().at(j) << ", ";
			}
			outputFile << '\n';
		}
		cout << endl << "Graph written to new_list.txt successfully." << endl;
	}
	else
		cout << "Something went wrong. We're fucked" << endl;
}
