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
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */
int  sumOfR(int size,int *arr)
{
    int sum = 0 ;
    for (int i = 0 ; i <size ; i++ )
    {
        sum += arr[i] ;
    }
    return sum ;
}
int sumOfC(int size, int** s,int pos)
{
    int sum = 0 ;
    for (int i = 0 ; i < size ; i++)
    {
        sum += s[i][pos] ;
    }
    return sum ;
}
int formingMagicSquare(int s_rows, int s_columns, int** s)
{
    int rows_sum = 0 ;
    int columns_sum = 0 ;
    int ret = 0 ;
//printf("%d , %d , %d \n" , sumOfR(s_rows,s[0]) ,
//sumOfR(s_rows,s[1]),sumOfR(s_rows,s[2]) ) ;
//printf("%d , %d , %d \n" , sumOfC(s_rows,s,0) ,
//sumOfC(s_rows,s,1),sumOfC(s_rows,s,2) ) ;
    for (int i = 0 ; i <s_rows; i++ )
    {
        for (int j = 0 ; j <s_rows; j++ )
        {
            rows_sum = sumOfR(s_rows,s[i]) ;
            columns_sum = sumOfC(s_rows,s,j) ;

            if (rows_sum != 15 &&columns_sum!=15)
            {
                printf("..") ;

                if (columns_sum < 15 )
                {
                  s[i][j] += (15 -rows_sum) ;
                    //ret += abs(15 -rows_sum);
                    //  printf("  : %d" ,ret ) ;
                }
                else if (rows_sum < 15 )
                {
                    s[i][j] += (15 -rows_sum) ;
                    ret += abs(15 -rows_sum);
                    //  printf("  : %d" ,ret ) ;
                }
            }
            if (rows_sum != 15&&columns_sum==15 )
            {

                s[i][j] += (15 -rows_sum) ;
                ret += abs(15 -rows_sum);
            }
            rows_sum = sumOfR(s_rows,s[i]) ;
            columns_sum = sumOfC(s_rows,s,j) ;
            printf("(R = %d, C = %d )",rows_sum,columns_sum) ;
        }
        printf("\n") ;
    }
    printf("\n-------------------------------------------------------------------\n") ;

    for (int i = 0 ; i <s_rows; i++ )
    {
        for (int j = 0 ; j <s_rows; j++ )
        {


            printf(" %d ", s[i][j]) ;
        }
        printf("\n") ;
    }

    printf("\n%d\n",ret);
    return  ret ;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++)
    {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++)
        {
            int s_item = parse_int(*(s_item_temp + j));

            *(*(s + i) + j) = s_item;
        }
    }

    int result = formingMagicSquare(3, 3, s);

    fprintf(fptr, "%d\n", result);

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
