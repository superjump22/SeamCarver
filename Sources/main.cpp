//
//  main.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include <iostream>
#include "SeamCarver.hpp"

int main(int argc, const char * argv[]) {
	SeamCarver *carver = new SeamCarver;
	carver->setInputImage("1", jpg);
	carver->setEnergyCalculator(new GradientCalculator);
	carver->importImage();
	carver->narrowWidth(200);
	carver->narrowHeight(200);
	carver->enlargeWidth(200);
	carver->enlargeHeight(200);
	return 0;
}
