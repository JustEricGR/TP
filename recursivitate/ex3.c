#include<stdio.h>

int cfmax(int n,int maxim)
{
    if(n<10)
    {
        return maxim;
    }
    
    if(maxim<(n%10))
    {
        maxim=n%10;
    }
    return cfmax(n/10,maxim);
    
}

int main(void)
{
    int nr=0,m=0;
    printf("nr=");
    scanf("%d",&nr);
    printf("Cifra maxima e:%d\n",cfmax(nr,m));
    return 0;
}