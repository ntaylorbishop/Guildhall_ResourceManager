/* 
 * File:   Node.cpp
 * Author: taylor
 * 
 * Created on January 16, 2015, 3:52 PM
 */

#include "Node.h"

Node::Node(string root) {
	this->root = root;
}
Node::~Node() {
}

void Node::addLink(string link) {
	links.push_back(link);
}
string Node::getName() {
	return root;
}
vector<string> Node::getLinks() {
	return links;
}