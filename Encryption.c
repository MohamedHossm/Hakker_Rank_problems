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

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
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
char* encryption(char* s) {
char newone [90] = {0} ;
char newone2D [90][90] = {0} ;
int j = 0 ;
int  squrRootR = 0;
for (int i = 0 ; s[i] ; i ++ ){
  if (s[i] != ' '){
    newone[j++] = s[i] ;
  }
}
squrRootR = (sqrt(j)+0.9) ;
j = 0 ;
printf("%s %d\n",newone , squrRootR) ;
int k = 0 ;
for (int i =  0 ; newone[j] ; i++ ){
  for ( k = 0 ; k < squrRootR &&newone[j]; k++){
    newone2D[i][k] = newone[j++] ;
  }
   //newone2D[i][k] = ' ' ;
}
for (int i =  0 ;  newone2D[i][0]  ; i++ ){
  printf("%s >> \n",newone2D[i]) ;

}
int l = 0 ;
int y = 0 ;
for (int x  =0 ; newone2D[0][x] ; x++){
  for ( y = 0 ; newone2D[y][x]; y++){
    s[l++]  = newone2D[y][x] ;
  }
   s[l++]= ' ';
}
s[l]= 0 ;
return s;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = encryption(s);

    fprintf(fptr, "%s\n", result);

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
