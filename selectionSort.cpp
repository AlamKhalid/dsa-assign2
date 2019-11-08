#pragma once

#include"swap.cpp"

void selectionSort(int arr[], int n) {

	for (int i = 0; i < n - 1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[least])
				least = j;
		}
		swap(&arr[i], &arr[least]);
	}
}