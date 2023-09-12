#include <iostream>
#include "Date.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Date d1;

	d1.getDate();
	d1.getDayOfWeek(d1);
	d1.printDate();
	int num;
	cout << "¬ведите число, на которое хотите увеличить дату: ";
	cin >> num;
	d1.addConst(d1, num);
	d1.printDate();
}