/*
 * Tree.h
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include "CSVDataLoader.h"
#include "Node.h"

#ifndef TREE_H_
#define TREE_H_

class Tree {
public:
	Tree();
	virtual ~Tree();
	void buildTree(std::string data, std::string config);
	void printTree();
	Node partition(std::vector<AttributeList> data, Node n);
private:
};

#endif
