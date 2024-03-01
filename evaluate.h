
#ifndef EVALUATE_H
#define EVALUATE_H

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

class Stack
{
    Node *top;
    int sizev;

public:
    Stack();
    void push(int item);
    void pop();
    int topValue();
    int isEmpty();
    void printStack();
};

int evaluate(string expression);
int convertCarToInt(char c);
int isValue(char c);
int isOperator(char c);
int result(int x, int y, char op);
int convertCarToInt(char c);
int result(int x, int y, char op);

#endif
