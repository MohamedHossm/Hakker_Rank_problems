int  chack(char* s,char data )
{
    for (int i = 0 ; s[i]; i ++ )
    {
        if (s[i] >='a' && s[i] <='z')
        {
            s[i] = s[i] - 'a'-'A';
        }
        if (data==s[i])
        {
            return 1;
        }
    }
    return 0;

}
char* pangrams(char* s)
{
    int c = 0 ;
    for (char i = 'A' ; i <= 'Z'; i++)
    {
        if (chack(s,i) ) c++;
        else
        {
            return "not pangram";
        }
    }
    if (c == 'Z') return "pangram";
    else
        return "not pangram";
}
