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
 * Complete the 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
int Arrays_Merge(char arrL[], char arrR[],int sizeL,int sizeR,char arrM[])
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

void mergeSort(char data[],int size )
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
    char right[midR] ;
    char left[midL] ;
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
int notmatched(char * arr1 , char *arr2 ,int len){
  int result = 0 ;
  for(int i = 0 ; arr1[i];i++){
    for (int j = 0 ; j <len ; j++ ){
      if (arr1[i]==arr2[j]){
        result ++  ;
        arr2[j] = '_' ;
        break;
      }
    }
  }
  return len-result;
}
int anagram(char* s) {
int len = strlen(s) ;
int Subsize =len/2 ;
int data =0;
char *ptr1 = (char*)malloc(Subsize*sizeof(int)) ;
char *ptr2 = (char*)malloc(Subsize*sizeof(int)) ;

if ((len&1)==1){
  data  = -1 ;
  return data;
}
for (int i = 0 ; i < Subsize ; i++){
  ptr1[i] =s[i];
  ptr2[i] =s[i+Subsize];

}
  ptr1[Subsize] =0 ;
  ptr2[Subsize] =0 ;
  mergeSort(ptr1,Subsize);
  mergeSort(ptr2,Subsize);
  printf("defore sub 1 :%s  sub 2 :%s data :  %d\n",ptr1 ,ptr2,data) ;

 data = notmatched(ptr1,ptr2,Subsize) ;
printf(" sub 1 :%s  sub 2 :%s data :  %d\n",ptr1 ,ptr2,data) ;
return data;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        char* s = readline();

        int result = anagram(s);

        fprintf(fptr, "%d\n", result);
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
