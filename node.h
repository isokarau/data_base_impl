#pragma once

#include "date.h"

#include <memory>
#include <string>

using namespace std;

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And, Or
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison cmp, const Date& date)
        : cmp_(cmp), date_(date) {}

    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison cmp_;
    const Date date_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison cmp, const string& event)
        : cmp_(cmp), event_(event) {}

    bool Evaluate(const Date& date, const string& event) const override;
private:
    Comparison cmp_;
    const string event_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation op,
            shared_ptr<Node> left,
            shared_ptr<Node> right)
        : op_(op), left_(left), right_(right) {}

    bool Evaluate(const Date& date, const string& event) const override;
private:
    LogicalOperation op_;
    shared_ptr<Node> left_;
    shared_ptr<Node> right_;
};
