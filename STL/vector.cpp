// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;

// int main()
// {
//     vector<int>v;
//     vector<int> a(5,1);
//     // all element is initialize with 1
//     vector <int> cpy(a);

//     cout << "print a" << endl;
//     for(int i:a)
//     {
//         cout << i << " ";
//     }cout << endl;

//     for(int i:cpy)
//     {
//         cout <<"copy of vector a"<< i << " ";
//     }cout << endl;

//     cout << v.capacity() <<endl;
//     v.push_back(1);
//     cout << v.capacity() << endl;
//     v.push_back(2);
//     cout << v.capacity() << endl;
//     v.push_back(3);
//     cout << v.capacity() << endl;

//     cout <<"element at 2 index" << v.at(2) << endl;
//     cout << "before pop" << endl;

//     for(int i:v)
//     {
//         cout << i << " ";
//     }cout << endl;

//     v.pop_back();
//     cout << "after pop" << endl;

//     for(int i:v)
//     {
//         cout << i << " ";
//     }cout << endl;

// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> arr = {1, 2, 2222, 21, 1};
//     sort(arr.begin(), arr.end());
//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     int s = 0, e = arr.size(), key = 2222;
//     while (s <= e)
//     {
//         int mid = (s+e) / 2;
//         if (arr[mid] == key)
//         {
//             cout<<mid;
//             return 0;
//         }
//         if (arr[mid] < key)
//             s = mid + 1;

//         else
//          e = mid - 1;
//     }

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// bool find_element(int x,int y, vector<int>& A, int i,int cnt=0) {
    
    
//     if (i == A.size()) {
//         return false;
//     }
//     if (A[i] == x || A[i]==y) {
        
//         return find_element(x,y, A, i + 1,cnt+1);

//     }
//     cout<<cnt;
//     if(cnt==2){
//         return true;
//     }
//     return find_element(x,y, A, i + 1,cnt);
// }

// int main() {
//     vector<int> A = {7, 3, 5, 2, 1};
//     int x,y;
//     cin >> x>>y;
//     int i = 0;
//     bool opt = find_element(x,y, A, i);
//     if (opt)
//         cout << "YES";
//     else
//         cout << "NO";

//     return 0;
// }


#include<iostream>
using namespace std;
// int lgtString(string s){
//     int size=s.size();
//     int cnt=0,j;
//     char* arr = new char[size + 1];
//     for (int  i = 0; i < s.size(); i++)
//     {
//         arr[i]=s[i];
//         cnt++;
//         if (i==0)
//         {
//             i++;
//         }

//         else{
//             j=i;
//            while (j--)
//            {
//             cout<<"size:"<<size<<endl;
//             if (arr[i]==arr[j])
//             {
//                 return cnt;
//             }
            
//            }
            
//         }
        
//     }
         
// }

int lgtstring(string s){
    int cnt =0;
    int Alpha[26] = {0};
    for (int  i = 0; i < s.size(); i++)
    {
        int index=s[i]-'a';
        if (Alpha[index]>0)
        {
            return cnt;
        }else{
            Alpha[index]++;
            cnt++;
        }
        
    }
    return cnt;
}
int ReturnFirstUniqueCount(string s){
    int maxCount = -1;
    int count = 0;
    int Alpha[26] = {0};
    int increment = 1;
    for(int i = 0; i < s.size(); i++){
        int index = s[i] - 'a';
        if(Alpha[index] > increment - 1)
        {
            increment++;
            count = 0;
        }
        if(Alpha[index] == increment-1)
            Alpha[index]++;
            else Alpha[index] = Alpha[index] + increment;
            count++;
            maxCount = max(count,maxCount);
    }
    return maxCount;
}





int main()
{
    string s = "pwwkesdchew";
    
    int cnt=ReturnFirstUniqueCount(s);
    cout<<cnt<<endl;
    cout<<lgtstring(s);
    
    return 0;
}
