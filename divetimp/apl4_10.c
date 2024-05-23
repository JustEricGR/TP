#include<stdio.h>
#include<stdlib.h>

int par(int x)
{
    return x%2==0;
}

int **citire(int **v,uint m,uint n)
{
    v=(int**)malloc(m*sizeof(int*));
    if(v==NULL)
    {
        printf("Eroare la alocare matrice\n");
        perror(NULL);
        exit(-1);
    }

    for(uint i=0;i<m;i++)
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
            scanf("%d",&v[i][j]);
        }
    }
    return v;
}

void afisare(int **v,uint m,uint n)
{
    for(uint i=0;i<m;i++)
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

int suma(int **v,uint m1,uint m,uint n1,uint n)
{
    if(m1>m || n1>n)
    {
        return 0;
    }

    if(m1==m && n1==n)
    {
        if(v[m1][n1]%2==0)
        {
            return v[m1][n1];
        }
        else
        {
            return 0;
        }
    }
    uint mid1=(m+m1)/2;
    uint mid2=(n+n1)/2;

    int s1=suma(v,m1,mid1,n1,mid2);
    int s2=suma(v,mid1+1,m,n1,mid2);
    int s3=suma(v,m1,mid1,mid2+1,n);
    int s4=suma(v,mid1+1,m,mid2+1,n);

    return s1+s2+s3+s4;
    
}

int main(void)
{
    uint m=0,n=0;
    printf("Cate linii sa aiba matricea:");
    scanf("%d",&m);
    printf("Cate coloane sa aiba matricea:");
    scanf("%d",&n);
    int **v=NULL;
    v=citire(v,m,n);
    afisare(v,m,n);
    printf("Suma este %d\n",suma(v,0,m-1,0,n-1));
    eliberare(v,m);
}