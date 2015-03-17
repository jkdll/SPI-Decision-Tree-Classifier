/*
 * Tree.cpp
 * Author: Jake J. Dalli
 * Project: SPI-Decision-Tree
 * Description: Tree Class for Decision Tree
 */

#include "headers/Tree.h"
#include <string>

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
	std::vector<AttributeList> dataset = CDL.getAttributes();
	Node n;
	partition(dataset, n);

}
Node Tree::partition(std::vector<AttributeList> data, Node n){
	n.insertAttributes(data);
	if(n.isNodeLeaf()){
		return n;
	} else {
		std::string name = n.getBestSplit();

	}
	return n;
}
void Tree::printTree(){

}


