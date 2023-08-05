// Program to implement stack using linked list.


#include <iostream>
using namespace std;

struct Node
{
   int data;
   Node *next;
};
class stack
{
   Node *top;

public:
   stack()
   {
      top = NULL;
   }

   void push(int n)
   {
      Node *newnode = new Node;
      newnode->data = n;
      newnode->next = top;
      top = newnode;
   }

   void pop()
   {
      if (top == NULL)
         cout << "Stack Underflow" << endl;
      else
      {
         cout << "The popped element is : " << top->data << endl;
         top = top->next;
      }
   }

   void display()
   {
      Node *ptr;

      if (top == NULL)
      {
         cout << "stack is empty";
      }
      else
      {
         ptr = top;
         cout << "Stack elements are : ";
         while (ptr != NULL)
         {
            cout << ptr->data << " ";
            ptr = ptr->next;
         }
      }
      cout << endl;
   }
};

int main()
{
   stack s;
   int ch, n;

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
         cin >> n;
         s.push(n);
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