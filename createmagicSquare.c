#include <stdio.h>
#define BIGINTMAX 500
void creatmagicsquare ( int size, int value, int posx,int posy) ;
int Add_Big_int  (int  * digits,int *sizemain, int *convert, int size  ) ;
int calculateDigits(long long );
int converttoArr( int *arr, long long  data ) ;
long long  power(int base, int data ) ;
int main ()
{
    int digits[BIGINTMAX] = {0} ;
    int convert[BIGINTMAX] = {0} ;
    int data = converttoArr(convert,500);
    converttoArr(digits,500);

    //int arr [3][3] = {0} ;
    // creatmagicsquare (   3, 4,0,0) ;
    int x = 0;
    int inputdata = 5 ;

    Add_Big_int(digits, &x, convert,data );
/*
    for (int i = 0 ; i <= inputdata ; i++)
    {
        Bigmult (i,convert,&x,digits);
        copyArr(digits,convert ) ;
    }
*/
    int cal = calculate_Size_print(digits);

    for (int i = cal ; i >=0 ; i -- )
    {
        printf("%d",digits[i]);
    }

    return 0 ;
}
int calculate_Size_print(int *data)
{
    int flage = 1 ;
    int j = 0 ;
    for ( int i = BIGINTMAX-1 ; flage ; i--)
    {
        j = i ;
        if (data[i]!=0)
        {
            flage = 0 ;
        }
    }
    return j ;
}
void copyArr(int* dataS,int* dataD)
{
    for (int i = 0 ; i < BIGINTMAX ; i ++ )
    {
        dataD[i] = dataS[i] ;
    }
}
void Bigmult (int data1, int* data2,int *ptr, int * digits  )
{

    for (int i = 1 ; i < data1 ; i ++ )
    {
        Add_Big_int(digits, ptr, data2,BIGINTMAX);
    }
}
int Add_Big_int  (int  * digits,int *sizemain, int *convert, int size  )
{


    //int size_1 = *sizemain ;
    int carry = 0 ;
    int i = 0 ;

    for ( i = 0 ; i < size ; i++ )
    {
        digits[i] += carry ;
        carry = 0 ;
        carry =  digits[i] + convert[i] ;

        if (carry > 9 )
        {
            digits[i] = carry %10 ;
            carry = 1 ;

        }
        else
        {
            digits[i] += convert[i] ;
            carry = 0 ;

        }

                if (i == size-1 && carry==1)
                {
                    size++;
                }

    }
    //  *sizemain = i ;

}
int converttoArr( int *arr, long long  data )
{
    int lem = calculateDigits(data);
    int i  = 0 ;
    //printf("....%d\n",lem );
    for ( i = 0 ; i<lem ; i++)
    {
        arr[i] =  data%10 ;
        data /=10 ;
    }
    return lem ;
}
int calculateDigits(long long  data )
{
    int i = 0 ;
    for ( i = 0 ; data ; i++)
    {
        data = data/10 ;
    }
    return i ;
}









void creatmagicsquare ( int size, int value, int posx,int posy )
{
    int arr [3][3] = {0} ;
    int row = posx;
    int count = 1 ;
    int col = posy ;
    arr[row][col] = value;

    for (; count<=9;)
    {
        if ((arr[row][col]%size)==0)
        {
            col ++ ;
        }
        else
        {
            row ++ ;
            col -- ;
        }
        if (col==size)
        {
            col =  0  ;

        }
        if (col==-1)
        {
            col =  size-1 ;
        }
        if (row==-1)
        {
            row =  size-1  ;

        }
        if (row==size)
        {
            row =  0  ;

        }

        value++ ;
        if (value > 9 )
        {
            value = value -9 ;
        }
        arr[row][col]  = value ;
        count++ ;
    }
    for (int i = 0 ; i < 3 ; i++ )
    {
        for (int j = 0 ; j < 3 ; j++)
        {
            printf("%-3d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n----------------------------------------------------------------\n");
}
