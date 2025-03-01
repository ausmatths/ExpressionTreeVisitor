#ifndef EXPRESSION_H
#define EXPRESSION_H

class Visitor;

// Expression interface - the element that visitors will visit
class Expression {
public:
    virtual ~Expression() = default;
    virtual void accept(Visitor& visitor) const = 0;
};

#endif // EXPRESSION_H