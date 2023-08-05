#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class circular_ll{
    public:
        circular_ll(){
            node *head = NULL;
            int data = 0;
            next = NULL;
        }
        void addToEmpty(int);
        void addToBeg(int);
        void addToLast(int);
        void addToMid(int,int);
        void delAtBeg(int);
        void delAtMid(int,int);
        void delAtLast(int);
        void count();
        void search();
        void display();
};

void circular_ll::addToEmpty(int n){
    node *tmp = new node;
    tmp->data = n;
    tmp->next = tmp;
    
}

void circular_ll::display(){
    node *tail;
    node* p = tail->next;
    do{
        cout<<" "<<p->data;
        p = p->next;
    }while(p!=tail->next);
}


int main(){
    circular_ll cl;
    cl.addToEmpty(5);
    cl.addToEmpty();
    cl.display();


    return 0;
}