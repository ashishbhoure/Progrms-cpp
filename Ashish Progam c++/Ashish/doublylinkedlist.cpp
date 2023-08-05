#include<iostream>
using namespace std;

struct node
{
    int data;
    node *prev ,*next;
};

class dlinkedlist{
    node *head ,*end;
    public:
        dlinkedlist(){
            head=end=NULL;
        }
    
    void insert(int);
    void prepend(int);
    void append(int);
    void addafter(int,int);
    void delAtBegning();
    void delATLast();
    void del(int);
    bool search(int);
    void search_backword(int);
    void remove_duplicate();
    bool palindrome();
    void sort();
    int lagrest_node();
    void reverse();
    void display();
    void traverse_backword();
    int count();
};

void dlinkedlist::insert(int n)
{int length;
    cout << "\n Enter the length of node/data which u want to fill  : " << endl;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "\n Enter the value # " << i + 1 << "  : ";
        cin >> n;
    node *t, *temp;
    temp = new node; 
    temp->data = n;
    temp->next = NULL;
    if (head == NULL)
    {
        temp->prev = NULL;
        head = temp;
    }
    else
    {
        t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
        temp->prev = t;
    }
    }
}

void dlinkedlist::prepend(int n){
    node *temp=new node;
    temp->data=n;
    temp->prev=NULL;
    temp->next=head;
    if(head!=NULL){
        head->prev=temp;
    }
    head=temp;
}

void dlinkedlist::append(int n){
    node *temp,*t;
    temp=new node;
    temp->prev=NULL;
    temp->data=n;
    temp->next=NULL;
    t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=temp;
    temp->prev=t;
}

void dlinkedlist::addafter(int loc,int n){
    int c=count();
    if(loc<0 || loc>c){
        cout<<"Invalid Loction"<<endl;
    }
    else{
        if(loc==0){
            prepend(n);
        }
        else if(loc==c){
            append(n);
        }
        else{
            node *temp,*t;
            temp=new node;
            temp->data=n;
            t=head;
            for(int i=1;i<loc;i++){
                t=t->next;
            }
            t->next->prev=temp;
            temp->next=t->next;
            temp->prev=t;
            t->next=temp;
        }
    }
}

void dlinkedlist::del(int n){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data==n){
            if(temp==head){
                if(head->next==NULL){
                    head=end=NULL;
                }
                else{
                    head=head->next;
                    head->prev=NULL;
                }
            }
            else{
                if(temp->next==NULL){
                    temp->prev->next=NULL;
                    end=temp->prev;
                }
                else{
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                }
            }
            delete temp;
            return;
        }
        temp=temp->next;
    }
    cout<<"\nElemenet not found : "<<endl;
}

void dlinkedlist::delAtBegning(){
    node* tmp;
    if(head==NULL){
        cout<<"Under FLow"<<endl;
    }
    else if(head->next==NULL){
        head=NULL;
        free(head);
        cout<<"Node Deleted"<<endl;
    }
    else{
        tmp=head;
        head=head->next;
        head->prev=NULL;
        free(tmp);
        cout<<"Node Deleted"<<endl;
    }
}


void dlinkedlist::delATLast(){

    node *tmp,*t;
    if(head==NULL){
        cout<<"Under Flow"<<endl;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        cout<<"Node Deleted"<<endl; 
    }
    else{
        tmp=head;
        while(tmp->next!=NULL){
            t=tmp;
            tmp=tmp->next;
        }
        free(tmp);
        t->next=NULL;
        cout<<"Node Deleted"<<endl;
    }
}

void dlinkedlist::reverse()
{
    node *t1, *t2;
    t1 = head;
    t2 = t1->next;
    t1->next = NULL;
    t1->prev = t2;
    while (t2 != NULL)
    {
        t2->prev = t2->next;
        t2->next = t1;
        t1 = t2;
        t2 = t2->prev; 
    }
    head = t1;
    cout<<"List Reversed"<<endl; 
}

int dlinkedlist::count(){
    node *temp=head;
    int c=0;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}

bool dlinkedlist::palindrome(){
    node *left=head;
    if(left==NULL){
        return true;
    }
    node *right=left;
    while(right->next!=NULL){
        right=right->next;
    }
    while(left!=right && right!=left->prev)
    {
        if(left->data!=right->data){
            cout<<"\n|| The List Is Not A Palimdorme || "<<endl;
            return false;
        }
        left=left->next;
        right=right->prev;
    }
    cout<<"\n|| The List Is Palindrome ||"<<endl;
    return true;    
}

int dlinkedlist::lagrest_node(){
    node *max,*tmp;
    tmp=max=head;
    while (tmp!=NULL)
    {
        if(tmp->data > max->data){
            max=tmp;
        }
        tmp=tmp->next;
    }
    cout<<endl<<max->data<<endl;
    return max->data;
}

bool dlinkedlist::search(int n){
    node *tmp;
    tmp=head;
    while(tmp!=NULL){
        if(tmp->data==n){
            cout<<"\nElement fount at position : "<<tmp->data<<endl;
            return true;
        }
        tmp=tmp->next;  
        
    }
    cout<<"\n Element not found :- ";
    return false;
}

