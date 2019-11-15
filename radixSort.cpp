#include <iostream>
#include <list>
#include <time.h>
#include <string>
#define radix 10 // base of decimal number
#define Size 100 // max size

using namespace std;

// for long and float
// for long max = 3 and for float max = 6 in radixSort function as 3rd argument
template <class X>
inline void radixSort(X *arr, int n, int max) // n is size and max is max num of digits in array (1-100 means max is 3 i.e 100)
{
	int i, j, m, p = 1, index, temp, count = 0;
	list<X> list[radix];

	for (i = 0; i < max; i++)
	{
		m = pow(radix, i + 1);
		p = pow(radix, i);

		for (j = 0; j < n; j++)
		{
			temp = (int)arr[j] % m;
			index = temp / p;      //find index for list array
			list[index].push_back(arr[j]);
		}

		count = 0;

		for (j = 0; j < 10; j++)
		{
			//delete from linked lists and store to array
			while (!list[j].empty())
			{
				arr[count] = *(list[j].begin());
				list[j].erase(list[j].begin());
				count++;
			}
		}
	}
}