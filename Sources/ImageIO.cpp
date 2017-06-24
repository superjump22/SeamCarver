//
//  ImageIO.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "ImageIO.hpp"

void ImageIO::importImage(vector<vector<Pixel>> &pixels, const string &file_name, ImageFormat format) const {
	string file_full_name = INPUTS_DIRECTORY + file_name;
	switch (format) {
		case jpg:
			file_full_name += ".jpg";
			break;
		case png:
			file_full_name += ".png";
			break;
	}
	CImg<uint8_t> image(file_full_name.c_str());
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

void ImageIO::exportImage(const vector<vector<Pixel>> &pixels, int width, int height, const string &file_name, ImageFormat format) const {
	CImg<uint8_t> image(width, height, 1, 3);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			const auto &pixel = pixels[i][j];
			image.atXYZC(j, i, 0, 0) = pixel.r;
			image.atXYZC(j, i, 0, 1) = pixel.g;
			image.atXYZC(j, i, 0, 2) = pixel.b;
		}
	}
	string file_full_name = OUTPUTS_DIRECTORY + file_name;
	switch (format) {
		case jpg:
			file_full_name += ".jpg";
			break;
		case png:
			file_full_name += ".png";
			break;
	}
	image.save(file_full_name.c_str());
}
