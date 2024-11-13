#include<bits/stdc++.h>

using namespace std;

int main()
{
    deque<int>d;
    d.push_back(1);
    d.push_front(2);

    for(int i:d)
    {
        cout << i << " ";
    }cout << endl;

    cout << "before erase" << d.size() << endl;
      for(int i:d)
    {
        cout << i  << " ";
    }cout << endl;
    d.erase(d.begin(),d.begin()+1);
    cout << "after eraseing" << endl;
    for(int i:d)
    {
        cout << i  << " ";
    }cout << endl;
}
