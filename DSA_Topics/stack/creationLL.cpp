#include<iostream>
using namespace std;

class stack{
    public:
    int top=-1;
    stack*next;

    stack(int d)
    {
        
        this->top=d;
        this->next=NULL;
    }
     
     void intsertAtTail(stack*&tail,int d)
     {
        stack*temp=new stack(d);
        tail->next=temp;
        tail=temp;
     }

    void push(int d,stack*&tail) 
    {
        if (tail==NULL)
        {
            stack*temp=new stack(d);
            tail=temp;
        }
        
        intsertAtTail(tail,d);
        top=tail->top;
    }
    int peek()
    {
        if (top>=0)
        {
            return top;
        }
        else
        {
            cout<<"Stack Underd=flow"<<endl;
            return -1;
        }
        
        
    }
};

int main()
{
    stack s(1);
    stack*tail=NULL;

    s.push(2,tail);
    cout<<"hh";
    s.peek();
    cout<<"hh";



    
}