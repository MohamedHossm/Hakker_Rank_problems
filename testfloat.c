#include <stdio.h>
//prototype
int convert_Float_ToString(char*str,float FloatNum);
void String_Reverse(char*str,float FloatNum);
void Print_string(char*str);
int main()
{
    char str[20]= {0};
    float FloatNum=3.55;
    String_Reverse(str,FloatNum);
    Print_string(str);
    return 0;
}
//implementation
int convert_Float_ToString(char*str,float FloatNum)
{
    int i,num,num2=0,res,c=0;
    num=FloatNum;
   // num=num%10;
    /*
    while(FloatNum-num2!=0)
    {
        FloatNum=FloatNum*10;
        num2=FloatNum;
        c++;
    }
    */
    num2=FloatNum*1000;
    c = 3 ;
    for(i=0; num2; i++)
    {
        res=num2%10;
        if(res==num && i==c)
        {
            str[i]='.';
            i++;
            str[i]=res+'0';
        }
        else
        {
            str[i]=res+'0';
        }
        num2=num2/10;
    }
    return i;
}
void String_Reverse(char*str,float FloatNum)
{
    int i,size,j;
    char temp=0;
    size=convert_Float_ToString(str,FloatNum);
    j=size-1;
    for(i=0; i<size/2; i++)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        j--;
    }
}
void Print_string(char*str)
{
    int i;
    for(i=0; str[i]; i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
}
