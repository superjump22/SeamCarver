//
//  ImageIO.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "ImageIO.hpp"

void ImageIO::importImage(vector<vector<Pixel>> &pixels, const string &fileName) const {
	CImg<uint8_t> image((INPUTS_DIRECTORY + fileName).c_str());
	int width = image.width();
	int height = image.height();
	pixels = vector<vector<Pixel>>(height);
	for (int i = 0; i < height; i++) {
		pixels[i] = vector<Pixel>(width);
		for (int j = 0; j < width; j++) {
			auto &pixel = pixels[i][j];
			pixel.r = image.atXYZC(j, i, 0, 0);
			pixel.g = image.atXYZC(j, i, 0, 1);
			pixel.b = image.atXYZC(j, i, 0, 2);
		}
	}
}

void ImageIO::exportImage(const vector<vector<Pixel>> &pixels, const string &fileName) const {
	unsigned int width = static_cast<unsigned int>(pixels[0].size());
	unsigned int height = static_cast<unsigned int>(pixels.size());
	CImg<uint8_t> image(width, height, 1, 3);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			const auto &pixel = pixels[i][j];
			image.atXYZC(j, i, 0, 0) = pixel.r;
			image.atXYZC(j, i, 0, 1) = pixel.g;
			image.atXYZC(j, i, 0, 2) = pixel.b;
		}
	}
	image.save((OUTPUTS_DIRECTORY + fileName).c_str());
}
