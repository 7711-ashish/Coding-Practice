#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
using namespace std;
void pop();
void push();
void display();
struct stack
{
   int item;
   int stack[size];
}s;
int top=-1;


void push()
{
    if(top==size-1)
    {
        cout<<"\n stack is full";
    }
    else
    {
        top=top+1;
        cout<<"\n\n Enter element in stack: ";
        cin>>s.item;
        s.stack[top]=s.item;
    }
}


void pop()
{
    if(top==0)
    {
        cout<<"\nStack is empty: ";
    }
    else
    {
        s.item=s.stack[top];
        top=top-1;
        cout<<"deleted data is: "cout<<s.item;
    }
}

void display()
{
    int i;
    if(top==0)
    {
        cout<<"\n Stack is empty: ";
    }
    else
    {
        for(i=top;i>0;i--)
        {
            cout<<"\n s.stack[i]";
        }
    }
}


int main()
{
    int opt ;
    while(1)
    {
        cout<<"\n\n1: push";
        cout<<"\n2: pop";
        cout<<"\n3: display";
        cout<<"\n4: exit";
        cout<<"\nEnter your choice: ";
        cin>>opt;
        if(opt>3||opt<1)
            break;
        switch(opt)
        {
            case 1:
                    push();
	                break;
            case 2:
	                pop();
	                break;
            case 3:
	                display();
	                break;
        }
    }
    return 0;
}