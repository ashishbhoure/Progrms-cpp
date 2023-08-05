#include<iostream>
using namespace std;

struct node{
    int p;
    int data;
    node *next;
};

struct node *front = NULL;

void insert(int n ,int p){
    node *tmp,*t;
    tmp = new node;
    tmp->data = n;
    tmp->p = p;

    if(front == NULL || p < front->p){
        tmp->next = front;
        front = tmp;
    }
    else{
        t = front;
        while(t->data != NULL && t->next->p <= p){
            t = t->next;
        }
        tmp->next = t->next;
        t->next = tmp;
    }
}

void del(){
    node *tmp;
    if(front == NULL){
        cout<<"\nQueue UnderFlow \n"<<endl;
    }
    else{
        tmp = front;
        cout<<"Deleted item is : "<<tmp->data<<endl;
        front = front->next;
        delete(tmp);
    }
}

void display(){
    node *ptr;
    ptr = front;

    if(front == NULL){
        cout<<"\nQueue is enmpty \n";
    }
    else{
        cout<<"Queue Is : "<<endl;
        cout<<"\nPriority       Item\n";
        while(ptr != NULL){
            cout<<ptr->p<<"\t\t"<<ptr->data<<endl;
            ptr = ptr->next;
        }  
    }
}

int main()
{
    int choice, n, p;  
    do  
    {  
        cout<<"1.Insert\n";  
        cout<<"2.Delete\n";  
        cout<<"3.Display\n";  
        cout<<"4.Quit\n";  
        cout<<"Enter your choice : ";  
        cin>>choice;  
        switch(choice)  
        {  
            case 1:  
                cout<<"Enter the data which is to be added in the queue : ";  
                cin>>n;  
                cout<<"Enter its priority : ";  
                cin>>p;  
                insert(n,p);  
                break;  
            case 2:  
                del();  
                break;  
            case 3:  
                display();  
                break;  
            case 4:  
            break;  
                default :  
                cout<<"Wrong choice\n";  
        }  
    }while(choice!=4);  
  
    return 0;
}