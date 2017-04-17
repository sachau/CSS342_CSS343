//#include "stdafx.h"
#include "Bird.h"
#include <iostream>
using namespace std;

Bird::Bird()
{
}

Bird::Bird(string n, int i)
{
	setBird(n, i);
}

//Sets bird's name and id number
void Bird::setBird(string n, int i)
{
	name = n;
	idNumber = i;
}

//Get bird;s name and id number
string Bird::getName()
{
	return name;
}
int Bird::getID()
{
	return idNumber;
}

//Overloads the operators to sort
bool Bird::operator>(const Bird &bi) const
{
	if (idNumber > bi.idNumber)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
bool Bird::operator<(const Bird &bi) const
{
	if (idNumber < bi.idNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Bird::operator>=(const Bird &bi)const{
	if (idNumber > bi.idNumber || idNumber == bi.idNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Bird::operator<=(const Bird &bi)const
{
	if (idNumber < bi.idNumber || idNumber == bi.idNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Bird::operator==(const Bird &bi) const
{
	if (idNumber == bi.idNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Bird::operator!=(const Bird &bi) const
{
	if (idNumber != bi.idNumber)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//overload assignment 
Bird Bird::operator=(const Bird &bi)
{
	return *this;
}

//Overlaods Input and OutPut for Birds
istream& operator>>(istream &inStream, Bird &bi)
{
	inStream >> bi.name >> bi.idNumber;
	return inStream;
}
ostream&  operator<<(ostream &outStream, const Bird &bi)
{
	Bird temp = bi;
	outStream << temp.getName() << temp.getID();
	return outStream;
}

Bird::~Bird()
{
}
