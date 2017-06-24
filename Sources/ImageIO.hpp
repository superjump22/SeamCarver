//
//  ImageIO.hpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#ifndef ImageIO_hpp
#define ImageIO_hpp

#define cimg_display 0
#define cimg_use_jpeg
#define cimg_use_png

#include <string>
#include <vector>
#include "config.hpp"
#include "CImg.hpp"

using std::string;
using std::vector;
using namespace cimg_library;

class Pixel {
private:
	uint8_t elem[3];
public:
	uint8_t &r = elem[0];
	uint8_t &g = elem[1];
	uint8_t &b = elem[2];
	Pixel(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0);
	Pixel(const Pixel &pixel);
	Pixel &operator=(const Pixel &pixel);
	uint8_t &operator[](int index);
	uint8_t operator[](int index) const;
};

class ImageIO {
public:
	void importImage(vector<vector<Pixel>> &pixels, const string &fileName) const;
	void exportImage(const vector<vector<Pixel>> &pixels, const string &fileName) const;
};

#endif /* ImageIO_hpp */
