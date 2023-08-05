#include<iostream>
using namespace std;
// const int max = 5;

class queue{
    int arr[5],front,rear ,x=5;
    public:
    queue(){
        front=rear=-1;
    }
    void addq(int data);
    int delq();
    void display();
};

void queue::addq(int n){
    // int arr[max];
    if(rear==x-1){
        cout<<"queue if Fulll "<<endl;
    }
    else{
        rear++;
        arr[rear]=n;
        if(front==-1){
            front = 0;
        }
    }
}

int queue::delq(){
    // int arr[max];
    int data;
    if(front==-1){
        cout<<"Queue is empty "<<endl;
        return -1;
    }
    data = arr[front];
    arr[front] = -1;
    if(front == rear){
        front = rear =-1;
    }
    else{
        front++;
    }
    return data;
}

void queue::display()
   {
    //    int arr[max];
       if(front == -1){
           cout<<"Quene is empty "<<endl;
       }
       else{
           cout<<"Quene elemant are : ";
           for(int i=front;i<=rear;i++){
               cout<<arr[i]<<" ";
           }
           cout<<endl;
       }
   }


int main(){
    queue q;
    q.addq(5);
    q.addq(4);
    q.display();
    q.delq();
    q.delq();
    q.delq();


    return 0;
}