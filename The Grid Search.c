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
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
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
int findstring (char * data1, char * data2, int *pos )
{
    int i = 0, j = 0 ;
    *pos = -1 ;
    for (i = 0, j = 0 ; data1[i] ; )
    {
       // printf("  %d  , %d , %c , %c \n",i, j, data1 [i], data2[j] ) ;

        if (data1 [i+j]== data2[j])
        {

         //  printf("found\n ");
            j ++  ;
        }
        else if (data1 [i]!= data2[j])
        {
          //  printf("none \n ");
            i ++ ;
            j = 0  ;
        }
        else
        {
            i++ ;
        }

        if (data2[j]== 0)
        {
            *pos = i  ;
            return 1 ;
        }

    }
    return 0 ;
}
char* gridSearch(int G_count, char** G, int P_count, char** P) {
  int s = 0 ,d = 0 ,pos = 0 ,lastpos = 0 ;
  int poses [G_count] ;
  int k = 0 ;

int checkpos = 0  ;
//int x = findstring("5633845374","3845",&checkpos);

for (int i = 0 ; i < G_count && k < P_count ; i ++ ){
 s =  findstring(G[i],P[k],&pos) ;
  //k++ ;
      poses [i] = pos ;

 if ( s == 1 ){
    printf("%s     ,  %d \n", P[k] , i) ;
   k++;
   s = 0 ;
 }
}

printf("%d\n",k ) ;
for (int i = 0 ; i < P_count; i++ ){
  printf(" %d  ",poses[i] ) ;
}

return "NO";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        int R = parse_int(*(first_multiple_input + 0));

        int C = parse_int(*(first_multiple_input + 1));

        char** G = malloc(R * sizeof(char*));

        for (int i = 0; i < R; i++) {
            char* G_item = readline();

            *(G + i) = G_item;
        }

        char** second_multiple_input = split_string(rtrim(readline()));

        int r = parse_int(*(second_multiple_input + 0));

        int c = parse_int(*(second_multiple_input + 1));

        char** P = malloc(r * sizeof(char*));

        for (int i = 0; i < r; i++) {
            char* P_item = readline();

            *(P + i) = P_item;
        }

        char* result = gridSearch(R, G, r, P);

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
