#ifndef PREFIX_VISITOR_H
#define PREFIX_VISITOR_H

#include <string>
#include "../Visitor.h"

// Concrete visitor - Prefix notation (Lisp-style)
class PrefixVisitor : public Visitor {
private:
    std::string result;

public:
    PrefixVisitor() {}  // Changed from = default; to {} to fix C++11 issue
    virtual ~PrefixVisitor() {}  // Changed syntax to fix C++11 issue

    virtual void visit(const Number& number);  // Removed override keyword
    virtual void visit(const Addition& addition);  // Removed override keyword
    virtual void visit(const Multiplication& multiplication);  // Removed override keyword

    std::string getResult() const;
};

#endif // PREFIX_VISITOR_H