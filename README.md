# Evaluation Program

This simple C++ program demonstrates the evaluation of mathematical expressions using a stack-based approach. The program utilizes a custom stack implementation for integer values and basic arithmetic operations.

## Usage

```bash
git clone 'git@github.com:AbderrahimeEl/ExpressionEvaluator.git' && cd ExpressionEvaluator
```
```bash
g++ main.cpp evaluate.cpp -o main
```
```bash
./main
```


## Files

- `evaluate.h`: Header file containing declarations of classes and functions used in the program.
- `evaluate.cpp`: Implementation file containing definitions of classes and functions used in the program.
- `main.cpp`: Main file containing the `main()` function to execute the program.

## Classes

### Node
Represents a node in a singly linked list.
- Attributes:
  - `item`: Integer value stored in the node.
  - `next`: Pointer to the next node.
- Methods:
  - `Node(int i)`: Constructor to initialize a node with an integer value.

### Stack
Represents a stack data structure implemented using linked lists.
- Attributes:
  - `top`: Pointer to the top of the stack.
  - `sizev`: Size of the stack.
- Methods:
  - `Stack()`: Constructor to initialize an empty stack.
  - `void push(int item)`: Pushes an item onto the stack.
  - `void pop()`: Pops an item from the top of the stack.
  - `int topValue()`: Returns the value at the top of the stack.
  - `int isEmpty()`: Checks if the stack is empty.
  - `void printStack()`: Prints the elements of the stack.

## Functions

1. `int evaluate(string expression)`: Evaluates a given arithmetic expression in postfix notation and returns the result.
2. `int convertCarToInt(char c)`: Converts a character representing a digit to an integer.
3. `int isValue(char c)`: Checks if a character represents a numeric value.
4. `int isOperator(char c)`: Checks if a character represents an arithmetic operator.
5. `int result(int x, int y, char op)`: Computes the result of an arithmetic operation between two operands.

## Example

`(((((15-10)*4)+100)+1000)/2) = 560`

**Note:**

- Ensure that the input expression is properly formatted in postfix notation.
- Division by zero results in an error message.
