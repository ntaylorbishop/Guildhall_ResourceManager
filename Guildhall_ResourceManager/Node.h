/* 
 * File:   Node.h
 * Author: taylor
 *
 * Created on January 16, 2015, 3:52 PM
 */

#ifndef NODE_H
#define	NODE_H

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Node {
public:
    Node(string root);
    Node(const Node& orig);
    virtual ~Node();

	void loadFromFile(string fileContents);
	void addLink(Node* link);
	void displayGraph();
	string getName();
	vector<string> getLinks();
private:
	string root;
	vector<Node*> links;
};

#endif	/* NODE_H */

