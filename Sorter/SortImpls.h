//This contains the sorts used by the diver(sorter). MergeSort and InsertSort was created 
//using examples in Data Abstraction & Problem Solving with C++ by Frank M. Carrano.
//Bottom up MergeSort was created with help from youtube video "6 2 Bottom up MergeSort 320"
//uploaded by Osiris Salazar

#pragma once
#include <vector>
using namespace std;
class SortImpls
{
public:
	SortImpls();
	~SortImpls();
};

//Helper function that will swap two numbers
void Swap(vector<int> &items, int num1, int num2)
{
	int temp = items[num1];//creates a temporary spot

	//switches the two numbers
	items[num1] = items[num2];
	items[num2] = temp;
}

//BubbleSort -- Goes through every number and swaps if they are not in order, 
//then returns to the beginning and swaps again
void BubbleSort(vector<int> &items, int start, int size)
{
	//Outer loop to sort the whole list
	for (int i = start; i < size; i++)
	{
		//Inner loop that sorts up to the last sorted item
		for (int n = 0; n < size - i; n++)
		{
			int next = n + 1;

			//Swap the items if one if bigger than the other
			if (items[n] > items[next])
			{
				Swap(items, n, next);
			}
		}
	}
}

//InsertionSort -- Takes a number and see if the numbers before it 
//is greater. If it is greater, shift number up in the list and 
//continue until it finds a number that is less than. Insert number 
//before.
void InsertSort(vector<int> &items, int start, int size)
{
	for (int i = start + 1; i < size + 1; i++)
	{
		int temp = items[i];
		int n = i;

		//If number before is greater than the temp, move all items right
		while((n > 0) && (items[n - 1] > temp))
		{
			items[n] = items[n - 1];
			n--;
		}

		//Place temp into correct place
		items[n] = temp;
		
	}
}

//Helper Function that is used by both Merges
void MergeHelper(vector<int> &items, int start, int mid, int end)
{
	//Creates a temp vector
	vector<int> tempInts(end + 1);

	int start1 = start;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = end;

	int index = start1;
	
	while ((start1 <= end1) && (start2 <= end2) && (index <= end))
	{
		if (items[start1] < items[start2])
		{
			tempInts[index] = items[start1];
			start1++;
		}
		else
		{
			tempInts[index] = items[start2];
			start2++;
		}
		index++;
	}
	
	while ((start1 <= end1) && (index <= end) && (start1 <= end))
	{
		tempInts[index] = items[start1];
		start1++;
		index++;
	}
	
	while ((start2 <= end2) && (start2 <= end) && (index <= end))
	{
		tempInts[index] = items[start2];
		start2++;
		index++;
	}
	
	//Copies temp vector back to the original
	for (index = start; index <= end; index++)
	{
		items[index] = tempInts[index];
	}

}

//Recursive merge sort that will break down the vector into separate vectors 
//then merges the two 
void MergeSort(vector<int> &items, int start, int size)
{
	if (start < size)
	{
		int mid = (start + size) / 2;
		MergeSort(items, start, mid);
		MergeSort(items, mid + 1 , size);
		MergeHelper(items, start, mid, size);
	}
	
}

//Iterative MergeSort also known as the Bottom up merge sort that 
//sorts two items at a time, then merges the two, 
//then merges four and so on.
void IterativeMergeSort(vector<int> &items, int start, int end)
{
	int size = end + 1;

	for (int i = 1; i < size; i = 2 * i)
	{
		for (int n = start; n < size - i; n = n + (2 * i))
		{
			MergeHelper(items, n, n + i -1, min(n + (2 * i) -1, end));
		}
	}
}

//Helper Function used to find pivot point
int selectPivot(int low, int high)
{
	int num = (high - low);
	if ((num % 2) != 0)
	{
		return (num / 2) + low + 1;
	}
	else
		return (num / 2) + low;

}

//Helps QuickSort
int sortHelp(vector<int> &items, int first, int last, int pivot){
	int temp = items[pivot];

	while (first != last)
	{
		if (items[first] >= temp && items[last] <= temp){
			Swap(items, first, last);
			
		}
		if (items[first] < temp){
			first += 1;
		}

		if (items[last] > temp){
			last -= 1;
		}
	}
	
	return first;

}

//QuickSort which will use the pivot point to sort vector into items that
//are greater than the pivot and items that are less than. Repeats until
//list is sorted.
void QuickSort(vector<int> &items, int first, int last){
	int index = selectPivot(first, last);
	
	if (first < last)
	{	
		index = sortHelp(items, first, last, index);
		
		QuickSort(items, first, index - 1);//sorts the left half of list
		QuickSort(items, index + 1, last);//sorts right half of list
	}

}

