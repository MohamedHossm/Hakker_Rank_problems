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
 * Complete the 'happyLadybugs' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING b as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
 int Arrays_Merge(char arrL[], char arrR[],char sizeL,int sizeR,char arrM[])
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


 int  isOk(char* b){
   char change = b[0] ;
   int data = 0 ;
   for (int i = 1 ; b[i] ; i++){

        if (change == b[i]){
       data = 1 ;
     }
     else if (data==1) {
     change = b[i] ;
     data = 0 ;
     }else {
       return 0 ;
     }
     }


   return  data ;
 }

char* happyLadybugs(char* b) {
int check = 0,datacheck = 0  ;
char fre[26] = {0} ;
////mergeSort(b ,strlen(b));
int ok = isOk(b);
if (ok ){
  return "YES";
}
printf("%d\n",ok) ;
// is ok string

for (int i = 0 ; b[i] ; i ++ ){
  if (b[i]=='_'){
    check ++ ;
  }else {
    fre[b[i]-'A']++;

  }
}
for (int i = 0 ; i < 26 ; i++){
  printf(" %c  , %d \n",i+'A' , fre[i]) ;
  if (fre[i]==1){
    datacheck = 1 ;
  }
}
printf("%d , %d \n",datacheck,check) ;
if (datacheck == 1 ||check ==0 ){
  return "NO";
}

return "YES";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int g = parse_int(ltrim(rtrim(readline())));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        char* b = readline();

        char* result = happyLadybugs(b);

        fprintf(fptr, "%s\n", result);
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
