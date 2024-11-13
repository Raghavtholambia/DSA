#include <stdio.h>
#include <string.h>

void bit_stuffing(int n, int arr[])
{
    int brr[30];
    int i = 0, j = 0, k;
    while (i < n)
    {
        if (arr[i] == 1)
        {
            int count = 1;
            brr[j] = arr[i];
            for (int k = i + 1; arr[k] == 1 && k < n && count < 5; k++)
            {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5)
                {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }
        else
        {
            brr[j] = arr[i];
        }
        i++;
        j++;
        
    }
    for (int i = 0; i < j; i++)
        {
            printf("%d", brr[i]);
        }
}
void bit_unstuffing(int n, int arr[])
{
    int brr[30];
    int i = 0, j = 0, k;
    while (i < n)
    {
        if (arr[i] == 1)
        {
            int count = 1;
            brr[j] = arr[i];
            for (int k = i + 1; arr[k] == 1 && k < n && count < 5; k++)
            {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5)
                {
                    k++;
                }
                i = k;
            }
        }
        else
        {
            brr[j] = arr[i];
        }
        i++;
        j++;
        
    }
    for (int i = 0; i < j; i++)
        {
            printf("%d", brr[i]);
        }
}



int main()
{
    int n = 8;
    int arr[] = {1, 0, 1, 1, 1, 1, 1, 1};
    bit_stuffing(n, arr);
    printf("\n");
    int arr2[] = {1, 1, 1, 1, 1, 0, 1, 1};
    bit_unstuffing(n, arr2);

    return 0;
}