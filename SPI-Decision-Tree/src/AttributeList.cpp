/*
 * AttributeList.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include "headers/AttributeList.h"
#include "headers/AttributeRecord.h"
#include "math.h"
#include <algorithm>


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
		if(this->records[i].getValue().compare(c) == 0){
			indexes.push_back(i);
		}
	}
	for(int i = 0; i<= indexes.size() - 1; i++){
		this->records.erase(this->records.begin()+indexes[i]);
	}
}
std::vector<std::string> AttributeList::getValues(){
	std::vector<std::string> vals;
	for(int i = 0; i <= this->records.size() - 1; i++){
		vals.push_back(this->records[i].getValue());
	}
	return vals;
}
void AttributeList::filterByIds(std::vector<int> i){
	std::vector<int> indexes;
	for(int i = 0; i <= this->records.size() - 1; i++){
		if(std::find(indexes.begin(), indexes.end(), this->records[i].getRowNumber()) != indexes.end()){
			indexes.push_back(i);
		}
	}
	for(std::vector<int>::size_type i = 0; i != indexes.size(); i++){
		this->records.erase(this->records.begin()+indexes[i]);
	}
}
std::vector<int> AttributeList::getRowNumbers(){
	std::vector<int> r;
	for(std::vector<AttributeRecord>::size_type i = 0; i != records.size(); i++) {
		r.push_back(records[i].getRowNumber());
	}
	//for(int i = 0; records.size() - 1; i++){
	//	r.push_back(records[i].getRowNumber());
	//}
	return r;
}
float AttributeList::getGiniIndex(){
	std::vector<std::string> vals = getValues();
	int size = vals.size();
	std::vector<std::string> classes;
	float gini;
	std::vector<int> counts;
	for(int i = 0; i <= vals.size() - 1; i++){
		if(std::find(classes.begin(), classes.end(), vals[i]) != classes.end()) {
		    // do nothing...
		} else {
		    classes.push_back(vals[i]);
		    counts.push_back(std::count (vals.begin(), vals.end(), vals[i]));
		}
	}
	for(int i = 0; i <= counts.size() - 1; i++){
		gini = gini + sqrt(counts[i]/size);
	}
	gini = 1 - gini;
	return gini;
}
std::vector<std::string> AttributeList::getValueClasses(){
	std::vector<std::string> vals = getValues();
		int size = vals.size();
		std::vector<std::string> classes;
		float gini;
		for(int i = 0; i <= vals.size() - 1; i++){
			if(std::find(classes.begin(), classes.end(), vals[i]) != classes.end()) {
			    // do nothing...
			} else {
			    classes.push_back(vals[i]);
			}
		}
		return classes;
}
