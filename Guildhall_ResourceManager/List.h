/* 
 * File:   List.h
 * Author: taylor
 *
 * Created on January 16, 2015, 3:52 PM
 */

#ifndef LIST_H
#define	LIST_H

#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Node.h"

//DEBUG
#include <iostream>

using namespace std;

class List {
public:
    List();
    virtual ~List();

	void addNode(string node);
	bool addLinksToNode(string link);
	void loadFromFile(string fileContents);
	void displayGraph();
	bool isNodeUsable(string nodeName);
	void writeToFile();
private:
	vector<Node> list;
};

#endif	/* LIST_H */

