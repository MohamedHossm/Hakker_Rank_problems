#include <stdio.h>
#include<math.h>
int reversnum(int data)
{
    int data2 = 0 ;
    for (; data;)
    {
        data2 =data2*10 + data%10 ;
        data = data/10 ;
    }
    return data2;
}
int beautifulDays(int i, int j, int k)
{
    // printf("%d , %d",i, reversnum(i)) ;
    int c = 0, result = 0,rev = 0 ;
    for (int start =i ; start<=j; start++)
    {

        rev =reversnum(start) ;
//printf(" S : %d rev: %d\n",start,rev) ;
        result = (start-rev);
        result = result<0 ?result*-1:result ;

        //printf(" res : %d rev: %d\n",result,rev) ;
        if (abs(result)%k==0)
        {
            c++;
        }
        // printf("%d ",c) ;

    }
    //printf("%d ",c) ;
    return c;
}
int main ()
{
    int i,j,k ;
    scanf("%d%d%d",&i,&j,&k);
    printf("%d\n",beautifulDays(i,j,k));
    return 0 ;
}
