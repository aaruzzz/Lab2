#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node
{
public:
    int info;
    Node *next;
};

class LinkedList
{
private:
    Node *HEAD;
    Node *TAIL;

public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addToHead(int data);
    void addToTail(int data);
    void add(int data, Node *predecessor);
    void removeFromHead();
    void remove(int data);
    Node *retrieve(int data, Node *outputNodePointer);
    bool search(int data);
    void traverse();

    int getFromHead();
    int getFromTail();
};
#endif
