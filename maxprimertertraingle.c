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
 * Complete the 'maximumPerimeterTriangle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY sticks as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int Arrays_Merge(int arrL[], int arrR[],int sizeL,int sizeR,int arrM[])
{
    int R, L,C=0;
    for (R = 0, L = 0 ; R<sizeR && L<sizeL ; C++)
    {
        if (arrL[L]>arrR[R])
        {
            arrM[C] = arrR[R] ;
            R++ ;
        }
        else
        {
            arrM[C] = arrL[L] ;
            L++ ;
        }
    }
    for (; L<sizeL; L++)
    {
        arrM[C] = arrL[L] ;
        C ++ ;
    }
    for (; R<sizeR; R++)
    {
        arrM[C] = arrR[R] ;
        C++ ;
    }
    return sizeL+sizeR ;
}
void mergeSort(int data[],int size )
{
    int  midR = 0 ;
    int  midL =0 ;
    if (size%2==0)
    {
        midR = (size)/2 ;
        midL = (size)/2 ;
    }
    else
    {
        midR = (size)/2 + 1 ;
        midL = (size)/2 ;
    }
    if (size < 2)
    {
        return ;
    }
    int right[midR] ;
    int left[midL] ;
    for (int i = 0 ; i < midR ; i ++ )
    {
        right[i] =data[midL+i] ;
    }
    for (int i = 0 ; i < midL ; i ++ )
    {
        left[i] =data[i] ;

    }
    mergeSort(right,midR);
    mergeSort(left,midL);
    Arrays_Merge(left,right,midL,midR,data);

}


int isTriangle (int a, int b,int c )
{
    int A = b+c ;
    int B = a+c ;
    int C = a+b ;
    if (a<A && b<B&&c<C)
    {
        return 1 ;
    }
    return 0 ;
}
int* maximumPerimeterTriangle(int sticks_count, int* sticks, int* result_count)
{
    static int data [3]  = {-1} ;
    int flage = 0 ;
    unsigned int  maxperimeter = 0, perimeter = 0  ;
    mergeSort(sticks,sticks_count );
    /*
    for (int i = 0 ; i <sticks_count ;i++ ){
    printf("%d",sticks[i])  ;
    }*/
    *result_count = 3 ;
    for (int i = 0 ; i < sticks_count-2 ; i ++ )
    {
        if (isTriangle(sticks[i],sticks[i+1],sticks[i+2]))
        {
            flage = 1 ;


            perimeter = sticks[i]+sticks[i+1]+sticks[i+2] ;
            printf(" maxperimeter : %u ,perimeter : %u,  %d  , %d ,%d \n"
                   ,maxperimeter, perimeter,sticks[i],sticks[i+1],sticks[i+2]);

            if ( perimeter >maxperimeter )
            {
                maxperimeter = perimeter;

                data[0] = sticks[i];
                data[1] = sticks[i+1];
                data[2] = sticks[i+2];
            }
        }

    }
    if (flage ==0) *result_count = 1 ;
    for (int i = 0 ; i <3 ; i++ )
    {
        printf("%d",data[i])  ;
    }
    return data;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** sticks_temp = split_string(rtrim(readline()));

    int* sticks = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        int sticks_item = parse_int(*(sticks_temp + i));

        *(sticks + i) = sticks_item;
    }

    int result_count;
    int* result = maximumPerimeterTriangle(n, sticks, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1)
        {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true)
    {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line)
        {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n')
        {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data)
        {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n')
    {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data)
        {
            data = '\0';
        }
    }
    else
    {
        data = realloc(data, data_length + 1);

        if (!data)
        {
            data = '\0';
        }
        else
        {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    while (*str != '\0' && isspace(*str))
    {
        str++;
    }

    return str;
}

char* rtrim(char* str)
{
    if (!str)
    {
        return '\0';
    }

    if (!*str)
    {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end))
    {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str)
{
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token)
    {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits)
        {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str)
{
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0')
    {
        exit(EXIT_FAILURE);
    }

    return value;
}
