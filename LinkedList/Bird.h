//Birds are sorted by their id numbers 
#ifndef BIRD_H
#define BIRD_H
//#pragma once
#include <string> 
#include <iostream>
using namespace std;
class Bird
{
	friend istream& operator>>(istream &inStream, Bird &bi);
	friend ostream& operator<<(ostream &outStream, const Bird &bi);
public:
	Bird();
	Bird(string n, int i);
	void setBird(string n, int i);
	
	string getName();
	int getID();

	bool operator>(const Bird &bi) const;
	bool operator<(const Bird &bi) const;
	bool operator>=(const Bird &bi)const;
	bool operator<=(const Bird &bi)const;
	bool operator==(const Bird &bi) const;
	bool operator!=(const Bird &bi) const;
	Bird operator=(const Bird &bi);


	~Bird();

private:
	int idNumber;
	string name;

};
#endif
