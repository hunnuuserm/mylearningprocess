#include"Date.h"


void testDate()
{
	Date a1(2023, 6, 19);
	Date a2(2023, 6, 30);
	Date a3(2023, 5, 30);
	Date a4(a1);
	(a1 + 40).printDate();
	(a1 + 400).printDate();
	(a1 + 4000).printDate();
	(a1 + 40000).printDate();

	cout << (a1 == a2) << endl;
	cout << (a1 >= a2) << endl;
	cout << (a1 <= a2) << endl;
	cout << (a1 > a2) << endl;
	cout << (a1 < a2) << endl;
	cout << (a1 != a2) << endl;
}

void testDate2()
{
	Date d1(2022, 7, 24);
	Date d2(2022, 7, 25);
	Date d3(2021, 7, 25);

	cout << (d1 < d2) << endl;
	cout << (d1 < d3) << endl;
	cout << (d1 == d3) << endl;
	cout << (d1 > d3) << endl;

	(++d1).printDate();
	d1.printDate();
	(d1++).printDate();
	d1.printDate();
}

void testDate3()
{
	Date d1(2023, 6, 19);
	Date d2(d1);
	Date d3(d1);
	Date d4(d1);
	Date d5(d1);
	(d1 -= 50).printDate();
	(d2 -= 500).printDate();
	(d3 -= 5000).printDate();
	(d4 -= 50000).printDate();
}

void testDate4()
{
	Date d1(2023, 6, 20);
	Date d2(d1);
	Date d3(d1);
	Date d4(d1);
	(++d1).printDate();
	d1.printDate();
	cout << endl;

	(d2++).printDate();
	d2.printDate();
	cout << endl;

	(--d3).printDate();
	d3.printDate();
	cout << endl;

	(d4--).printDate();
	d4.printDate();
	cout << endl;

	cout << "------------------" << endl;
	Date dd1(6023, 7, 23);
	Date dd2(2023, 6, 20);
	cout << dd1 - dd2 << endl;
}

void testDate5()
{
	Date d1(2023, 6, 21);
	Date d2 = d1 + 1;
	Date d3 = d1;
	cout << d1 << d2 << d3 << endl;
}

int main()
{
	/*testDate();*/
	/*testDate2();*/
	/*testDate3();*/
	/*testDate4();
	int arr[] = { 0,1,2,3,4,5,6,7 };
	cout << 6[arr]<< endl;*/
	testDate5();
	return 0;
}