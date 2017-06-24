//
//  Heap.cpp
//  SeamCarver
//
//  Created by Guo Chen on 6/25/17.
//  Copyright © 2017 Guo Chen. All rights reserved.
//

#include "Heap.hpp"

Heap::Heap(int size): size(2), elem(vector<int>(size + 2)) {}

int Heap::adjustSibling(int index) {
	if ((index | 1) >= size)
		return index;
	int sibling;
	if (index & 1)
	{
		sibling = index - 1;
		if (elem[index] >= elem[sibling])
			return index;
	}
	else
	{
		sibling = index + 1;
		if (elem[index] <= elem[sibling])
			return index;
	}
	int temp = elem[index];
	elem[index] = elem[sibling];
	elem[sibling] = temp;
	return sibling;
}

int Heap::adjustUncle(int index) {
	if (index < 4)
		return index;
	int grandpa = index >> 2;
	int left_uncle = grandpa << 1;
	int right_uncle = left_uncle | 1;
	if (elem[left_uncle] > elem[index])
	{
		int temp = elem[index];
		elem[index] = elem[left_uncle];
		elem[left_uncle] = temp;
		return left_uncle;
	}
	if (elem[right_uncle] < elem[index])
	{
		int temp = elem[index];
		elem[index] = elem[right_uncle];
		elem[right_uncle] = temp;
		return right_uncle;
	}
	return index;
}

int Heap::adjustChild(int index) {
	int child, nephew, temp;
	if (index & 1)
	{
		nephew = (index - 1) << 1 | 1;
		if (nephew >= size)
			return index;
		child = index << 1 | 1;
		temp = nephew;
		if (child < size && elem[nephew] < elem[child])
			temp = child;
		if (elem[temp] <= elem[index])
			return index;
	}
	else
	{
		child = index << 1;
		if (child >= size)
			return index;
		nephew = (index + 1) << 1;
		temp = child;
		if (nephew < size && elem[nephew] < elem[child])
			temp = nephew;
		if (elem[temp] >= elem[index])
			return index;
	}
	int temp1 = elem[index];
	elem[index] = elem[temp];
	elem[temp] = temp1;
	return temp;
}

int Heap::deleteElem(int index) {
	if (size <= 2)
		return 0;
	if (size == 3 || (size == 4 && index == 3))
		return elem[--size];
	int result = elem[index];
	elem[index] = elem[--size];
	int temp;
	do
	{
		temp = index;
		adjustSibling(temp);
		index = adjustChild(temp);
	} while (index != temp);
	return result;
}

void Heap::insert(int value)
{
	int index = size++;
	int temp = index;
	elem[index] = value;
	do
	{
		index = adjustSibling(temp);
		temp = adjustUncle(index);
	} while (index != temp);
}

int Heap::max() const {
	return elem[3];
}

int Heap::min() const {
	return elem[2];
}

int Heap::extractMax()
{
	return deleteElem(3);
}

int Heap::extractMin()
{
	return deleteElem(2);
}
