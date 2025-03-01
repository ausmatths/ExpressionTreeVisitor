#include <iostream>
#include <memory>

#include "../include/Elements/Number.h"
#include "../include/Elements/Addition.h"
#include "../include/Elements/Multiplication.h"
#include "../include/Visitors/PrefixVisitor.h"
#include "../include/Visitors/PostfixVisitor.h"
#include "../include/Visitors/InfixVisitor.h"

int main() {
    // Create the expression tree: (3+7)*6
    auto tree = std::make_shared<Multiplication>(
            std::make_shared<Addition>(
                    std::make_shared<Number>(3),
                    std::make_shared<Number>(7)
            ),
            std::make_shared<Number>(6)
    );

    // Use PrefixVisitor
    PrefixVisitor prefixVisitor;
    tree->accept(prefixVisitor);
    std::string prefixResult = prefixVisitor.getResult();

    // Use PostfixVisitor
    PostfixVisitor postfixVisitor;
    tree->accept(postfixVisitor);
    std::string postfixResult = postfixVisitor.getResult();

    // Use InfixVisitor
    InfixVisitor infixVisitor;
    tree->accept(infixVisitor);
    std::string infixResult = infixVisitor.getResult();

    // Output results
    std::cout << "Prefix: " << prefixResult << std::endl;
    std::cout << "Postfix: " << postfixResult << std::endl;
    std::cout << "Infix: " << infixResult << std::endl;

    return 0;
}
// completed and working perfectly