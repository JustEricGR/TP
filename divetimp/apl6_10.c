#include<stdio.h>
#include<stdlib.h>

int **citire(int **v,uint n)
{
    v=(int**)malloc(n*sizeof(int*));
    if(v==NULL)
    {
        printf("Eroare la alocare matrice\n");
        perror(NULL);
        exit(-1);
    }

    for(uint i=0;i<n;i++)
    {
        v[i]=(int*)malloc(n*sizeof(int));
        if(v[i]==NULL)
        {
            printf("Eroare la alocare vector\n");
            perror(NULL);
            exit(-1);
        }
        for(uint j=0;j<n;j++)
        {
            v[i][j]=0;
        }
    }
    return v;
}

void afisare(int **v,uint n)
{
    for(uint i=0;i<n;i++)
    {
        for(uint j=0;j<n;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }printf("\n");
}

void eliberare(int **v,uint m)
{
    for(uint i=0;i<m;i++)
    {
        free(v[i]);
    }
    free(v);
}

int *produse(int **v,uint size)

int main(void)
{
    uint size=0,nr=0;
    scanf("%d %d",&size,&nr);
    int **v=NULL;
    v=citire(v,size);
    for(uint k=0;k<nr;k++)
    {
        uint i=0,j=0;
        scanf("%d %d",&i,&j);
        v[i-1][j-1]=1;
    }
    afisare(v,size);
    eliberare(v,size);
}