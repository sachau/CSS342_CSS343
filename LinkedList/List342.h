#ifndef LIST342_H
#define LIST342_H
//Creates a Linked List that is sorted accoring to the object
//Can read in a file that will also create a list but user must
//input correct file.
//#pragma once
#include "Child.h"
#include "Bird.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template <class ItemType>
class List342
{

	friend ostream&  operator<<(ostream &outStream, const List342<ItemType> &list)
	{
		Node *pNode;
		pNode = list.head;
		while (pNode != NULL)
		{
			ItemType *temp = pNode->data;
			outStream << (*temp);
			pNode = pNode->next;
		}
		return outStream;
	}


public:
	List342();
	List342(List342 &copy);
	bool BuildList(string fileName);
	bool Insert(ItemType *item);
	bool Remove(ItemType target, ItemType &result);
	bool Peek(ItemType target, ItemType &result);
	bool isEmpty();
	void ClearList();
	bool Merge(List342 &list1, List342 &list2);
	void operator=(List342<ItemType> &source);
	bool operator==(List342<ItemType> &source);
	bool operator!=(List342<ItemType> &source);
	List342<ItemType>& operator+(List342<ItemType> &source);
	void operator+=(List342<ItemType> &source);

	~List342();
private:

	struct Node
	{
		ItemType *data;
		Node *next;
	};

	Node *head;
	bool readInFile;

};

template <class ItemType>
List342<ItemType>::List342()
{
	head = NULL;
	readInFile = false;
}

template <class ItemType>
List342<ItemType>::List342(List342 &source)
{

	this->head = NULL;
	Node *sNode, *dNode, *insNode;
	dNode = new Node;
	ItemType *o = new ItemType;
	o = (source.head)->data;
	dNode->next = NULL;
	dNode->data = o;
	this->head = dNode;
	sNode = (source.head)->next;

	while (sNode != NULL)
	{
		insNode = new Node;
		ItemType *object = new ItemType;
		object = sNode->data;
		insNode->data = object;
		insNode->next = NULL;
		dNode->next = insNode;
		dNode = dNode->next;
		sNode = sNode->next;
	}
	delete sNode;
	readInFile = false;

}

//Builds a sorted list when a file in inported
template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
	ifstream InFile;
	InFile.open(fileName.c_str());
	ItemType *object;

	if (InFile.is_open())
	{
		while (!InFile.eof())
		{
			object = new ItemType;
			InFile >> (*object);
			Insert((object));
		}
		InFile.close();
		readInFile = true;

		return true;
	}
	else
	{
		cout << "Cannout open file";
		return false;
	}
}

//Inserts an item in the list and sorts it
template <class ItemType>
bool List342<ItemType>::Insert(ItemType *item)
{

	Node *insNode = new Node;
	insNode->data = item;
	if (head == NULL)
	{
		head = insNode;
		insNode->next = NULL;
		return true;
	}
	if (*item <= *head->data)
	{
		insNode->next = head;
		head = insNode;

		return true;
	}
	else
	{
		Node *pNode = head;

		while ((pNode->next != NULL) && (*((pNode->next)->data) < *item))
		{
			pNode = pNode->next;
		}

		insNode->next = pNode->next;
		pNode->next = insNode;
		return true;
	}
	return false;
}

//Removes the targeted item
template <class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType &result)
{
	Node *pTemp, *pNode;
	if (head == NULL)
	{
		return false;
	}
	if (*head->data == target)
	{
		result = target;
		pTemp = head;
		head = head->next;
		delete pTemp;
		return true;
	}
	pNode = head;
	while (pNode->next != NULL)
	{
		if (*pNode->next->data == target)
		{
			result = target;
			pTemp = pNode->next;
			pNode->next = pNode->next->next;
			delete pTemp;
			return true;
		}
		pNode = pNode->next;

	}
	return false;
}

//Sees if the targeted item is in the list
template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType &result)
{
	Node *pTemp, *pNode;
	if (head == NULL)
	{
		return false;
	}
	if (*head->data == target)
	{
		result = target;
		return true;
	}
	pNode = head;
	while (pNode->next != NULL)
	{
		if (*pNode->next->data == target)
		{
			result = target;
			return true;
		}
		pNode = pNode->next;

	}
	return false;
}

