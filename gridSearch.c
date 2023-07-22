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
int getpos(char **data, int size, char index, int *x, int *y  )
{
    for (int i = 0 ; i < size ; i++)
    {
        if (i < *x)
        {
            continue;
        }
        for (int j= 0 ; data[i][j] ; j++)
        {
            if (i == *x&& j<=*y)
            {
                continue;
            }
            if (data[i][j] ==index )
            {
                *x = i ;
                *y = j ;
                return  1 ;
            }
        }
    }
    return 0 ;
}
char* gridSearch(int G_count, char** G, int P_count, char** P)
{
    int stx =  0 ;
    int sty = 0 ;
    int g = 0;
    int c = 0 ;
    int size = strlen(P[0]);
start:
    g = getpos(G,G_count,P[0][0],&stx,&sty );
    if (g)
    {
        for (int i = stx; i < P_count+stx ; i++)
        {
            for (int j= sty; j < size+sty&&G[i][j] ; j++)
            {
                if (P[i-stx][j-sty]==G[i][j])
                {
                    c ++ ;
                }
                else if ( i !=G_count )
                {
                    c = 0 ;
                    goto start ;
                }
            }
        }
    }
    printf("%d",c) ;

    if (c==(P_count*size))
    {
        return "YES";

    }
    return "NO";

}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        char** first_multiple_input = split_string(rtrim(readline()));

        int R = parse_int(*(first_multiple_input + 0));

        int C = parse_int(*(first_multiple_input + 1));

        char** G = malloc(R * sizeof(char*));

        for (int i = 0; i < R; i++)
        {
            char* G_item = readline();

            *(G + i) = G_item;
        }

        char** second_multiple_input = split_string(rtrim(readline()));

        int r = parse_int(*(second_multiple_input + 0));

        int c = parse_int(*(second_multiple_input + 1));

        char** P = malloc(r * sizeof(char*));

        for (int i = 0; i < r; i++)
        {
            char* P_item = readline();

            *(P + i) = P_item;
        }

        char* result = gridSearch(R, G, r, P);

        fprintf(fptr, "%s\n", result);
    }

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
