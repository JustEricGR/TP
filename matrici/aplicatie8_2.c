#include<stdio.h>
#include<string.h>

int maxim(int a,int b)
{
    if(a>b)return a;
    else return b;
}

void citire(int v[10][10],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            v[i][j]=maxim(i,j);
        }
    }
}

void afisare(int v[10][10],int size)
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
    int v[10][10];
    int size=0;

    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        memset(v[i],0,10*sizeof(int));
    }
    citire(v,size);
    afisare(v,size);
}