#include "../../include/Visitors/InfixVisitor.h"
#include "../../include/Elements/Number.h"
#include "../../include/Elements/Addition.h"
#include "../../include/Elements/Multiplication.h"

void InfixVisitor::visit(const Number& number) {
    result += std::to_string(number.getValue());
}

void InfixVisitor::visit(const Addition& addition) {
    result += "(";
    addition.getLeft()->accept(*this);
    result += "+";
    addition.getRight()->accept(*this);
    result += ")";
}

void InfixVisitor::visit(const Multiplication& multiplication) {
    multiplication.getLeft()->accept(*this);
    result += "*";
    multiplication.getRight()->accept(*this);
}

std::string InfixVisitor::getResult() const {
    return result;
}