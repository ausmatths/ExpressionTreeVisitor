
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
    ~Multiplication() override = default;

    const std::shared_ptr<Expression>& getLeft() const;
    const std::shared_ptr<Expression>& getRight() const;
    void accept(Visitor& visitor) const override;
};

#endif // MULTIPLICATION_H