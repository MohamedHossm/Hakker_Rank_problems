#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b)
{
    int check  = 0  ;

    for (int i = 0 ; a[i]||b[i] ; i++ )
    {
        if (a[i] !=b[i])
        {
            if (a[i] < b[i])
            {
                check = 0 ;
            }
            else
            {

                check = 1 ;
            }

            break;
        }
    }
    return check;

}

int lexicographic_sort_reverse(const char* a, const char* b)
{

    int check  = 0  ;
    for (int i = 0 ; a[i]||b[i] ; i++ )
    {
        if (a[i] !=b[i])
        {
            if (a[i]< b[i])
            {
                check = 1 ;
            }
            else
            {
                check = 0 ;
            }

            break;
        }
    }
    return check;

}

int sort_by_number_of_distinct_characters(const char* a, const char* b)
{

    int freq1 [26] = {0} ;
    int freq2 [26] = {0};
    int len1 = 0 ;
    int len2 = 0 ;
    for (int i = 0 ; a[i]; i++)
    {
        freq1[a[i]-'a'] ++ ;
    }
    for (int i = 0 ; b[i]; i++)
    {
        freq2[b[i]-'a'] ++ ;
    }
    for (int i = 0 ; i<26; i++)
    {
        if (freq1[i]!=0 )
            len1 ++ ;
    }
    for (int i = 0 ; i<26; i++)
    {
        if (freq2[i]!=0 )
            len2 ++ ;
    }
    if (len1 > len2)
    {
        return 1 ;
    }
    else if (len1 < len2)
    {
        return 0 ;
    }
    else
    {
        return lexicographic_sort(a,b);
    }

}

int sort_by_length(const char* a, const char* b)
{
    int len1 = strlen(a);
    int len2 = strlen(b) ;
    if (len1 > len2)
    {
        return 1 ;
    }
    else if (len1 < len2)
    {
        return 0 ;
    }
    else
    {
        return lexicographic_sort(a,b);
    }

}
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{

    char *temp = 0   ;
    for (int i = 0 ; i < len  ; i ++ )
    {
        for (int j = 0 ; j < len-i-1  ; j ++ )
        {
            for ( int k = 0  ; k < 2500  ; k ++ )
            {

            }
            if (cmp_func(arr[j],arr[j+1])==1)
            {
                temp=arr[j]  ;
                arr[j]=arr[j+1]  ;
                arr[j+1]=temp  ;

            }
        }
    }

}

int main()
{
    int n;
    scanf("%d", &n);

    char** arr;
    arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}
