#include <iostream>
#include "LLStack.h"
using namespace std;

StackL::StackL()
{
    top = NULL;
}

StackL::~StackL() {}

void StackL::push(int val)
{
    Node *newnode = new Node();
    newnode->data = val;
    newnode->next = top;
    top = newnode;

}

void StackL::pop()
{
    if (top == NULL)
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "The popped element is " << top->data << endl;
        top = top->next;
    }
}

void StackL::display()
{
    struct Node *ptr;
    if (top == NULL)
        cout << "stack is empty";
    else
    {
        ptr = top;
        cout << "Stack elements are: ";
        while (ptr != NULL)
        {
            cout << "\n" << ptr->data;
            ptr = ptr->next;
        }
    }
    cout << endl;
}

int main()
{
    StackL s;
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            s.push(val);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            s.display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}
