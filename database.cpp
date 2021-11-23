#include "database.h"

#include <algorithm>

void Database::Add(const Date& date, const string& event) {
    if (storage[date].count(event) == 0) {
        storage[date].insert(event);
        history[date].push_back(event);
    }
}

void Database::Print(ostream& out) const {
    for (const auto& it : history) {
        for (const auto& event : it.second) {
            out << it.first << " " << event << "\n";
        }
    }
}

int Database::RemoveIf(function<bool(const Date& date, const string& event)> p) {
    int count = 0;
    map<Date, set<string>> new_storage;
    map<Date, vector<string>> new_history;

    for (const auto& it : history) {
        for (const auto& event : it.second) {
            if (!p(it.first, event)) {
                new_storage[it.first].insert(event);
                new_history[it.first].push_back(event);
            } else {
                ++count;
            }
        }
    }

    storage = new_storage;
    history = new_history;

    return count;
}

vector<Entry> Database::FindIf(function<bool(const Date& date, const string& event)> p) const {
    vector<Entry> result;
    for (const auto& item : history) {
        for (const auto& event : item.second) {
            if (p(item.first, event)) {
                result.push_back({item.first, event});
            }
        }
    }
    return result;
}


Entry Database::Last(const Date& date) const {
    auto it = history.upper_bound(date);
    if (it == history.begin()) {
        throw invalid_argument("All elements are bigger!");
    } else {
        --it;
        return {it->first, it->second.back()};
    }
}

