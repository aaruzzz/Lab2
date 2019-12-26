#ifndef LLQUEUE_H
#define LLQUEUE_H

class Node
{
public:
    int data;
    Node *next;
};

class QueueL
{
private:
    Node *front;
    Node *rear;
    Node *temp;

public:
    QueueL();
    ~QueueL();
    void enqueue();
    void dequeue();
    void display();
};
#endif
