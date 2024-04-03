#include<stdio.h>
#include<string.h>
#include<ctype.h>

char *strrev(char *s) {
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++) 
    {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
    return s;
}

char *modif1(char *s)
{
    for(int i=0;i<strlen(s);i++)
    {
        s[i]=toupper(s[i]);
    }
    return s;
}

char *modif2(char *s)
{
    s[0]=toupper(s[0]);
    for(int i=1;i<strlen(s);i++)
    {
        s[i]=tolower(s[i]);
    }
    return s;
}

int main(int argc,char **argv)
{
    int nrfct=0;
    char *(*fct[3])(char*);
    for(int i=1;i<argc;i++)
    {
        if(!strcmp(argv[i],"-u"))
        {
            fct[nrfct++]=modif1;
            
        }
        else if(!strcmp(argv[i],"-f"))
        {
            fct[nrfct++]=modif2;
        }
        else if(!strcmp(argv[i],"-r"))
        {
            fct[nrfct++]=strrev;
        }
        else
        {
            for(int j=0;j<nrfct;j++)
            {
                argv[i]=fct[j](argv[i]);
            }
            puts(argv[i]);
        }
    }
    
}