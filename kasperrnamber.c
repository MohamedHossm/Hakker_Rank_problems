
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

int parse_int(char*);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */
int   IsKaperkarnum( long long num)
{
    unsigned long long Largnum = num*num ;

    int sum = 0 ;
    int digits =  0 ;
    for (int i = 1 ; Largnum ; i ++ )
    {
        Largnum = Largnum /10 ;
        digits = i ;
    }
    Largnum = num*num  ;
  //  printf(" Largnum : %lld \n ",Largnum);

    if (num == 1 )
    {
        return 1 ;
    }
    unsigned long long power = pow(10,(digits+1)/2 ) ;
   // printf(" p : %lld \n ",power);

    sum = Largnum%power + Largnum/power  ;
   // printf("%d , %d , %d ,%d \n", Largnum%power,Largnum/power,sum, num ) ;
    if (num %power==0)
    {
        return 0 ;
    }
    if (sum == num)
    {
        return 1;
    }
    return 0 ;
}
void kaprekarNumbers(int p, int q)
{
    for (int i = p ; i <= q ; i ++ )
    {
        if (IsKaperkarnum(i))
        {
            printf("%d ",i);
        }
    }
}
int main()
{

kaprekarNumbers(1 ,99999);
   //printf("%d",IsKaperkarnum(77778 ));

}
