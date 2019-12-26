#include <iostream>
#include <cstdlib>
#include "LLQueue.h"
using namespace std;

QueueL::QueueL() {
    front = NULL;
    rear = NULL;
}

QueueL::~QueueL() {}

void QueueL::enqueue() {
   int val;
   cout<<"Insert the element in queue : "<<endl;
   cin>>val;
   if (rear == NULL) {
      rear = (Node*)malloc(sizeof(Node));
      rear->next = NULL;
      rear->data = val;
      front = rear;
   } else {
      temp=(Node*)malloc(sizeof(Node));
      rear->next = temp;
      temp->data = val;
      temp->next = NULL;
      rear = temp;
   }
}
void QueueL::dequeue() {
   temp = front;
   if (front == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = temp;
   } else {
      cout<<"Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}

void QueueL::display() {
   temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}
int main() {
    QueueL q;
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;
do {
   cout<<"Enter your choice : "<<endl;
   cin>>ch;
   switch (ch) {
      case 1: q.enqueue();
         break;
      case 2: q.dequeue();
         break;
      case 3: q.display();
         break;
      case 4: cout<<"Exit"<<endl;
         break;
      default: cout<<"Invalid choice"<<endl;
   }
} while(ch!=4);
   return 0;
}
