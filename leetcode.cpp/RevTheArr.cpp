                                        //reverse the arr

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> reverse(vector <int> v)
// {
//     int s = 0;
//     int e = v.size()-1;

//     while (e >= s)
//     {
//         swap(v[s] , v[e]);
//         s++;
//         e--;
//     }
//     return v;
// }

// void print(vector<int> v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }cout << endl;
    
// }

// int main()
// {
//     int no;
//     vector <int> v;
//     int elem;

//     cout << "enter a no element" << endl;
//     cin >> no;
//     for (int  i = 0; i <= no; i++)
//     {
//         cout << "enter the element" << endl;
//         cin >> elem;
//         v.push_back(elem);
//     }

//      for (int  i = 0; i <= no; i++)
//     {
//         cout << v[i] << " ";
//     }cout << endl;

//     vector <int>ans = reverse(v);

//     cout << "after reversing the array" << endl;

//      print(ans);

//     return 0;
// }

            // reverse the arr from the give index

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> reverse(vector <int> v , int ind)
// {
//     int s = ind + 1;
//     int e = v.size()-1;

//     while (e >= s)
//     {
//         swap(v[s] , v[e]);
//         s++;
//         e--;
//     }
//     return v;
// }

// void print(vector<int> v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }cout << endl;
    
// }

// int main()
// {
//     int no;
//     vector <int> v;
//     int elem;
//     int ind;

//     cout << "enter a no element" << endl;
//     cin >> no;
//     for (int  i = 0; i <= no; i++)
//     {
//         cout << "enter the element" << endl;
//         cin >> elem;
        
//         v.push_back(elem);
//     }

//      for (int  i = 0; i <= no; i++)
//     {
//         cout << v[i] << " ";
//     }cout << endl;
//     cout << "enter the index from which you want to reverse the arr" << endl;
//     cin >> ind;

//     vector <int>ans = reverse(v , ind);

//     cout << "after reversing the array" << endl;

//      print(ans);

//     return 0;
// }

                //merge sort

// #include<bits/stdc++.h>
// using namespace std;

// int merge(int arr1[],int arr2[],int arr[],int n,int m)
// {
//     int i=0,j=0,k=0;

//     while (i<n && j<m)
//     {
//         if (arr1[i]<arr2[j])
//         {
//             arr[k++] = arr1[i++];
//         }
//         else
//         {
//             arr[k++] = arr2[j++];
//         }
     
//     }
//     while (i<n)
//         {
//             arr[k++] = arr1[i++];
//         }
        
//         while (j<m)
//         {
//             arr[k++] = arr2[j++];
//         }

   
//       for (int i = 0; i < k; i++)
//     {
//         cout << arr[i] << " " ;
//     }
    
        
// }
// int main()
// {
//     int arr1[3]={1,3,5};
//     int arr2[3]={2,4,6};
//     int arr[6] = {0};
//    merge(arr1,arr2,arr,3,3);
// }



//         zero at last problem
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int arr[6] = {1,0,3,0,4,3};
//     int j =0 ;
//     for (int i = 0; i < 6; i++)
//     {
//         if (arr[i] != 0)
//         {
//             swap(arr[j],arr[i]); 
//             j++;
//         }
        
//     }
//     for (int  i = 0; i < 6; i++)
//     {
//         cout << " " << arr[i];
//     }
    

// }



//                     rotation problem

// #include<bits/stdc++.h>
// using namespace std;


//   class rotate
//   {
//     public:
//     void rotote(vector<int>&nums , int k)
//     {
//     vector <int>temp(nums.size());
//     for (int  i = 0; i < nums.size(); i++)
//     {
//         temp[(i+k)%nums.size()] = nums[i];
//     }
//     nums = temp;
    
//     }
//   };

