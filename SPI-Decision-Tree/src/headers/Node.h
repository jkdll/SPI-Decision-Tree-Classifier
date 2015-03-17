/*
 * Node.h
 *
 *  Created on: Mar 17, 2015
 *      Author: jake
 */

#include "AttributeList.h"

class Node {
public:
	Node();
	virtual ~Node();
	void insertAttributes(std::vector<AttributeList> al);
	bool isNodeLeaf();
	std::string getBestSplit();
private:
	std::vector<AttributeList> attributes;
	std::vector<Node> children;
};
