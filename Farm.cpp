#include <iostream>
#include "Farm.h"

int getRubber(Farm farm) {
	return farm.noEachTree[0];
}
int getCaffee(Farm farm) {
	return farm.noEachTree[1];
}
int getTea(Farm farm) {
	return farm.noEachTree[2];
}

int getCrop(Farm farm, int kindOfTree) {
	return farm.noEachTree[kindOfTree];
}

void setMinCirBarrier(Farm& farm) {
	double xMin, yMin, xMax, yMax;
	xMin = xMax = farm.listTree[0].point.x;
	yMin = yMax = farm.listTree[0].point.y;

	for (int i = 1; i < farm.noTree; i++) {

		if (xMin > farm.listTree[i].point.x)
			xMin = farm.listTree[i].point.x;
		if (yMin > farm.listTree[i].point.y)
			yMin = farm.listTree[i].point.y;
		if (xMax < farm.listTree[i].point.x)
			xMax = farm.listTree[i].point.x;
		if (yMax < farm.listTree[i].point.y)
			yMax = farm.listTree[i].point.y;
	}
	farm.cirBarrier = 2 * ((xMax - xMin) + (yMax - yMin));
}

double getMinCirBarrier(Farm farm) {
	return farm.cirBarrier;
}

void setPipe(Farm& farm) {
	Point pipe;
	double x = 0, y = 0;
	for (int i = 0; i < farm.noTree; i++) {
		x += farm.listTree[i].point.x;
		y += farm.listTree[i].point.y;
	}

	pipe.x = x / farm.noTree;
	pipe.y = y / farm.noTree;

	farm.pipe = pipe;
}


double getPipe(Farm farm) {
	double totalLengthOfPipe = 0;
	for (int i = 0; i < farm.noTree; i++) {
		totalLengthOfPipe += farm.pipe.distancePoint(farm.listTree[i].point);
	}

	return totalLengthOfPipe;
}