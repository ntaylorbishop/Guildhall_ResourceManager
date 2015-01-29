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

using namespace std;

class List {
public:
    List();
    List(const List& orig);
    virtual ~List();

	void loadFromFile(string fileContents);
private:
	vector<string> list;
};

#endif	/* LIST_H */

