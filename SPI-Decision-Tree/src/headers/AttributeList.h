/*
 * AttributeList.h
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include <string>
#include "AttributeRecord.h"
#include <stdio.h>
#include <vector>

#ifndef ATTRIBUTELIST_H
#define ATTRIBUTELIST_H

class AttributeList {
public:
	AttributeList();
	virtual ~AttributeList();
	void setData(std::string n, bool d);
	std::string getName();
	bool isDiscrete();
	std::vector<AttributeRecord> getRecords();
	void addRecord(AttributeRecord ar);
	void setLastElementClass(std::string c);
	bool isLeaf();
	void filter(std::string c);
	void filterByIds(std::vector<int> i);
	std::vector<std::string> getValues();
	float getGiniIndex();
	std::vector<int> getRowNumbers();
private:
	std::string sName;
	bool bDiscrete;
	std::vector<AttributeRecord> records;
};

#endif
