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

#define ATTRIBUTELIST_H_

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
	int getGiniIndex();
private:
	std::string sName;
	bool bDiscrete;
	std::vector<AttributeRecord> records;
};

