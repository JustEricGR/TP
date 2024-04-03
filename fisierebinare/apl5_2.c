#include<stdio.h>
#include<stdlib.h>
#define CHUNK 4096

void transfer(const char *f,const char *g)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"rb"))==NULL)
    {
        printf("Eroare la deschidere fisier 1\n");
        perror(NULL);
        exit(-1);
    }

    FILE *fout=NULL;
    if((fout=fopen(g,"wb"))==NULL)
    {
        printf("Eroare la deschidere fisier 2\n");
        perror(NULL);
        exit(-1);
    }

    unsigned char v[CHUNK+1]="";
    long int pozitie=0;
    
    while(fread(v,sizeof(unsigned char),CHUNK,fin)<=CHUNK)
    {
        pozitie=ftell(fin);
        fseek(fout,pozitie,SEEK_SET);
        fwrite(v,sizeof(unsigned char),CHUNK,fout);

    }

    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere fisier 1\n");
        perror(NULL);
        exit(-1);
    }

    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere fisier 2\n");
        perror(NULL);
        exit(-1);
    }
}

int main(int argc,char **argv)
{
    transfer(argv[1],argv[2]);
    return 0;
}