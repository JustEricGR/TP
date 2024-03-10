#include <stdio.h>
int f1(int a,int b)
{ 
    return a+b; 
}

int f2(int a,int b)
{ 
    return a-b; 
}

int main(void)
{
    int a=7,b=5;
    int (*pf)(int,int); // pf - pointer la o functie
    pf=f1; // se seteaza pf cu adresa functiei f1
    printf("op(%d,%d)=>%d\n",a,b,pf(a,b)); // se apelează functia pointata
    pf=f2;
    printf("op(%d,%d)=>%d\n",a,b,pf(a,b));
    return 0;
}
