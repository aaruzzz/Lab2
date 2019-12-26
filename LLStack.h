#ifndef LSTACK_H
#define LSTACK_H

class Node
{
public:
    int data;
    Node *next;
};

class StackL
{
private:
    Node *top;

public:
    StackL();
    ~StackL();
    void push(int);
    void pop();
    void display();
};
#endif
