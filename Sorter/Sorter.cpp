// Sorter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "SortImpls.h"
using namespace std;

void PrinArray(const vector <int> & array, string name);
void InitArray( vector<int> & array, int randMax);

int main(int argc,char *argv[])
{
	 
	if(argc != 3)
	{
		cout <<
			"Usage: Sorter SORT_TYPE ARRAY_SIZE";
		return-1;
	}
	string sort_name = string(argv[1]);
	int size = atoi(argv [2]);
	if (size <= 0)
	{
		cerr <<	"array size must be positive" << endl;
		return -1;
	}
	srand(1);
	vector<int> items(size);
	InitArray(items, size);
	cout << "Sort employed: " << sort_name << endl;
	cout << "initial:" << endl;
	PrinArray(items,string("items"));

	int begin = GetTickCount();
	// Place logic to determine and call function of interest here.
	// Do not call all of them

	if (sort_name == "QuickSort")
	{
		QuickSort(items, 0, size - 1);
	}
	
	if (sort_name == "IterativeMergeSort")
	{
		IterativeMergeSort(items, 0, size - 1);
	}

	if (sort_name == "MergeSort")
	{
		MergeSort(items, 0, size - 1);
	}

	if (sort_name == "BubbleSort")
	{
		BubbleSort(items, 0, size - 1);
	}

	if (sort_name == "InsertSort")
	{
		InsertSort(items, 0, size - 1);
	}
	
	int end = GetTickCount();
	
	cout << "sorted:" << endl;
	PrinArray(items, string("item"));
	int elapsed_secs = end - begin;
	cout << "Time (ms): " << elapsed_secs << endl;
	
	return 0;
}

// array initialization with random numbers
void InitArray(vector<int> & array,int randMax)
{
	int size = array.size();
	for(int i = 0; i < size;)
	{
		int tmp = (randMax == -1) ? rand() : rand() % randMax;
		bool hit = false;
		for(int j = 0; j < i; j++)
		{
			if(array[j] == tmp)
			{
				hit = true;
				break;
			}
		}
		if(hit)
		{
			continue;
		}
		array[i] = tmp;
		i++;
	}
	
}

// Function to Print Array
void PrinArray(const vector<int> & array, string name)
{
	int size = array.size();
	for(int i = 0; i < size; i++)
		cout << name << "[" << i << "] = " << array [i] << endl;
}

