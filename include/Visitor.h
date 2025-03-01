#ifndef VISITOR_H
#define VISITOR_H

// Forward declarations
class Number;
class Addition;
class Multiplication;

// Visitor interface
class Visitor {
public:
    virtual ~Visitor() {}  // Changed from = default; to {} to fix C++11 issue
    virtual void visit(const Number& number) = 0;
    virtual void visit(const Addition& addition) = 0;
    virtual void visit(const Multiplication& multiplication) = 0;
};

#endif // VISITOR_H