/*
 * Histogram.h
 *
 *  Created on: Mar 17, 2015
 *      Author: jake
 */

#include <vector>

#ifndef HISTOGRAM_H_
#define HISTOGRAM_H_

class Histogram {
public:
	Histogram();
	virtual ~Histogram();
	int getWidth();
	void setValue(int i, int v);
	int getValue(int i);
	void addValue(int v);
	void rmValue(int v);
	int getPos();
	void setPos(int p);
private:
	std::vector<int> values;
	int pos;
};

#endif /* HISTOGRAM_H_ */
