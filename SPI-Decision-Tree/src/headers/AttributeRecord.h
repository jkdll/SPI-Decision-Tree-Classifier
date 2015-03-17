/*
 * AttributeRecord.h
 *
 *  Created on: Mar 13, 2015
 *      Author: jake
 */

#include <string>

#ifndef ATTRIBUTERECORD_H_
#define ATTRIBUTERECORD_H_

class AttributeRecord {
public:
	AttributeRecord();
	virtual ~AttributeRecord();
	int getRowNumber();
	std::string getValue();
	std::string getClass();
	void setRowNumber(int r);
	void setValue(std::string v);
	void setClass(std::string t);
private:
	int tid;
	std::string value;
	std::string target;
};

#endif /* ATTRIBUTERECORD_H_ */
