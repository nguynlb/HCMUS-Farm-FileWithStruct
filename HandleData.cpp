#include "HandleData.h"

void readFarm(const char filePath[], Farm& farm)
{
	std::ifstream inFile(filePath);

	if (!inFile.is_open()) {
		std::cout << "Error: Cannot Open File\n";
		return;
	}

	Farm temp;
	inFile >> temp.noTree;
	for (int i = 0; i < temp.noTree; i++) {
		inFile >> temp.listTree[i].point.x;
		inFile >> temp.listTree[i].point.y;
		inFile >> temp.listTree[i].kindOfTree;
	}

	temp.updateNoTree();
	setMinCirBarrier(temp);
	setPipe(temp);


	farm = temp;

	inFile.close();
}

void writeFarm(const char filePath[], Farm farm) {
	std::ofstream outFile(filePath);

	if (!outFile.is_open()) {
		std::cout << "Error: Cannot Open File\n";
		return;
	}

	for (int i = 0; i < 3; i++) {
		outFile << farm.noEachTree[i] << " ";
	}
	outFile << std::endl;

	outFile << getMinCirBarrier(farm) << std::endl;
	outFile << getPipe(farm);

	outFile.close();
}