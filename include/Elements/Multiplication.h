#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include <memory>
#include "../Expression.h"

// Concrete element - Multiplication
class Multiplication : public Expression {
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    Multiplication(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    virtual ~Multiplication() {}  // Changed syntax to fix C++11 issue

    const std::shared_ptr<Expression>& getLeft() const;
    const std::shared_ptr<Expression>& getRight() const;
    virtual void accept(Visitor& visitor) const;  // Removed override keyword
};

#endif // MULTIPLICATION_H