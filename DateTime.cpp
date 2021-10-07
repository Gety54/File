#include <iostream>
#include "DateTime.h"
using namespace std;
int DateTime::iterations = 0;
// default constructor
DateTime::DateTime() {
	DateTime::setYear(2020);
	DateTime::setMonth(7);
	DateTime::setDay(20);
	DateTime::setHours(15);
	DateTime::setMinute(15);
	DateTime::setSecond(15);
}
// value constructor
DateTime::DateTime(int day, int month, int year, int hours, int minute, int  second) {
	DateTime::setYear(year);
	DateTime::setMonth(month);
	DateTime::setDay(day);
	DateTime::setHours(hours);
	DateTime::setMinute(minute);
	DateTime::setSecond(second);
}

// copy constructor

DateTime::DateTime(const DateTime& object) {
	this->year = object.year;
	this->month = object.month;
	this->day = object.day;
	this->hours = object.hours;
	this->minute = object.minute;
	this->second = object.second;
}

//check leap year, return 1 - leap year and return 0 - not leap year

bool DateTime::leapYear(int year) {
	if (year % 4 == 0 (year % 100 != 0 || year % 400 == 0))
		return 1;
	else
		return 0;
}
// check month, return 1 - 31 day in month and return 0 - 30 day in month
bool DateTime::checkMonth(int month) {
	if (month == 2) {
		cout << "Eror! Wrong number" << endl;
	}
	else {
		if (month <= 7 && month % 2 != 0)
			return 1;
		if (month <= 7 && month % 2 == 0 && month != 2)
			return 0;
		if (month > 7 && month % 2 == 0)
			return 1;
		if (month > 7 && month % 2 != 0)
			return 0;
	}
}
// translation to string
char* DateTime::toString() {
	char adate[5], ayear[5], amonth[5], ahours[5], aminute[5], asecond[5];
	int ysize = 0, size = 0;
	if (DateTime::getYear() > 999 && DateTime::getYear() < 10000) {
		ayear[0] = DateTime::getYear() / 1000 + '0';
		ayear[1] = (DateTime::getYear() / 100) % 10 + '0';
		ayear[2] = (DateTime::getYear() / 10) % 10 + '0';
		ayear[3] = DateTime::getYear() % 10 + '0';
		ysize += 4;
	}
	else if (DateTime::getYear() > 99 && DateTime::getYear() < 1000)
	{
		ayear[0] = DateTime::getYear() / 100 + '0';
		ayear[1] = (DateTime::getYear() / 10) % 10 + '0';
		ayear[2] = DateTime::getYear() % 10 + '0';
		ysize += 3;
	}
	if (DateTime::getDay() > 9) {
		adate[0] = DateTime::getDay() / 10 + '0';
		adate[1] = DateTime::getDay() % 10 + '0';
	}
	else {
		adate[0] = '0';
		adate[1] = DateTime::getDay() + '0';
	}
	if (DateTime::getMonth() > 9) {
		amonth[0] = DateTime::getMonth() / 10 + '0';
		amonth[1] = DateTime::getMonth() % 10 + '0';
	}
	else {
		amonth[0] = '0';
		amonth[1] = DateTime::getMonth() + '0';
	}
	if (DateTime::getHours() > 9) {
		ahours[0] = DateTime::getHours() / 10 + '0';
		ahours[1] = DateTime::getHours() % 10 + '0';
	}
	else {
		ahours[0] = '0';
		ahours[1] = DateTime::getHours() + '0';
	}
	if (DateTime::getMinute() > 9) {
		aminute[0] = DateTime::getMinute() / 10 + '0';
		aminute[1] = DateTime::getMinute() % 10 + '0';
	}
	else {
		aminute[0] = '0';
		aminute[1] = DateTime::getMinute() + '0';
	}
	if (DateTime::getSecond() > 9) {
		asecond[0] = DateTime::getSecond() / 10 + '0';
		asecond[1] = DateTime::getSecond() % 10 + '0';
	}
	else {
		asecond[0] = '0';
		asecond[1] = DateTime::getSecond() + '0';
	}
	size = ysize + 10;
	char* resChar = new char[size + 6];
	for (int i = 0; i < 2; i++)
		resChar[i] = adate[i];
	resChar[2] = ':';
	for (int i = 0; i < 2; i++)
		resChar[i + 3] = amonth[i];
	resChar[5] = ':';
	for (int i = 0; i < ysize; i++)
		resChar[i + 6] = ayear[i];
	resChar[6 + ysize] = '\t';
	for (int i = 0; i < 2; i++)
		resChar[i + ysize + 7] = ahours[i];
	resChar[9 + ysize] = ':';
	for (int i = 0; i < 2; i++)
		resChar[i + ysize + 10] = aminute[i];
	resChar[ysize + 12] = ':';
	for (int i = 0; i < 2; i++)
		resChar[ysize + 13 + i] = asecond[i];
	resChar[size + 6 - 1] = '\0';
	return resChar;
}
// reduce or enlarge year, month, day, hours, minute and second
// year - 1
void DateTime::reduceYear() {
	DateTime::setYear(DateTime::getYear() - 1);
	iterations++;
}
// year + 1
void DateTime::enlargeYear() {
	DateTime::setYear(DateTime::getYear() + 1);
	iterations++;
}
// month - 1
void DateTime::reduceMonth() {
	if (DateTime::getMonth() - 1 < 1) {
		DateTime::setMonth(12);
		DateTime::reduceYear();
	}
	else {
		DateTime::setMonth(DateTime::getMonth() - 1);
	}
	iterations++;
}
// month + 1
void DateTime::enlargeMonth() {
	if (DateTime::getMonth() + 1 > 12) {
		DateTime::setMonth(1);
		DateTime::enlargeYear();
	}
	else {
		DateTime::setMonth(DateTime::getMonth() + 1);
	}
	iterations++;
}
// day - 1
void DateTime::reduceDay() {
	if (DateTime::getDay() == 1) {
		if (DateTime::getMonth() == 3) {  // month = febraly
			if (leapYear(DateTime::getYear())) {  // check leap year
				DateTime::setDay(29);
				DateTime::reduceMonth();
			}
			else {
				DateTime::setDay(28);
				DateTime::reduceMonth();
			}
		}
		else if (DateTime::checkMonth(DateTime::getMonth())) {  // check month
			DateTime::setDay(31);
			DateTime::reduceMonth();
		}
		else {
			DateTime::setDay(30);
			DateTime::reduceMonth();
		}
	}
	else {
		DateTime::setDay(DateTime::getDay() - 1);
	}
	iterations++;
}
// day + 1
void DateTime::enlargeDay() {
	if (DateTime::getDay() == 28 && DateTime::getMonth() == 2 && !leapYear(DateTime::getYear())) { // 28:02:year and year not leap year
		DateTime::setDay(1);
		DateTime::enlargeMonth();
	}
	else if (DateTime::getDay() == 29 && DateTime::getMonth() == 2 && leapYear(DateTime::getYear())) { // 29:02:year and leap year
		DateTime::setDay(1);
		DateTime::enlargeMonth();
	}
	else if (DateTime::getDay() == 30 && !DateTime::checkMonth(DateTime::getMonth())) {
		DateTime::setDay(1);
		DateTime::enlargeMonth();
	}
	else if (DateTime::getDay() == 31 && DateTime::checkMonth(DateTime::getMonth())) {
		DateTime::setDay(1);
		DateTime::enlargeMonth();
	}
	else {
		DateTime::setDay(DateTime::getDay() + 1);
	}
	iterations++;
}
// hours - 1
void DateTime::reduceHours() {
	if (DateTime::getHours() - 1 < 0) {
		DateTime::setHours(23);
		DateTime::reduceDay();
	}
	else {
		DateTime::setHours(DateTime::getHours() - 1);
	}
	iterations++;
}
// hours + 1
void DateTime::enlargeHours() {
	if (DateTime::getHours() + 1 > 24) {
		DateTime::setHours(0);
		DateTime::enlargeDay();
	}
	else {
		DateTime::setHours(DateTime::getHours() + 1);
	}
	iterations++;
}
// minute - 1
void DateTime::reduceMinute() {
	if (DateTime::getMinute() - 1 < 0) {
		DateTime::setMinute(59);
		DateTime::reduceHours();
	}
	else {
		DateTime::setMinute(DateTime::getMinute() - 1);
	}
	iterations++;
}
// minute + 1
void DateTime::enlargeMinute() {
	if (DateTime::getMinute() + 1 > 60) {
		DateTime::setMinute(0);
		DateTime::enlargeHours();
	}
	else {
		DateTime::setMinute(DateTime::getMinute() + 1);
	}
	iterations++;
}
// second - 1
void DateTime::reduceSecond() {
	if (DateTime::getSecond() - 1 < 0) {
		DateTime::setMinute(59);
		DateTime::reduceMinute();
	}
	else {
		DateTime::setSecond(DateTime::getSecond() - 1);
	}
	iterations++;
}
// second + 1
void DateTime::enlargeSecond() {
	if (DateTime::getSecond() + 1 > 60) {
		DateTime::setSecond(0);
		DateTime::enlargeMinute();
	}
	else {
		DateTime::setSecond(DateTime::getSecond() + 1);
	}
	iterations++;
}
// Get year, month, day, hours, minute, second
int DateTime::getDay() {
	return day;
}
int DateTime::getYear() {
	return year;
}
int DateTime::getMonth() {
	return month;
}
int DateTime::getHours() {
	return hours;
}
int DateTime::getMinute() {
	return minute;
}
int DateTime::getSecond() {
	return second;
}
// Set year, month, day, hours, minute, second
void DateTime::setYear(int year) {
	if (year < 10000 && year > 999) {
		this->year = year;
	}
	try {
		if (year >= 10000 || year <= 999) {
			throw 111;
		}
	}
	catch (int i) {
		cout << "Error " << i << "   the year value must be in the ranges 1000 to 9999" << endl;
	}
}
void DateTime::setMonth(int month) {
	if (month > 0 && month < 13) {
		this->month = month;
	}
	else {
		try {
			if (year >= 10000 || year <= 999) {
				throw 111;
			}
		}
		catch (int i) {
			cout << "Error " << i << "   month value must not be negative or greater than 12" << endl;
		}
	}
}
void DateTime::setDay(int day) {
	if (day > 0 && day < 32) {
		if (DateTime::getMonth() == 2) {
			if (leapYear(DateTime::getYear())) {
				if (day < 30) {
					this->day = day;
				}
				else {
					try {
						if (day >= 30) {
							throw 111;
						}
					}
					catch (int i) {
						cout << "Eror " << i << "   value of month February cannot be more than 29" << endl;
					}
				}
			}
			else {
				if (day < 29) {
					this->day = day;
				}
				else {
					try {
						if (day >= 29) {
							throw 111;
						}
					}
					catch (int i) {
						cout << "Eror " << i << "   the value of the month February cannot be more than 28 since it is not a leap year" << endl;
					}
				}
			}
		}
		else {
			if (DateTime::checkMonth(DateTime::getMonth())) {
				this->day = day;
			}
			else {
				if (day < 31) {
					this->day = day;
				}
				else {
					try {
						if (day >= 31) {
							throw 111;
						}
					}
					catch (int i) {
						cout << "Eror " << i << "   this month cannot be 31 days" << endl;
					}
				}
			}
		}
	}
	else {
		try {
			if (day >= 32) {
				throw 111;
			}
		}
		catch (int i) {
			cout << "Eror " << i << "   the value of a month should not be more than 31" << endl;
		}
	}
}
void DateTime::setHours(int hours) {
	if (hours > -1 && hours < 24) {
		this->hours = hours;
	}
	try {
		if (hours > 23 || hours < 0) {
			throw 111;
		}
	}
	catch (int i) {
		cout << "Eror " << i << "   the hour value cannot be negative or greater than 23" << endl;
	}
}
void DateTime::setMinute(int minute) {
	if (minute > -1 && minute < 60) {
		this->minute = minute;
	}
	try {
		if (minute >= 60 || minute < 0) {
			throw 111;
		}
	}
	catch (int i) {
		cout << "Eror " << i << "   second value cannot be negative or greater than 59" << endl;
	}
}
void DateTime::setSecond(int second) {
	if (second > -1 && second < 60) {
		this->second = second;
	}
	try {
		if (second > 60 || second < 0) {
			throw 111;
		}
	}
	catch (int i) {
		cout << "Eror " << i << "   second value cannot exceed 60" << endl;
	}
}