//Checks to see if list is empty
template <class ItemType>
bool List342<ItemType>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}

}

//Deletes clears the list
template <class ItemType>
void List342<ItemType>::ClearList()
{
	Node *pTemp;
	while (head != NULL)
	{
		pTemp = head;
		head = head->next;
		if (readInFile == true)
		{
			delete pTemp->data;
		}
		delete pTemp;
	}


}

//Combines two list into a new one. Unless the third list is the "new" list, the
//two list that were combined together will be cleared
template <class ItemType>
bool List342<ItemType>::Merge(List342 &list1, List342 &list2)
{
	if (list1 == list2)
	{
		return false;
	}

	Node *firstPNode, *secondPNode;
	if (list1.head == NULL && list2.head == NULL)
	{
		return false;
	}
	firstPNode = (list1.head);
	secondPNode = (list2.head);
	while (firstPNode != NULL)
	{
		Insert(firstPNode->data);
		firstPNode = firstPNode->next;
	}

	while (secondPNode != NULL)
	{
		Insert(secondPNode->data);
		secondPNode = secondPNode->next;
	}
	list1.ClearList();
	list2.ClearList();
	return true;
}

//Assignment - Exisiting object is assigned new values
template <class ItemType>
void List342<ItemType>::operator=(List342<ItemType> &source)
{
	Node *sNode, *dNode, *insNode;
	if (this == &source)
	{
		return;
	}
	this->ClearList();

	dNode = new Node;
	ItemType *o = new ItemType;
	o = (source.head)->data;
	dNode->next = NULL;
	dNode->data = o;
	this->head = dNode;
	sNode = (source.head)->next;

	while (sNode != NULL)
	{
		insNode = new Node;
		ItemType *object = new ItemType;
		object = sNode->data;
		insNode->data = object;
		insNode->next = NULL;
		dNode->next = insNode;
		dNode = dNode->next;
		sNode = sNode->next;
	}
	delete sNode;
	delete dNode;
}

//Overloads operators
template <class ItemType>
bool List342<ItemType>::operator==(List342<ItemType> &source)
{
	Node *firstPNode, *secondPNode;
	if (head == NULL && source.head == NULL)
	{
		return true;
	}
	firstPNode = head;
	secondPNode = (source.head);
	while (firstPNode != NULL)
	{
		if (*firstPNode->data != *secondPNode->data)
		{
			return false;
		}
		firstPNode = firstPNode->next;
		secondPNode = secondPNode->next;
	}
	return true;
}
template <class ItemType>
bool List342<ItemType>::operator!=(List342<ItemType> &source)
{
	Node *firstNode, *firstPNode, *secondNode, *secondPNode;
	if (head == NULL && source.head == NULL)
	{
		return false;
	}
	firstPNode = head;
	secondPNode = (source.head);
	while (firstPNode != NULL)
	{
		if (*firstPNode->data != *secondPNode->data)
		{
			return true;
		}
		firstPNode = firstPNode->next;
		secondPNode = secondPNode->next;
	}
	return false;
}
template <class ItemType>
List342<ItemType>& List342<ItemType>::operator+(List342<ItemType> &source)
{
	Node *firstPNode;
	if (source.head == NULL)
	{
		return *this;
	}
	firstPNode = (source.head);
	while (firstPNode != NULL)
	{
		Insert(firstPNode->data);
		firstPNode = firstPNode->next;
	}
	return *this;
}
template <class ItemType>
void List342<ItemType>::operator+=(List342<ItemType> &source)
{
	Node *firstPNode;
	if (source.head == NULL)
	{
		return;
	}
	firstPNode = (source.head);
	while (firstPNode != NULL)
	{
		Insert(firstPNode->data);
		firstPNode = firstPNode->next;
	}

}

template <class ItemType>
List342<ItemType>::~List342()
{
	this->ClearList();
}

#endif
