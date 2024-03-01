
#include "evaluate.h"

// node methods
Node::Node(int i)
{
    item = i;
    next = nullptr;
}

// Stack methods
Stack::Stack()
{
    sizev = 0;
    top = NULL;
}

void Stack::push(int item)
{
    Node *N = new Node(item);

    if (this->isEmpty())
    {
        this->top = N;
        this->sizev++;
        return;
    }

    N->next = this->top;
    this->top = N;
    this->sizev++;
}

void Stack::pop()
{
    if (this->isEmpty())
        return;
    Node *temp;
    temp = this->top;
    this->top = this->top->next;
    free(temp);
}

int Stack::isEmpty()
{
    if (this->sizev == 0)
        return 1;
    return 0;
}

void Stack::printStack()
{
    Node *temp;
    temp = this->top;
    while (temp != NULL)
    {
        cout << "\n " << temp->item;
        temp = temp->next;
    }
}

int Stack::topValue()
{
    if (!isEmpty())
    {
        return top->item;
    }
    return 0;
}

// start manipulation methods

int evaluate(string expression)
{
    Stack operand;
    Stack operatOr;
    int i = 0;

    while (expression[i] != '\0')
    {
        if (isValue(expression[i]))
        {
            string number;
            int j = i;
            while (isValue(expression[j]))
            {
                number += expression[j];
                j++;
            }
            operand.push(stoi(number)); // string to int
            i = j - 1;
        }
        else if (isOperator(expression[i]))
            operatOr.push(expression[i]);

        if (expression[i] == ')')
        {
            int x = operand.topValue();
            operand.pop();
            int y = operand.topValue();
            operand.pop();
            int r = result(y, x, operatOr.topValue());
            operand.push(r);
            operatOr.pop();
        }
        i++;
    }
    return operand.topValue();
}
int convertCarToInt(char c)
{
    return c - '0';
}

int isValue(char c)
{
    if (convertCarToInt(c) >= 0 && convertCarToInt(c) <= 9)
        return 1;
    return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int result(int x, int y, char op)
{
    switch (op)
    {
    case '*':
        return x * y;
        break;
    case '+':
        return x + y;
        break;
    case '-':
        return x - y;
        break;
    case '/':
        if (y != 0)
        {
            return x / y;
        }
        printf("error !");
        return 0;
        break;
    default:
        printf("error !");
        return 0;
    }
}

// end
