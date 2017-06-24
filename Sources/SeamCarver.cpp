//
//  SeamCarver.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "SeamCarver.hpp"

SeamCarver::SeamCarver() {}

SeamCarver::SeamCarver(const string &file_name, ImageFormat format, EnergyCalculator *calculator): file_name(file_name), format(format), calculator(calculator) {}

void SeamCarver::setInputImage(const string &file_name, ImageFormat format) {
	this->file_name = file_name;
	this->format = format;
}

void SeamCarver::setEnergyCalculator(EnergyCalculator *calculator) {
	this->calculator = calculator;
}

void SeamCarver::importImage() {
	ImageIO io;
	io.importImage(origin_pixels, file_name, format);
	pixels = origin_pixels;
	origin_width = static_cast<int>(origin_pixels[0].size());
	origin_height = static_cast<int>(origin_pixels.size());
	width = origin_width;
	height = origin_height;
}

vector<int> SeamCarver::findHorizontalSeam() {
	vector<int> seam(width);
	seam[1] = 1;
	for (int y = 2; y < height - 1; y++) {
		if (energy[y][1] < energy[seam[1]][1]) {
			seam[1] = y;
		}
	}
	for (int x = 2; x < width - 1; x++) {
		seam[x] = seam[x - 1] == 1 ? 1 : seam[x - 1] - 1;
		int max = seam[x - 1] == height - 2 ? height - 2 : seam[x - 1] + 1;
		for (int y = seam[x] + 1; y <= max; y++) {
			if (energy[y][x] < energy[seam[x]][x]) {
				seam[x] = y;
			}
		}
	}
	seam[0] = seam[1];
	seam[width - 1] = seam[width - 2];
	return seam;
}

vector<int> SeamCarver::findVerticalSeam() {
	vector<int> seam(height);
	seam[1] = 1;
	for (int x = 2; x < width - 1; x++) {
		if (energy[1][x] < energy[1][seam[1]]) {
			seam[1] = x;
		}
	}
	for (int y = 2; y < height - 1; y++) {
		seam[y] = seam[y - 1] == 1 ? 1 : seam[y - 1] - 1;
		int max = seam[y - 1] == width - 2 ? width - 2 : seam[y - 1] + 1;
		for (int x = seam[y] + 1; x <= max; x++) {
			if (energy[y][x] < energy[y][seam[y]]) {
				seam[y] = x;
			}
		}
	}
	seam[0] = seam[1];
	seam[height - 1] = seam[height - 2];
	return seam;
}

void SeamCarver::removeHorizontalSeam(vector<int> seam) {
	for (int x = 0; x < width; x++) {
		pixels[seam[x] - 1][x] = pixels[seam[x] - 1][x] + pixels[seam[x]][x];
		pixels[seam[x] + 1][x] = pixels[seam[x] + 1][x] + pixels[seam[x]][x];
		for (int y = seam[x]; y < height - 1; y++) {
			pixels[y][x] = pixels[y + 1][x];
		}
	}
	height--;
}

void SeamCarver::removeVerticalSeam(vector<int> seam) {
	for (int y = 0; y < height; y++) {
		pixels[y][seam[y] - 1] = pixels[y][seam[y] - 1] + pixels[y][seam[y]];
		pixels[y][seam[y] + 1] = pixels[y][seam[y] + 1] + pixels[y][seam[y]];
		for (int x = seam[y]; x < width - 1; x++) {
			pixels[y][x] = pixels[y][x + 1];
		}
	}
	width--;
}

void SeamCarver::narrowHeight(int rows_num) {
	for (int i = 0; i < rows_num; i++) {
		energy = calculator->calculateEnergy(pixels, width, height);
		horizontal_seams.push_back(findHorizontalSeam());
		removeHorizontalSeam(horizontal_seams.back());
	}
	ImageIO io;
	io.exportImage(pixels, width, height, file_name + "_horizontal", format);
	vector<int> seam;
	while (horizontal_seams.size() > 0) {
		seam = horizontal_seams.back();
		for (int x = 0; x < width; x++) {
			for (int y = height; y > seam[x]; y--) {
				pixels[y][x] = pixels[y - 1][x];
			}
			pixels[seam[x]][x] = {255, 0, 0};
		}
		height++;
		horizontal_seams.pop_back();
	}
	io.exportImage(pixels, width, height, file_name + "_horizontal_seams", format);
	pixels = origin_pixels;
	width = origin_width;
	height = origin_height;
}

void SeamCarver::narrowWidth(int cols_num) {
	for (int i = 0; i < cols_num; i++) {
		energy = calculator->calculateEnergy(pixels, width, height);
		vertical_seams.push_back(findVerticalSeam());
		removeVerticalSeam(vertical_seams.back());
	}
	ImageIO io;
	io.exportImage(pixels, width, height, file_name + "_vertical", format);
	vector<int> seam;
	while (vertical_seams.size() > 0) {
		seam = vertical_seams.back();
		for (int y = 0; y < height; y++) {
			for (int x = width; x > seam[y]; x--) {
				pixels[y][x] = pixels[y][x - 1];
			}
			pixels[y][seam[y]] = {255, 0, 0};
		}
		width++;
		vertical_seams.pop_back();
	}
	io.exportImage(pixels, width, height, file_name + "_vertical_seams", format);
	pixels = origin_pixels;
	width = origin_width;
	height = origin_height;
}
