#pragma once

inline void swap(int *p, int *q) {

	int temp = *p;
	*p = *q;
	*q = temp;
}