#pragma once

#include "date.h"
#include "entry.h"

#include <functional>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& out) const;

	int RemoveIf(function<bool(const Date& date, const string& event)> p);

    vector<Entry> FindIf(function<bool(const Date& date, const string& event)> p) const;

    Entry Last(const Date& date) const;

private:
    map<Date, set<string>> storage;
    map<Date, vector<string>> history;
};
