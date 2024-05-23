#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float fct(float x)
{
    return sin(x)+sin(2*x)+x;
}

float aprox(float (*f)(float),float *a,float *b,float y)
{
    float x=(*b-*a)/2;
    if(f(x)-y<=0.5*pow(10,-8))
    {
        return x;
    }
    else
    {
        if(f(x)>y)
        {
            *b=x;
        }
        else
        {
            *a=x;
        }
        return aprox(f,a,b,y);
    }
}

int main(void)
{
    
    float y=0;
    float a=0,b=1;
    printf("In ce nr sa se calc fct:");
    scanf("%f",&y);
    printf("%f\n",aprox(fct,&a,&b,y));
}