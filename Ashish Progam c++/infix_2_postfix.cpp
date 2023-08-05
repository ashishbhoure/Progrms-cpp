#include<iostream>
using namespace std;

class postfix{

    // int stack[100], n = 100, top = -1;
    public:

    int push(char x);
    int pop();
    int  priority(char c);

};

int postfix::push(char x)
{
    int top;
    int stack[100],n=100;
    if (top >= n - 1)
        cout << "Stack Overflow " << endl;
    else
    {
        top++;
        stack[top] = x;
    }
}

int postfix::pop()
{
int stack[100],n=100;
    int top;
    if (top <= -1)
        cout << "Stack Underflow " << endl;
    else
    {
        cout << "The popped element is : " << stack[top] << endl;
        top--;
    }
}

int postfix::priority(char x){
    if(x == '('){
        return 0;
    }
    if(x == '+' || x == '-'){
        return 1;
    }
    if(x == '*' || x == '/'){
        return 2;
    }
}

int main(){
    postfix p;
    int top = -1 , stack[100];
    char exp[20];
    char *e,x;
    cout<<"Enter the Expression :: "<<endl;
    cin>>exp;
    e=exp;
    while(*e != NULL){
        if(isalnum(*e)){
            cout<<*e;
        }
        else if(*e == '('){
            p.push(*e);
        }
        else if(*e == ')'){
            while((x = p.pop()) != '('){
                // x=p.pop();
                cout<<x;
            }
        }
        else{
            while(p.priority(stack[top]) >= p.priority(*e)){
                p.pop();
            }
            p.push(*e);
        }
        e++;
    }
    while(top != -1){
        p.pop();
    }

}