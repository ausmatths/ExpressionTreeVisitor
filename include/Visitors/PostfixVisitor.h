
#ifndef POSTFIX_VISITOR_H
#define POSTFIX_VISITOR_H

#include <string>
#include "../Visitor.h"

// Concrete visitor - Postfix notation (RPN)
class PostfixVisitor : public Visitor {
private:
    std::string result;

public:
    PostfixVisitor() = default;
    ~PostfixVisitor() override = default;

    void visit(const Number& number) override;
    void visit(const Addition& addition) override;
    void visit(const Multiplication& multiplication) override;

    std::string getResult() const;
};

#endif // POSTFIX_VISITOR_H