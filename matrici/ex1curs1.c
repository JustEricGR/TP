#include<stdio.h>
#include<stdlib.h>

void eliberare(int **v,int n)
{
    for(int i=0;i<n;i++)
        free(v[i]);
    free(v);
}

int maxim(int a,int b)
{
    if(a>b)return a;
    else return b;
}

void citire(int **v,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        v[i]=(int*)malloc(m*sizeof(int));
        if(v[i]==NULL)
        {
            printf("Eroare la alocarea pe linia %d\n",i);
            perror(NULL);
            exit(-1);
        }
        for(int j=0;j<m;j++)
        {
            v[i][j]=maxim(i,j);
        }
    }
}

void afisare(int **v,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }
}


int main(void)
{
    int **v=NULL;
    int m=0,n=0;
    scanf("%d",&n);
    scanf("%d",&m);
    
    v=(int**)malloc(n*sizeof(int*));
    if(v==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }

    for(int i=0;i<n;i++)
        v[i]=NULL;

    citire(v,n,m);
    afisare(v,n,m);
    eliberare(v,n);
}