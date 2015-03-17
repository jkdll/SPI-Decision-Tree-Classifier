/*
 * Tree.cpp
 * Author: Jake J. Dalli
 * Project: SPI-Decision-Tree
 * Description: Tree Class for Decision Tree
 */

#include "headers/Tree.h"

Tree::Tree() {
	// TODO Auto-generated constructor stub

}

Tree::~Tree() {
	// TODO Auto-generated destructor stub
}
void Tree::buildTree(std::string data, std::string config){
	CSVDataLoader CDL;
	CDL.setPath(data);
	CDL.setConfigPath(config);
	CDL.load();
	CDL.printAttributeList();

}
void Tree::printTree(){

}

