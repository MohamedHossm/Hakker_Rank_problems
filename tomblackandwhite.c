
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
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'taumBday' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER b
 *  2. INTEGER w
 *  3. INTEGER bc
 *  4. INTEGER wc
 *  5. INTEGER z
 */
long long min(long long  *data )
{
    long long  min = data[0] ;
    for (int i = 0; i < 3 ; i++)
    {
        if (min >data[i] )
        {
            min = data[i] ;
        }
    }
    return min ;
}
long long  taumBday(unsigned long long  b, unsigned long long w, unsigned long long bc, unsigned long long wc, unsigned long long z)
{
    /*3 6
    9 1 1*/
   unsigned long long data [3] = {0} ;
    data[0] = (bc* b) + (w * wc );
    data[1]= (bc* b) + (w * (bc+z)) ;
    data[2] = ((wc+z)* b )+ (w * wc) ;
      unsigned long long x = min(data) ;
    printf("%llu , %llu , %llu  , %llu\n", data[0], data[1],data[2], x ) ;

    return x ;
}

int main()
{
    long long  b =27984 , w=1402,bc = 619246 , wc = 615589 , z=247954  ;
    long long  x = taumBday(b, w,bc, wc, z) ;
    printf("%llu ,",x);
}
