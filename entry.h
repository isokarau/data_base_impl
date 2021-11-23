#pragma once

#include "date.h"

#include <string>
#include <sstream>

using namespace std;

struct Entry {
    Date date_;
    string event_;
};

ostream& operator << (ostream& out, const Entry& entry);

bool operator==(const Entry& lhs, const Entry& rhs);
