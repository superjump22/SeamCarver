//
//  SeamCarver.hpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#ifndef SeamCarver_hpp
#define SeamCarver_hpp

#include <string>
#include <vector>
#include "EnergyCalculator.hpp"

using std::string;
using std::vector;

class SeamCarver {
protected:
	string file_name;
	EnergyCalculator *calculator;
	vector<vector<Pixel>> pixels;
	vector<int> findHorizontalSeam(int num = 1);
	vector<int> findVerticalSeam(int num = 1);
	void removeHorizontalSeam(vector<int> seam);
	void removeVerticalSeam(vector<int> seam);
	void insertHorizontalSeam(vector<int> seam);
	void insertVerticalSeam(vector<int> seam);
	void narrowWidth(int cols_num);
	void narrowHeight(int rows_num);
	void enlargeWidth(int cols_num);
	void enlargeHeight(int rows_num);
public:
	SeamCarver(const string &file_name, EnergyCalculator *calculator = nullptr);
	void setInputImage(const string &file_name);
	void setEnergyCalculator(EnergyCalculator *calculator);
	void resizeWidth(int new_width);
	void resizeHeight(int new_height);
	void resize(int new_width, int new_height);
};

#endif /* SeamCarver_hpp */
