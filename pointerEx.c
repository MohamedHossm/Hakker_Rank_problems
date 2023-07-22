#include <stdio.h>
int main()
{
    int x = 0 ;
    int y = 300 ;
    changeXValue(y,&x,2);
    printf(" X : %d", x );
    return 0 ;
}
void changeXValue(int data1, void *data2, int type)
{
    if (type==1 )
    {
        *(char*)data2 = data1 ;

    }

    if (type==2 )
    {
        *(int*)data2 = data1 ;

    }
}
