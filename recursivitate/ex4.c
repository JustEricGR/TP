#include<stdio.h>

int fib(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}

int main(void)
{
    int nr=0;
    printf("Al catelea termen fibonacci sa fie gasit:");
    scanf("%d",&nr);
    printf("Termenul este:%d\n",fib(nr));
}