//
//  Pixel.hpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#ifndef Pixel_hpp
#define Pixel_hpp

#include <cstdint>

class Pixel {
protected:
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
	double toGray() const;
};

inline double Pixel::toGray() const {
	return (0.2989 * r + 0.5870 * g + 0.1140 * b) * 0.003921568627;
}

inline Pixel operator+(const Pixel &pixel1, const Pixel &pixel2) {
	return Pixel((pixel1.r + pixel2.r) / 2,
				 (pixel1.g + pixel2.g) / 2,
				 (pixel1.b + pixel2.b) / 2);
}

#endif /* Pixel_hpp */
