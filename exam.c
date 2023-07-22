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
 * Complete the 'mostActive' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY customers as parameter.
 */

/*
 * To return the string array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * char** return_string_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
 *
 *     return a;
 * }
 *
 * char** return_string_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     char** a = malloc(5 * sizeof(char*));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = malloc(20 * sizeof(char));
 *     }
 *
 *     *(a + 0) = "dynamic";
 *     *(a + 1) = "allocation";
 *     *(a + 2) = "of";
 *     *(a + 3) = "string";
 *     *(a + 4) = "array";
 *
 *     return a;
 * }
 *
 */
void Merge(char* arr[],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;
    char** L=malloc(sizeof(char *)*nL);
    char** R=malloc(sizeof(char *)*nR);
    int i;
    for(i=0; i<nL; i++)
    {
        L[i]=malloc(sizeof(arr[low+i]));
        strcpy(L[i],arr[low+i]);
    }
    for(i=0; i<nR; i++)
    {
        R[i]=malloc(sizeof(arr[mid+i+1]));
        strcpy(R[i],arr[mid+i+1]);
    }
    int j=0,k;
    i=0;
    k=low;
    while(i<nL&&j<nR)
    {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);
}
void MergeSort(char* arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}

char** mostActive(int customers_count, char** customers, int* result_count)
{
    char** names = malloc(customers_count * sizeof(char*));
    int persantage = 0 ;
    int flage = 0 ,lastflage = 0 ;
    int j = 0 ;
    //sort
    MergeSort(customers,0,customers_count-1);
    // printf("\nThe Sorted Array is: ");
    //for(int i=0; i<customers_count; i++)printf("%s\n",customers[i]);
    names[j]=malloc(sizeof(customers[0]));
    strcpy(names[j],customers[0]);
    //strcpy(names[0],customers[0] );

    for (int i = 1 ; i <customers_count ; i++ )
    {
        if (strcmp(names[j],customers[i])!=0 )
        {

            lastflage = flage ;
            flage = 0 ;
        }


        if (strcmp(names[j],customers[i])==0 )
        {
            flage++ ;
            // printf(" '%s' ,    '%s' flage : %d\n",names[j],customers[i],i);
        }
         printf("start: '%s' ,'%s' : %d \n",names[j],customers[i],flage);
        if(flage==1  )
        {
            persantage = (float)lastflage/((float)(customers_count))*(100.0) ;
            printf("%d , i : %d  j :%d\n",persantage, i ,j );
            if (persantage > 5)
            {
                j++;
                 strcpy(names[j],customers[i-1]);
                names[j]=malloc(sizeof(customers[0]));


            }

        }
    }
    for(int i=0; i<j; i++)printf("%s\n",names[i]);
    *result_count =3 ;
    return names;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int customers_count = parse_int(ltrim(rtrim(readline())));

    char** customers = malloc(customers_count * sizeof(char*));

    for (int i = 0; i < customers_count; i++)
    {
        char* customers_item = readline();

        *(customers + i) = customers_item;
    }

    int result_count;
    char** result = mostActive(customers_count, customers, &result_count);

    for (int i = 0; i < result_count; i++)
    {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1)
        {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

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
