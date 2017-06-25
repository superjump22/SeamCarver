//
//  SeamCarver.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "SeamCarver.hpp"

// =============================================================================
//
// Protected
//
// =============================================================================

void SeamCarver::calculateEnergy() {
	energy = calculator->calculateEnergy(pixels, width, height);
}

void SeamCarver::findHorizontalSeam() {
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
	horizontal_seams.push_back(seam);
}

void SeamCarver::findHorizontalSeam(int num) {
	Heap heap(height - 2);
	for (int y = 1; y < height - 1; y++) {
		heap.insert(energy[y][1], y);
	}
	for (int i = 0; i < num; i++) {
		vector<int> seam(width);
		seam[1] = heap.extractMin();
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
		horizontal_seams.push_back(seam);
	}
	std::sort(horizontal_seams.begin(), horizontal_seams.end(), compare);
}

void SeamCarver::findVerticalSeam() {
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
	vertical_seams.push_back(seam);
}

void SeamCarver::findVerticalSeam(int num) {
	Heap heap(width - 2);
	for (int x = 1; x < width - 1; x++) {
		heap.insert(energy[1][x], x);
	}
	for (int i = 0; i < num; i++) {
		vector<int> seam(height);
		seam[1] = heap.extractMin();
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
		vertical_seams.push_back(seam);
	}
	std::sort(vertical_seams.begin(), vertical_seams.end(), compare);
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

// =============================================================================
//
// Public
//
// =============================================================================

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

void SeamCarver::narrowWidth(int cols_num) {
	for (int i = 0; i < cols_num; i++) {
		calculateEnergy();
		findVerticalSeam();
		removeVerticalSeam(vertical_seams.back());
	}
	ImageIO io;
	io.exportImage(pixels, width, height, file_name + "_横向收缩", format);
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
	io.exportImage(pixels, width, height, file_name + "_横向收缩_seams", format);
	pixels = origin_pixels;
	width = origin_width;
	height = origin_height;
}

void SeamCarver::narrowHeight(int rows_num) {
	for (int i = 0; i < rows_num; i++) {
		calculateEnergy();
		findHorizontalSeam();
		removeHorizontalSeam(horizontal_seams.back());
	}
	ImageIO io;
	io.exportImage(pixels, width, height, file_name + "_纵向收缩", format);
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
	io.exportImage(pixels, width, height, file_name + "_纵向收缩_seams", format);
	pixels = origin_pixels;
	width = origin_width;
	height = origin_height;
}

void SeamCarver::enlargeWidth(int cols_num) {
	calculateEnergy();
	vector<vector<Pixel>> seams_image = pixels;
	findVerticalSeam(cols_num);
	while (vertical_seams.size() > 0) {
		vector<int> seam = vertical_seams.back();
		for (int y = 0; y < height; y++) {
			pixels[y].push_back(Pixel());
			seams_image[y].push_back(Pixel());
			for (int x = width; x > seam[y]; x--) {
				pixels[y][x] = pixels[y][x - 1];
				seams_image[y][x] = seams_image[y][x - 1];
			}
			pixels[y][seam[y]] = pixels[y][seam[y] - 1] + pixels[y][seam[y] + 1];
			seams_image[y][seam[y]] = {0, 255, 0};
		}
		width++;
		vertical_seams.pop_back();
	}
	ImageIO io;
	io.exportImage(pixels, width, height, file_name + "_横向伸展", format);
	io.exportImage(seams_image, width, height, file_name + "_横向伸展_seams", format);
	pixels = origin_pixels;
	width = origin_width;
	height = origin_height;
}

void SeamCarver::enlargeHeight(int rows_num) {
	calculateEnergy();
	vector<vector<Pixel>> seams_image = pixels;
	findHorizontalSeam(rows_num);
	while (horizontal_seams.size() > 0) {
		pixels.push_back(vector<Pixel>(width));
		seams_image.push_back(vector<Pixel>(width));
		vector<int> seam = horizontal_seams.back();
		for (int x = 0; x < width; x++) {
			for (int y = height; y > seam[x]; y--) {
				pixels[y][x] = pixels[y - 1][x];
				seams_image[y][x] = seams_image[y - 1][x];
			}
			pixels[seam[x]][x] = pixels[seam[x] - 1][x] + pixels[seam[x] + 1][x];
			seams_image[seam[x]][x] = {0, 255, 0};
		}
		height++;
		horizontal_seams.pop_back();
	}
	ImageIO io;
	io.exportImage(pixels, width, height, file_name + "_纵向伸展", format);
	io.exportImage(seams_image, width, height, file_name + "_纵向伸展_seams", format);
	pixels = origin_pixels;
	width = origin_width;
	height = origin_height;
}

void SeamCarver::test(int num) {

}
