
#include "../../include/Visitors/PrefixVisitor.h"
#include "../../include/Elements/Number.h"
#include "../../include/Elements/Addition.h"
#include "../../include/Elements/Multiplication.h"

void PrefixVisitor::visit(const Number& number) {
    result += std::to_string(number.getValue());
}

void PrefixVisitor::visit(const Addition& addition) {
    result += "(+ ";
    addition.getLeft()->accept(*this);
    result += " ";
    addition.getRight()->accept(*this);
    result += ")";
}

void PrefixVisitor::visit(const Multiplication& multiplication) {
    result += "(* ";
    multiplication.getLeft()->accept(*this);
    result += " ";
    multiplication.getRight()->accept(*this);
    result += ")";
}

std::string PrefixVisitor::getResult() const {
    return result;
}