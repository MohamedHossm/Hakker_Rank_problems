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
void creatmagicsquare ( int size, int value, int posx,int posy) ;
void Add_Big_int  (int  * digits,int *sizemain, int *convert, int size  ) ;
int calculateDigits(long long );
int converttoArr( int *arr, long long  data ) ;
long long  power(int base, int data ) ;
char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
int calculate_Size_print(int *data)
{
    int flage = 1 ;
    int j = 0 ;
    for ( int i = 299 ; flage ; i--)
    {
        j = i ;
        if (data[i]!=0)
        {
            flage = 0 ;
        }
    }
    return j ;
}
void copyArr(int* dataS,int* dataD)
{
    for (int i = 0 ; i < 300 ; i ++ )
    {
        dataD[i] = dataS[i] ;
    }
}
void Bigmult (int data1, int* data2,int *ptr, int * digits  )
{

    for (int i = 1 ; i < data1 ; i ++ )
    {
        Add_Big_int(digits, ptr, data2,300);
    }
}
void Add_Big_int  (int  * digits,int *sizemain, int *convert, int size  )
{

    //int dig = 0 ;
    //int size_1 = *sizemain ;
    int carry = 0 ;
    int i = 0 ;
    int c = 0 ;
    for ( i = 0 ; i < size ; i++ )
    {
        digits[i] += carry ;
        carry = 0 ;
        carry =  digits[i] + convert[i] ;

        if (carry > 9 )
        {
            digits[i] = carry %10 ;
            carry = 1 ;
            c++ ;
        }
        else
        {
            digits[i] += convert[i] ;
            carry = 0 ;
            c++ ;
        }
        if (i == size-1 && carry==1)
        {
            size++;
        }

    }
    *sizemain = i ;

}

int converttoArr( int *arr, long long  data )
{
    int lem = calculateDigits(data);
    int i  = 0 ;
    //printf("....%d\n",lem );
    for ( i = 0 ; i<lem ; i++)
    {
        arr[i] =  data%10 ;
        data /=10 ;
    }
    return lem ;
}
int calculateDigits(long long  data )
{
    int i = 0 ;
    for ( i = 0 ; data ; i++)
    {
        data = data/10 ;
    }
    return i ;
}


void extraLongFactorials(int n) {
   int digits[300] = {0} ;
    int convert[300] = {0} ;
    int data = converttoArr(convert, 1);
    //int arr [3][3] = {0} ;
    // creatmagicsquare (   3, 4,0,0) ;
    int x = 100;
    //int mult = 5 ;
    Add_Big_int(digits, &x, convert,data );

    for (int i = 0 ; i <= n ; i++)
    {
        Bigmult (i,convert,&x,digits);
        copyArr(digits,convert ) ;
    }
    int cal = calculate_Size_print(digits);

    for (int i = cal ; i >=0 ; i -- )
    {
        printf("%d",digits[i]);
    }
}








int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    extraLongFactorials(n);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
