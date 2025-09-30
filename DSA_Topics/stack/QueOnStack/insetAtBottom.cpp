// insert element at the bottom of the stack


#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s)
{
    if (s.empty())
    {
        s.push(69);
        cout<<s.top()<<" "<<endl;
        return;
    }
    int num=s.top();
    s.pop();
    insertAtBottom(s);
    s.push(num);

    
}

int main()
{
    stack<int> s;
    s.push(236);
    s.push(243);
    s.push(2);
    s.push(3);
    s.push(123);
    cout<<s.size()<<endl;
    insertAtBottom(s);
    cout<<s.size();
    return 0;
}