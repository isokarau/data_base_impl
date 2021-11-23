#include "entry.h"

ostream& operator<<(ostream& out, const Entry& entry) {
    out << entry.date_ << " " << entry.event_;
    return out;
}

bool operator==(const Entry& lhs, const Entry& rhs) {
    return lhs.date_ == rhs.date_ && lhs.event_ == rhs.event_;
}
