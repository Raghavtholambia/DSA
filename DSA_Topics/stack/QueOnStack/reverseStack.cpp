// reverse the stack using stack

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    string sh="raghav";
    stack<char> s;

    for (int  i = 0; i < sh.length(); i++)
    {
        s.push(sh[i]);
    }
    string ans="";
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();

    }
    cout<<"ans: "<<ans<<endl;

    

}