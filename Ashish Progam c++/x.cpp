#include<iostream>
using namespace std;


class node{
    public:
    int data;
    node *next;

    node(int n){
        data = n;
        next = NULL;
    }
};

void addAtBeg(int n){
    node* head=NULL;
    node *tmp ;
    tmp = new node(n);
    // tmp->data = n; 
    if(head==NULL){
        tmp->next = tmp;
        head=tmp;
        return;
    }
    node *t=head;
    while(t->next!=head){
        t=t->next;
    }
    t->next=tmp;
    tmp->next=head;
    head=tmp;
}

void display(){
    node *head=NULL;
    node *tmp=head;
    do
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }while(tmp!=head);
    cout<<endl;
}

int main(){
    // node *head=NULL;
    addAtBeg(5);
    addAtBeg(4);
    display();

    return 0;
}