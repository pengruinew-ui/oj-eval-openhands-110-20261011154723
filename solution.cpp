#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int month_days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date
{
private:
    int _year;
    int _month;
    int _day;
    
    // Check if a year is leap year
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    // Get days in a month for a given year
    int getDaysInMonth(int year, int month) const {
        if (month == 2 && isLeapYear(year)) {
            return 29;
        }
        return month_days[month];
    }
    
    // Validate if a date is valid
    bool isValidDate(int year, int month, int day) const {
        if (year < 1900 || year > 2030) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > getDaysInMonth(year, month)) return false;
        return true;
    }
    
public:
    // Default constructor: 1900-1-1
    Date() : _year(1900), _month(1), _day(1) {}
    
    // Parameterized constructor with validation
    Date(int yy, int mm, int dd) {
        if (isValidDate(yy, mm, dd)) {
            _year = yy;
            _month = mm;
            _day = dd;
        } else {
            _year = 1900;
            _month = 1;
            _day = 1;
        }
    }
    
    // Prefix ++ operator (next day)
    Date& operator++() {
        _day++;
        if (_day > getDaysInMonth(_year, _month)) {
            _day = 1;
            _month++;
            if (_month > 12) {
                _month = 1;
                _year++;
            }
        }
        return *this;
    }
    
    // Postfix ++ operator (next day)
    Date operator++(int) {
        Date temp = *this;
        ++(*this);
        return temp;
    }
    
    // Prefix -- operator (previous day)
    Date& operator--() {
        _day--;
        if (_day < 1) {
            _month--;
            if (_month < 1) {
                _month = 12;
                _year--;
            }
            _day = getDaysInMonth(_year, _month);
        }
        return *this;
    }
    
    // Postfix -- operator (previous day)
    Date operator--(int) {
        Date temp = *this;
        --(*this);
        return temp;
    }
    
    // Date + int days (returns new date)
    Date operator+(int days) const {
        Date result = *this;
        if (days > 0) {
            for (int i = 0; i < days; i++) {
                ++result;
            }
        } else if (days < 0) {
            for (int i = 0; i < -days; i++) {
                --result;
            }
        }
        return result;
    }
    
    // Date - int days (returns new date)
    Date operator-(int days) const {
        return *this + (-days);
    }
    
    // Date - Date (returns absolute difference in days)
    int operator-(const Date& other) const {
        Date d1 = *this;
        Date d2 = other;
        int diff = 0;
        
        if (d1 < d2) {
            // d1 is earlier, count forward
            while (d1 < d2) {
                ++d1;
                diff++;
            }
        } else {
            // d2 is earlier or equal, count forward from d2
            while (d2 < d1) {
                ++d2;
                diff++;
            }
        }
        
        return diff;
    }
    
    // < comparison operator (returns 1 if true, 0 if false)
    int operator<(const Date& other) const {
        if (_year != other._year) {
            return _year < other._year ? 1 : 0;
        }
        if (_month != other._month) {
            return _month < other._month ? 1 : 0;
        }
        return _day < other._day ? 1 : 0;
    }
    
    // Output function (backup if operator<< doesn't work)
    void out() const {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
    
    
};



void Test()
{
    int op;
    cin >> op;
    int yy, mm, dd;
    if (op == 1 || op == 0)
    {
        Date d0;
        Date d1(2000, 2, 29);
        Date d2(1900, 2, 29);
        d0.out(); d1.out(); d2.out();
    }
    if (op == 2 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        for (int i=0;i<5;++i) (++d0).out();
        for (int i=0;i<5;++i) (d0++).out();
        for (int i=0;i<5;++i) (d0--).out();
        for (int i=0;i<2;++i) (--d0).out();
        d0.out();
    }
    if (op == 3 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        (d0+100).out();
        (d0-1000).out();
    }
    if (op == 4 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        Date d1(2020, 12, 21);
        cout << (d0 < d1) << endl;
    }
    if (op == 5 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        Date d1(1912, 6, 23);
        cout << d0 - d1 << endl;
    }
}
int main()
{
    Test();
    return 0;
}