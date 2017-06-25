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
	carver->setEnergyCalculator(new GradientCalculator);
	
	carver->setInputImage("1", jpg);
	carver->importImage();
	carver->narrowWidth(200);
	carver->enlargeWidth(100);
	carver->enlargeHeight(100);
	
	carver->setInputImage("2", png);
	carver->importImage();
	carver->narrowWidth(50);
	carver->narrowHeight(50);
	carver->enlargeWidth(50);
	carver->enlargeHeight(50);
	
	carver->setInputImage("3", jpg);
	carver->importImage();
	carver->narrowWidth(50);
	
	carver->setInputImage("4", jpg);
	carver->importImage();
	carver->narrowWidth(50);
	
	carver->setInputImage("5", jpg);
	carver->importImage();
	carver->narrowWidth(200);
	
	carver->setInputImage("6", jpg);
	carver->importImage();
	carver->narrowWidth(200);
	carver->narrowHeight(200);
	carver->enlargeWidth(200);
	carver->enlargeHeight(200);
	
	carver->setInputImage("7", jpg);
	carver->importImage();
	carver->narrowWidth(100);
	
	carver->setInputImage("8", jpg);
	carver->importImage();
	carver->narrowWidth(100);
	
	carver->setInputImage("9", jpg);
	carver->importImage();
	carver->narrowWidth(100);

	carver->setInputImage("10", jpg);
	carver->importImage();
	carver->narrowWidth(100);
	return 0;
}
