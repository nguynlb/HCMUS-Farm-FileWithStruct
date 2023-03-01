#pragma once
#include "Farm.h"
#include <iostream>
#include <fstream>

void readFarm(const char filePath[], Farm& farm);
void writeFarm(const char filePath[], Farm farm);
