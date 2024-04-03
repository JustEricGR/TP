#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define CHUNK 30

int nrLit(char *s)
{
    //printf("%ld",strlen(s));
    return strlen(s);
}

int histo(char *s)
{
    uint litere[26]={0};
    for(uint i=0;i<strlen(s);i++)
    {
        if(isupper(s[i]))s[i]=tolower(s[i]);
        litere[s[i]-'a']++;
    }

    for(uint i=0;i<26;i++)
    {
        printf("%c - %d\n",i+'a',litere[i]);
    }
    return 1;
}

int main(int argc,char **argv)
{
    char *rez=NULL;
    int current=CHUNK,flag=0;
    rez=(char*)malloc(current*sizeof(char));
    int size=0;
    int n=0;
    int (*fct)(char *s);
    strcpy(rez,"");
    for(uint i=1;i<argc;i++)
    {
        if(!strcmp(argv[i],"0"))
        {
            fct=nrLit;
        }
        else if(!strcmp(argv[i],"1"))
        {
            fct=histo;
            flag++;
        }
        else
        {
            size+=strlen(argv[i])+1;
            if(size>=current)
            {
                current+=CHUNK;
                rez=(char*)realloc(rez,current*sizeof(char));
            }
            
            strcat(rez,argv[i]);
        }

    }

    n=fct(rez);
    if(flag==0)
    {
        printf("%d\n",n);
    }
    
    free(rez);
    
}