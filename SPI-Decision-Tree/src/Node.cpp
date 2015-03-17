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
void Node::split(std::string n, std::string v){
	int nAttrToSplit = 0;
	for(int i = 0; i <= this->attributes.size() - 1; i++){
		if(this->attributes[i].getName().compare(n) == 0){
			nAttrToSplit = i;
		}
	}
	std::vector<std::string> classes = this->attributes[nAttrToSplit].getValueClasses();
	std::vector<AttributeList> newAttributeList = this->attributes;
	for(int i = 0; i <= classes.size() - 1; i++){
		newAttributeList[nAttrToSplit].filter(classes[i]);
		std::vector<int> rowNumbers = this->attributes[nAttrToSplit].getRowNumbers();
		for(int j = 0; j <= newAttributeList.size() - 1; j++){
			newAttributeList[j].filterByIds(rowNumbers);
		}
	}
	Node newNode;
	newNode.insertAttributes(newAttributeList);
	this->children.push_back(newNode);
}
