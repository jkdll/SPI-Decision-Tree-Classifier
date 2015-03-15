/*
 * AttributeList.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include "headers/AttributeList.h"


// TODO: Attribute List must contain: Attribute Value, Class Label and Record ID. Create these.

AttributeList::AttributeList() {
	this->sName = "";
	this->bDiscrete = false;
}

AttributeList::~AttributeList() {
	// TODO Auto-generated destructor stub
}

void AttributeList::setData(std::string n, bool d){
	this->sName = n;
	this->bDiscrete = d;
}
std::string AttributeList::getName(){
	return sName;
}
bool AttributeList::isDiscrete(){
	return bDiscrete;
}



