#include<stdio.h>
#include<math.h>
#include<string.h>

typedef enum{
    PICO,
    NANO,
    MICRO,
    MILI,
    CENTI,
    DECI,
    DECA,
    HECTO,
    KILO,
    MEGA,
    GIGA
}opt;

typedef enum{
    GRAM,
    METRU,
    LITRU
}u_m;

typedef struct{
    unsigned int valoare:16;
}Masuratoare;

void citire()
{
    Masuratoare v={0};
    int aux=0,unitate=0,tip=0;
    char nume_unit[10]="";
    double rez=0;
    printf("valoare=");
    scanf("%d",&aux);
    v.valoare=aux;
    printf("unitate de masura(0 pt grame, 1 pt metri, 2 pt litri):");
    scanf("%d",&tip);
    switch(tip)
    {
        case GRAM:
            strcpy(nume_unit,"grame");
            break;
        case METRU:
            strcpy(nume_unit,"metri");
            break;
        case LITRU:
            strcpy(nume_unit,"litri");
            break;
        default:
            strcpy(nume_unit,"grame");
            break;

    }
    printf("In ce unitate sa se transforme:\n");
    printf("0 pt pico, 1 pt nano, 2 pt micro, 3 pt mili, 4 pt centi, 5 pt deci, 6 pt deca, 7 pt hecto, 8 pt kilo, 9 pt mega, 10 pt giga\n");
    scanf("%d",&unitate);
    switch(unitate)
    {
        case PICO:
            rez=v.valoare*pow(10,12);
            printf("%.f pico%s\n",rez,nume_unit);
            break;
        case NANO:
            rez=v.valoare*pow(10,9);
            printf("%.f nano%s\n",rez,nume_unit);
            break;
        case MICRO:
            rez=v.valoare*pow(10,6);
            printf("%.f micro%s\n",rez,nume_unit);
            break;
        case MILI:
            rez=v.valoare*pow(10,3);
            printf("%.f mili%s\n",rez,nume_unit);
            break;
        case CENTI:
            rez=v.valoare*pow(10,2);
            printf("%.f centi%s\n",rez,nume_unit);
            break;
        case DECI:
            rez=v.valoare*pow(10,1);
            printf("%.f deci%s\n",rez,nume_unit);
            break;
        case DECA:
            rez=v.valoare*pow(10,-1);
            printf("%0.1f deca%s\n",rez,nume_unit);
            break;
        case HECTO:
            rez=v.valoare*pow(10,-2);
            printf("%0.2f hecto%s\n",rez,nume_unit);
            break;
        case KILO:
            rez=v.valoare*pow(10,-3);
            printf("%0.3f kilo%s\n",rez,nume_unit);
            break;
        case MEGA:
            rez=v.valoare*pow(10,-6);
            printf("%0.6f mega%s\n",rez,nume_unit);
            break;
        case GIGA:
            rez=v.valoare*pow(10,-9);
            printf("%0.9f giga%s\n",rez,nume_unit);
            break;
        default:
            rez=v.valoare;
            printf("%f %s\n",rez,nume_unit);
    }
}

int main(void)
{
    citire();
    return 0;
}