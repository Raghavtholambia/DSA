#include<bits/stdc++.h>
using namespace std;
int main()
{
    list<int> l(5,100);

    for(int i:l)
    {
        cout << i << " ";
    }cout << endl;

    l.pop_back();

    for(int i : l)
    {
        cout << i << " ";
    }

}