
        //basic queue

#include<bits/stdc++.h>

using namespace std;

// int main()
// {
//     queue<string> q;

//     q.push("raghav");
//     q.push("kumar");
//     q.push("tholambia");
    
//     cout << "top element : " << q.front() << endl;
//     cout << "size before pop : " << q.size() << endl;
//     q.pop();
//     cout << "toop element : " << q.front() << endl;
//     cout << "size after pop : " << q.size() << endl;
// }

        //priority queue

// int main()
// {
//     priority_queue<int> maxi;
//     priority_queue < int,vector<int> , greater<int> >mini;
    
//     maxi.push(1);
//     maxi.push(111);
//     maxi.push(10);
//     maxi.push(4);
   
    
//     int n = maxi.size();
//     for (int i = 0; i < n; i++)
//     {
//         cout << maxi.top() << " ";
//         maxi.pop();
//     }cout << endl;

//     mini.push(1);
//     mini.push(111);
//     mini.push(10);
//     mini.push(4);

//      int m = mini.size();

//     for (int i = 0; i < m; i++)
//     {
//         cout << mini.top() << " ";
//         mini.pop();
//     }cout << endl;


//     cout << "Is it empty " << maxi.empty();
    


// }        

int main()
{
    int x;
     priority_queue<int> maxi;
    priority_queue < int,vector<int> , greater<int> >mini;
    
    // maxi.push(1);
    // maxi.push(111);
    // maxi.push(10);
    // maxi.push(4);
   for (int i = 0; i < 5; i++)
   {
        cout << "enter no. " <<endl;
        cin >> x;
        maxi.push(x);
   }
    
    int n = maxi.size();
    for (int i = 0; i < n; i++)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;
}