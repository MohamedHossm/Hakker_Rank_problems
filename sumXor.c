#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

long parse_long(char*);

/*
 * Complete the 'sumXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */

unsigned long long sumXor(    unsigned long long  n)
{
    unsigned long long   c = 0 ;
    unsigned long long   Xor = 0 ;
    unsigned long long  sum = 0 ;

    for (unsigned long long  i = 0 ; i <=n ; i ++)
    {
        Xor =  (n ^ i ) ;
        sum  =  (n + i ) ;
      //  printf("  c:   %llu  i :  %llu  Xor:   %llu  Sum :  %llu \n", c, i,Xor,sum);
        if (sum==Xor)
        {
            c ++ ;
        }
    }
    return c ;
}

int main()
{
    unsigned long long n = 0 ;
    scanf("%llu",&n);
    printf("%llu",n);

    sumXor(n);
}
