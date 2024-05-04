#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Propozitie{
    char text[1000]; 
    struct Propozitie *pred; // inlantuire la predecesor
    struct Propozitie *urm; // inlantuire la urmator
}Propozitie;
// aloca un nou cuvant si ii seteaza campul text
// campurile pred si urm raman neinitializate
Propozitie *Propozitie_nou(const char *text)
{
    Propozitie *c=(Propozitie*)malloc(sizeof(Propozitie));
    if(!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text,text);
    return c;
}

typedef struct{
    Propozitie *prim; // primul cuvant din lista
    Propozitie *ultim; // ultimul cuvant din lista
 }Propozitii;
// initializare propozitie noua
void Propozitii_init(Propozitii *p)
{
    p->prim=p->ultim=NULL;
}


// adauga un cuvant la sfarsitul propozitiei
void Propozitii_adauga(Propozitii *p,Propozitie *c)
{
    c->pred=p->ultim; // predecesorul cuvantului este ultimul cuvant din lista
    if(p->ultim)
    { // daca mai sunt si alte cuvinte in lista
        p->ultim->urm=c; // ultimul cuvant din lista va pointa catre noul cuvant
    }
    else
    { // altfel, daca c este primul cuvant din lista
        p->prim=c; // seteaza si inceputul listei la el
    }
    p->ultim=c; // seteaza sfarsitul listei pe noul cuvant
    c->urm=NULL; // dupa cuvantul introdus nu mai urmeaza niciun cuvant
}
// cauta un text in propozitie si daca il gaseste returneaza un pointer la cuvantul respectiv
// daca nu-l gaseste, returneaza NULL

void Propozitie_elibereaza(Propozitii *p)
{
    Propozitie *c,*urm;
    for(c=p->prim;c;c=urm)
    {
        urm=c->urm;
        free(c);
    }
 Propozitii_init(p);
}

void citire(Propozitii *p,const char *f)
{
    FILE *fin=NULL;
    if((fin=fopen(f,"r"))==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    char line[1000]="";
    Propozitie *c=NULL,*c1=NULL;
    while(fgets(line,1000,fin)!=NULL)
    {
        c=Propozitie_nou(line);
        
        
        c1=p->ultim;

        if(p->prim==NULL)
        {
            Propozitii_adauga(p,c);
        }

        else
        {
            
            while(c1!=NULL && strcmp(c->text,c1->text)<0)
            {
                c1=c1->pred;
            }
                
            if (c1 == NULL)
            {
                c->urm = p->prim;
                p->prim->pred = c;
                p->prim = c;
            }
            else if (c1 == p->ultim)
            {
                c->pred = p->ultim;
                p->ultim->urm = c;
                p->ultim = c;
            }
            else
            {
                c->pred = c1;
                c->urm = c1->urm;
                c1->urm->pred = c;
                c1->urm = c;
            }
                
            
        
        }
        
            
        
        
        
        
    }
    if(fclose(fin)!=0)
    {
        printf("Eroare la inchidere\n");
        perror(NULL);
        exit(-1);
    }
}

void afisare(Propozitii p)
{
    Propozitie *c=NULL;
    for(c=p.prim;c;c=c->urm)
    {
        printf("%s",c->text);
    }
}

int main(int argc,char **argv)
{
    Propozitii p;
    Propozitii_init(&p); 
    citire(&p,argv[1]);
    afisare(p);
    Propozitie_elibereaza(&p);
    return 0;
}
