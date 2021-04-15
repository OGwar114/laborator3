#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caso.h"

void meniu()
{
    printf("\t MENIU:\n");
    printf("1_Crearea listei in memoria dinamica\n");
    printf("2_Introducerea informatiei despre elementele listei de la tastatura\n");
    printf("3_Afisarea informatiei despre elementele listei la ecran\n");
    printf("4_Cautarea elementului in lista\n");
    printf("5_Modificarea campurilor unui element din lista\n");
    printf("6_Determinarea adresei ultimului element din lista\n");
    printf("7_Determinarea lungimii listei (numarul de elemente)\n");
    printf("8_Interschimbarea a doua elemente indicate in lista\n");
    printf("9_Sortarea listei\n");
    printf("10_Adaugarea unui element nou la sfarsitul listei\n");
    printf("11_Adaugarea unui element nou la inceputul listei\n");
    printf("12_Inserarea unui element nou dupa elementul indicat al listei\n");
    printf("13_Inserarea unui element nou inaintea elementului indicat in lista\n");
    printf("14_Stergerea elementului indicat in lista\n");
    printf("15_Divizarea listei in doua liste\n");
    printf("16_Concatinarea a doua liste\n");
    printf("17_Salvarea informatiei despre elementele liste in fisier\n");
    printf("18_Citirea informatiei despre elementele listei din fisier\n");
    printf("19_Eliberarea memoriei alocate pentru lista\n");
    printf("0_Iesire din program\n");

}

int alocare(int z)
{
    Casa *c, *p;
    int i;
    for(i=0; i<z; i++)
    {
        c=(Casa*)malloc(sizeof(*c));
        if(c==NULL)
        {
            head=NULL;
            return 0;
        }
        if(i==0)
        {
            head=c;
        }
        else
        {
            p->next=c;
        }
        p=c;
    }
    c->next=NULL;
    return 1;
}
void introduce()
{
    Casa*c;
    int i;
    c=head;
    i=0;
    printf("Introduceti datele despre lista\n");
    while(c)
    {
        printf("Casa nr %d: \n", i+1);
        printf("Dati adresa casei:\n");
        fflush(stdin);
        gets(c->adresa);
        printf("Dati nr de telefon:\n");
        fflush(stdin);
        gets(c->telefon);
        printf("Dati suprafata casei:\n");
        fflush(stdin);
        gets(c->suprafata);
        printf("Dati nr de odai in casa:\n");
        scanf("%d",&c->odai);
        printf("Dati pretul casei:\n");
        fflush(stdin);
        gets(c->cost);
        i++;
        c=c->next;
        if(c==head)
            break;
    }
    return;
}

void afisare (Casa *c)
{

    int i;
    c=head;
    i=0;
    printf("Info despre elementele listei: \n");
    while(c)
    {
        printf("Element %d: \n", i+1);
        printf("Adressa:%s\nTelefon:%s\nSuprafata:%s\nOdai:%d\nCost:%s \nAdresa elementului curent:%p\nAdresa elementului urmator:%p\n", c->adresa, c->telefon, c->suprafata,c->odai,c->cost,c,c->next);
        i++;
        c=c->next;
        if(c==head) break;
    }
    return;
}
void afisare2 (Casa *c)
{

    int i;
    c=head2;
    i=0;
    printf("Info despre elementele listei: \n");
    while(c)
    {
        printf("Element %d: \n", i+1);
        printf("Adressa:%s\nTelefon:%s\nSuprafata:%s\nOdai:%d\nCost:%s \nAdresa elementului curent:%p\nAdresa elementului urmator:%p\n", c->adresa, c->telefon, c->suprafata,c->odai,c->cost,c,c->next);
        i++;
        c=c->next;
        if(c==head2) break;
    }
    return;
}

