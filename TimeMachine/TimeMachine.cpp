// TimeMachine.cpp : Defines the entry point for the console application.
//Main to use test TimeSpan objects

#include "TimeSpan.h"
#include "TimeSpan.cpp"
#include <iostream>
using namespace std;


int main()
{
	
	int waitVar;
	TimeSpan t1, t2( -1, 0, 1), t3(3,-30,0);
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
	dur7 = t2 + t3;
	TimeSpan t4(1, 2, 3), t5(3, 3, 4), t6(1,-120,-5), t7(7),t8(1,6,121);


	cout << "Time is" << endl;
	cout << t2.getHours() << " hours " << t2.getMinutes() << " minutes "
		<< t2.getSeconds() << " seconds" << endl;
	cout << dur7.getHours() << " hours " << dur7.getMinutes() << " minutes "
		<< dur7.getSeconds() << " seconds" << endl;
	cout << dur1 << endl;
	

	cout << dur1 << endl;
	cout << dur2 << endl;
	cout << dur3 << endl;
	cout << dur4 << endl;
	cout << dur5 << endl;
	cout << dur6 << endl;
	cout << dur7 << endl;
	dur7 += dur3;
	cout << dur3 << endl;
	cout << dur7 << endl;

	if
		(dur3 != dur6)
	{
		cout <<
			"Durations are different."
			<< endl;
	}
	else
	{
		cout <<
			"Durations are the same"
			<< endl;
	}
	dur7.setHours(7);
	cout << dur7 << endl;
	cout << t4 << endl;
	cout << t5 << endl;
	cout << t6 << endl;
	t4 -= t5;
	cout << "t4 - t5 = " << t4 << endl;
	t6 = t7 - t8;
	cout << t7 << endl;

	cout << t8 << endl;
	TimeSpan t9( 2,3);
	cout << t9 << endl;
	t9 = -(t9);
	cout << t9 << endl;
	cout << "Input a time with 3 numbers: ";
	cin >> t1;
	cout << t1 << endl;
	
	cin >> waitVar;

	return 0;
	
}

