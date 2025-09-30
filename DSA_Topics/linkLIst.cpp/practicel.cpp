#include<iostream>
#include<vector>

using namespace std;

    int removeDuplicates(vector<int>& nums) {
 
        int size=nums.size();
        int arr[size]; 
        int prev = nums[0];
        int original = 0;
        for(int i=1; i <= size; i++)
        {
           if(nums[i] != prev){
            arr[original] = prev;
            prev = nums[i];
            original++;
           }
        }
        for(int i = 0; i < original; i++)
            cout<<arr[i]<<" ";
       
        return original;
    }

int main()
{
vector<int>nums={1,2,2,3,3,8};
int size = removeDuplicates(nums);
cout<<size;

// for (int i = 0; i <nums.size(); i++)
// {
//     cout<<nums[i]<<" ";
// }

}