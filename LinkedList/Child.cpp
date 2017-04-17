//#include "stdafx.h"
#include "Child.h"
#include <string> 
#include <iostream>
using namespace std;

Child::Child()
{
	nice = true;
}

Child::Child(string fName, string lName, int a)
{
	setName(fName, lName);
	setAge(a);
	nice = true;
}
//Set child's name, age, and if they are nice
void Child::setName(const string fName, const string lName)
{
	firstName = fName;
	lastName = lName;

}
void Child::setAge(int a)
{
	age = a;
}
void Child::setNice(bool n)
{
	nice = n;
}

//Get the child's name, age, and nice
string Child::getName()
{
	return firstName + lastName;
}
int Child::getAge()
{
	return age;
}
bool Child::getNice()
{
	return nice;
}

//Overload operators
bool Child::operator>(const Child &chi) const
{
	if (lastName > chi.lastName)
	{
		return true;
	}
	else if (lastName == chi.lastName && firstName > chi.firstName)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Child::operator<(const Child & chi) const
{
	if (lastName < chi.lastName)
	{
		return true;
	}
	else if (lastName == chi.lastName && firstName < chi.firstName)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Child::operator>=(const Child & chi)const
{
	if (lastName == chi.lastName && firstName == chi.firstName && age == chi.age)
	{
		return true;
	}
	else if (lastName > chi.lastName)
	{
		return true;
	}
	else if (lastName == chi.lastName && firstName > chi.firstName)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool Child::operator<=(const Child & chi)const
{
	if (lastName == chi.lastName && firstName == chi.firstName && age == chi.age)
	{
		return true;
	}
	else if(lastName < chi.lastName)
	{
		return true;
	}
	else if (lastName == chi.lastName && firstName < chi.firstName)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Child::operator==(const Child & chi) const
{
	if (lastName == chi.lastName && firstName == chi.firstName && age == chi.age && nice == chi.nice)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Child::operator!=(const Child & chi) const
{
	if (lastName != chi.lastName && firstName != chi.firstName && age != chi.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Assignment Operator
Child Child::operator=(const Child & chi)
{
	firstName = chi.firstName;
	lastName = chi.lastName;
	age = chi.age;
	nice = chi.nice;
	return *this;
}

//Overloads input and output for Child
istream& operator>>(istream &inStream, Child &chi)
{
	inStream >> chi.firstName >> chi.lastName >> chi.age;
	return inStream;
}
ostream&  operator<<(ostream &outStream, const Child &chi)
{
	Child temp = chi; 
	outStream << temp.getName() << temp.getAge() << temp.getNice();
	return outStream;
}

Child::~Child()
{
}
