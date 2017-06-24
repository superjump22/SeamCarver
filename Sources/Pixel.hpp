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
};

inline int distance2(const Pixel &pixel1, const Pixel &pixel2) {
	int result = (pixel1.r - pixel2.r) * (pixel1.r - pixel2.r);
	result += (pixel1.g - pixel2.g) * (pixel1.g - pixel2.g);
	result += (pixel1.b - pixel2.b) * (pixel1.b - pixel2.b);
	return result;
}

#endif /* Pixel_hpp */
