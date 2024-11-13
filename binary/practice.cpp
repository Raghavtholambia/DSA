#include<bits/stdc++.h>
using namespace std;

void zero(int *arr,int *arr1,int i,int j)
{
    int cnt=0;
    if (i==9)
    {
        cout << "no solution" << endl;
        return;
    }
   while (i==9)
   {
        if (arr[i]==0)
        {
                arr1[j++]=arr[i++];
        }

        if (arr[i]==1)
        {
                arr1[j++]=arr[i++];
                cnt++;
        }

        if (cnt==5)
        {
            arr1[j]=0;
            j++;
        }        
   }
   
        return;
    
    
}
int main()
{
    int arr[10]={0,1,0,1,1,1,1,1,0,1};
    int arr1[12];
    int i=0,j=0;
    zero(arr,arr1,i,j);
    for (int i = 0; i < 13; i++)
    {
        cout << arr1[i] << endl;
    }
    
}