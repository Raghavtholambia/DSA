            // Sieve Of Eratosthenes

#include<bits/stdc++.h>
using namespace std;

int cntprime(int n)
{
    int cnt = 0;
    vector <bool> prime(n+1,true);
    prime[0]=prime[1]=false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
           cnt++;
           for (int j = 2*i; j < n; j=j+1)
           {
            prime[j] = 0;
           }
           
        }
        
    }
   return  cnt; 

}

int main()
{
    int n;
    cout << "enter the no. till you want to print prime no." << endl;
    cin >> n;
    cout <<  cntprime(n);
}