
#ifndef INFIX_VISITOR_H
#define INFIX_VISITOR_H

#include <string>
#include "../Visitor.h"

// Concrete visitor - Infix notation (traditional)
class InfixVisitor : public Visitor {
private:
    std::string result;

public:
    InfixVisitor() = default;
    ~InfixVisitor() override = default;

    void visit(const Number& number) override;
    void visit(const Addition& addition) override;
    void visit(const Multiplication& multiplication) override;

    std::string getResult() const;
};

#endif // INFIX_VISITOR_H