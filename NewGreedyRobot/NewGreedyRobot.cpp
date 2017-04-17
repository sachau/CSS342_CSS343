// NewGreedyRobot.cpp : Defines the entry point for the console application.
//This is the main driver of the Robot

//#include "stdafx.h"
#include "Robot.h"


int main()
{
	char userInput;
	bool end = false;
	
	Robot r1(0,0,0,0);
	
	cout << "Input four numbers to indicate Robot's location and Treasure's Location: " << endl;	
	cin >> r1;
	cout << r1;

	cout << "If you want to move robot, input n,e,w,s." << endl;
	cout << "If you want to list all the paths, input r" << endl;
	cout << "If you want to exit, input z" << endl;
	while (end == false)
	{
		cin >> userInput;
		if (userInput == 'n')
		{
			r1.moveY('n');
			cout << r1;
		}
		else if (userInput == 'e')
		{
			r1.moveX('e');
			cout << r1;
		}
		else if (userInput == 's')
		{
			r1.moveY('s');
			cout << r1;
		}
		else if (userInput == 'w')
		{
			r1.moveX('w');
			cout << r1;
		}
		else if (userInput == 'r')
		{
			r1.LocateTreasure();
			
		}
		else if (userInput = 'z')
		{
			end = true;
		}

	}

	return 0;
}

