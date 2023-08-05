#include "iostream"
using namespace std;

struct Node{

    struct Node* prev;
    int data;
    struct Node* next;

};
class stack{

    Node* top ;
    public:
    stack(){
        top =NULL;
    }

    void push(int data){

        Node* newnode;
        newnode = new Node();

        if(!newnode){
            cout << "Stack Overflow" << endl;
        }

        newnode->prev = top;
        newnode->data = data;  
        newnode->next = NULL;

        top = newnode;
    }

    void pop(){

        if(top == NULL){
            cout << "Stack Underflow";
            exit(1);
        }

        Node* tmp;
        tmp = new Node();

        tmp->next = NULL;
        tmp->data = top->prev->data;
        tmp->prev = top->prev->prev;

        free(top);
        top = tmp;

    }

    void display(){

        Node* ptr;
        ptr = top;

        cout << ptr->data << " ";
        while(ptr->prev != NULL){
            cout << ptr->prev->data << " ";
            ptr = ptr->prev;
        }
        cout << endl;
    }
};

int main(){

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