#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<string.h>

char *compunere(int n,...)
{
    char *rez=(char*)malloc(n*sizeof(char));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    int adder=0;
    va_list va;
    va_start(va,n);
    for(int i=0;i<n;i++)
    {
        char c=va_arg(va,int);
        if(strchr("aeiouAEIOU",c))rez[adder++]=c;
    }
    return rez;
}

int main(void)
{
    char *rez=compunere(5,'A','n','a','e','b');
    puts(rez);
    free(rez);
}