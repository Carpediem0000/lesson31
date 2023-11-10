#include "Date.h"

bool Date::isLeapYear() const
{
	return (year % 4 == 0 && year % 100 != 0 || year%400 == 0);
}

int Date::monthDays() const
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	else if(month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else
	{
		return isLeapYear() ? 29 : 28;
	}
}

void Date::nextDate()
{
	if (month == 12 && day == 31)
	{
		year++;
		month = 1;
		day = 1;
	}
	else if(day == monthDays())
	{
		month++;
		day = 1;
	}
	else
	{
		day++;
	}
}

void Date::prevDate()
{
	if (month == 1 && day == 1)
	{
		year--;
		month = 12;
		day = 31;
	}
	else if (day == 1)
	{
		month--;
		day = monthDays();
	}
	else
	{
		day--;
	}
}

Date::Date()
{
	time_t t = time(0);
	tm obj;
	localtime_s(&obj, &t);
	year = obj.tm_year + 1900;
	month = obj.tm_mon + 1;
	day = obj.tm_mday;
}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear() const
{
	return year;
}

void Date::setMonth(int month)
{
	if (month > 0 && month < 13)
	{
		this->month = month;
	}
}

int Date::getMonth() const
{
	return month;
}

void Date::setDay(int day)
{
	if (day > 0 && day <= monthDays())
	{
		this->day = day;
	}
}

int Date::getDay() const
{
	return day;
}

void Date::showDate() const
{
	cout << day / 10 << day % 10 << "." << month / 10 << month % 10 << "." << year << endl;
}

bool Date::valid() const
{
	return (day >= 1 && day <= monthDays() && month >= 1 && month <= 12);
}

bool Date::operator==(const Date& obj) const&
{
	if (year == obj.year && month == obj.month && day == obj.day)
		return true;
	return false;
}

bool Date::operator!=(const Date& obj) const&
{
	return !(*this == obj);
}

bool Date::operator>(const Date& obj) const&
{
	if (year > obj.year)
		return true;
	else if(year == obj.year && month > obj.month)
		return true;
	else if(year == obj.year && month == obj.month && day > obj.day)
		return true;
	else
		return false;
}

bool Date::operator<(const Date& obj) const&
{
	return !(*this > obj) && (*this != obj);
}

bool Date::operator>=(const Date& obj) const&
{
	return (*this > obj) || (*this == obj);
}

bool Date::operator<=(const Date& obj) const&
{
	return (*this < obj) || (*this == obj);
}

Date& Date::operator+=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->nextDate();
	}
	return *this;
}

Date& Date::operator-=(int days)
{
	for (int i = 0; i < days; i++)
	{
		this->prevDate();
	}
	return *this;
}

Date& Date::operator+=(float months)
{
	month += months;
	if (month > 12)
	{
		year += month / 12;
		month = (month - 1) % 12 + 1;
	}
	return *this;
}

Date& Date::operator-=(float months)
{
	month -= months;
	if (month < 0)
	{
		year -= (abs(month-1)) / 12 + 1;
		month = 12 - abs(month % 12);
	}
	return *this;
}

Date& Date::operator+=(long years)
{
	year += years;
	return *this;
}

Date& Date::operator-=(long years)
{
	year -= years;
	return *this;
}

Date Date::operator+(int days) const&
{
	Date tmp = *this;
	tmp += days;
	return tmp;
}

Date Date::operator-(int days) const&
{
	Date tmp = *this;
	tmp -= days;
	return tmp;
}

Date Date::operator+(float months) const&
{
	Date tmp = *this;
	tmp += months;
	return tmp;
}

Date Date::operator-(float months) const&
{
	Date tmp = *this;
	tmp -= months;
	return tmp;
}

Date Date::operator+(long years) const&
{
	Date tmp = *this;
	tmp += years;
	return tmp;
}

Date Date::operator-(long years) const&
{
	Date tmp = *this;
	tmp -= years;
	return tmp;
}

int Date::operator-(const Date& obj) const&
{
	Date tmp = *this;
	int amount = 0;
	if (tmp > obj) {
		cout << "1";
		while (tmp != obj) {
			tmp -= 1;
			amount++;
		}
	}
	else if (tmp < obj) {
		cout << "2";
		while (obj != tmp) {
			tmp += 1;
			amount++;
		}
	}
	return amount;
}

Date& Date::operator--()
{
	this->prevDate();
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	this->prevDate();
	return tmp;
}

Date& Date::operator++()
{
	this->nextDate();
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	this->nextDate();
	return tmp;
}

Date operator+(int days, const Date& a)
{
	return a + days;
}

Date operator-(int days, const Date& a)
{
	return a - days;
}

Date operator+(float months, const Date& a)
{
	return a + months;
}

Date operator-(float months, const Date& a)
{
	return a - months;
}

Date operator+(long years, const Date& a)
{
	return a + years;
}

Date operator-(long years, const Date& a)
{
	return a - years;
}

ostream& operator<<(ostream& os, const Date& t)
{
	os << t.day / 10 << t.day % 10 << "." << t.month / 10 << t.month % 10 << "." << t.year;
	return os;
}

istream& operator>>(istream& is, Date& t)
{
	do
	{
		cout << "dd mm yyyy => ";
		is >> t.day >> t.month >> t.year;
	} while (!t.valid());
	return is;
}