#include<stdio.h>
#include<stdlib.h>
#define CHUNK 500

int main(int argc,char **argv)
{
    FILE *fout=NULL;
    FILE *fin=NULL;
    if((fout=fopen(argv[argc-1],"wb"))==NULL)
    {
        printf("Eroare la deschiderea fisierului de scriere\n");
        perror(NULL);
        exit(-1);
    }
    
    uint citit=0;
    char v[CHUNK]="";
    for(int i=1;i<argc-1;i++)
    {
        if((fin=fopen(argv[i],"rb"))==NULL)
            continue;
        else
        {
            while((citit=fread(v,sizeof(char),1,fin))>0)
            {
                fwrite(v,sizeof(char),citit,fout);
            }
            
            if(fclose(fin)!=0)
            {
                printf("Eroare la inchidere fisier\n");
                perror(NULL);
                exit(-1);
            }
        }
        fseek(fout,0,SEEK_END);

    }
    if(fclose(fout)!=0)
    {
        printf("Eroare la inchidere fisier\n");
        perror(NULL);
        exit(-1);
    }
    return 0;
}