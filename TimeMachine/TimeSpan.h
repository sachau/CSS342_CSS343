#ifndef TimeSpan_H
#define TimeSpan_H
#define MAX_TIME 60

#include <iostream>
using namespace std;

class TimeSpan
{
	friend istream& operator>>(istream &inStream, TimeSpan &time);
	friend ostream& operator<<(ostream &outStream, const TimeSpan &time);

	
	

public:
	TimeSpan();
	TimeSpan(int num1);
	TimeSpan(int min, int sec);
	TimeSpan(int hour, int min, int sec);
	
	int getHours() const;
	void setHours(int hr);
	int getMinutes() const;
	void setMinutes(int min);
	int getSeconds() const;
	void setSeconds(int sec);

	void CalculateTime();

	TimeSpan operator+(const TimeSpan &time) const;
	TimeSpan operator-(const TimeSpan &time) const;
	TimeSpan& operator+=(const TimeSpan &time);
	TimeSpan& operator-=(const TimeSpan &time);
	TimeSpan& operator= (const TimeSpan &time);

	bool operator!=(const TimeSpan &time) const;
	bool operator==(const TimeSpan &time) const;

	TimeSpan operator-() const;

	~TimeSpan();

private:
	int hour;
	int minute;
	int second;
	
};

#endif