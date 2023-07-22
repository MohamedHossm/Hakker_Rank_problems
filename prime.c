#include<stdio.h>
int main()
{

    int n = 0 ;
    int c = 0 ;
    int k = 0 ;
    int data  = 0 ;
    scanf("%d",&data) ;
    for (int indexI = 0 ; indexI< data; indexI++)
    {
        fflush(stdin);
        scanf("%d",&n) ;
        k  = 1 ;
        if (n == 1 )
        {
            printf("Not prime\n") ;
            continue;
        }
         c = 0 ;
        for (int i = 2 ; i <= n/2; i++ )
        {
               k  = 1 ;
            if ((n%i) == 0 )
            {
                c++ ;
                 printf("%d\n",c) ;
                if (c == 1 )
                {
                    k  = 0 ;
                    printf(" %d Not prime\n",n) ;
                    break;
                }
            }

        }
        if (k)
            printf(" %d Prime \n",n) ;


    }

    return 0;
}
