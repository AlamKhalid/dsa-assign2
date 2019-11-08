#pragma once

#include"swap.cpp"

int partition(int arr[], int i, int j) {

	int key = i;
	while (i < j) {
		while (arr[i] <= arr[key])
			i++;
		while (arr[j] > arr[key])
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[j], &arr[key]);
	return j;
}

void quickSort(int arr[], int low, int high) {

	if (low < high) {

		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}