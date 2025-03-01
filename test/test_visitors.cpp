#include <iostream>
#include <memory>
#include <string>
#include <cassert>
#include <vector>

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

    // Constructor to fix initialization list issues in C++98/03
    TestCase(const std::string& n,
             const std::shared_ptr<Expression>& expr,
             const std::string& prefix,
             const std::string& postfix,
             const std::string& infix)
            : name(n), expression(expr),
              expectedPrefix(prefix), expectedPostfix(postfix), expectedInfix(infix) {
    }
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
    // Create test cases manually instead of using initializer list (C++11 feature)
    std::vector<TestCase> testCases;

    // Test Case 1: Simple Number
    testCases.push_back(TestCase(
            "Simple Number",
            std::make_shared<Number>(5),
            "5",
            "5",
            "5"
    ));

    // Test Case 2: Simple Addition
    testCases.push_back(TestCase(
            "Simple Addition",
            std::make_shared<Addition>(
                    std::make_shared<Number>(2),
                    std::make_shared<Number>(3)
            ),
            "(+ 2 3)",
            "2 3 +",
            "(2+3)"
    ));

    // Test Case 3: Simple Multiplication
    testCases.push_back(TestCase(
            "Simple Multiplication",
            std::make_shared<Multiplication>(
                    std::make_shared<Number>(4),
                    std::make_shared<Number>(5)
            ),
            "(* 4 5)",
            "4 5 *",
            "4*5"
    ));

    // Test Case 4: Complex Expression (2 + 3) * (4 + 5)
    testCases.push_back(TestCase(
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
    ));

    // Test Case 5: Required homework case (3 + 7) * 6
    testCases.push_back(TestCase(
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
    ));

    // Run all test cases using traditional for loop instead of range-based for
    for (size_t i = 0; i < testCases.size(); ++i) {
        runTestCase(testCases[i]);
    }

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}