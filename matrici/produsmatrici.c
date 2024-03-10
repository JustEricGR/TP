#include<stdio.h>
#include<stdlib.h>

void eliberare(int **v,int size)
{
    for(int i=0;i<size;i++)free(v[i]);
    free(v);
}

void citire(int **v,int m,int n)
{
    for(int i=0;i<size;i++)
    {
        v[i]=(int*)malloc(m*sizeof(int));
        if(v[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            eliberare(v,size);
            exit(-1);
        }
        for(int j=0;j<n;j++)
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
    }printf("\n");
}

int *parcurgereLinie(int **v,int size)
{
    int *row=NULL;
    row=(int*)malloc(size11*sizeof(int));
    if(row==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    for(int i=0;i<size;i++)
    {
        row[i]=
    }
}

void produs(int *v1,int size11,int size12,int **v2,int size22)
{
    int **rez=NULL;
    int addline=0,addcol=0;
    int *row=NULL,*col=NULL;
    row=(int*)malloc(size11*sizeof(int));
    if(row==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    col=(int*)malloc(size12*sizeof(int));
    if(col==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    rez=(int**)malloc(size11*sizeof(int*));
    if(rez==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }



    

    for(int i=0;i<size11;i++)
    {
        rez[i]=(int*)malloc(size22*sizeof(int));
        if(rez[i]==NULL)
        {
            printf("Eroare la alocare\n");
            perror(NULL);
            exit(-1);
        }

        int a=0,b=0,c=0;
        for(int j=0;j<size22;j++)
        {
            a=v1[i][j];
            b=v1[]

        }
    }
}


