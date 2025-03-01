#ifndef INFIX_VISITOR_H
#define INFIX_VISITOR_H

#include <string>
#include "../Visitor.h"

// Concrete visitor - Infix notation (traditional)
class InfixVisitor : public Visitor {
private:
    std::string result;

public:
    InfixVisitor() {}  // Changed from = default; to {} to fix C++11 issue
    virtual ~InfixVisitor() {}  // Changed syntax to fix C++11 issue

    virtual void visit(const Number& number);  // Removed override keyword
    virtual void visit(const Addition& addition);  // Removed override keyword
    virtual void visit(const Multiplication& multiplication);  // Removed override keyword

    std::string getResult() const;
};

#endif // INFIX_VISITOR_H