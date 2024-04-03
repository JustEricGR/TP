#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define CHUNK 16

void afisare(char *s,int size)
{
    for(int i=0;i<size;i+=2)
    {
        printf("%2x%2x ",s[i],s[i+1]);
    }printf("\n");
}

int main(int argc,char **argv)
{
    int citit=0;
    FILE *fin=NULL;
    if((fin=fopen(argv[1],"rb"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }

    char aux[CHUNK]="";
    while((citit=fread(aux,sizeof(char),CHUNK,fin))>0)
    {
        printf("%08lx ",ftell(fin));
        afisare(aux,citit);
    }

    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    return 0;
    
}