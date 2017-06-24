//
//  SeamCarver.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "SeamCarver.hpp"

SeamCarver::SeamCarver(const string &file_name, EnergyCalculator *calculator): file_name(file_name), calculator(calculator) {}

void SeamCarver::setInputImage(const string &file_name) {
	this->file_name = file_name;
}

void SeamCarver::setEnergyCalculator(EnergyCalculator *calculator) {
	this->calculator = calculator;
}

void SeamCarver::resize(int new_width, int new_height) {
	if (new_width >= origin_width && new_height >= origin_height) {
		
	} else if (new_width >= origin_width && new_height < origin_height) {
		
	} else if (new_width < origin_width && new_height >= origin_height) {
		
	} else {
		
	}
}
