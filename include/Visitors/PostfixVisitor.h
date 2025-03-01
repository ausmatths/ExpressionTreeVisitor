#ifndef POSTFIX_VISITOR_H
#define POSTFIX_VISITOR_H

#include <string>
#include "../Visitor.h"

// Concrete visitor - Postfix notation (RPN)
class PostfixVisitor : public Visitor {
private:
    std::string result;

public:
    PostfixVisitor() {}  // Changed from = default; to {} to fix C++11 issue
    virtual ~PostfixVisitor() {}  // Changed syntax to fix C++11 issue

    virtual void visit(const Number& number);  // Removed override keyword
    virtual void visit(const Addition& addition);  // Removed override keyword
    virtual void visit(const Multiplication& multiplication);  // Removed override keyword

    std::string getResult() const;
};

#endif // POSTFIX_VISITOR_H