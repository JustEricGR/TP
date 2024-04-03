#include<stdio.h>
#include<stdlib.h>

void comparare(const char *f1,const char *f2)
{
    FILE *fin1=NULL;
    FILE *fin2=NULL;
    if((fin1=fopen(f1,"rb"))==NULL)
    {
        printf("Eroare la deschiderea primului fisier\n");
        perror(NULL);
        exit(-1);
    }

    if((fin2=fopen(f2,"rb"))==NULL)
    {
        printf("Eroare la deschiderea celui de al doilea fisier\n");
        perror(NULL);
        exit(-1);
    }

    int ind1=0,ind2=0;
    fseek(fin1,-1,SEEK_END);
    ind1=ftell(fin1);
    fseek(fin2,-1,SEEK_END);
    ind2=ftell(fin2);
    printf("lungime1:%d\n",ind1);
    printf("lungime2:%d\n",ind2);

    unsigned char c1=0,c2=0;
    fseek(fin1,0,SEEK_SET);
    fseek(fin2,0,SEEK_SET);
    while(fread(&c1,sizeof(unsigned char),1,fin1) || fread(&c2,sizeof(unsigned char),1,fin2))
    {
        
        if(ind1==ind2)
        {
            if(c1!=c2)
            {
                printf("%ld - %02X - %02X\n",ftell(fin1),c1,c2);
            }           
        }

        else
        {
            if(ind1>ind2)
                printf("%02X\n",c1);
            else if(ind1<ind2)
                printf("%02X\n",c2);
        }
    }

    if(fclose(fin1)!=0)
    {
        printf("Eroare la inchidere 1\n");
        perror(NULL);
        exit(-1);
    }

    if(fclose(fin2)!=0)
    {
        printf("Eroare la inchidere 2\n");
        perror(NULL);
        exit(-1);
    }


}

int main(int argc,char **argv)
{
    comparare(argv[1],argv[2]);
}