// to stack in one arrey first arrey top =-1 and the second one top =sizeof arr.

#include<iostream>
using namespace std;


class stack{

    int top1;
    int top2;
    int size;
    int *arr;

    public:
    stack(int s)
    {
        this->size=s;
        this->top1=-1;
        this->top2=s;
        arr=new int[s];
    }


    void push1(int d)
    {
        if (top2-top1>1)
        {
            top1++;
            arr[top1]=d;
        }
        else cout<<"stack OverFlow"<<endl;
        
    }
    void push2(int d)
    {
        if (top2-top1>1)
        {
            top2--;
            arr[top2]=d;
        }
        else cout<<"stack OverFlow"<<endl;
        
    }
    int peek1()
    {
        if (top1>=0)  return arr[top1];
        else return -1;
    }
    int peek2()
    {
        if (top2<size)  return arr[top2];
        else return -1;
    }

    void pop1()
    {
        if (top1>=0) top1--;
        else  cout<<"Stack under flow"<<endl;     
    }
    void pop2()
    {
        if (top2<size) top2++;
        else  cout<<"Stack under flow"<<endl;     
    }
};


int main()
{
    stack s(5);
    s.push1(2);
    s.push1(23);
    s.push1(9);
    s.pop1();
    cout<<s.peek1()<<endl;
    
    s.push2(22);
    s.push2(92);
    s.pop2();
    cout<<s.peek2()<<endl;

}