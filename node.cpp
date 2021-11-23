#include "node.h"

#include <stdexcept>

template<typename T>
bool Compare(Comparison cmp, T left, T right) {
    if (cmp == Comparison::Equal) {
        return left == right;
    }
    if (cmp == Comparison::Greater) {
        return left > right;
    }
    if (cmp == Comparison::GreaterOrEqual) {
        return left >= right;
    }
    if (cmp == Comparison::Less) {
        return left < right;
    }
    if (cmp == Comparison::LessOrEqual) {
        return left <= right;
    }
    if (cmp == Comparison::NotEqual) {
        return left != right;
    }
    throw invalid_argument("Invalid comparison!");
}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(cmp_, date, date_);
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(cmp_, event, event_);
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if (op_ == LogicalOperation::And) {
        return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    }
    if (op_ == LogicalOperation::Or) {
        return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }
    throw invalid_argument("Invalid logical operation!");
}