void dlinkedlist::search_backword(int n){
    node* tmp;
    int pos=0;
    tmp=head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    while(tmp!=NULL){
        pos++;
        if(tmp->data==n){
            cout<<"Found at position : "<<tmp->data<<endl;
            return ;
        }
        if(tmp->prev!=NULL){
            tmp=tmp->prev;
        }
        else{
            break;
        }
        cout<<"Element Not Found  "<<endl;
        return ;
    }
}

void dlinkedlist::remove_duplicate(){
    node* tmp,*t,*i;
    if(head==NULL){
        cout<<"List is Empty : "<<endl;
        return;
    }
    else{
        for(tmp=head;tmp!=NULL;tmp=tmp->next){
            for(i=tmp->next;i!=NULL;i=i->next){
                if(tmp->data==i->data){
                    t=i;
                    i->prev->next=i->next;
                    if(i->next!=NULL){
                        i->next->prev=i->prev;
                        t=NULL;
                    }
                }
            }
        }
    }
}

void dlinkedlist::sort(){
    node *tmp=NULL,*t=NULL;
    int p;
    if(head==NULL){
        cout<<"List is Empty : ";
        return;
    }
    else{
        for(tmp=head;tmp->next!=NULL;tmp=tmp->next){
            for(t=tmp->next;t!=NULL;t=t->next){
                if(tmp->data>t->data){
                    p=tmp->data;
                    tmp->data=t->data;
                    t->data=p;
                }
            }
        }
    }
}

void dlinkedlist::display(){
    if(head==NULL)
      cout<<"List is empty";
    node *t;
    t=head;
    cout<<endl;
    while(t!=NULL)
    {
        cout<<" "<<t->data;
        t=t->next;
    }
}

void dlinkedlist::traverse_backword(){
    node *tmp=head;
    if(head==NULL){
        cout<<"empty list "<<endl;
        return;
    }
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    while(tmp!=NULL){
        cout<<" "<<tmp->data;
        tmp=tmp->prev;
    }
}

int main(){
    dlinkedlist dl;
    int n,choice,loc;
    dl.insert(n);
    dl.display();  

    node *head;
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;         
        cout<<"1.Add at begning"<<endl;
        cout<<"2.Add at last"<<endl;
        cout<<"3.Add after position"<<endl;
        cout<<"4.Delete At beginning"<<endl;
        cout<<"5.Delete"<<endl;
        cout<<"6.Delete At Last"<<endl;
        cout<<"7.Remove Duplicates"<<endl;
        cout<<"8.Palindrome()"<<endl;
        cout<<"9.Sort the list"<<endl;
        cout<<"10.Largest Node"<<endl;
        cout<<"11.Reverse"<<endl;
        cout<<"12.Search()"<<endl;
        cout<<"13.Search From Backward direction"<<endl;
        cout<<"14.Display"<<endl;
        cout<<"15.Traverse From Backward"<<endl;
        cout<<"16.Count"<<endl;
        cout<<"17.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: \n";
            cin>>n;
            dl.prepend(n);
            dl.display();
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: \n";
            cin>>n;
            dl.append(n);
            dl.display();
            cout<<endl;
            break;
        case 3:
            cout<<"\nInsert Element after postion: \n";
            cin>>loc;
            cout<<"\nEnter the element: \n";
            cin>>n;   
            dl.addafter(loc,n);
            dl.display();
            cout<<endl;
            break;
        case 4:
            dl.delAtBegning();
            dl.display();
            break;
        case 5:
            if (head == NULL)
            {                      
                cout<<"List empty,nothing to delete\n"<<endl;   
                break;
            }
            cout<<"Enter the element for deletion: \n"<<endl;
            cin>>n;
            dl.del(n);
            dl.display();
            cout<<endl;
            break;
        case 6:
            dl.delATLast();
            dl.display();
            break;
        case 7:
            dl.remove_duplicate();
            cout<<"\nAfter Removing Duplicates"<<endl;
            dl.display();
            break;
        case 8:
            dl.palindrome();
            dl.display();
            break;
        case 9:
            cout<<"\nSorted list is : "<<endl;
            dl.sort();
            dl.display();
            break;
        case 10:
            cout<<"\nLargest Node is : "<<endl;
            dl.lagrest_node();
            dl.display();
            break;
        case 11:
            if (head == NULL)
            {
                cout<<"List empty,nothing to reverse\n"<<endl;
                break;
            }
            dl.reverse();
            dl.display();
            cout<<endl;
            break;
        case 12:
            cout<<"\nEnter element you want to search : \n";
            cin>>n;
            dl.search(n);
            break;
        case 13:
            cout<<"\nEnter element you want to search : \n";
            cin>>n;
            dl.search_backword(n);
            dl.display();
            break;
        case 14:
            dl.display();
            cout<<endl;
            break;
        case 15:
            cout<<"\nTreaverse from back side : "<<endl;
            dl.traverse_backword();
            break;
        case 16:
            cout<<"\nNumber of elements are: \n"<<dl.count()<<endl;
            break;   
        case 17:
            exit(1);
        default:
            cout<<"Wrong choice\n"<<endl;
        }
    }
    return 0;
}
