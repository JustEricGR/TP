#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void citire(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        v[i]=(int*)malloc(size*sizeof(int));
        if(v[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
        for(int j=0;j<size;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
}

void afisare(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }
}

void afisareVectLinie(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Suma de pe linia %d este:%d\n",i+1,v[i]);
    }
}

void afisareVectColoana(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Suma de pe coloana %d este:%d\n",i+1,v[i]);
    }
}

void sume(int **v,int size)
{
    int *sLinie=NULL,*sCol=NULL;
    sLinie=(int*)malloc(size*sizeof(int));
    if(sLinie==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    sCol=(int*)malloc(size*sizeof(int));
    if(sCol==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    memset(sCol,0,size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        sLinie[i]=0;
        
        for(int j=0;j<size;j++)
        {
            //sCol[j]=0;
            sCol[j]+=v[i][j];
            sLinie[i]+=v[i][j];
        }
        
    }
    afisareVectLinie(sLinie,size);
    afisareVectColoana(sCol,size);
    free(sLinie);
    free(sCol);
}

int main(void)
{
    int size=0;
    scanf("%d",&size);
    int **v=NULL;
    v=(int **)malloc(size*sizeof(int*));
    if(v==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }
    citire(v,size);
    afisare(v,size);
    sume(v,size);
    for(int i=0;i<size;i++)
        free(v[i]);
    free(v);

}