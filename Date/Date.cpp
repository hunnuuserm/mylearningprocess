#include"Date.h"

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > getMonthDay(_year, _month))
	{
		_day -= getMonthDay(_year, _month);
		_month += 1;
		if (_month == 13)
		{
			_month = 1;
			_year += 1;
		}
	}
	return *this;
}


Date Date::operator+(int day)const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

bool Date::operator==(const Date& x)const
{
	return _year == x._year
		&& _month == x._month
		&& _day == x._day;
}

bool Date::operator!=(const Date& x)const
{
	return!(*this == x);
}

bool Date::operator>(const Date& x)const
{
	if (_year > x._year)
	{
		return true;
	}
	else if (_year == x._year &&_month > x._month)
	{
		return true;
	}
	else if (_year == x._year && _month == x._month && _day > x._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator>=(const Date& x)const
{
	return(*this == x) || (*this > x);
}

bool Date::operator<(const Date& x)const
{
	return !(*this >= x);
}

bool Date::operator<=(const Date& x)const
{
	return !(*this > x);
}

Date& Date:: operator++()
{
	return *this += 1;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month -= 1;
		if (_month == 0)
		{
			_month = 12;
			_year -= 1;
		}
		_day = getMonthDay(_year, _month) + _day;
	}
	return *this;
}

Date Date::operator-(int day)const
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator--()
{
	return *this -= 1;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

int Date::operator-(const Date& d2)const
{
	Date tmp(d2);
	int count = 0;
	while (tmp != *this)
	{
		tmp += 1;
		count++;
	}
	return count; 
}

ostream& operator<<(ostream& out, Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;
	return out;
}