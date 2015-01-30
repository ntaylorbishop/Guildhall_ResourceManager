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
    virtual ~Node();

	void addLink(string link);
	string getName();
	vector<string> getLinks();
private:
	string root;
	vector<string> links;
};

#endif	/* NODE_H */

