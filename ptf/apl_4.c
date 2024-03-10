#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void tab(int a, int b, int rezultate,double (*fct)(double))
{
    int treapta=(b-a)/rezultate;
    for(double i=a;i<=b;i+=treapta)
    {
        double rez=0;
        rez=fct(i);
        printf("f(%f)=%f\n",i,rez);
    }
}


int main(void)
{
    int a=0,b=0,nrRez=0,opt=0;
    double (*pf)(double);
    printf("Introduceti inceputul intervalului:");
    scanf("%d",&a);
    printf("Introduceti capatul intervalului:");
    scanf("%d",&b);
    printf("Cate masuratori sa se faca?");
    scanf("%d",&nrRez);
    printf("Scrieti 0 pt cos, 1 pt sqrt si 2 pt fabs, default cos\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 0:
        {
            pf=cos;
            break;
        }
        case 1:
        {
            pf=sqrt;
            break;
        }
        case 2:
        {
            pf=fabs;
            break;
        }
        default:
        {
            pf=cos;
            break;
        }
    }
    tab(a,b,nrRez,pf);
}