#ifndef ADDITION_H
#define ADDITION_H

#include <memory>
#include "../Expression.h"

// Concrete element - Addition
class Addition : public Expression {
private:
    std::shared_ptr<Expression> left;
    std::shared_ptr<Expression> right;

public:
    Addition(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right);
    virtual ~Addition() {}  // Changed syntax to fix C++11 issue

    const std::shared_ptr<Expression>& getLeft() const;
    const std::shared_ptr<Expression>& getRight() const;
    virtual void accept(Visitor& visitor) const;  // Removed override keyword
};

#endif // ADDITION_H