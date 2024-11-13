
// merge sort using recursion

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    // int len1 = e - mid;
    // int len2 = e - s + mid;
    int len1 =  mid-s+1;
    int len2 = e-mid;

    int *first=new int[len1];
    int *second=new int[len2];

    int mainArreyIndex=s;
    for (int i = 0; i < len1; i++)
    {
        first[i]=arr[mainArreyIndex++];
    }
     mainArreyIndex=mid+1;
    for (int i = 0; i < len1; i++)
    {
        first[i]=arr[mainArreyIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    mainArreyIndex = s;


    while (index1<len1 && index2<len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArreyIndex++]=second[index1++];
        }
        else
        {
            arr[mainArreyIndex++] = second[index2++];
        }
        
        
    }
    while (index1<len1)
        {
            arr[mainArreyIndex++]=first[index1++];
        }
        while (index2<len2)
        {
            arr[mainArreyIndex++]=second[index2++];
        }
        delete[] first;
        delete[] second;

    
    
    
}

void merge_sort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;

    merge_sort(arr, s, mid);
    merge_sort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[6] = {1,0,22,2,222,22};
    int n = 6;
    merge_sort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
       
        cout << arr[i] << " ";
    }
    return 0;
}