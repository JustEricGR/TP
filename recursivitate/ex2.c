#include<stdio.h>

int suma(int n)
{
    if(n<10)
    {
        return n;
    }
    else
    {
        return n%10+suma(n/10);
    }
}

int main(void)
{
    int n=0;
    printf("Introd un nr:");
    scanf("%d",&n);
    printf("Suma cifrelor este:%d\n",suma(n));
    return 0;
}