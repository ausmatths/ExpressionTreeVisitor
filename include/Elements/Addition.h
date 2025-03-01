
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
    ~Addition() override = default;

    const std::shared_ptr<Expression>& getLeft() const;
    const std::shared_ptr<Expression>& getRight() const;
    void accept(Visitor& visitor) const override;
};

#endif // ADDITION_H