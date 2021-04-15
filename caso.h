typedef struct Casa
{
    char adresa[100];
    char telefon[100];
    char suprafata[100];
    int odai;
    char cost[100];
    struct Casa* next;
} Casa;

Casa *head;
Casa *head2;

int alocare(int z);
void meniu();
void afisare (Casa *c);
void afisare2 (Casa *c);
Casa* cautare(int temp);
void modifica();
void ultimulelement();
int lungimea();
void schimb (Casa* c1, Casa *c2);
void sortare();
void eliberare();
Casa* adaufaresfarsit();
Casa* adaugareainceput();
Casa* adaugadupa();
Casa* adaugareinainte();
Casa* predecesor(int temp);
void stergere();
int salvare(char *fname);
int citire(char *fname);
void impartire();
void lipire();
