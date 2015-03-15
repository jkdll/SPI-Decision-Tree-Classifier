/*
 * CSVDataLoader.h
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#define CSVDATALOADER_H_
#include <iostream>
#include <string>
#include <vector>
#include "AttributeList.h"

class CSVDataLoader {
public:
	CSVDataLoader();
	// Accessors
	std::string getPath();
	std::string getConfigPath();
	int getNAttributes();
	int getNRecords();
	int getNTargetAttribute();
	std::vector<AttributeList> getAttributes();
	void printData();
	// Modifiers
	void setConfigPath(std::string c);
	void setPath(std::string p);
	virtual ~CSVDataLoader();
	// Functions
	bool load();
private:
	std::string path;
	std::string config;
	int nAttributes;
	int nRecords;
	int nTargetAttribute;
	void initData();
	std::vector<AttributeList> attributes;
};
