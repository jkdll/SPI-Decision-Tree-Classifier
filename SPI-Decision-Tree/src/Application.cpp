#include <iostream>
#include "headers/CSVDataLoader.h"

int main(){
	CSVDataLoader CDL;
	CDL.setPath("data//cars//car.data");
	CDL.setConfigPath("data//cars//car.config");
	CDL.load();
	CDL.printAttributeList();
	return 0;
}

