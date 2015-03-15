/*
 * AttributeRecord.cpp
 *
 *  Created on: Mar 13, 2015
 *      Author: jake
 */

#include "headers/AttributeRecord.h"

AttributeRecord::AttributeRecord() {
	tid = -1;

}

AttributeRecord::~AttributeRecord() {
	// TODO Auto-generated destructor stub
}
int AttributeRecord::getRowNumber(){
	return this->tid;
}
std::string AttributeRecord::getValue(){
	return this->value;
}
std::string AttributeRecord::getClass(){
	return this->target;
}
void AttributeRecord::setRowNumber(int r){
	this->tid = r;
}
void AttributeRecord::setValue(std::string v){
	this->value = v;
}
void AttributeRecord::setVlass(std::string t){
	this->target = t;
}
