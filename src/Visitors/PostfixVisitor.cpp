#include "../../include/Visitors/PostfixVisitor.h"
#include "../../include/Elements/Number.h"
#include "../../include/Elements/Addition.h"
#include "../../include/Elements/Multiplication.h"

void PostfixVisitor::visit(const Number& number) {
    result += std::to_string(number.getValue()) + " ";
}

void PostfixVisitor::visit(const Addition& addition) {
    addition.getLeft()->accept(*this);
    addition.getRight()->accept(*this);
    result += "+ ";
}

void PostfixVisitor::visit(const Multiplication& multiplication) {
    multiplication.getLeft()->accept(*this);
    multiplication.getRight()->accept(*this);
    result += "* ";
}

std::string PostfixVisitor::getResult() const {
    // Remove trailing space
    if (!result.empty() && result.back() == ' ') {
        return result.substr(0, result.length() - 1);
    }
    return result;
}