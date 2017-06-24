//
//  main.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include <iostream>
#include "ImageIO.hpp"

int main(int argc, const char * argv[]) {
	ImageIO *io = new ImageIO;
	vector<vector<Pixel>> pixels;
	io->importImage(pixels, "1.jpg");
	io->exportImage(pixels, "1.png");
	return 0;
}
