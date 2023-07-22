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
 * Complete the 'stones' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER a
 *  3. INTEGER b
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
int* stones(int n, int a, int b, int* result_count) {
  int size = 0 ;
int *ptr =(int *) malloc (size*sizeof(int ));
int index_1 = n-1  , index_2 = 0  ;
for (  ; index_1>=0 ; index_2++,index_1-- ){
  //printf(" %d " , (a*index_1)+ (b*index_2)  );
  size++ ;
  ptr =(int *) realloc(ptr , size *(sizeof(int )));
  ptr[size-1] = (a*index_1)+ (b*index_2) ;
}

mergeSort(ptr, size);
if (a==b){
    size = 1 ;
}
for(int i = 0 ; i < size ; i++ ){
   printf(" %d " , ptr[i]);
}
  printf("\n-------------- \n");



*result_count = size ;
return ptr;
}
int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int T = parse_int(ltrim(rtrim(readline())));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        int a = parse_int(ltrim(rtrim(readline())));

        int b = parse_int(ltrim(rtrim(readline())));

        int result_count;
        int* result = stones(n, a, b, &result_count);

        for (int i = 0; i < result_count; i++) {
            fprintf(fptr, "%d", *(result + i));

            if (i != result_count - 1) {
                fprintf(fptr, " ");
            }
        }

        fprintf(fptr, "\n");
    }

    fclose(fptr);

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
