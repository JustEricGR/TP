#include<stdio.h>

int poz(int a)
{
    return a>=0;
}

int par(int a)
{
    return a%2==0;
}

int testare(int *v,int n,int(*cond)(int))
{
    for(int i=0;i<n;i++)
    {
        if(!cond(v[i]))return 0;
    }
    return 1;
}

int main(void)
{
    int v[5]={4,8,1,2,0};
    printf("toate elementele sunt pozitive: %d\n",testare(v,5,poz));
    printf("toate elementele sunt pare: %d\n",testare(v,5,par));
}