Casa* cautare(int temp)
{
    Casa *c;
    int count=0;
    c=head;
    for(Casa *c=head; c!=NULL; c=c->next)
    {
        if(count==temp-1)
        {
//            printf("Adressa:%s\nTelefon:%s\nSuprafata:%s\nOdai:%d\nCost:%s\n", c->adresa, c->telefon, c->suprafata,c->odai,c->cost);
            return c;
        }
        count++;
    }
    printf("nu sa gasit elementul");
//    printf("Adressa:%s\nTelefon:%s\nSuprafata:%s\nOdai:%d\nCost:%s\n", c->adresa, c->telefon, c->suprafata,c->odai,c->cost);
}

void modifica()
{
    int temp,count=0;
    Casa *c;
    c=head;
    printf("Al citulea elem aveti nevoie: ");
    scanf("%d",&temp);
    for(Casa *c=head; c!=NULL; c=c->next)
    {
        if(count==temp-1)
        {
            printf("Dati adressa:\n ");
            scanf("%s", &c->adresa);
            printf("Dati nr de telefon:\n ");
            scanf("%s", &c->telefon);
            printf("Dati suprafata:\n ");
            scanf("%s", &c->suprafata);
            printf("Dati odai:\n ");
            scanf("%d", &c->odai);
            printf("Dati cost:\n ");
            scanf("%s", &c->cost);
            return ;
        }
        count++;
    }
    printf("nu sa gasit elementul");
}

void ultimulelement()
{
    Casa *c;
    c=head;
    while(c->next!=NULL)
    {
        c=c->next;
        if(c->next==head)
            break;
    }
    printf("Adresa ultimului element al listei: %p \n ", c);
}

int lungimea()
{
    Casa *c;
    int temp,count=0;
    c=head;
    for(Casa *c=head; c!=NULL; c=c->next)
    {
        count++;
    }
    return count;
}

void schimb (Casa* c1, Casa *c2)
{
    Casa temp;
    Casa *tc1, *tc2;
    tc1=c1->next;
    tc2=c2->next;
    temp=*c1;
    *c1=*c2;
    *c2=temp;
    c1->next=tc1;
    c2->next=tc2;
    return;
}
void sortare()
{
    Casa *c1,*c2;
    int n;
    n=lungimea();
    for(int i=0; i<n-1; i++)
    {
        c1=head;
        c2=c1->next;
        for(int j=0; j<n-1-i; j++)
        {
            if((c1->odai) > (c2->odai))
            {
                schimb(c1,c2);
            }
            c1=c1->next;
            c2=c2->next;
        }
    }
}

void eliberare()
{
    Casa *c,*temp;
    c=head;
    while(c)
    {
        temp=c;
        c=c->next;
        free(temp);
    }
    head=NULL;
    return;
}

Casa* adaugaresfarsit()
{
    Casa *c,*temp;
    temp=(Casa*)malloc(sizeof(Casa));
    c=head;
    printf("Introduceti datele despre casa noua:\n");
    printf("Dati adresa casei:\n");
    scanf("%s",&temp->adresa);
    printf("Dati nr de telefon:\n");
    scanf("%s",&temp->telefon);
    printf("Dati suprafata casei:\n");
    scanf("%s",&temp->suprafata);
    printf("Dati nr de odai in casa:\n");
    scanf("%d",&temp->odai);
    printf("Dati pretul casei:\n");
    scanf("%s",&temp->cost);
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
    }
    else
    {
        while(c)
        {
            if(c->next==NULL)
            {
                c->next=temp;
                temp->next=NULL;
            }
            c=c->next;
        }
    }

}
Casa* adaugareinceput()
{
    Casa *c,*temp;
    temp=(Casa*)malloc(sizeof(Casa));
    printf("Introduceti datele despre casa noua:\n");
    printf("Dati adresa casei:\n");
    scanf("%s",&temp->adresa);
    printf("Dati nr de telefon:\n");
    scanf("%s",&temp->telefon);
    printf("Dati suprafata casei:\n");
    scanf("%s",&temp->suprafata);
    printf("Dati nr de odai in casa:\n");
    scanf("%d",&temp->odai);
    printf("Dati pretul casei:\n");
    scanf("%s",&temp->cost);
    if(head==NULL)
    {
        head=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=head;
        head=temp;//intrebare cum dece?
    }
}
Casa* adaugadupa()
{
    Casa *c,*temp;
    c=head;
    int nr;
    printf("Al citulea elem aveti nevoie");
    scanf("%d",&nr);
    temp=(Casa*)malloc(sizeof(Casa));
    printf("Introduceti datele despre casa noua:\n");
    printf("Dati adresa casei:\n");
    scanf("%s",&temp->adresa);
    printf("Dati nr de telefon:\n");
    scanf("%s",&temp->telefon);
    printf("Dati suprafata casei:\n");
    scanf("%s",&temp->suprafata);
    printf("Dati nr de odai in casa:\n");
    scanf("%d",&temp->odai);
    printf("Dati pretul casei:\n");
    scanf("%s",&temp->cost);
    c=cautare(nr);
    temp->next=c->next;
    c->next=temp;
}

