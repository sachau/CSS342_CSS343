//This will get numbers and transform them into time spans. 


#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	hour = 0;
	minute = 0;
	second = 0;
}

TimeSpan::TimeSpan(int hr, int min, int sec)
{
	hour = 0;
	minute = 0;
	second = 0;

	setHours(hr);
	setMinutes(min);
	setSeconds(sec);	
}
	
TimeSpan::TimeSpan(int min, int sec)
{
	hour = 0;
	minute = 0;
	second = 0;

	setMinutes(min);
	setSeconds(sec);
}

TimeSpan::TimeSpan(int num1)
{
	hour = 0;
	minute = 0;
	second = 0;
	setSeconds(num1);
}

void TimeSpan::setHours(int hr)
{
		hour = hr;
		CalculateTime();
}

void TimeSpan::setMinutes(int min)
{
	minute = min;
	CalculateTime();
}

void TimeSpan::setSeconds(int sec)
{
	second = sec;
	CalculateTime();

}

int TimeSpan::getHours() const
{
	return hour;
}


int TimeSpan::getMinutes() const
{
	return minute;
}

int TimeSpan::getSeconds() const
{
	return second;
}

//Reduces the time to never have more than or
//less than 59 minutes or 59 seconds
void TimeSpan::CalculateTime(){
	double tempSeconds = (hour * MAX_TIME * MAX_TIME) + (minute * MAX_TIME) + second;
	
	hour = tempSeconds / (MAX_TIME * MAX_TIME);
	minute = (tempSeconds - (hour * MAX_TIME * MAX_TIME)) / MAX_TIME; 
	second = (tempSeconds - (hour * MAX_TIME * MAX_TIME) - (minute * MAX_TIME));	


}


//Override operators to work with TimeSpan obejects
TimeSpan TimeSpan::operator+(const TimeSpan &time) const
{
	TimeSpan tempTime;

	tempTime.hour = time.hour + hour;
	tempTime.minute = time.minute + minute;
	tempTime.second = time.second + second;
	tempTime.CalculateTime();

	return tempTime;
}

TimeSpan TimeSpan::operator-(const TimeSpan &time) const
{
	TimeSpan tempTime;

	tempTime.hour = hour - time.hour;
	tempTime.minute = minute - time.minute;
	tempTime.second = second - time.second;
	tempTime.CalculateTime();

	return tempTime;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan &time)
{
	hour = time.hour + hour;
	minute = time.minute + minute;
	second = time.second + second;
	CalculateTime();

	return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &time)
{
	hour = hour - time.hour;
	minute = minute - time.minute;
	second = second - time.second;
	CalculateTime();

	return *this;
}

TimeSpan& TimeSpan::operator= (const TimeSpan &time)
{
	hour = time.hour;
	minute = time.minute;
	second = time.second;

	return *this;
}

//prints out TimeSpan Object
ostream&  operator<<(ostream &outStream, const TimeSpan &time)
{
	outStream << time.getHours() << " hours " << time.getMinutes() << " minutes " << time.getSeconds() << " seconds";
	return outStream;
}

//Input from user must contain 3 intergers 
istream& operator>>(istream &inStream, TimeSpan &time)
{
	int hr, min, sec;
	inStream >> time.hour >> time.minute >> time.second;
	time.CalculateTime();
	return inStream;
}

//Compare TimeSpan object
bool TimeSpan::operator!=(const TimeSpan &time) const
{
	return ((hour != time.hour) || (minute != time.minute || second != time.second));
}

bool TimeSpan::operator==(const TimeSpan &time) const
{
	return ((hour == time.hour) && (minute == time.minute) && (second == time.second));
}

//Makes TimeSpan Obects negative without reducing them
TimeSpan TimeSpan::operator-() const
{
	TimeSpan tempTime;
	if (hour != 0)
	{	
		tempTime.hour = -hour;
		tempTime.minute = -minute;
		tempTime.second = -second;
	}
	else if (minute != 0)
	{ 
		tempTime.minute = -minute;
		tempTime.second = -second;
	}
	else if (second != 0)
	{
		tempTime.second = -second;
	}


	return tempTime;
}

TimeSpan::~TimeSpan()
{
}
