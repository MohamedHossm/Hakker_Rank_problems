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
 * Complete the 'marcsCakewalk' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY calorie as parameter.
 */
void sort (int calorie_count, long long * calorie)
{
    int temp = 0 ;
    for (int i = 0 ; i < calorie_count ; i ++ )
    {
        for (int j = 0 ; j < calorie_count-i  -1; j ++ )
        {
            if (calorie[j] < calorie[j+1] )
            {
                temp = calorie[j] ;
                calorie[j] = calorie[j+1] ;
                calorie[j+1] = temp ;
            }
        }
    }
}
long long Power(int data, int power)
{
    long long redult  =  1 ;
    if (power==0 )
    {
        return 1 ;

    }
    for (int i = 0 ; i < power ; i ++ )
    {
        redult = redult *data ;
    }
    return redult ;
}
long long  marcsCakewalk(int calorie_count, long long * calorie)
{
    unsigned  long long  resulte = 0 ;
    sort(calorie_count,  calorie) ;
    for (int i = 0 ; i < calorie_count ; i++)
        printf("calories : %d ",calorie[i] );
    for (int i = 0 ; i< calorie_count ; i++)
    {
        resulte = resulte + (Power(2, i) *calorie[i]) ;
    }
    printf(" resulte : %llu",resulte);
    return  resulte ;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** calorie_temp = split_string(rtrim(readline()));

    long long * calorie = malloc(n * sizeof( long long  ));

    for (int i = 0; i < n; i++)
    {
        int calorie_item = parse_int(*(calorie_temp + i));

        *(calorie + i) = calorie_item;
    }

    long result = marcsCakewalk(n, calorie);

    fprintf(fptr, "%ld\n", result);

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
