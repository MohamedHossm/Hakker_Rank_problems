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
 * Complete the 'separateNumbers' function below.
 *
 * The function accepts STRING s as parameter.
 */
int getDigites(int n)
{
    int i = 0 ;
    for (i = 0 ; n ; i ++ )
    {
        n = n/10 ;
    }
    return   i ;
}
long long  convertSToD(char* s, int digits,int start )
{
    long long data = 0 ;
    for (int i = start ; i < digits+start ; i ++ )
    {
        data = data *10+ s[i]-'0' ;
    }
    return data ;
}
void separateNumbers(char* s)
{
    int digits  =1 ;
    int start = 0 ;
    int pos = 0 ;
    long long arr[32] = {0};
    int len = strlen(s) ;
//long long x = convertSToD(s , digits ) ;
    int du  = 1 ;
    int j = 0 ;
    for(int i = 0 ; i < len && digits < 9 ; i +=digits,j++ )
    {
        printf("%d , %d ,%d ,%d \n",digits,du,arr[j-1], i  );
        digits = getDigites(du ) ;
        arr[j] = convertSToD(s,digits,i);
        if (j > 0 &&(arr[j-1]!=arr[j]))
        {
             printf("--%d , %d,\n",du,arr[j]) ;

                i = -1*digits ;
                du =(arr[j] * 10) ;
                j = -1;


        }
        else
        {
            du = arr[j] + 9 ;
        }
// arr[j] = convertSToD(s,digits,i);




    }
    for(int i = 0 ; i< j ; i++)
    {
        printf(" .%lld. ",arr[i]) ;
    }

    printf(" \n----------------------\n");
}

int main()
{
    separateNumbers("1000010001") ;
}
