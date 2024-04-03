#include<stdio.h>
#include<stdlib.h>

int main(int argc,char **argv)
{
    FILE *fout=NULL;
    if((fout=fopen(argv[1],"wb"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }

    long int offset=0;
    if(sscanf(argv[2],"%lx",&offset)==1)
    {
        fseek(fout,offset,SEEK_SET);
        for(int i=3;i<argc;i++)
        {
            unsigned int n=0;
            sscanf(argv[i],"%d",&n);
            fwrite(&n,sizeof(int),1,fout);
        }
    }

    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }

    return 0;
}