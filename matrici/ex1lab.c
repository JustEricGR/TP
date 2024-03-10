#include<stdio.h>
#include<string.h>

void citire(float v[10][10],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            v[i][j]=(float)(i+j)/2;
        }
    }
}

void afisare(float v[10][10],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%5.2g",v[i][j]);
        }printf("\n");
    }
}

int main(void)
{
    float v[10][10];
    int size=0;

    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        memset(v[i],0,10*sizeof(int));
    }
    citire(v,size);
    afisare(v,size);
}