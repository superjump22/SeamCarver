//
//  EnergyCalculotor.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "EnergyCalculator.hpp"

void GradientCalculator::calculateEnergy(vector<vector<int>> &energy_matrix, const vector<vector<Pixel>> &pixels) const {
	int width = static_cast<int>(pixels[0].size());
	int height = static_cast<int>(pixels.size());
	energy_matrix = vector<vector<int>>(height);
	for (int i = 0; i < height - 1; i++) {
		energy_matrix[i] = vector<int>(width);
		for (int j = 0; j < width - 1; j++) {
			energy_matrix[i][j] += distance2(pixels[i][j], pixels[i][j + 1]);
			energy_matrix[i][j] += distance2(pixels[i][j], pixels[i + 1][j]);
		}
		energy_matrix[i][width - 1] += distance2(pixels[i][width - 1], pixels[i][0]);
		energy_matrix[i][width - 1] += distance2(pixels[i][width - 1], pixels[i + 1][width - 1]);
	}
	energy_matrix[height - 1] = vector<int>(width);
	for (int j = 0; j < width - 1; j++) {
		energy_matrix[height - 1][j] += distance2(pixels[height - 1][j], pixels[height - 1][j + 1]);
		energy_matrix[height - 1][j] += distance2(pixels[height - 1][j], pixels[0][j]);
	}
	energy_matrix[height - 1][width - 1] += distance2(pixels[height - 1][width - 1], pixels[height - 1][0]);
	energy_matrix[height - 1][width - 1] += distance2(pixels[height - 1][width - 1], pixels[0][width - 1]);
}
