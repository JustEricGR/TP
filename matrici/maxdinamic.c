#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void eliberare(int **v,int size)
{
    for(int i=0;i<size;i++)free(v[i]);
    free(v);
}



void citire(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        v[i]=(int*)malloc(size*sizeof(int));
        if(v==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }
        for(int j=0;j<size;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
}

void afisareVect(int *v,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("Maximul de pe coloana %d este %d\n",i+1,v[i]);
    }
}

void max(int **v,int size)
{
    int *max=NULL;
    max=(int*)malloc(size*sizeof(int));
    if(max==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    memset(max,0,size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            max[j]=0;
            if(max[j]<v[i][j])max[j]=v[i][j];
        }
    }
    
    afisareVect(max,size);
    
    
    free(max);
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

int main(void)
{
    int **v=NULL;
    int size=0;
    scanf("%d",&size);
    v=(int**)malloc(size*sizeof(int*));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        eliberare(v,size);
        exit(-1);

    }
    citire(v,size);
    afisare(v,size);
    max(v,size);
    eliberare(v,size);
}