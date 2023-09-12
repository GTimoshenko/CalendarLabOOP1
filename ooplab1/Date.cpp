#include <iostream>
#include "Date.h"
using namespace std;

Date::Date() {}
Date::Date(const Date& d1) {
	this->_day = d1._day;
	this->_month = d1._month;
	this->_year = d1._year;
}
Date::~Date() {}

void Date::getDate() {
	cout << "Введите данные";
	cout << endl;

	cout << "День: ";
	cin >> _day;
	cout << endl;

	cout << "Месяц:";
	cin >> _month;
	cout << endl;

	cout << "Год:";
	cin >> _year;
	cout << endl;
}

void Date::printDate() {
	cout << _dayOfWeek << _day << "." << _month << "." << _year << endl;
}
Date Date::getDayOfWeek(Date& d) {
	int temp = this->_month;
	if (temp < 3) {
		temp += 12;
		this->_year--;
	}

	int k = this->_year % 100;
	int j = this->_year / 100;

	int dayOfWeek = (this->_day + 13 * (temp + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

	switch (dayOfWeek) {
	case 0:
		this->_dayOfWeek = "Сегодня Суббота, ";
		break;
	case 1:
		this->_dayOfWeek = "Сегодня Воскресенье, ";
		break;
	case 2:
		this->_dayOfWeek = "Сегодня Понедельник, ";
		break;
	case 3:
		this->_dayOfWeek = "Сегодня Вторник, ";
		break;
	case 4:
		this->_dayOfWeek = "Сегодня Среда, ";
		break;
	case 5:
		this->_dayOfWeek = "Сегодня Четверг, ";
		break;
	case 6:
		this->_dayOfWeek = "Сегодня Пятница, ";
		break;
	default:
		this->_dayOfWeek = "";
		break;
	}
	return d;
}

Date Date::addConst(Date& d, int num) {
	int monthLen, totalDays = 0, yearLen = 365, temp;
	if (this->_year % 4 == 0) {
		yearLen = 366;
	}

	int currMonth = 1;
	while (currMonth < this->_month) {
		switch (currMonth) {
		case 1:
			monthLen = 31;
			break;
		case 2:
			if (this->_year % 4 == 0) {
				monthLen = 29;
			}
			else monthLen = 28;
			break;
		case 3:
			monthLen = 31;
			break;
		case 4:
			monthLen = 30;
			break;
		case 5:
			monthLen = 31;
			break;
		case 6:
			monthLen = 30;
			break;
		case 7:
			monthLen = 31;
			break;
		case 8:
			monthLen = 31;
			break;
		case 9:
			monthLen = 30;
			break;
		case 10:
			monthLen = 31;
			break;
		case 11:
			monthLen = 30;
			break;
		case 12:
			monthLen = 31;
			break;
		}
		currMonth++;

		totalDays += monthLen;
	}


	totalDays += this->_day;


	temp = num - (yearLen - totalDays);
	if (temp > 0) {
		totalDays = temp;
		this->_year++;
		if (this->_year % 4 == 0) {
			yearLen = 366;
		}
	}
	else totalDays += num;


	currMonth = 1;
	while (totalDays > 0) {
		switch (currMonth) {
		case 1:
			monthLen = 31;
			break;
		case 2:
			if (this->_year % 4 == 0) {
				monthLen = 29;
			}
			else monthLen = 28;
			break;
		case 3:
			monthLen = 31;
			break;
		case 4:
			monthLen = 30;
			break;
		case 5:
			monthLen = 31;
			break;
		case 6:
			monthLen = 30;
			break;
		case 7:
			monthLen = 31;
			break;
		case 8:
			monthLen = 31;
			break;
		case 9:
			monthLen = 30;
			break;
		case 10:
			monthLen = 31;
			break;
		case 11:
			monthLen = 30;
			break;
		case 12:
			monthLen = 31;
			break;
		}
		currMonth++;
		if (currMonth > 12) {
			currMonth = 1;
			this->_year++;
		}

		totalDays -= monthLen;
	}


	totalDays += monthLen;
	currMonth--;
	
	this->_day = totalDays;
	this->_month = currMonth;
	getDayOfWeek(d);
	return d;
}

