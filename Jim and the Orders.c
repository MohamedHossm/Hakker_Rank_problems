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
 * Complete the 'jimOrders' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY orders as parameter.
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
 typedef struct compare CC;
 struct compare{
   int order ;
   int num ;
   int preperetime ;
   int total ;
 };
 int Arrays_Merge(CC arrL[], CC arrR[],int sizeL,int sizeR,CC arrM[])
{
    int R, L,C=0;
    for (R = 0, L = 0 ; R<sizeR && L<sizeL ; C++)
    {
        if (arrL[L].total > arrR[R].total)
        {
            arrM[C].total = arrR[R].total ;
            arrM[C].preperetime = arrR[R].preperetime ;
            arrM[C].order = arrR[R].order ;
            arrM[C].num = arrR[R].num ;

            R++ ;
        }
        else
        {
            arrM[C].total = arrL[L].total ;
            arrM[C].preperetime = arrL[L].preperetime ;
            arrM[C].order = arrL[L].order ;
            arrM[C].num = arrL[L].num ;
            L++ ;
        }
    }
    for (; L<sizeL; L++)
    {
         arrM[C].total = arrL[L].total ;
          arrM[C].preperetime = arrL[L].preperetime ;
          arrM[C].order = arrL[L].order ;
          arrM[C].num = arrL[L].num ;
        C ++ ;
    }
    for (; R<sizeR; R++)
    {
         arrM[C].total = arrR[R].total ;
          arrM[C].preperetime = arrR[R].preperetime ;
          arrM[C].order = arrR[R].order ;
          arrM[C].num = arrR[R].num ;

        C++ ;
    }
    return sizeL+sizeR ;
}

void mergeSort(CC data[],int size )
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
    CC right[midR] ;
    CC left[midL] ;
    for (int i = 0 ; i < midR ; i ++ )
    {
        right[i].total =data[midL+i].total ;
        right[i].preperetime =data[midL+i].preperetime ;
        right[i].order =data[midL+i].order ;
        right[i].num =data[midL+i].num ;

    }
    for (int i = 0 ; i < midL ; i ++ )
    {
        left[i].total =data[i].total ;
        left[i].preperetime =data[i].preperetime ;
        left[i].order =data[i].order ;
        left[i].num =data[i].num ;


    }
    mergeSort(right,midR);
    mergeSort(left,midL);
    Arrays_Merge(left,right,midL,midR,data);

}
int* jimOrders(int orders_rows, int orders_columns, int** orders, int* result_count) {
CC data[orders_rows] ;
int *arr = (int*)malloc(orders_rows*sizeof(int)) ;
for (int i = 0 ; i < orders_rows ; i  ++ ){
   data[i].num = i +1 ;
  data[i].order = orders[i][0] ;
  data[i].preperetime = orders[i][1] ;
 data[i].total = data[i].preperetime + data[i].order ;
}
mergeSort(data ,orders_rows );
for (int i = 0 ; i < orders_rows ; i  ++){
  arr[i] = data[i].num ;
  printf(" %d  , %d , %d \n",data[i].total,data[i].preperetime,data[i].order) ;
}

*result_count = orders_rows;
return arr;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int** orders = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        *(orders + i) = malloc(2 * (sizeof(int)));

        char** orders_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++) {
            int orders_item = parse_int(*(orders_item_temp + j));

            *(*(orders + i) + j) = orders_item;
        }
    }

    int result_count;
    int* result = jimOrders(n, 2, orders, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