Casa* adaugareinainte()
{
    Casa *c,*temp;
    int nr;
    c=head;
    printf("Al citulea elem aveti nevoie");
    scanf("%d",&nr);
    temp=(Casa*)malloc(sizeof(Casa));
    printf("Introduceti datele despre casa noua:\n");
    printf("Dati adresa casei:\n");
    scanf("%s",&temp->adresa);
    printf("Dati nr de telefon:\n");
    scanf("%s",&temp->telefon);
    printf("Dati suprafata casei:\n");
    scanf("%s",&temp->suprafata);
    printf("Dati nr de odai in casa:\n");
    scanf("%d",&temp->odai);
    printf("Dati pretul casei:\n");
    scanf("%s",&temp->cost);
    c=predecesor(nr);
    temp->next=c->next;
    c->next=temp;
}
Casa* predecesor(int temp)
{
    Casa *c;
    int count=0;
    c=head;
    for(Casa *c=head; c!=NULL; c=c->next)
    {
        if(count==temp-2)
        {
            return c;
        }
        count++;
    }
    printf("nu sa gasit elementul");

}
void stergere()
{
    Casa *c,*p;
    int temp;
    printf("Al citulea elem aveti nevoie");
    scanf("%d",&temp);
    c=cautare(temp);
    p=predecesor(temp);
    p->next=c->next;
    free(c);
}
int salvare(char *fname)
{
    Casa *c;
    c=head;
    FILE *fp;
    fp=fopen(fname,"w");
    if(fp==NULL)
    {
        return 0;
    }
    while(c)
    {
        fprintf(fp, "%s %s %s %d %s ",c->adresa,c->telefon,c->suprafata,c->odai,c->cost);
        c=c->next;
    }
    fclose(fp);
    return 1;
}
int citire(char *fname)
{
    Casa *c,*p;
    c=head;
    FILE *fp;
    fp=fopen(fname,"r");
    if(fp==NULL)
    {
        return 0;
    }
    while(c)
    {
        fscanf(fp, "%s%s%s%d%s",&c->adresa,&c->telefon,&c->suprafata,&c->odai,&c->cost);
        c=c->next;
    }
    fclose(fp);
    return 1;
}

void impartire()
{
    Casa *c,*p,*r;
    int temp;
    printf("Al citulea elem aveti nevoie");
    scanf("%d",&temp);
    c=head;
    c=predecesor(temp);
    p=cautare(temp);
    c->next=NULL;
    head2=p;
    afisare(c);
    afisare2(head2);
}

void lipire()
{
    Casa *c;
    c=head;
    while(c)
    {
        if(c->next==NULL)
        {
            c->next=head2;
            head2=NULL;
            break;
        }
        c=c->next;
    }
}
