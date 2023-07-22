
#include<stdio.h>

int main ()
{
    char string[30];
    int i, j, k ;
    int data [] = {1,2,3,4,5,6,7,8,9,10,0} ;
    char data1 [] = {'j','k',0} ;

    int size = sizeof (data)/sizeof(data[0]);
    int size1 = sizeof (string)/sizeof(string[0]);
    /*
      while (1)
      {
          StrScan(string, 30);
          Str_print(string);
          Convertletters(string);
          Str_print(string);

      }
    */
    if (strComp("mohaemd","mohaemd")==0)
    {
        printf("a7la code ya negme \n");
    }
    else
    {
        printf("norm \n");

    }
    return 0 ;
}
int strComp(char data1[], char data2[])
{
    //               0     ,    1
    for(int i = 0 ; data1[i]||data2[i] ; i ++ )
    {
        if (data1[i]!= data2[i])
        {
            return 1 ;
        }

    }
    return 0 ;
}
void Convertletters (char data [])
{
    for (int i  = 0 ; data[i] ; i ++)
    {
        if (data[i] >='A'&&data[i]<='Z' )
        {
            data[i]= data[i] +'a' -'A' ;
        }
    }
}
void StrScan(char str[],int maxSize )
{
    int i = 0  ;
    fflush(stdin);
    scanf("%c",&str[i]);

    for ( i = 0 ; str[i]!= 10 && i < maxSize-1 ;  )
    {
        i ++ ;
        scanf("%c",&str[i]);
    }
    str[i]= 0 ;
}

void printArry(int *arr, int size  )
{
    for (int i = 0 ; i < size ; i++)
    {
        printf(" %d \n", arr[i]);
    }
    printf("\n======================================================\n");

}
int Str_length(char *arr  )
{
    int i = 0 ;
    for (; arr[i]; i++ ) {}
    return i ;
}

void Str_print(char *arr  )
{

    for (int i = 0 ; arr[i] != '\0' ; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n======================================================\n");

}
