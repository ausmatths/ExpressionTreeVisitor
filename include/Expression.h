#ifndef EXPRESSION_H
#define EXPRESSION_H

// Forward declarations
class Visitor;

// Expression interface - the element that visitors will visit
class Expression {
public:
    virtual ~Expression() {}  // Changed from = default; to {} to fix C++11 issue
    virtual void accept(Visitor& visitor) const = 0;
};

#endif // EXPRESSION_H