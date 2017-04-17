
//#include "stdafx.h"
#include "Robot.h"

Robot::Robot()
{
	
}

Robot::Robot(Points beginPoint)
{
	locationOfRobotX = beginPoint.x;
	locationOfRobotY = beginPoint.y;
	locationOfTreasureX = 0;
	locationOfTreasureY = 0;
}

Robot::Robot(int x, int y, int x2, int y2)
{
	locationOfRobotX = x;
	locationOfRobotY = y;
	locationOfTreasureX = x2;
	locationOfTreasureY = y2;
	actualSize = 0;
}

//Moves the location of robot depending on input from user
void Robot::moveX(char x)
{
	if (x == 'e')
	{
		locationOfRobotX += 1;
	}
	if (x == 'w')
	{
		locationOfRobotX -= 1;
	}
}
void Robot::moveY(char y)
{
	if (y == 'n')
	{
		locationOfRobotY += 1;
	}
	if (y == 's')
	{
		locationOfRobotY -= 1;
	}
}

//Finds the number of shortes path and use it to find combinations
void Robot::LocateTreasure()
{
	if (locationOfRobotX == locationOfTreasureX && locationOfRobotY == locationOfTreasureY){
		shortestNumOfPaths = 0;
		cout << "Robot is at Treasure";
	}
	else
	{
		//Find the shortest number of paths
		Points difference;
		difference.x = locationOfTreasureX - locationOfRobotX;
		difference.y = locationOfTreasureY - locationOfRobotY;
		int tempX = difference.x;
		int tempY = difference.y;
		int n = tempX + tempY;
		int r = tempX;

		if (n < 0)
		{
			n *= -1;
		}
		if (r < 0)
		{
			r *= -1;
		}

		int temp = Factoring(r) * Factoring(n - r);

		n = Factoring(n);

		if (temp == 0)
		{
			shortestNumOfPaths = 1;
		}
		else
		{
			shortestNumOfPaths = n / temp;
		}

		//Finds the first path
		Path(difference, direction);
	
		//Pust original path into a list
		listOfCombination[0] = direction;
		actualSize++;
		amountOfSteps = direction.length();

		//Uses the first path to find combinations
		combinationOfDirection(direction, 1, shortestNumOfPaths -1);
	}

	//Print out the list
	for (int i = 0; i < actualSize; i++)
	{
		cout << listOfCombination[i] << endl;
	}

	//print out shortest amount of paths
	cout << "Number of Paths: " << actualSize;
}

//Finds the inital path of the Robot to the Treasure
string Robot::Path(Points difference, string &ans)
{
	
	if (difference.x == 0 && difference.y == 0)
	{		
		return direction;
	}

	else if (difference.y > 0)
	{
		difference.y -= 1;
		direction += 'N';
		return Path(difference,direction);
	}
	else if (difference.y < 0)
	{
		difference.y += 1;
		direction += 'S';
		return Path(difference,direction);
	}

	else if (difference.x > 0)
	{
		difference.x -= 1;
		direction += 'E';
		return Path(difference,direction);
	}
	else if (difference.x < 0)
	{
		difference.x += 1;
		direction += 'W';
		return  Path(difference,direction);		
	}	
}

//Finds the combinations using recursion 
string Robot::combinationOfDirection(string &ans, int num, int com)
{
	int tempNum = num;
	if (com == 0)
	{
		return "";
	}
	
		if (direction[tempNum] == direction[tempNum - 1])
		{
			if (tempNum > amountOfSteps - 2)
			{
				return combinationOfDirection(ans, 1, com);
			}
			else
			{
				return combinationOfDirection(ans, tempNum + 1, com);
			}		
		}
		else
		{
			char temp;
			temp = ans[tempNum];
			ans[tempNum] = ans[tempNum - 1];
			ans[tempNum - 1] = temp;
			
			if (CheckSimilarPaths(ans) == false)
			{
				listOfCombination[actualSize] = ans;
				actualSize++;
				com++;
			}
			if (tempNum > amountOfSteps - 2)
			{
				return combinationOfDirection(ans, 1, com - 1);		
			}
			else
			{
				return combinationOfDirection(ans, tempNum + 1, com - 1);
			}
	}
}

//Check to see if path is already listed
bool Robot::CheckSimilarPaths(string path)
{
	bool temp = false;
	for (int i = 0; i < actualSize; i++)
	{
		if (path == listOfCombination[i])
		{
			return true;
		}		
	}

	return temp;
}

ostream&  operator<<(ostream &outStream, const Robot &rob)
{
	outStream << "Robot: (" << rob.locationOfRobotX << "," << rob.locationOfRobotY << ") "
		<< "Treasure: (" << rob.locationOfTreasureX << "," << rob.locationOfTreasureY << ")";
	return outStream;
}

istream& operator>>(istream &inStream, Robot &rob)
{
	int x1, y1, x2, y2;

	inStream >> rob.locationOfRobotX >> rob.locationOfRobotY 
		>> rob.locationOfTreasureX >> rob.locationOfTreasureY;

	return inStream;
}


//Function to factor a number
int Robot::Factoring(int i)
{
	if (i == 0)
	{
		return 0;
	}
	if (i == 1){
		return 1;
	}
	else
	{
		return(i * Factoring(i - 1));
	}

}


Robot::~Robot()
{
}
