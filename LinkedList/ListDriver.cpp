// ListDriver.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include "Child.h"
#include "Bird.h"
#include "List342.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	
	int x;
	string fName;
	ifstream InFile;
	List342<Bird> bir;
	List342<Child> chi;
	Bird b1("Jay", 7);
	Bird b2("Jay", 8);
	Child c1("ann","hanlin", 7), c2("pradnya","dhala", 8);
	Child c3("bill","vollmann", 13), c4("cesar","ruiz", 6);
	Child c5("piqi","tang", 7), c6("pete","rose", 13), c7("hank",	"aaron", 3);
	Child c8("madison", "fife", 7), c9("miles", "davis", 65);
	Child c10("john", "zorn", 4), c11;
	List342<Child> class1, class2, soccer, chess, class3;
	List342<Bird> list1;
	int a = 1, b = -1, c = 13;
	
	list1.Insert(&b2);
	list1.Insert(&b1);
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	chess.Insert(&c10);
	chess.Insert(&c7);
	
	
	cout << "This is class1: " << class1 << endl;
	cout << "This is class2: " << class2 << endl;
	
	if (class1 != class2)
	{
		cout << "class1 is different than class 2" << endl;
	}
	
	
	if(class1.Peek(c2, c11))
	{
		cout << c11 << " is in class1" << endl;
	}

	if (class1.Remove(c1, c11))
	{
		class2.Insert(&c11);
		cout << c1 << " has been removed from class1 and placed in class2" << endl;
	}
	cout << "This is class2: "  << class2 << endl;
	cout << "This is the chess club: " << chess << endl;
	
	chess.ClearList();
	chess.Insert(&c9);
	cout << "this is now the chess club: " << chess << endl;
	List342<Child> soccer2 = soccer;
	// Note that the Merge function is probably not as intuitive as we like
	// but the fact the lists allow duplicates confuse the situation.
	chess.Merge(soccer, class2);
	cout <<"this is now the chess club: "<< chess << endl;
	if(soccer.isEmpty())
	{
		cout << "The soccer club is now empty" << endl;
	}
	cout << "This is the soccer2 club: " << soccer2 << endl;
	

	List342<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout << "These are the numbers: " << numbers << endl;

	
	
	cout << "Input a Bird List file name:";
	cin >> fName;
	cout << bir.BuildList(fName);
	cout << bir << endl;
	cout << "Input a Child List file name:";
	cin >> fName;
	cout << chi.BuildList(fName);
	cout << chi;
	
	cin >> x;
	return 0;
}

