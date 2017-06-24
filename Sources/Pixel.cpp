//
//  Pixel.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "Pixel.hpp"

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b): elem{r, g, b} {}

Pixel::Pixel(const Pixel &pixel) {
	*this = pixel;
}

Pixel &Pixel::operator=(const Pixel &pixel) {
	r = pixel.r;
	g = pixel.g;
	b = pixel.b;
	return *this;
}

uint8_t &Pixel::operator[](int index) {
	return elem[index];
}

uint8_t Pixel::operator[](int index) const {
	return elem[index];
}
