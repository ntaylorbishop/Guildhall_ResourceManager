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
	cout << endl;
	for (int i = 0; i < list.size(); i++) {
		cout << list.at(i).getName() << " --> ";
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

}