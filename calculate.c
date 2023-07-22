#include <stdio.h>
int main()
{
    int arr[5] = {5,9,10,7, 4} ;
    printf("%d",divisibleSumPairs(5,2,5,arr));


}
char CheckIfPowerOf_N(int data,int n )
{
    char ret = 1 ;
    if (data < 0)
    {
        data = data *-1 ;
    }
    if (n < 0)
    {
        n = n *-1 ;
    }
    for (int i = n ; i <= data ; i*=n)
    {
        if (data == i)  ret = 0 ;
    }
    return ret ;
}
int divisibleSumPairs(int n, int k, int ar_count, int* ar)
{
    ar_count = 0 ;
    for (int i = 0 ; i < n ; i ++ )
    {
        for (int j = i+1 ; j < n ; j ++ )
        {
            printf(" %d + %d = %d\n",ar[i],ar[j],ar[i]+ar[j]);

            if ((ar[i]+ar[j])%k==0)
            {
                printf("> > > %d \n",ar[i]+ar[j]);

                ar_count ++ ;
            }
        }
    }
    return ar_count;
}
