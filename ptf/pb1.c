#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double fct1(double x)
{
    return (x*x*x+4)/(x*x+5);
}

double fct2(double x)
{
    return x+10;
}

double fct3(double x)
{
    return 2*x*x-1;
}

void tab(int a, int b, int rezultate,double (*fct)(double))
{
    int treapta=(b-a+1)/rezultate;
    for(double i=a;i<=b;i+=treapta)
    {
        double rez=0;
        rez=fct(i);
        printf("%.4g\t",rez);
    }printf("\n");
}

int main(void)
{
    int a=0,b=0,nrRez=0;
    double (*pf[3])(double);
    pf[0]=fct1;
    pf[1]=fct2;
    pf[2]=fct3;
    printf("Introduceti inceputul intervalului:");
    scanf("%d",&a);
    printf("Introduceti capatul intervalului:");
    scanf("%d",&b);
    printf("Cate masuratori sa se faca?");
    scanf("%d",&nrRez);
    
    
    
    tab(a,b,nrRez,pf[0]);
    tab(a,b,nrRez,pf[1]);
    tab(a,b,nrRez,pf[2]);
}