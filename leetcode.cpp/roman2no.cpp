// C++ program to demonstrate  
// functionality of unordered_map 
// #include <iostream> 
// #include <unordered_map> 
// using namespace std; 
  
// // Driver code 
// int main() 
// { 
//   // Declaring umap to be of  
//   // <string, int> type key  
//   // will be of STRING type  
//   // and mapped VALUE will 
//   // be of int type 
//   unordered_map<string, int> umap; 
  
//   // inserting values by using [] operator 
//   umap["GeeksforGeeks"] = 10; 
//   umap["Practice"] = 20; 
//   umap["Contribute"] = 30; 
  
//   // Traversing an unordered map 
//   for (auto x : umap) 
//     cout << x.first << ": " << x.second << endl; 
// }


#include<bits/stdc++.h>
using namespace std;
int roman2Int(string s)
{
    int res=0;
    unordered_map <char,int> rom{
            {'I', 1},
            {'V', 5},
            {'X', 10}, 
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
    };
    // cout<<rom['M'];
    for (int  i = 0; i < s.size()-1; i++)
    {
        // cout<<rom[s[i]]<<endl;
        if (rom[s[i]]>rom[s[i+1]])
        {
            res=res+rom[s[i]];
        }else
        res=res-rom[s[i]];
        
    }
            return res + rom[s[s.size() - 1]];        

    
}
int main()
{
    string s="I";
    int ans= roman2Int(s);
    cout<<ans;
}