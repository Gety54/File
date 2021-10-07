#pragma once
class DateTime
{
public:
    DateTime();
    DateTime(int day, int month, int year, int hours, int minute, int  second);
    DateTime(const DateTime& object);
    char* toString();
    void reduceYear(); // year - 1
    void enlargeYear(); // year + 1
    void reduceMonth(); // month - 1
    void enlargeMonth(); // month + 1
    void reduceDay(); // day - 1
    void enlargeDay(); // day + 1
    void reduceHours(); // hours - 1
    void enlargeHours(); // hours + 1
    void reduceMinute(); // minute - 1
    void enlargeMinute(); // minute + 1
    void reduceSecond(); // second - 1
    void enlargeSecond(); // second + 1
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setHours(int hours);
    void setMinute(int minute);
    void setSecond(int second);
    int getYear();
    int getMonth();
    int getDay();
    int getHours();
    int getMinute();
    int getSecond();
    static int iterations;
private:
    int year, month, day, hours, minute, second;
    bool leapYear(int year);
    bool checkMonth(int month);
};