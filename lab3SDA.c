#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "caso.c"


void main ()
{
    Casa *C,*S,*a,*c;
    char asd[50], fname[50];
    int z,temp,x,y,tempcautare;
    int k1,k2;
    printf("Cate case aveti?\n");
    scanf("%d",&z);
    do
    {
        system("cls");
        meniu();
        printf("Ce doriti sa alegeti\n");
        scanf("%d",&temp);

        switch (temp)
        {
        case 1:
            alocare(z);
            printf("Memoria a fost alocata cu succes");
            getch();
            break;
        case 2:
            introduce();
            getch();
            break;
        case 3:
            afisare(c);
            getch();
            break;
        case 4:
            printf("Al citulea elem aveti nevoie");
            scanf("%d",&temp);
            C=cautare(temp);
            printf("Adressa:%s\nTelefon:%s\nSuprafata:%s\nOdai:%d\nCost:%s\n", C->adresa, C->telefon, C->suprafata,C->odai,C->cost);
            getch();
            break;
        case 5:
            modifica();
            getch();
            break;
        case 6:
            ultimulelement();
            getch();
            break;
        case 7:
            k1=lungimea();
            printf("Lungimea liste %d",k1);
            getch();
            break;
        case 8:
            printf("Faceti schimbul a 2 elemente\n");
             printf("Al citulea elem aveti nevoie");
    scanf("%d",&temp);
            C=cautare(temp);
             printf("Al citulea elem aveti nevoie");
    scanf("%d",&temp);
            S=cautare(temp);
            schimb(C,S);
            getch();
            break;
        case 9:
            sortare();
            printf("Sortarea sa efectuat cu success");
            getch();
            break;
        case 10:
            adaugaresfarsit();
            getch();
            break;
        case 11:
            adaugareinceput();
            getch();
            break;
        case 12:
            adaugadupa();
            getch();
            break;
        case 13:
            adaugareinainte();
            getch();
            break;
        case 14:
            stergere();
            getch();
            break;
        case 15:
            impartire(head,head2);
            getch();
            break;
        case 16:
            lipire();
            getch();
            break;
        case 17:
            puts("Dati numele fisierului:");
            fflush(stdin);
            gets(fname);
            x=salvare(fname);
            if(x==1)
                puts("Citirea din fisier s-a efectuat cu succes");
            else
                puts("Fisierul nu a fost deschis");
            getch();
            break;
        case 18:
            puts("Dati numele fisierului:");
            fflush(stdin);
            gets(fname);
            x=citire(fname);
            if(x==1)
                puts("Citirea din fisier s-a efectuat cu succes");
            else
                puts("Fisierul nu a fost deschis");
            getch();
            break;
        case 19:
            eliberare();
            printf("Eliberarea sa efectuat cu success");
            getch();
            break;
        }

    }
    while(temp!=0);
}


