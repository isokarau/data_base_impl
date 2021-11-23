#include "date.h"

#include <iomanip>

int Date::GetYear() const {
    return year_;
}

int Date::GetMonth() const {
    return month_;
}

int Date::GetDay() const {
    return day_;
}

Date ParseDate(istream& is) {
    bool ok = true;

    int year;
    ok = ok && (is >> year);
    ok = ok && (is.peek() == '-');
    is.ignore(1);

    int month;
    ok = ok && (is >> month);
    ok = ok && (is.peek() == '-');
    is.ignore(1);

    int day;
    ok = ok && (is >> day);

    ok = ok && (month <= 12 && month >= 1);
    ok = ok && (day <= 31 && day >= 1);

    if (!ok) {
        throw logic_error("Wrong date format!");
    }
    return Date(year, month, day);
}

ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() <<
      "-" << setw(2) << setfill('0') << date.GetMonth() <<
      "-" << setw(2) << setfill('0') << date.GetDay();
  return stream;
}

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetDay() < rhs.GetDay();
}

bool operator == (const Date& lhs, const Date& rhs) {
    return lhs.GetYear() == rhs.GetYear() &&
            lhs.GetMonth() == rhs.GetMonth() &&
            lhs.GetDay() == rhs.GetDay();
}

bool operator <= (const Date& lhs, const Date& rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator > (const Date& lhs, const Date& rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}

bool operator >= (const Date& lhs, const Date& rhs) {
    return lhs > rhs || lhs == rhs;
}

bool operator != (const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}
