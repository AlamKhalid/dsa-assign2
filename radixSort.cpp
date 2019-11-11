#pragma once

// A utility function to get maximum value in arr[] 
template <class X>
inline X getMax(X arr[], int n)
{
	X mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
template <class X>
inline void countSort(X arr[], int n, int exp)
{
	X *output = new X[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		arr[i] = output[i];

	delete[] output;
}

// The main function to that sorts arr[] of size n using  
// Radix Sort 
template <class X>
inline void radixSort(X arr[], int n)
{
	// Find the maximum number to know number of digits 
	X m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

/*
#include <iostream>
#include <string>

using std::string;

size_t getMax(string arr[], int n)
{
size_t max = arr[0].size();
for (int i = 1; i < n; i++)
{
if (arr[i].size()>max)
max = arr[i].size();
}
return max;
}

void countSort(string a[], int size, size_t k)
{
string *b = NULL; int *c = NULL;
b = new string[size];
c = new int[257];

for (int i = 0; i <257; i++)
c[i] = 0;
for (int j = 0; j <size; j++)
c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;

for (int f = 1; f <257; f++)
c[f] += c[f - 1];

for (int r = size - 1; r >= 0; r--)
{
b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
}

for (int l = 0; l < size; l++)
a[l] = b[l];

// avold memory leak
delete[] b;
delete[] c;
}


void radixSort(string b[], int r)
{
size_t max = getMax(b, r);
for (size_t digit = max; digit > 0; digit--)
countSort(b, r, digit - 1);
}

int main(void)
{
string data[] = {"Zeerak", "Danial", "Haseeb", "Alam" ,"Uper-Wala-Sab-Lora-Han"};
puts("before sorting:");
for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
printf("    %s\n", data[i].c_str());
radixSort(data, (int)(sizeof(data) / sizeof(data[0])));
puts("after sorting:");
for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
printf("    %s\n", data[i].c_str());
return 0;
}
*/ // this is chappa from internet 50%