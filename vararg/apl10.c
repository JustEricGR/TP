#include<stdio.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void enc(char *s,int n)
{
    int lungime=strlen(s);
    char *rez=(char*)calloc(lungime+1,sizeof(char));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for(int i=0;i<lungime;i++)
    {
        if(isupper(s[i]))s[i]=tolower(s[i]);
        if((s[i]+n)>'z')rez[i]='a'+s[i]+n-'z'-1;
        else
            rez[i]=s[i]+n;
    }
    rez[lungime]=0;
    puts(rez);
    free(rez);
}

void dec(char *s,int n)
{
    int lungime=strlen(s);
    char *rez=(char*)calloc(lungime+1,sizeof(char));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for(int i=0;i<lungime;i++)
    {
        if(isupper(s[i]))s[i]=tolower(s[i]);
        if((s[i]-n)<'a')rez[i]='z'+s[i]-n-'a'+1;
        else
            rez[i]=s[i]-n;
    }
    puts(rez);
    free(rez);
}

int main(int argc,char **argv)
{
    int cheie=0;
    if(sscanf(argv[2],"%d",&cheie)==1)
    {
        if(!strcasecmp(argv[1],"enc"))
        {
            for(int i=3;i<argc;i++)
            {
                enc(argv[i],cheie);
            }
        }

        if(!strcasecmp(argv[1],"dec"))
        {
            for(int i=3;i<argc;i++)
            {
                dec(argv[i],cheie);
            }
        }
    }
    
}