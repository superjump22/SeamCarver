//
//  EnergyCalculotor.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "EnergyCalculator.hpp"

vector<vector<double>> GradientCalculator::calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const {
	vector<vector<double>> energy(height);
	for (int i = 0; i < height; i++) {
		energy[i] = vector<double>(width);
	}
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			energy[i][j] += (pixels[i][j].toGray() - pixels[i][j + 1].toGray()) * (pixels[i][j].toGray() - pixels[i][j + 1].toGray());
			energy[i][j] += (pixels[i][j].toGray() - pixels[i + 1][j].toGray()) * (pixels[i][j].toGray() - pixels[i + 1][j].toGray());
		}
	}
	return energy;
}

vector<vector<double>> SobelCalculator::calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const {
	vector<vector<double>> energy(height);
	for (int i = 0; i < height; i++) {
		energy[i] = vector<double>(width);
	}
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			double value = 0;
			value -= pixels[i - 1][j - 1].toGray();
			value -= 2 * pixels[i][j - 1].toGray();
			value -= pixels[i + 1][j - 1].toGray();
			value += pixels[i - 1][j + 1].toGray();
			value += 2 * pixels[i][j + 1].toGray();
			value += pixels[i + 1][j + 1].toGray();
			energy[i][j] += value * value;
			value = 0;
			value -= pixels[i - 1][j - 1].toGray();
			value -= 2 * pixels[i - 1][j].toGray();
			value -= pixels[i - 1][j + 1].toGray();
			value += pixels[i + 1][j - 1].toGray();
			value += 2 * pixels[i + 1][j].toGray();
			value += pixels[i + 1][j + 1].toGray();
			energy[i][j] += value * value;
		}
	}
	return energy;
}

vector<vector<double>> RobertsCrossCalculator::calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const {
	vector<vector<double>> energy(height);
	for (int i = 0; i < height; i++) {
		energy[i] = vector<double>(width);
	}
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			energy[i][j] += (pixels[i + 1][j + 1].toGray() - pixels[i][j].toGray()) * (pixels[i + 1][j + 1].toGray() - pixels[i][j].toGray());
			energy[i][j] += (pixels[i + 1][j].toGray() - pixels[i][j + 1].toGray()) * (pixels[i + 1][j].toGray() - pixels[i][j + 1].toGray());
		}
	}
	return energy;
}
