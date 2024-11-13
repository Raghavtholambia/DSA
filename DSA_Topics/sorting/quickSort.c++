
//                                                     // quick sort


// #include<iostream>
// using namespace std;

// int partial(int *arr,int s,int e)
// {
//     int pivot=arr[s];
//     int cnt=0;
//     for (int  i = s+1; i <=e; i++)
//     {
//         if (pivot>=arr[i])
//         {
//             cnt++;
//         }
//     }
//     int pivotindex =s+cnt;
//     swap(arr[pivotindex],arr[s]);

//     int fi=s,li=e;
//     while (fi<pivotindex && li>pivotindex)
//     {
//         while (arr[fi]<arr[pivotindex])
//         {
//             fi++;
//         }
//         while (arr[li]>arr[pivotindex])
//         {
//             li--;
//         }
//         if (fi<pivotindex && li>pivotindex)
//         {
//             swap(arr[fi++],arr[li--]);
//         }
        
//         return pivotindex;
        
//     }
    

// }

// void Quick_Sort(int*arr,int s ,int e)
// {
//     if (s>=e)
//     {
//         return;
//     }
//     int p=partial(arr,s,e);

//     // left part
//     Quick_Sort(arr,s,p-1);
//     // right part
//     Quick_Sort(arr,p+1,e);
// }

// int main()
// {
//     int arr[]={2,1,10,4,5,33,22,0};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     Quick_Sort(arr,0,n-1);
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i] << " ";
//     }   
// }


#include<iostream>
using namespace std;
void mergeSort(int *arr,int s,int e)
{
    if (s>=e)
    {
        return;
    }
 
    
}
int main()
{
    int arr[4]={3,1,3,22};
    mergeSort(arr,0,3);

}