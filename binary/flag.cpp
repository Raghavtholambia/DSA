#include<iostream>
using namespace std;

void bit_s(int *arr,int arr2[],int i,int j)
{
    int count =0;
    if (i==10)
    {
        return;
    }
    while (i<=10 &&j<=12)
    {
       
        if (arr[i]==1)
        {
            count++;
            arr2[j++]=arr[i++];
        }
        else
        {
             arr2[j++]=arr[i++];
        }

        if (count == 5)
        {
            arr2[j++]=arr[i++];
            j++;
            arr2[j++]=0;
        } 
        
        
        
    }
    for (int i = 0; i < 8; i++)
    {
        cout << arr2[i] << " ";
    }
    return;
}

int main()
{
    int arr[]={1,1,1,1,1,1,1,1,1,1};
    int arr2[12];
    int i=0,j=0;

    bit_s(arr,arr2,i,j);   

}