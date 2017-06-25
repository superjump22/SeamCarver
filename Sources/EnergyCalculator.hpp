//
//  EnergyCalculator.hpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#ifndef EnergyCalculator_hpp
#define EnergyCalculator_hpp

#include <vector>
#include "Pixel.hpp"

using std::vector;

class EnergyCalculator {
public:
	virtual vector<vector<double>> calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const = 0;
};

class GradientCalculator: public EnergyCalculator {
public:
	virtual vector<vector<double>> calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const;
};

class SobelCalculator: public EnergyCalculator {
public:
	virtual vector<vector<double>> calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const;
};

class RobertsCrossCalculator: public EnergyCalculator {
public:
	virtual vector<vector<double>> calculateEnergy(const vector<vector<Pixel>> &pixels, int width, int height) const;
};

#endif /* EnergyCalculator_hpp */
