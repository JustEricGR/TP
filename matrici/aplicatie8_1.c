#include<stdio.h>
#include<string.h>

void citire(int v[10][10],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",&v[i][j]);
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
    int size=0,cond=1;

    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        memset(v[i],0,10*sizeof(int));
    }
    citire(v,size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(v[i][j]<0)
            {
                cond=0;
                break;
            }
        }
        if(!cond)break;
    }
    if(cond)printf("Toate nr sunt poz\n");
    else printf("Exista si nr negative\n");
    afisare(v,size);
    
}