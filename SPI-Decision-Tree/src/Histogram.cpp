/*
 * Histogram.cpp
 *
 *  Created on: Mar 17, 2015
 *      Author: jake
 */

#include "headers/Histogram.h"
#include <vector>
#include <algorithm>    // std::remove

Histogram::Histogram() {
	pos = -1;
}

Histogram::~Histogram() {
	// TODO Auto-generated destructor stub
}

int Histogram::getWidth(){
	return this->values.size();
}
void Histogram::setValue(int i, int v){
	this->values[i] = v;
}
int Histogram::getValue(int i){
	return this->values[i];
}
void Histogram::addValue(int v){
	this->values.push_back(v);
}
void Histogram::rmValue(int v){
	this->values.erase(std::remove(this->values.begin(), this->values.end(), v), this->values.end());
}
int Histogram::getPos(){
	return pos;
}
void Histogram::setPos(int p){
	this->pos = p;
}
