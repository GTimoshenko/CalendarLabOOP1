#include <iostream>

int getDayOfWeek(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int dayOfWeek = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return dayOfWeek;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int year = 988;
    int month = 7;
    int day = 28;

    int dayOfWeek = getDayOfWeek(year, month, day);

    switch (dayOfWeek) {
    case 0:
        std::cout << "�������" << std::endl;
        break;
    case 1:
        std::cout << "�����������" << std::endl;
        break;
    case 2:
        std::cout << "�����������" << std::endl;
        break;
    case 3:
        std::cout << "�������" << std::endl;
        break;
    case 4:
        std::cout << "�����" << std::endl;
        break;
    case 5:
        std::cout << "�������" << std::endl;
        break;
    case 6:
        std::cout << "�������" << std::endl;
        break;
    default:
        std::cout << "������" << std::endl;
        break;
    }

    return 0;
}