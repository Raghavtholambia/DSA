#include<iostream>
using namespace std;

int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] <= W)
    {
        return max(
            val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1), 
            knapsack(wt, val, W, n - 1)                           
        );
    }
    else
    {
        return knapsack(wt, val, W, n - 1); // Can't include
    }
}

int main(){
    cout<<"10111133323"<<endl;
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    int W = 7, n = 4;

   int ans= knapsack(wt,val,W,n);
   cout<<ans;

    return 0;

}