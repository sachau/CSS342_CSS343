
// This program will assume that there is never more than 50 combinations, but if there is a large amount of combinations, it will only 
// print out the first couple ones. The program will take in two points, one for the robot and one for the treasure. 
// Given the two points, the program will then decide which directions the robot needs to take. After finding out the direction it will then figure out the
// shortest number of paths the robot can take. When the directions and the number of shortest paths, it wll mix the direction to find different combinations. 
#ifndef Robot_H
#define Robot_h
#pragma once
#include <string>
#include <iostream>
#include <string>
using namespace std;

struct Points
{
	int x;
	int y;
};

class Robot
{
	friend istream& operator>>(istream &inStream, Robot &rob);
	friend ostream& operator<<(ostream &outStream, const Robot &rob);
	
public:

	Robot();
	Robot(Points beginPoint);
	Robot(int x, int y, int x2, int y2);

	
	void moveX(char x);
	void moveY(char y);
	void LocateTreasure( );
	string Path(Points difference, string &ans);
	string combinationOfDirection(string &ans, int num, int com);
	int Factoring(int i);
	bool CheckSimilarPaths(string path);
	
	~Robot();

private:
	int locationOfRobotX;
	int locationOfRobotY;
	int locationOfTreasureX;
	int locationOfTreasureY;
	int shortestNumOfPaths;
	string direction;
	int amountOfSteps;
	string listOfCombination[50]; 
	int actualSize;
	
};

#endif