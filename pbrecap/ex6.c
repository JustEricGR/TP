#include<stdio.h>
#include<math.h>
#define IN "X.IN"
#define OUT "REZULTATE6.TXT"

double f(double x)
{
    return x;
}

double g(double x)
{
    return 1+2*x+3*pow(x,2)+4*pow(x,3);
}

double e(double x)
{
    return pow(3,x);
}

double d(double x)
{
    return sin(x)+pow(2,x);
}

double c(double x,double (*fct1)(double),double (*fct2)(double))
{
    return fct1(x)/fct2(x);
}

double b(double x,double (*fct1)(double),double (*fct2)(double))
{
    return fct1(x)*fct2(x);
}

double a(double x,double y)
{
    return x+y;
}

void scriere(double x)
{
    FILE *fin=NULL;
    if((fin=fopen(IN,"wb"))==NULL)
    {
        printf("Eroare la deschidere fisier de scriere valori\n");
        perror(NULL);
        return;
    }
    fwrite(&x,sizeof(double),1,fin);
    if(fclose(fin))
    {
        printf("Eroare la inchidere fisier in\n");
        perror(NULL);
        return;
    }
}

void write(double x,FILE *fout)
{
    
    fprintf(fout,"%g ",x);
    
}

int main(void)
{
    double x=0;
    printf("Scrieti valoarea lui x:");
    scanf("%lg",&x);
    scriere(x);
    FILE *fout=NULL;
    if((fout=fopen(OUT,"w"))==NULL)
    {
        printf("Eroare la deschidere fisier de scriere valori\n");
        perror(NULL);
        return 0;
    }
    double val1=0,val2=0,val3=0;
    val3=c(x,f,g);
    val2=b(x,d,e);
    val1=a(b(x,d,e),c(x,f,g));
    write(val1,fout);
    write(val2,fout);
    write(val3,fout);
    write(d(x),fout);
    write(e(x),fout);
    write(f(x),fout);

    if(fclose(fout))
    {
        printf("Eroare la inchidere fisier in\n");
        perror(NULL);
        return 0;
    }
}