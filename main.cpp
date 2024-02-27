#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int item;
    Node *next;
    Node(int);
};

Node::Node(int i)
{
    item = i;
    next = NULL;
}

class pile
{
    Node *top;
    int sizev;

public:
    pile();
    void push(int item);
    void pop();
    int topValue();
    int isEmpty();
    void printPile();
};
int evaluate(string expression);
// start manipulation
int convertcar(char c)
{
    return c - '0';
}

int isvalue(char c)
{
    if (convertcar(c) >= 0 && convertcar(c) <= 9)
        return 1;
    return 0;
}

int isopera(char c)
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

int main()
{
    pile P;
    string str = "((((15-1)*6)-10)+1000)";
    int result = evaluate(str);
    cout << endl
         << result << endl;
}

pile::pile()
{
    sizev = 0;
    top = NULL;
}

void pile::push(int item)
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

void pile::pop()
{
    if (this->isEmpty())
        return;
    Node *temp;
    temp = this->top;
    this->top = this->top->next;
    free(temp);
}

int pile::isEmpty()
{
    if (this->sizev == 0)
        return 1;
    return 0;
}

void pile::printPile()
{
    Node *temp;
    temp = this->top;
    while (temp != NULL)
    {
        cout << "\n " << temp->item;
        temp = temp->next;
    }
}

int pile::topValue()
{
    if (!isEmpty())
    {
        return top->item;
    }
    return 0;
}

int evaluate(string expression)
{
    pile operand;
    pile operatOr;
    int i = 0;

    while (expression[i] != '\0')
    {
        if (isvalue(expression[i]))
        {
            string number;
            int j = i;
            while (isvalue(expression[j]))
            {
                number += expression[j];
                j++;
            }
            operand.push(stoi(number));
            cout << stoi(number) << "   ";
            i = j-1;
        }
        else if (isopera(expression[i]))
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
