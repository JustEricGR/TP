#include<stdio.h>
#include<stdlib.h>

typedef enum{
    SCAZUTA,
    MEDIE,
    MARE
};

typedef enum{
    NU,
    DA
};



typedef struct{
    unsigned char pericol:2;
    unsigned char reteta:1;
    unsigned char varsta:5;
}Medicament;

void citire(Medicament v)
{
    unsigned char pericol=0,reteta=0,varsta=0;
    scanf("%hhd %hhd %hhd",&pericol,&reteta,&varsta);
    switch(pericol)
    {
        case SCAZUTA:
            v.pericol=0;
            printf("Pericol scazut, ");
            break;
        case MEDIE:
            v.pericol=1;
            printf("Pericol mediu, ");
            break;
        case MARE:
            printf("Pericol mare, ");
            break;
    }

    switch(reteta)
    {
        case NU:
            v.reteta=0;
            printf("nu trebuie reteta, ");
            break;
        case DA:
            v.reteta=1;
            printf("trebuie reteta, ");
            break;
    }
    v.varsta=varsta;
    printf("varsta minima este %d.\n",v.varsta);


}

int main(void)
{
    Medicament v={0,0,0};
    citire(v);
    return 0;
}

