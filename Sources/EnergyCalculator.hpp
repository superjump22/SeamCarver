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
	virtual void calculateEnergy(vector<vector<int>> &energy_matrix, const vector<vector<Pixel>> &pixels) const = 0;
};

class GradientCalculator: public EnergyCalculator {
public:
	virtual void calculateEnergy(vector<vector<int>> &energy_matrix, const vector<vector<Pixel>> &pixels) const;
};

#endif /* EnergyCalculator_hpp */
