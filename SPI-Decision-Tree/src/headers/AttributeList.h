/*
 * AttributeList.h
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include <string>

#define ATTRIBUTELIST_H_

class AttributeList {
public:
	AttributeList();
	virtual ~AttributeList();
	void setData(std::string n, bool d);
	std::string getName();
	bool isDiscrete();
private:
	std::string sName;
	bool bDiscrete;
};

