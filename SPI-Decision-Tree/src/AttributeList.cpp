/*
 * AttributeList.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include "headers/AttributeList.h"
#include "headers/AttributeRecord.h"


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
std::vector<AttributeRecord> AttributeList::getRecords(){
	return this->records;
}
void AttributeList::addRecord(AttributeRecord ar){
	this->records.push_back(ar);
}
void AttributeList::setLastElementClass(std::string c){
	this->records.back().setClass(c);
}
bool AttributeList::isLeaf(){
	bool ret = true;
	if(this->records.size() == 0){
		return true;
	}
	std::string first = this->records[0].getClass();
	for(int i = 0; i <= this->records.size() - 1; i++){
		ret = (this->records[i].getClass() == first) && ret;
	}
	return ret;
}

void AttributeList::filter(std::string c){
	std::vector<int> indexes;
	for(int i = 0; i <= this->records.size() - 1; i++){
		indexes.push_back(i);
	}
	for(int i = 0; i<= indexes.size() - 1; i++){
		this->records.erase(this->records.begin()+indexes[i]);
	}
}
