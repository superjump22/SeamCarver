//
//  Heap.hpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <vector>

using std::vector;

struct Pair {
	double key;
	int value;
};

class Heap {
private:
	int size;
	vector<Pair> elem;
	int adjustSibling(int index);
	int adjustUncle(int index);
	int adjustChild(int index);
	int deleteElem(int index);
public:
	Heap(int size);
	void insert(double key, int value);
	int max() const;
	int min() const;
	int extractMax();
	int extractMin();
};

#endif /* Heap_hpp */
