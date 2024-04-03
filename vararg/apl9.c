#include<stdio.h>

int main(int argc,char **argv)
{
    double suma=0;
    for(int i=0;i<argc;i++)
    {
        float n=0;
        sscanf(argv[i],"%g",&n);
        suma+=n;
        
    }
    printf("Suma este:%g\n",suma);
    return 0;
}