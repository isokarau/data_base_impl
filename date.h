#pragma once

#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

class Date {
public:
//    Date()
//        : year_(1), month_(1), day_(1) {}

    Date(int year, int month, int day)
        : year_(year), month_(month), day_(day) {}

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    int year_;
    int month_;
    int day_;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& stream, const Date& date);

bool operator < (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
