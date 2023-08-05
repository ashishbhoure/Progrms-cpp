#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class c_linkedlist
{
    node *start;

public:
    c_linkedlist()
    {
        start = NULL;
    }

    void print();
    void append(int);
    void addAtBeg(int);
    void addAfter(int, int);
    void del(int);
    int counter();
};

void c_linkedlist ::append(int n)
{
    node *p, *t;
    p = new node;
    p->data = n;

    t = start;

    if (t == NULL)
    {
        p->next = p;
        start = p;
        return;
    }
    while (t->next != start)
    {
        t = t->next;
    }
    t->next = p;
    p->next = start;
}

void c_linkedlist ::del(int num)
{
    node *t, *old;
    t = start;

    if (t == NULL)
        return;

    if (t->data == num)
    {
        if (t->next == t)
            start = NULL;
        else
            start = t->next;
        delete t;
        return;
    }

    t = t->next;
    old = start;

    while (t != start)
    {
        if (t->data == num)
        {
            old->next = t->next;
            delete t;
            return;
        }
        old = t;
        t = t->next;
    }
}

int c_linkedlist ::counter()
{
    node *t;
    int count = 0;
    t = start;
    if (t == NULL)
    {
        return count;
    }
    do
    {
        ++count;
        t = t->next;
    } while (t != start);
    return count;
}

void c_linkedlist ::addAfter(int num, int loc)
{

    int count = counter();
    if (loc > count || loc < 0)
    {
        cout << "\nCan't add after " << loc << " : location does not exist.";
        return;
    }

    if (loc == 0)
    {
        addAtBeg(num);
    }
    else if (loc == count)
    {
        append(num);
    }
    else
    {
        node *p, *t;
        p = new node;
        p->data = num;
        t = start;
        for (int i = 1; i < loc; i++)
        {
            t = t->next;
        }

        p->next = t->next;
        t->next = p;
    }
    cout << "\n"
         << num << " added after location : " << loc;
}

void c_linkedlist ::addAtBeg(int n)
{
    node *p, *t;
    p = new node;
    p->data = n;
    p->next = start;
    t = start;

    if (t != NULL)
    {
        while (t->next != start)
        {
            t = t->next;
        }
        t->next = p;
    }
    else
    {
        p->next = p;
    }

    start = p;
}

void c_linkedlist ::print()
{
    node *t;
    t = start;
    if (t == NULL)
    {
        cout << "\nEmpty List";
        return;
    }
    else
    {
        cout << "\n\nThe elements of linked list are : " << endl;
        do
        {

            cout << "\n"
                 << t->data;
            t = t->next;
        } while (t != start);
    }
}

int main()
{
    c_linkedlist c1;
    int n, num, loc;
    do
    {
        cout << "\n\n\t\tCHOOSE ANY OPTION";
        cout << "\n\n1. Append.";
        cout << "\n2. Print.";
        cout << "\n3. Add at Beginning.";
        cout << "\n4. Add After a location.";
        cout << "\n5. Delete a node.";
        cout << "\n\n0. EXIT";
        cout << "\n\nEnter your choice : ";
        cin >> n;

        switch (n)
        {
        case 0:
            break;
        case 1:
            cout << "\nEnter number to be appended : ";
            cin >> num;
            c1.append(num);
            break;
        case 2:
            c1.print();
            break;
        case 3:
            cout << "\nEnter the number to be added at beginning : ";
            cin >> num;
            c1.addAtBeg(num);
            break;
        case 4:
            cout << "\nEnter the number to be added : ";
            cin >> num;
            cout << "\nEnter the location to be added after : ";
            cin >> loc;
            c1.addAfter(num, loc);
            break;
        case 5:
            cout << "\nEnter the number to be deleted : ";
            cin >> num;
            c1.del(num);
            break;
        default:
            cout << "\nInvalid Choice!";
            cout << "\nPlease enter a valid number ";
        }
    } while (n != 0);
    return 0;
}