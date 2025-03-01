
#ifndef PREFIX_VISITOR_H
#define PREFIX_VISITOR_H

#include <string>
#include "../Visitor.h"

// Concrete visitor - Prefix notation (Lisp-style)
class PrefixVisitor : public Visitor {
private:
    std::string result;

public:
    PrefixVisitor() = default;
    ~PrefixVisitor() override = default;

    void visit(const Number& number) override;
    void visit(const Addition& addition) override;
    void visit(const Multiplication& multiplication) override;

    std::string getResult() const;
};

#endif // PREFIX_VISITOR_H