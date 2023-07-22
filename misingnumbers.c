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
 * Complete the 'missingNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY brr
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */
int Arrays_Merge(int arrL[], int arrR[],int sizeL,int sizeR,int arrM[])
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
void mergeSort(int data[],int size )
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
    int right[midR] ;
    int left[midL] ;
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

int * findTheDiff(int arr_count, int* arr, int brr_count, int* brr,int *result)
{
    int resultvalue = 0 ;
    int *Data =(int *)malloc(50*sizeof(int));
    int j = 0, k= 0,  s= 0 ;
    for (int  i = 0 ; i < brr_count||i < arr_count; i++)
    {
        if (arr[j]==brr[k])
        {
            j++;
            k++;
        }
        else
        {

            if (arr[j]> brr[k])
            {
                Data[s] = brr[k] ;
                k++;
                s++ ;
            }
            if (arr[j]<brr[k])
            {
                Data[s] = arr[j] ;
                j++;
                s++ ;
            }

        }
    }
    *result = s ;
    return Data ;
}
int* missingNumbers(int arr_count, int* arr, int brr_count, int* brr, int* result_count)
{
    int * d = 0 ;
    mergeSort(arr,arr_count);
    mergeSort(brr,brr_count);
    d = findTheDiff( arr_count,  arr,  brr_count,  brr, result_count);
    for (int i = 0 ; i < *result_count ; i++)
    {
        printf("%d\n",d[i]);
    }
    return d ;
}

int main()
{
    int size1 = 0 ;
    int size2 = 0 ;
    int arr1 [5000] = {0} ;
    int arr2 [5000] = {0} ;

    scanf("%d",&size1);
    for(int i = 0 ; i < size1 ; i ++ )
    {
        scanf("%d",&arr1+i);

    }
    scanf("%d",&size2);
    for(int i = 0 ; i < size2 ; i ++ )
    {
        scanf("%d",&arr2+i);

    }
    int x = 0 ;
  //  missingNumbers(size1,arr1,size2,arr2,&x) ;
}
