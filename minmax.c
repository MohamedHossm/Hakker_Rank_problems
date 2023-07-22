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
 * Complete the 'maxMin' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */
int max (int arr_count, int* arr){
  int maxv = arr[0] ;
  int save = 0 ;
  for (int index_i = 1 ;index_i < arr_count; index_i++ ){
    if (maxv < arr[index_i]){
      maxv = arr[index_i];
      save = index_i ;
    }
  }


  return maxv;
}
int min (int arr_count, int* arr){
  int maxv = arr[0] ;
  int save = 0 ;
  for (int index_i = 1 ;index_i < arr_count; index_i++ ){
    if (maxv > arr[index_i]){
      maxv = arr[index_i];
      save = index_i ;
    }
  }
    arr[save] = 1000000;


  return maxv;
}
int Min (int arr_count, int* arr){
  int maxv = arr[0] ;
  int save = 0 ;
  for (int index_i = 1 ;index_i < arr_count; index_i++ ){
    if (maxv > arr[index_i]){
      maxv = arr[index_i];
      save = index_i ;
    }
  }


  return maxv;
}
int maxMin(int k, int arr_count, int* arr) {
int x = 0 ;
int *ptr = (int *)malloc(k*sizeof(int)) ;
for (int i =  0 ; i < k ; i++){
 ptr[i]=  min(arr_count ,arr);
}
for (int i =  0 ; i < k ; i++){
 printf("%d ",ptr[i]);
}
printf("\n");
int min1 = Min(k,ptr) ;
int max1 = max(k,ptr) ;
  printf("max : %d   min : %d  \n",max1 , min1);

 int r = max1 - min1;
  printf("R : %d \n",r);

return r ;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int k = parse_int(ltrim(rtrim(readline())));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(ltrim(rtrim(readline())));

        *(arr + i) = arr_item;
    }

    int result = maxMin(k, n, arr);

    fprintf(fptr, "%d\n", result);

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
