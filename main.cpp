#include<iostream>
#include"mergeSort.cpp"
#include"quickSort.cpp"
#include"radixSort.cpp"
#include"selectionSort.cpp"

using namespace std;

int main() {

	long arr[] = {4,7,1,10,6,8,2};
	string arr1[] = {"alam","ali","umar","haseeb"};

	mergeSort(arr, 0, 6);
	for (int i = 0;i < 7;i++)
		cout << arr[i]<<" ";
}

