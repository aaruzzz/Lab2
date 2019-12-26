#include <iostream>
#include "LinkedList.h"

//Singly linked list implementation
LinkedList::LinkedList()
{
    HEAD = NULL;
    TAIL = NULL;
}

LinkedList::~LinkedList() {}

//Check if the list is empty and return integer value 0 for false and 1 for true
bool LinkedList::isEmpty()
{
    return (this->HEAD == NULL);
}

//Add new data infront of the head
void LinkedList::addToHead(int data)
{
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = HEAD;
    HEAD = newNode;
    if (TAIL == NULL)
    {
        TAIL = HEAD;
    }
}

//add new data at the tail end
void LinkedList::addToTail(int data)
{
    Node *newNode = new Node();
    newNode->info = data;
    newNode->next = NULL;
    TAIL->next = newNode;
    TAIL = newNode;
}

//add item betweeen the nodes
void LinkedList::add(int data, Node *pre)
{
    Node *node = new Node();
    node->info = data;
    node->next = pre->next;
    pre->next = node;
}

//delete data from the head
void LinkedList ::removeFromHead()
{
    Node *nodeToDelet = new Node();
    nodeToDelet = HEAD;
    HEAD = nodeToDelet->next;
    delete nodeToDelet;
}

//delete data from node
void LinkedList::remove(int data)
{
    //check if list is empty
    if (this->isEmpty())
    {
        std::cout << "List was empty";
    }
    else
    {
        //check if the data present in head
        if (this->HEAD->info == data)
        {
            this->removeFromHead();
            if (this->HEAD == NULL)
                this->TAIL == NULL;
        }
        else
        {
            Node *temp = this->HEAD->next;
            Node *prev = this->HEAD;

            while (temp != NULL)
            {
                if (temp->info == data)
                {
                    //remove temp node
                    prev->next = temp->next;
                    delete temp;
                    if (prev->next == NULL)
                        this->TAIL = prev;
                }
                else
                {
                    prev = prev->next;
                    temp = temp->next;
                }
            }
        }
    }
}

// (g) retrieve(data, outputNodePointer): Returns the pointer to the node with the requested data
Node *LinkedList::retrieve(int data, Node *opPtr)
{
    //check if list is empty
    if (this->isEmpty())
    {
        std::cout << "List was empty";
        return 0;
    }
    else
    {
        //check if the data present in head
        if (this->HEAD->info == data)
        {
            *opPtr = *this->HEAD;
            return opPtr;
        }
        else
        {
            Node *temp = this->HEAD->next;
            while (temp != NULL)
            {
                if (temp->info == data)
                {
                    *opPtr = *temp;
                    return opPtr;
                }
                else
                {
                    temp = temp->next;
                }
            }
            opPtr->info = -1;
            return opPtr;
        }
    }
}

// (h) search(data): Returns true if the data exists in the list, and false otherwise
bool LinkedList::search(int data)
{
    //check if list is empty
    if (this->isEmpty())
    {
        std::cout << "List was empty";
        return 0;
    }
    else
    {
        //check if the data present in head
        if (this->HEAD->info == data)
        {
            return true;
        }
        else
        {
            Node *temp = this->HEAD->next;
            while (temp != NULL)
            {
                if (temp->info == data)
                {
                    return true;
                }
                else
                {
                    temp = temp->next;
                }
            }
            return false;
        }
    }
}

void LinkedList::traverse()
{
    //check if list is empty
    if (this->isEmpty())
    {
        std::cout << "List was empty";
    }
    else
    {
        Node *temp = this->HEAD;
        while (temp != NULL)
        {
            std::cout << temp->info << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

int LinkedList::getFromHead() { return this->HEAD->info; }
int LinkedList::getFromTail() { return this->TAIL->info; }

//end of singly linked list implementation


int main() {

    LinkedList l;
    std::cout << l.isEmpty() << std::endl; //evaluate to 1(true)
    l.addToHead(10);
    l.addToHead(20);
    l.addToTail(50);
    std::cout << l.isEmpty() << std::endl;//evaluate to 0(false)
    std::cout << l.getFromHead() << " -----> Head data" << std::endl;
    std::cout << l.getFromTail() << " -----> tail data" << std::endl;
    std::cout << l.search(20) << std::endl;
    std::cout << l.search(230) << std::endl;
    l.removeFromHead();
    std::cout << "Traversing linkedlist\n";
    l.traverse();

}
