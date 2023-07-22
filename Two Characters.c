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
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
void getfreq(char s [], int freq[])
{
    for (int i = 0 ; i < 26;  i ++ )
    {
        freq[i] = 0  ;
    }
    for (int i = 0 ; s[i];  i ++ )
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            freq[s[i]-'a']++ ;
    }
}
char getmin(int freq[])
{
    int min = 20000000;
    char value = -1 ;
    for (int i = 0 ; i < 26 ; i ++ )
    {
        if (freq[i] < min&& freq[i] > 0)
        {
            min = freq[i] ;
            value = i ;
        }
    }
    return value ;
}
int countlet (int freq[])
{
    int c =  0 ;
    for (int i = 0 ; i < 26 ; i++)
    {

        if (freq[i]!=0)
        {
            c++ ;
        }
    }
    return c ;
}
void copy(char* s, char* c)
{
    int j = 0 ;
    int i = 0 ;
    for ( i = 0 ; s[i] ; i ++ )
    {
        c[i] = s[i] ;
       // j++ ;
    }
    c[i] = 0 ;
}
void copyWoz(char* s, char* c)
{
    int j = 0 ;
    for (int i = 0 ; s[i] ; i ++ )
    {
        if (s[i]=='_'){
          continue;
        }
        c[j] = s[i] ;
        j++ ;
    }
    c[j] = 0 ;
}
char chaeckrebe(char* c)
{
    for (int i = 1 ; c[i] ; i ++ )
    {
        if (c[i]==c[i-1])
            return c[i];
    }
    return -1 ;
}
void delet(char* c,  char index1 ,char index2  )
{
    for (int i = 0 ; c[i] ; i ++ )
    {
        if (c[i]!=index1&&c[i]!=index2)
            c[i] = '_' ;
    }

}
int isValid ( char data  []  ){
 for (int i = 1 ; data[i] ; i ++ ){
     if (data[i]==data[i-1]){
       return  0 ;
     }
 }
 return  1 ;
}
int alternate(char* s)
{
    int counter = 0 ;
    int freq [26] = {0} ;
    int isvalidval = 0 ;
    int countermax = 0 ;
    int check = 0 ;
    char* newOne = (char*)calloc(strlen(s),sizeof(char));
    char* newOne1 = (char*)calloc(strlen(s),sizeof(char));

    for (int i = 0 ; i < 26 ; i ++ ){
        for (int j = 0 ; j < 26 ; j ++ ){
         counter = 0 ;
            if (i == j )continue;
             getfreq (s, freq);
            if (freq[i] ==0 ||freq[j]==0)continue;
            copy(s ,newOne1 );
           delet(newOne1 , i+'a' , j+'a');
           copyWoz( newOne1, newOne);
          isvalidval = isValid( newOne );
          if (isvalidval){
            getfreq (newOne, freq);


           for (int b = 0 ; b <26 ; b++ ){
           counter+=freq[b] ;

           if (counter >countermax ){
               countermax =counter ;
           }
           }
          }
        }
    }
    return countermax;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int l = parse_int(ltrim(rtrim(readline())));

    char* s = readline();

    int result = alternate(s);

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
