#pragma once

class Date {
	int _day = 0;
	int _month = 0;
	int _year = 0;
	std::string _dayOfWeek = " ";
public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	void getDate();
	void printDate();

	Date getDayOfWeek(Date& d);
	Date addConst(Date& d, int num);

	~Date();
};
