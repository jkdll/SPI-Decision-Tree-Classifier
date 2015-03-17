/*
 * Node.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: jake
 */

#include "headers/Node.h"

Node::Node() {
	// TODO Auto-generated constructor stub

}

Node::~Node() {
	// TODO Auto-generated destructor stub
}
void Node::insertAttributes(std::vector<AttributeList> al){
	this->attributes = al;
}
bool Node::isNodeLeaf(){
	bool ret = true;
	for(int i = 0; i <= attributes.size() - 1; i++){
		ret = ret && attributes[i].isLeaf();
	}
	return ret;
}
std::string Node::getBestSplit(){
	float maxGini = 0;
	std::string name;
	for(int i = 0; i <= attributes.size() - 1; i++){
		float tempGini = attributes[i].getGiniIndex();
		if(tempGini >= maxGini){
			maxGini = tempGini;
			name = attributes[i].getName();
		}
	}
	return name;
}
