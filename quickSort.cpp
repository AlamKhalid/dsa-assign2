#pragma once

#include"swap.cpp"

template <class X>
inline int partition(X arr[], int i, int j) {

	int key = i;
	while (i < j) {
		while (arr[i] <= arr[key])
			i++;
		while (arr[j] > arr[key])
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap<X>(&arr[j], &arr[key]);
	return j;
}

template <class X>
inline void quickSort(X arr[], int low, int high) {

	if (low < high) {

		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}