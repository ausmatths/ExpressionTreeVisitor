
#include "../../include/Elements/Multiplication.h"
#include "../../include/Visitor.h"

Multiplication::Multiplication(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {
}

const std::shared_ptr<Expression>& Multiplication::getLeft() const {
    return left;
}

const std::shared_ptr<Expression>& Multiplication::getRight() const {
    return right;
}

void Multiplication::accept(Visitor& visitor) const {
    visitor.visit(*this);
}