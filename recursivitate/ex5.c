#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *fib(char *s1,char *s2,int n)
{
    s1=(char*)malloc(100*sizeof(char));
    scanf("%99s",s1);
    s2=(char*)malloc(100*sizeof(char));
    scanf("%99s",s2);
    char *rez=(char*)malloc(200*sizeof(char));
    strcpy(rez,"");
    rez=strcat(rez,s1);
    rez=strcat(rez,s2);
    for(int i=0;i<n;i++)
    {
        char* termenNou = (char*)malloc(1000 * sizeof(char));
        if (termenNou == NULL) {
            printf("Eroare la alocarea de memorie!\n");
            exit(1);
        }
        strcpy(termenNou, rez);
        strcat(termenNou, s2);

        strcpy(rez, termenNou);

        free(termenNou);
    
    }
    return rez;
}

int main(void)
{
    int n=0;
    printf("Al catelea termen sa se afiseze:");
    scanf("%d",&n);
    char *s1=NULL,*s2=NULL;
    puts(fib(s1,s2,n));
    free(s1);
    free(s2);
}