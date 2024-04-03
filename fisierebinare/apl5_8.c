#include<stdio.h>
#include<stdlib.h>

typedef struct{
    uint n;
    int nrap;
}Intregi;

void afisare(Intregi *v,uint size)
{
    for(uint i=0;i<size;i++)
    {
        printf("%c - %d\n",v[i].n,v[i].nrap);
    }
}

void cautare(Intregi *v,uint size,FILE *f)
{
    fseek(f,0,SEEK_SET);
    uint n=0;
    while(fread(&n,sizeof(uint),1,f)==1)
    {       
        for(uint i = 0; i < size; i++)
        {
            if((char)n == v[i].n)
            {
                v[i].nrap++;
            }
        }
    }
    
}

int main(int argc,char **argv)
{
    FILE *fin=NULL;
    if((fin=fopen(argv[1],"rb"))==NULL)
    {
        printf("Eroare la deschidere fisier\n");
        perror(NULL);
        exit(-1);
    }

    Intregi *v=NULL;
    v=(Intregi*)malloc((argc-2)*sizeof(Intregi));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    uint adder=0;
    for(uint i=2;i<argc;i++)
    {
        v[i-2].nrap=0;
        sscanf(argv[i],"%d",&v[i-2].n);
        
    }
    
    cautare(v,argc-2,fin);
    afisare(v,argc-2);
    

    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
    free(v);
    return 0;
}