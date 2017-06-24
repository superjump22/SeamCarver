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
#include "ImageIO.hpp"

using std::string;
using std::vector;

class SeamCarver {
protected:
	string file_name;
	ImageFormat format;
	EnergyCalculator *calculator;
	vector<vector<Pixel>> origin_pixels;
	int origin_width;
	int origin_height;
	vector<vector<Pixel>> pixels;
	int width;
	int height;
	vector<vector<int>> energy;
	vector<vector<int>> horizontal_seams;
	vector<vector<int>> vertical_seams;
protected:
	vector<int> findHorizontalSeam();
	vector<int> findVerticalSeam();
//	vector<vector<int>> findHorizontalSeam(int num);
//	vector<vector<int>> findVerticalSeam(int num);
	void removeHorizontalSeam(vector<int> seam);
	void removeVerticalSeam(vector<int> seam);
//	void insertHorizontalSeam(vector<int> seam);
//	void insertVerticalSeam(vector<int> seam);

public:
	SeamCarver();
	SeamCarver(const string &file_name, ImageFormat format, EnergyCalculator *calculator);
	void setInputImage(const string &file_name, ImageFormat format);
	void setEnergyCalculator(EnergyCalculator *calculator);
	void importImage();
	void narrowWidth(int cols_num);
	void narrowHeight(int rows_num);
	void narrow(int rows_num, int cols_num);
	void enlargeWidth(int cols_num);
	void enlargeHeight(int rows_num);
	void enlarge(int rows_num, int cols_num);
};

#endif /* SeamCarver_hpp */
