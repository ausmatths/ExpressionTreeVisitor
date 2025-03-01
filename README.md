# Expression Tree Visitor Pattern

This project implements an expression tree using the Visitor design pattern. It allows for representing arithmetic expressions and traversing them using different visitors to produce various notations.

## Overview

The project is structured around the Visitor design pattern:

- **Expression Interface**: Abstract base class for all expression elements
- **Concrete Elements**:
    - `Number`: Represents a numeric value
    - `Addition`: Represents an addition operation with left and right operands
    - `Multiplication`: Represents a multiplication operation with left and right operands
- **Visitor Interface**: Defines methods to visit each type of expression element
- **Concrete Visitors**:
    - `PrefixVisitor`: Outputs expressions in prefix notation (Lisp-style)
    - `PostfixVisitor`: Outputs expressions in postfix notation (RPN)
    - `InfixVisitor`: Outputs expressions in traditional infix notation

## Building the Project

The project uses CMake as its build system:

```bash
# Create a build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
cmake --build .
```

## Running the Program

After building, you can run the main program:

```bash
./expression_tree
```

This will create an expression tree representing `(3+7)*6` and output it in three different notations:

```
Prefix: (* (+ 3 7) 6)
Postfix: 3 7 + 6 *
Infix: (3+7)*6
```

## Running the Tests

You can also run the tests to verify the functionality:

```bash
./run_tests
```

This will run through several test cases to confirm that the visitors correctly format different expressions.

## Directory Structure

```
ExpressionTreeVisitor/
│
├── include/                        # Header files directory
│   ├── Expression.h                # Expression interface
│   ├── Elements/                   # Concrete expression elements
│   │   ├── Number.h                # Number element
│   │   ├── Addition.h              # Addition element
│   │   └── Multiplication.h        # Multiplication element
│   ├── Visitor.h                   # Visitor interface
│   └── Visitors/                   # Concrete visitors
│       ├── PrefixVisitor.h         # Prefix notation visitor
│       ├── PostfixVisitor.h        # Postfix notation visitor
│       └── InfixVisitor.h          # Infix notation visitor
│
├── src/                            # Source files directory
│   ├── Elements/                   # Implementation of elements
│   │   ├── Number.cpp              # Number implementation
│   │   ├── Addition.cpp            # Addition implementation
│   │   └── Multiplication.cpp      # Multiplication implementation
│   ├── Visitors/                   # Implementation of visitors
│   │   ├── PrefixVisitor.cpp       # Prefix visitor implementation
│   │   ├── PostfixVisitor.cpp      # Postfix visitor implementation
│   │   └── InfixVisitor.cpp        # Infix visitor implementation
│   └── main.cpp                    # Main program entry point
│
├── test/                           # Test files directory
│   └── test_visitors.cpp           # Test cases for visitors
│
├── CMakeLists.txt                  # CMake build configuration
└── README.md                       # This file
```