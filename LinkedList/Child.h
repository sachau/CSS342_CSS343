//The child's age will not be used to sort. All children are set to being nice. 
#ifndef CHILD_H
#define CHILD_H
//#pragma once
#include <string>
using namespace std;

class Child
{
	friend istream& operator>>(istream &inStream, Child &chi);
	friend ostream& operator<<(ostream &outStream, const Child &chi);
public:
	Child();
	Child(string fName, string lName, int a);

	void setName(const string fName, const string lName);
	void setAge(int a);
	void setNice(bool n);

	string getName();
	int getAge();
	bool getNice();

	bool operator>(const Child & chi) const;
	bool operator<(const Child & chi) const;
	bool operator>=(const Child & chi)const;
	bool operator<=(const Child & chi)const;
	bool operator==(const Child & chi) const;
	bool operator!=(const Child & chi) const;
	Child operator=(const Child & chi);

	~Child();

private:
	string firstName;
	string lastName;
	int age;
	bool nice;
};
#endif



