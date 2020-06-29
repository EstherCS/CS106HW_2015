// Uses "selection sort" algorithm to sort the sequence data[] in ascending order.
#include <iostream>
#include <iomanip>
using namespace::std;
#include <ctime>

// recursively Print all elements in the array intArray
void recursivePrintArray(const int intArray[], int last);

// recursive function to sort the array data using the Selection sort algorithm
void recursiveSelectionSort(int data[], int last);

// find largest element and put it in last position
void putMaxInLast(int data[], int last);

// function main begins program execution
int main()
{
	//   srand( static_cast< int >( time(0) ) );

	unsigned int seed;
	cout << "Enter seed: ";
	cin >> seed;
	cout << endl;
	srand(seed);

	int number;
	cout << "Enter the number of integers to be sorted: ";
	cin >> number;

	int *data = new int[number];

	// fill array with random numbers between 1-MAXRANGE
	for (int i = 0; i < number; i++)
		data[i] = 1 + rand() % 100;

	cout << "\nUnsorted array is:\n";
	recursivePrintArray(data, number - 1); // display unsorted array

	recursiveSelectionSort(data, number - 1);

	cout << "\n\nSorted array is:\n";
	recursivePrintArray(data, number - 1); // display sorted array
	cout << endl << endl;

	delete[] data;

	system("pause");
} // end function main

void recursivePrintArray(const int intArray[], int last)
{
	if (last >= 0)
	{
		cout << intArray[last] << "  ";
		recursivePrintArray(intArray, last - 1);
	}
}

void recursiveSelectionSort(int data[], int last)
{
	if (last >= 0)
	{
		putMaxInLast(data, last);
		recursiveSelectionSort(data, last - 1);
	}
}

void putMaxInLast(int data[], int last)
{
	int j;

	for (int i = 0; i < last; i++)
	{
		int Max = i;
		for (j = i + 1; j < last + 1; j++)
		{
			if (data[j] > data[Max])
				Max = j;
		}
		int temp = data[i];
		data[i] = data[Max];
		data[Max] = temp;
	}
}
