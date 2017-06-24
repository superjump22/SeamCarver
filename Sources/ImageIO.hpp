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
#include "Pixel.hpp"
#include "CImg.hpp"

using std::string;
using std::vector;
using namespace cimg_library;

enum ImageFormat {
	jpg, png
};

class ImageIO {
public:
	void importImage(vector<vector<Pixel>> &pixels, const string &file_name, ImageFormat format) const;
	void exportImage(const vector<vector<Pixel>> &pixels, int width, int height, const string &file_name, ImageFormat format) const;
};

#endif /* ImageIO_hpp */
