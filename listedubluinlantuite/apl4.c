/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produs{
    char text[16]; 
    struct Produs *pred;
    struct Produs *urm; 
}Produs;


Produs *Produs_nou(const char *text)
{
    Produs *c=(Produs*)malloc(sizeof(Produs));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text,text);
    return c;
}

typedef struct Categorie{
    char text[16]; 
    Produs *pred;
    Produs *urm; 
}Categorie;



Categorie *Categorie_nou(const char *text)
{
    Categorie *c=(Categorie*)malloc(sizeof(Categorie));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text,text);
    return c;
}

typedef struct{
    Categorie 
}


typedef struct{
    Categorie *prim; 
    Categorie *ultim;
}FULL;

void Produs_init(Produs *p)
{
    p->prim=p->ultim=NULL;
}

void Categorie_init(Categorie *c)
{
    c->prim=c->ultim=NULL;
}

void Propozitie_adauga(Categorie *p,Produs *c)
{
    c->pred=p->ultim; 
    if(p->ultim)
    { 
        p->ultim->urm=c; 
    }
    else
    { 
        p->prim=c; 
    }
    p->ultim=c;     
    c->urm=NULL;
}

void Categorie_adauga(Categorii *p,Produs *c)
{
    c->pred=p->ultim; 
    if(p->ultim)
    { 
        p->ultim->urm=c; 
    }
    else
    { 
        p->prim=c; 
    }
    p->ultim=c;     
    c->urm=NULL;
}


Cuvant *Propozitie_cauta(Propozitie *p,const char *text)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm)
    {
        if(!strcmp(c->text,text))return c;
    }
    return NULL;
}





void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c,*urm;
    for(c=p->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
    Propozitie_init(p);
}



int main()
{
    Propozitie p;
    int op; // optiune
    char text[16];
    Cuvant *c;
    Propozitie_init(&p); // initializare propozitie vida
    do
    {
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - stergere cuvant\n");
        printf("4 - iesire\n");
        printf("5 - numarare\n");
        printf("6 - cuvant de adaugat\n");
        printf("optiune: ");scanf("%d",&op);
        switch(op)
        {
            case 1:
                Propozitie_elibereaza(&p); // elibereaza posibila propozitie anterioara
                for(;;)
                {
                scanf("%s",text);
                // intre ultimul cuvant si punct trebuie sa existe un spatiu, pentru ca punctul sa fie considerat separat
                    if(!strcmp(text,"."))break; // atentie: "." este un sir de caractere, nu o litera (char)
                    Cuvant *c=Cuvant_nou(text);
                    Propozitie_adauga(&p,c);
                }
                break;
        case 2:
            for(c=p.prim;c;c=c->urm)printf("%s ",c->text);
            printf(".\n");
            break;
        case 3:
            printf("cuvant de sters:");scanf("%s",text);
            c=Propozitie_cauta(&p,text);
            if(c)
            {
                Propozitie_sterge(&p,c);
            }
            else
            {
                printf("cuvantul \"%s\" nu se gaseste in propozitie\n",text);
            }
            break;
        case 4:break;
        case 5:
            numarare(p);
            break;
        case 6:
        {
            char cuv1[16]="",cuv2[16]="";
            printf("Ce cuvant sa fie inserat:");
            scanf("%s",cuv2);
            printf("Unde sa fie inserat:");
            scanf("%s",cuv1);
            inserareCuvant(&p,cuv1,cuv2);
            break;
        }
        default:printf("optiune invalida");
        }
    }
    while(op!=4);
    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produs{
    char text[16]; 
    struct Produs *pred;
    struct Produs *urm; 
}Produs;


Produs *Produs_nou(const char *text)
{
    Produs *c=(Produs*)malloc(sizeof(Produs));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text,text);
    return c;
}

typedef struct Categorie{
    char text[16]; 
    Produs *pred;
    Produs *urm; 
}Categorie;



Categorie *Categorie_nou(const char *text)
{
    Categorie *c=(Categorie*)malloc(sizeof(Categorie));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text,text);
    return c;
}


typedef struct{
    Categorie *prim; 
    Categorie *ultim;
}FULL;

void Produs_init(Produs *p)
{
    p->prim=p->ultim=NULL;
}

void Categorie_init(Categorie *c)
{
    c->prim=c->ultim=NULL;
}

void Propozitie_adauga(Categorie *p,Produs *c)
{
    c->pred=p->ultim; 
    if(p->ultim)
    { 
        p->ultim->urm=c; 
    }
    else
    { 
        p->prim=c; 
    }
    p->ultim=c;     
    c->urm=NULL;
}

void Categorie_adauga(Categorii *p,Produs *c)
{
    c->pred=p->ultim; 
    if(p->ultim)
    { 
        p->ultim->urm=c; 
    }
    else
    { 
        p->prim=c; 
    }
    p->ultim=c;     
    c->urm=NULL;
}


Cuvant *Propozitie_cauta(Propozitie *p,const char *text)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm)
    {
        if(!strcmp(c->text,text))return c;
    }
    return NULL;
}





void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c,*urm;
    for(c=p->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
    Propozitie_init(p);
}



int main()
{
    Propozitie p;
    int op; // optiune
    char text[16];
    Cuvant *c;
    Propozitie_init(&p); // initializare propozitie vida
    do
    {
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - stergere cuvant\n");
        printf("4 - iesire\n");
        printf("5 - numarare\n");
        printf("6 - cuvant de adaugat\n");
        printf("optiune: ");scanf("%d",&op);
        switch(op)
        {
            case 1:
                Propozitie_elibereaza(&p); // elibereaza posibila propozitie anterioara
                for(;;)
                {
                scanf("%s",text);
                // intre ultimul cuvant si punct trebuie sa existe un spatiu, pentru ca punctul sa fie considerat separat
                    if(!strcmp(text,"."))break; // atentie: "." este un sir de caractere, nu o litera (char)
                    Cuvant *c=Cuvant_nou(text);
                    Propozitie_adauga(&p,c);
                }
                break;
        case 2:
            for(c=p.prim;c;c=c->urm)printf("%s ",c->text);
            printf(".\n");
            break;
        case 3:
            printf("cuvant de sters:");scanf("%s",text);
            c=Propozitie_cauta(&p,text);
            if(c)
            {
                Propozitie_sterge(&p,c);
            }
            else
            {
                printf("cuvantul \"%s\" nu se gaseste in propozitie\n",text);
            }
            break;
        case 4:break;
        case 5:
            numarare(p);
            break;
        case 6:
        {
            char cuv1[16]="",cuv2[16]="";
            printf("Ce cuvant sa fie inserat:");
            scanf("%s",cuv2);
            printf("Unde sa fie inserat:");
            scanf("%s",cuv1);
            inserareCuvant(&p,cuv1,cuv2);
            break;
        }
        default:printf("optiune invalida");
        }
    }
    while(op!=4);
    return 0;
}

