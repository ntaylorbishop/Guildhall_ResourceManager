/* 
 * File:   Node.cpp
 * Author: taylor
 * 
 * Created on January 16, 2015, 3:52 PM
 */

#include "Node.h"

Node::Node() {
	this->root = "default";
}
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
void Node::setName(string root) {
	this->root = root;
}
vector<string> Node::getLinks() {
	return links;
}