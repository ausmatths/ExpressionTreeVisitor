#include <iostream>
#include <memory>
#include <string>
#include <cassert>

#include "../include/Elements/Number.h"
#include "../include/Elements/Addition.h"
#include "../include/Elements/Multiplication.h"
#include "../include/Visitors/PrefixVisitor.h"
#include "../include/Visitors/PostfixVisitor.h"
#include "../include/Visitors/InfixVisitor.h"

// Test case structure
struct TestCase {
    std::string name;
    std::shared_ptr<Expression> expression;
    std::string expectedPrefix;
    std::string expectedPostfix;
    std::string expectedInfix;
};

// Run a test case
void runTestCase(const TestCase& test) {
    std::cout << "Running test: " << test.name << std::endl;

    // Test prefix visitor
    PrefixVisitor prefixVisitor;
    test.expression->accept(prefixVisitor);
    std::string prefixResult = prefixVisitor.getResult();

    // Test postfix visitor
    PostfixVisitor postfixVisitor;
    test.expression->accept(postfixVisitor);
    std::string postfixResult = postfixVisitor.getResult();

    // Test infix visitor
    InfixVisitor infixVisitor;
    test.expression->accept(infixVisitor);
    std::string infixResult = infixVisitor.getResult();

    // Check results
    std::cout << "  Prefix  - Expected: " << test.expectedPrefix << ", Got: " << prefixResult << std::endl;
    assert(prefixResult == test.expectedPrefix);

    std::cout << "  Postfix - Expected: " << test.expectedPostfix << ", Got: " << postfixResult << std::endl;
    assert(postfixResult == test.expectedPostfix);

    std::cout << "  Infix   - Expected: " << test.expectedInfix << ", Got: " << infixResult << std::endl;
    assert(infixResult == test.expectedInfix);

    std::cout << "Test passed!" << std::endl << std::endl;
}

int main() {
    // Define test cases
    std::vector<TestCase> testCases = {
            // Test Case 1: Simple Number
            {
                    "Simple Number",
                    std::make_shared<Number>(5),
                    "5",
                    "5",
                    "5"
            },

            // Test Case 2: Simple Addition
            {
                    "Simple Addition",
                    std::make_shared<Addition>(
                            std::make_shared<Number>(2),
                            std::make_shared<Number>(3)
                    ),
                    "(+ 2 3)",
                    "2 3 +",
                    "(2+3)"
            },

            // Test Case 3: Simple Multiplication
            {
                    "Simple Multiplication",
                    std::make_shared<Multiplication>(
                            std::make_shared<Number>(4),
                            std::make_shared<Number>(5)
                    ),
                    "(* 4 5)",
                    "4 5 *",
                    "4*5"
            },

            // Test Case 4: Complex Expression (2 + 3) * (4 + 5)
            {
                    "Complex Expression",
                    std::make_shared<Multiplication>(
                            std::make_shared<Addition>(
                                    std::make_shared<Number>(2),
                                    std::make_shared<Number>(3)
                            ),
                            std::make_shared<Addition>(
                                    std::make_shared<Number>(4),
                                    std::make_shared<Number>(5)
                            )
                    ),
                    "(* (+ 2 3) (+ 4 5))",
                    "2 3 + 4 5 + *",
                    "(2+3)*(4+5)"
            },

            // Test Case 5: Required homework case (3 + 7) * 6
            {
                    "Homework Example",
                    std::make_shared<Multiplication>(
                            std::make_shared<Addition>(
                                    std::make_shared<Number>(3),
                                    std::make_shared<Number>(7)
                            ),
                            std::make_shared<Number>(6)
                    ),
                    "(* (+ 3 7) 6)",
                    "3 7 + 6 *",
                    "(3+7)*6"
            }
    };

    // Run all test cases
    for (const auto& testCase : testCases) {
        runTestCase(testCase);
    }

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}