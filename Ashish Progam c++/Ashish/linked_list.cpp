//  Program to create linked list.


#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *current = NULL;
};

class linkedlist
{
    node *head;

public:
    linkedlist()
    {
        head = NULL;
    }

    void insert(int);
    void prepend(int);
    void append(int);
    void addafter(int, int);
    void del(int);
    void sorting();
    void deleteduplicate();
    void deleteunsortdulicate();
    void reverse();
    void display();
    void count();
    bool search(int);
    ~linkedlist()
    {
        node *temp = head;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Program to insert an element in the linked list

void linkedlist::insert(int n)
{
    int length;
    cout << "\n Enter the length of node/data which u want to fill  : " << endl;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "\n Enter the value # " << i + 1 << "  : ";
        cin >> n;

        node *temp = new node, *t;
        temp->data = n;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            t = temp;
        }
        else
        {
            t->next = temp;
            t = t->next;
        }
    }
}

void linkedlist::prepend(int n)
{
    node *temp;
    temp = new node;
    temp->data = n;
    temp->next = head;
    head = temp;
}

void linkedlist::append(int n)
{

    node *temp, *t;
    temp = new node;
    temp->data = n;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

void linkedlist::addafter(int loc, int n)
{
    node *temp, *t;
    temp = new node;
    temp->data = n;
    t = head;
    for (int i = 0; i < loc; i++)
    {
        t = t->next;
        temp->next = t->next;
    }
    t->next = temp;
}

// Program to delete an element in the linked list

void linkedlist::del(int n)
{
    node *t, *old;
    t = head;
    while (t != NULL)
    {
        if (t->data == n)
        {
            if (t == head)
            {
                head = t->next;
            }
            else
            {
                old->next = t->next;
                delete t;
                return;
            }
        }
        else
        {
            old = t;
            t = t->next;
        }
    }
    cout << "\nelement ot found";
}

// Program to create sorted list.

void linkedlist::sorting()
{
    int temp;
    node *ptr, *t;
    ptr = head;
    while (ptr->next != NULL)
    {
        t = ptr->next;
        while (t != NULL)
        {
            if (ptr->data > t->data)
            {
                temp = ptr->data;
                ptr->data = t->data;
                t->data = temp;
            }
            t = t->next;
        }
        ptr = ptr->next;
    }
}

// Program to delete duplicates from unsorted list

void linkedlist::deleteduplicate()
{
    node *curr = head;
    node *next_n;
    if (curr == NULL)
    {
        return;
    }
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            next_n = curr->next->next;
            free(curr->next);
            curr->next = next_n;
        }
        else
        {
            curr = curr->next;
        }
    }
}

// Program to delete duplicates from unsorted list

void linkedlist::deleteunsortdulicate()
{
    node *t1, *t2, *temp;
    t1 = head;
    while (t1 != NULL && t1->next != NULL)
    {
        t2 = t1;
        while (t2->next != NULL)
        {
            if (t1->data == t2->next->data)
            {
                temp = t2->next;
                t2->next = t2->next->next;
                delete (temp);
            }
            else
            {
                t2 = t2->next;
            }
        }
        t1 = t1->next;
    }
}

// Program to reverse a linked linkedlist

void linkedlist::reverse()
{
    node *prev, *current, *nextnode;

    if (head == NULL)
    {
        cout << "\nList is Empty : ";
        return;
    }
    if (head->next == NULL)
    {
        cout << "only one node is there : ";
        return;
    }
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    head = prev;
}

void linkedlist::display()
{
    if (head == NULL)
    {
        cout << "\n list is empty";
    }

    node *t;
    t = head;
    while (t != NULL)
    {
        cout << " " << t->data;
        t = t->next;
    }
}

// Program to find out length of linked list.

void linkedlist::count()
{
    if (head == NULL)
    {
        cout << "\nlist is empty";
    }
    else
    {
        node *t;
        int counter = 0;
        t = head;
        while (t != NULL)
        {
            counter++;
            t = t->next;
        }
        cout << "\n Total no of node is :" << counter << endl
             << endl;
    }
}

// Program to search an element in a linked list.

bool linkedlist::search(int n)
{

    node *tmp;
    tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == n)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

int main()
{
    linkedlist ls;

    int n;
    ls.insert(n);
    ls.display();
    ls.count();

    int option;
    do
    {
        cout << "\n\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. add after()" << endl;
        cout << "4. delete()" << endl;
        cout << "5. search()" << endl;
        cout << "6. sorting()" << endl;
        cout << "7. remove duplicates in sorted list" << endl;
        cout << "8. remove duplicates in unsorted list" << endl;
        cout << "9. revrse()" << endl;
        cout << "10. distructor called()" << endl;
        cout << "11. Clear Screen" << endl;
        cout << "12. End loop" << endl
             << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\n Enter the value which u want to append : ";
            cin >> n;
            ls.append(n);
            ls.display();
            ls.count();
            break;

        case 2:
            cout << "\n Enter the value which u want to prepend : ";
            cin >> n;
            ls.prepend(n);
            ls.display();
            ls.count();
            break;

        case 3:
            int loc;
            cout << "\n Enter the location and the value where u wnd to add a data :";
            cout << "location : ";
            cin >> loc;
            cout << "value : ";
            cin >> n;
            ls.addafter(loc, n);
            ls.display();
            ls.count();

        case 4:
            cout << "\n Enter the value which u want to delete : ";
            cin >> n;
            ls.del(n);
            ls.display();
            ls.count();
            break;

        case 5:
            cout << "enter the value which u wnat to find : ";
            cin >> n;
            if (ls.search(n))
            {
                cout << "\nEntered value is found ";
            }
            else
            {
                cout << "\nEnter value is not found ";
            }
            break;

        case 6:
            cout << "\n After Srting : ";
            ls.sorting();
            ls.display();
            ls.count();
            break;

        case 7:
            cout << "\nRemove all duplicates in sorted linked list : ";
            ls.deleteduplicate();
            ls.display();
            ls.count();
            break;

        case 8:
            cout << "\nRemove all Duplicates in Unsorted linked list : ";
            ls.deleteunsortdulicate();
            ls.display();
            ls.count();
            break;

        case 9:
            cout << "\nReversed list is : ";
            ls.reverse();
            ls.display();
            ls.count();
            break;

        case 10:
            cout << "\n Destructor Calleed : ";
            ls.~linkedlist();
            ls.display();
            ls.count();
            break;

        case 11:
            system("cls");
            break;

        case 12:
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 12);

    return 0;
}
