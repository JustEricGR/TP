#include<stdio.h>

int cmmdc(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return cmmdc(b,a%b);
    }

}

int main(void)
{
    int a=0,b=0;
    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("Cmmdc este:%d\n",cmmdc(a,b));
    return 0;
}