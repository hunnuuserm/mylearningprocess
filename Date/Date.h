#pragma once
#include<iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, Date& d);
public:
	int getMonthDay(int year, int month)
	{
		static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}
		return arr[month];
	}

	Date(int year=1900, int month=1, int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void printDate()const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	Date& operator+=(int day);
	Date operator+(int day)const;
	Date& operator-=(int day);
	Date operator-(int day)const;

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	bool operator==(const Date& x)const;
	bool operator!=(const Date& x)const;
	bool operator>(const Date& x)const;
	bool operator>=(const Date& x)const;
	bool operator<(const Date& x)const;
	bool operator<=(const Date& x)const;

	int operator-(const Date& d2)const;


private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, Date& d);