#include<stdio.h>
#include<stdlib.h>

void eliberare(int **v,int size)
{
    for(int i=0;i<size;i++)free(v[i]);
    free(v);
}

void afisare(int **v,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }printf("\n");
}

void initializare(int size)
{
    int **v=NULL;
    v=(int**)malloc(size*sizeof(int*));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
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
            if(i==j)
            {
                v[i][j]=1;
            }
            else v[i][j]=0;
        }
    }
    afisare(v,size);
    eliberare(v,size);
}

int main(void)
{
    int size=0;
    scanf("%d",&size);
    initializare(size);
}