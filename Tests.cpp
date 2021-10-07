// Eror 111 - inappropriate number or expression
#include <iostream>
#include "DateTime.h"
using namespace std;
bool testLeapyear() {
    DateTime today;
    today.setMonth(2);
    int day = today.getDay();
    cout << today.toString() << endl;
    today.setDay(31);
    if (day == today.getDay()) {
        return 1;
    }
    else {
        return 0;
    }
}
bool testMonth() {
    DateTime today;
    int month = today.getMonth();
    cout << today.toString() << endl;
    today.setMonth(20);
    if (month == today.getMonth()) {
        return 1;
    }
    else {
        return 0;
    }
}
bool testSecond() {
    DateTime today;
    int second = today.getSecond();
    cout << today.toString() << endl;
    today.setSecond(77);
    if (second == today.getSecond()) {
        return 1;
    }
    else {
        return 0;
    }
}
bool testReduceleapyear() {
    DateTime today;
    today.setDay(1);
    today.setMonth(3);
    cout << today.toString() << endl;
    today.reduceDay();
    cout << today.toString() << endl;
    if (today.getDay() == 29 && today.getMonth() == 2) {
        return 1;
    }
    else {
        return 0;
    }
}
bool testEnlargeleapyear() {
    DateTime today;
    today.setDay(29);
    today.setMonth(2);
    cout << today.toString() << endl;
    today.enlargeDay();
    cout << today.toString() << endl;
    if (today.getDay() == 1 && today.getMonth() == 3) {
        return 1;
    }
    else {
        return 0;
    }
}
bool testYear() {
    DateTime today;

    cout << today.toString() << endl;
    int year = today.getYear();
    cout << "get year value: " << today.getYear() << endl;
    today.setYear(436575638);
    cout << "get year value after change: " << today.getYear() << endl;

    if (year == today.getYear()) {
        return 1;
    }
    else {
        return 0;
    }
}
bool testNotleapyear() {
    DateTime today;
    today.setYear(2003);
    today.setMonth(2);
    cout << today.toString() << endl;
    today.setDay(29);
    if (today.getDay() == 29) {
        return 0;
    }
    else {
        return 1;
    }
}

bool testCopyconstructor() {
    DateTime tomorrow(22, 4, 2021, 15, 33, 21);
    DateTime today(tomorrow);
    cout << "1. " << tomorrow.toString() << endl;
    cout << "2. " << today.toString() << endl;
    if (tomorrow.getYear() == today.getYear()) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    cout << "result testLeapyear: " << testLeapyear() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "result testYear: " << testYear() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "result testNotleapyear: " << testNotleapyear() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "result testCopyconstructor: " << testCopyconstructor() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "result testMonth: " << testMonth() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "result testSecond: " << testSecond() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "result testReduceleapyear: " << testReduceleapyear() << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "result testEnlargeleapyear: " << testEnlargeleapyear() << endl;
    cout << "-------------------------------------------------" << endl;
    return 0;
}