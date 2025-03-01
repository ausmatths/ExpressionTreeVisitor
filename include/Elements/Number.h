#ifndef NUMBER_H
#define NUMBER_H

#include "../Expression.h"

// Concrete element - Number
class Number : public Expression {
private:
    int value;

public:
    explicit Number(int value);
    virtual ~Number() {}  // Changed syntax to fix C++11 issue

    int getValue() const;
    virtual void accept(Visitor& visitor) const;  // Removed override keyword
};

#endif // NUMBER_H