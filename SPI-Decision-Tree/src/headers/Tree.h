/*
 * Tree.h
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include "CSVDataLoader.h"


class Tree {
public:
	Tree();
	virtual ~Tree();
	void buildTree(std::string data, std::string config);
	void printTree();
private:
};

