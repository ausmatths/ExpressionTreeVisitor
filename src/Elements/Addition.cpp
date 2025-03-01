#include "../../include/Elements/Addition.h"
#include "../../include/Visitor.h"

Addition::Addition(std::shared_ptr<Expression> left, std::shared_ptr<Expression> right)
        : left(std::move(left)), right(std::move(right)) {
}

const std::shared_ptr<Expression>& Addition::getLeft() const {
    return left;
}

const std::shared_ptr<Expression>& Addition::getRight() const {
    return right;
}

void Addition::accept(Visitor& visitor) const {
    visitor.visit(*this);
}