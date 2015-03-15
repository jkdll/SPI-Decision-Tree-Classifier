/*
 * CSVDataLoader.cpp
 *
 *  Created on: Mar 12, 2015
 *      Author: jake
 */

#include "headers/CSVDataLoader.h"
#include <string>
#include <fstream> // To Open File
#include <sstream> // To Read String
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <errno.h>


CSVDataLoader::CSVDataLoader() {
	this->path = "";
	this->config = "";
	initData();
}
CSVDataLoader::~CSVDataLoader() {
	// TODO Auto-generated destructor stub
}
std::string CSVDataLoader::getPath(){
	return path;
}
void CSVDataLoader::setPath(std::string p){
	this->path = p;
}
std::string CSVDataLoader::getConfigPath(){
	return config;
}
void CSVDataLoader::setConfigPath(std::string c){
	this->config = c;
}
int CSVDataLoader::getNAttributes(){
	return nAttributes;
}
int CSVDataLoader::getNRecords(){
	return nRecords;
}
int CSVDataLoader::getNTargetAttribute(){
	return nTargetAttribute;
}
std::vector<AttributeList> CSVDataLoader::getAttributes(){
	return this->attributes;
}
bool CSVDataLoader::load(){
	initData();
	// Open Config File.
	std::ifstream  fConfig(this->config.c_str());
	std::string line, cell;
	std::ifstream  data(this->path.c_str());
	if(!fConfig.is_open()){ // Open Config File.
		std::cerr << "CSVDataLoader: Error Loading Config File " << strerror(errno) << "\n";
		return false;
	} else { // Load Config Data.
		while(std::getline(fConfig,line))
		{
			this->nAttributes++;
			std::stringstream  attrStream(line);
			int cellCount = 0;
			while(std::getline(attrStream,cell,','))
			{
				if(cellCount == 1 && cell.compare("target") == 0){
					this->nTargetAttribute = nAttributes;
				}
				std::cout << cell;
				cellCount++;
			}
			cellCount = 0;
		}
	}
	if(this->nTargetAttribute == -1 || this->nAttributes == 0){
		std::cerr << "CSVDataLoader: Config Missing Attribute Data.\n";
	}
	std::cout << "Reading Data Set: " + path + " (" << this->nAttributes <<  " Attributes) \n";
	// Open Data File.
	if(!data.is_open()){
		std::cerr << "CSVDataLoader: Error Loading Data" << strerror(errno) << "\n";
		return false;
	} else {
		while(std::getline(data,line))
		{
			std::cout << line + "\n";
			std::stringstream  lineStream(line);
			this->nRecords++;
				/*while(std::getline(lineStream,cell,','))
				{
					std::cout << cell;
				}*/
		}
	}
	std::cout << "Read " << this->nRecords << " Records from " + this->path + "\n";
	return true;
}

void CSVDataLoader::printData(){
	std::cout << 'Records: ' << this->nRecords << ', Attributes: ' + this->nAttributes + '; Target: ' << this->nTargetAttribute;
}
void CSVDataLoader::initData(){
	this->nAttributes = 0;
	this->nRecords = 0;
	this->nTargetAttribute = -1;
}
