#include <stdio.h>
int main    ()
{
    int data = 108 ;
    int count = 0 ;
    int step = 0 ;
    for (int i = 0 ; i < data ; i++)
    {
        if ((data^i)== (data+i))
        {
            count ++ ;
        }else {
        step = i ;
        }
        printf( "%d , %d , %d , %d , %d \n", data^i, data+i, i ,count,step ) ;

    }
    printf( " >>>>>>> %d \n ",count);

}
