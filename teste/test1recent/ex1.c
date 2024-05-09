#include<stdio.h>
#include<stdarg.h>

void draw(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("*");
    }printf("\n");
}

void shape(int n,...)
{
    va_list va;
    va_start(va,n);
    draw(n);
    for(;;)
    {
        int nr=va_arg(va,int);
        if(!nr)break;
        draw(nr);
    }
    va_end(va);
}

int main(void)
{
    shape(5,2,1,0);
}