#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack <string> s;
    s.push("raghav");
    s.push("acp");
    s.push("aryan");
    cout << "size of stack : " << s.size() << endl;
    cout << "top element : " <<s.top() << endl;
    s.pop();
    cout << "top element : " <<s.top() << endl;

    cout << "size of stack : " << s.size();


}