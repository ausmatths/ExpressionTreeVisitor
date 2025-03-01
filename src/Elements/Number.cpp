
#include "../../include/Elements/Number.h"
#include "../../include/Visitor.h"

Number::Number(int value) : value(value) {
}

int Number::getValue() const {
    return value;
}

void Number::accept(Visitor& visitor) const {
    visitor.visit(*this);
}