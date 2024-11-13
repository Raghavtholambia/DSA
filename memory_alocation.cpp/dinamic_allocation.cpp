#include<iostream>
using namespace std;

                            //new:-It is use to provide memory in heap inseed of stack.

// int sum(int *arr ,int n)
// {
//     int sum=0;
//     for (int i = 0; i < n; i++)
//     {
//         sum +=arr[i];
//     }
//     return sum;
// }
// int main()
// {
//     int n;
//     cout << "enter the no. of elements" <<endl;
//     cin >> n;
//     int*arr = new int [n];
//     for (int i = 0; i < n; i++)
//     {
//        cout << "enter no." <<endl;
//         cin >> arr[i];
//     }
//    int  ans = sum(arr,n);
//     cout << ans;
// }

 //                               //delete:- it is use to delete allocated memory by new

// int main()
// {    
    
//     int *num = new int;
//     cin >> *num;
//     cout << *num << " size:" <<sizeof(num) << endl;
//     delete num;
//     cout << *num << " size:" <<sizeof(num);
//             //int arr delete []arr            
// }                                

                                //dynamic memory allocation in 1D array (matrix)

// int main()
// {
//     int row , col;
//     cin >> row;
//     cin >>col;
//     int** arr = new int*[row];

//     for (int i = 0; i < row; i++)
//     {
//         arr[i] = new int[col];
//     }
    
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cin >> arr[i][j];
//         }    
//     }

//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             cout << arr[i][j] << " ";
//         }cout << endl;  
//     }
//     for (int i = 0; i < row; i++)
//     {
//         delete []arr[i];
//     }
//     delete []arr;
// }
