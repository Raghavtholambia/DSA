#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums,vector<int>output,int index,vector<vector<int>>&ans)
{
    if (index>=nums.size())
    {
        ans.push_back(output);
        return;
    }
    
    //exclude
    solve(nums,output,index+1,ans);

    //include
    int element = nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
}
int main()
{
    int el;
    vector<int>nums(5);
    cout << "enter 3 element";
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    return 0;
}