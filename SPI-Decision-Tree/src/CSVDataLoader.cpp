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
#include <cstdlib>


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
			std::string name;
			while(std::getline(attrStream,cell,','))
			{
				AttributeList ar;
				if(cellCount == 0){
					// Set Name
					name = cell;
				}
				if(cellCount == 1){
					if(cell.compare("discrete") == 0){
						// Set Discrete
						ar.setData(name,true);
					} else if(cell.compare("continuous") == 0){
						// Set Continuous
						ar.setData(name,false);
					} else if(cell.compare("target") == 0){
						// Set Target Attribute
						this->nTargetAttribute = this->nAttributes;
						// Set Discrete
						ar.setData(name,true);
					} else {
						// Error
						std::cerr << "CSVDataLoader:: Error in CSV Configuration.";
						std::exit(EXIT_FAILURE);
					}
					this->attributes.push_back(ar);
				}
				// std::cout << cell;
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
			// std::cout << line + "\n";
			std::stringstream  lineStream(line);
			this->nRecords++;
			int cellCount = 0;
				while(std::getline(lineStream,cell,','))
				{
					// TODO: Parallization Point
					AttributeRecord ar;
					ar.setRowNumber(this->nRecords);
					ar.setValue(cell);
					this->attributes[cellCount].addRecord(ar);
					if(cellCount == (this->nTargetAttribute - 1)){
						for(int i = 0; i <= this->attributes.size() - 1; i++){
							this->attributes[i].setLastElementClass(cell);
						}
					}
					cellCount++;
				}
		}
	}
	this->attributes.erase(this->attributes.begin() + this->nTargetAttribute - 1);
	int limit = this->nRecords;
	std::cout << "Read " << this->nRecords << " Records from " + this->path + "\n";
	return true;
}

void CSVDataLoader::printData(){
	std::cout << "Meta Data --> ";
	std::cout << "Records: " << this->nRecords << ", Attributes: " << this->nAttributes << ", Target: " << this->nTargetAttribute << "\n";
	std::cout << "Attribute List Data --> ";
	std::cout << "Size: " << this->attributes.size();
}
void CSVDataLoader::printAttributeList(){
	std::cout << "\n -------- PRINTING ATTRIBUTE LIST -------------- \n";
	for(int i = 0; i <= this->attributes.size() - 1; i++){
		std::cout << this->attributes[i].getName() + " \\ ";
	}
	std::cout << "\n";
	for(int i = 0; i <= this->attributes.size() - 1; i++){
		std::cout << this->attributes[i].getRecords()[0].getValue() << " (" << this->attributes[i].getRecords()[0].getClass() << "),";
	}
	std::cout << "\n";
}
void CSVDataLoader::initData(){
	this->nAttributes = 0;
	this->nRecords = 0;
	this->nTargetAttribute = -1;
}
