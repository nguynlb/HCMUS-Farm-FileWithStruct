#include "HandleData.h"
#include "Farm.h"

int main() {
	Farm farm;
	readFarm("NongTrai.in", farm);
	writeFarm("NongTrai.out", farm);
	return 0;
}