/*
 * Node.h
 *
 *  Created on: Mar 17, 2015
 *      Author: jake
 */

#include "AttributeList.h"

#ifndef NODE_H
#define NODE_H

class Node {
public:
	Node();
	virtual ~Node();
	void insertAttributes(std::vector<AttributeList> al);
	bool isNodeLeaf();
	std::string getBestSplit();
	void split(std::string n, std::string v);
private:
	std::vector<AttributeList> attributes;
	std::vector<Node> children;
};
#endif
