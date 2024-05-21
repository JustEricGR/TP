#include<stdio.h>
#include<math.h>

int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

float taylor(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return (float)(pow(x,n)/fact(n))+taylor(x,n-1);
    }
}

int main(void)
{
    int n=0,x=0;
    printf("Cati termeni sa aiba suma taylor:");
    scanf("%d",&n);
    printf("In ce nr sa se calculeze suma:");
    scanf("%d",&x);
    printf("%.4f\n",taylor(x,n));
    
}