#include<stdio.h>

float phi(int a,int b)
{
    return (float)a/b;
}


int fib(int nr)
{
    
    if(nr==1 || nr==0)
    {
        
        return 1;
    }
    else
    {
        return fib(nr-1)+fib(nr-2);
    }
}

void rap(int n)
{
    for(int i=1;i<n;i++)
    {
        int a=fib(i);
        int b=fib(i-1);
        printf("%.4f ",phi(a,b));
    }printf("\n");
}



int main(void)
{
    int nr=0;
    printf("Cate rapoarte sa se afiseze:");
    scanf("%d",&nr);
    rap(nr);
}