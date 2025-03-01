#ifndef NUMBER_H
#define NUMBER_H

#include "../Expression.h"

// Concrete element - Number
class Number : public Expression {
private:
    int value;

public:
    explicit Number(int value);
    ~Number() override = default;

    int getValue() const;
    void accept(Visitor& visitor) const override;
};

#endif // NUMBER_H