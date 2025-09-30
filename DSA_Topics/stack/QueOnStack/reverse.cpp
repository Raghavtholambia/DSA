//reverse stack using recursion  


#include<iostream>
#include<stack>
using namespace std;

void insertAtBOttom(stack<int>&s,int num)
{
    if (s.empty())
    {
        s.push(num);
        return;
    }
    int a=s.top();
    s.pop();
    insertAtBOttom(s,num);
    s.push(a);

    
}

void reverse(stack<int>&s)
{
    if (s.empty())   return;
    
    int num = s.top();
    s.pop();
    reverse(s);
    insertAtBOttom(s,num);    
}

int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<endl;
    reverse(s);
    cout<<s.top()<<endl;
}