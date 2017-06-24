//
//  EnergyCalculotor.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "EnergyCalculator.hpp"

vector<vector<int>> GradientCalculator::calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const {
	vector<vector<int>> energy(height);
	for (int i = 0; i < height; i++) {
		energy[i] = vector<int>(width);
	}
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			energy[i][j] += distance2(pixels[i][j], pixels[i][j + 1]);
			energy[i][j] += distance2(pixels[i][j], pixels[i + 1][j]);
		}
	}
	return energy;
}
