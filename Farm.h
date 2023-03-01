#pragma once
#include <math.h>
#define MAX 100
#define RUBBER 0
#define CAFFEE 1
#define TEA 2

struct Point {
	double x, y;

	double distancePoint(Point other) {
		double deltaX = (x - other.x) * (x - other.x);
		double deltaY = (y - other.y) * (y - other.y);

		return sqrt(deltaX + deltaY);
	}
};

struct IndustrialCrop {
	Point point;
	int kindOfTree;
};

struct Farm {
	int noTree;
	IndustrialCrop listTree[MAX];
	int noEachTree[3] = {0};
	Point pipe;
	double cirBarrier;

	void updateNoTree() {
		for (int i = 0; i < noTree; i++) {
			noEachTree[listTree[i].kindOfTree]++;
		}
	}
};

int getRubber(Farm farm);
int getTea(Farm farm);
int getCaffee(Farm farm);
int getCrop(Farm farm, int kindOfTree);

void setMinCirBarrier(Farm& farm);
double getMinCirBarrier(Farm farm);

void setPipe(Farm& farm);
double getPipe(Farm farm);
