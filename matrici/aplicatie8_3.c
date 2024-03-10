#include<stdio.h>

void citire(int v[20][10],int m,int n)
{
    int nr=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            v[i][j]=nr;
            nr++;

        }
    }
}

void afisare(int v[20][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4d",v[i][j]);
        }printf("\n");
    }
}

int main(void)
{
    int m=0,n=0;
    int v[20][10];
    printf("Nr de linii:");
    scanf("%d",&m);
    printf("Nr de coloane:");
    scanf("%d",&n);
    citire(v,m,n);
    afisare(v,m,n);

}