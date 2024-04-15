#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 1024
#define FILENAME "data.bin"
typedef struct date{
    int jour;
    int mois;
    int annes;
}Date;

typedef struct personne{
    int nu;
    char nom[20];
    int age;
    Date tarikhh;
    int notes;
}Personne;

typedef struct saveable{
    Personne t[TABLE_SIZE];
    int counter  ;
}saveable;
void add(struct saveable *p)
 {

     printf("donnes le nu\n");
     scanf("%d", &p->t[p->counter].nu);
     printf("donnes le nom\n");
     scanf("%s", &p->t[p->counter].nom);
     printf("donnes l'age\n");
     scanf("%d", &p->t[p->counter].age);
     printf("donnes la date/jour\n");
     scanf("%d", &p->t[p->counter].tarikhh.jour);
     printf("donnes la date/mois\n");
     scanf("%d", &p->t[p->counter].tarikhh.mois);
     printf("donnes la date/annes\n");
     scanf("%d", &p->t[p->counter].tarikhh.annes);
     printf("donnes les notes\n");
     scanf("%d", &p->t[p->counter].notes);
     p->counter++;
 }
void removeP(struct saveable *p){
    int r;
    printf("donner la cas a effacer");
    scanf("%d",&r);
    for (int i = r; i < TABLE_SIZE; ++i) {
        p->t[i]=p->t[i+1];
    }
    p->t[p->counter]=p->t[p->counter+1];
    p->counter=p->counter-1;

}
void editR(struct saveable *p){
    int e;
    printf("donnes la cas a edite");
    scanf("%d",&e);
    printf("edit le nu\n");
    scanf("%d", &p->t[e].nu);
    printf("edit le nom\n");
    scanf("%s", &p->t[e].nom);
    printf("edit l'age\n");
    scanf("%d", &p->t[e].age);
    printf("edit la date/jour\n");
    scanf("%d", &p->t[e].tarikhh.jour);
    printf("edit la date/mois\n");
    scanf("%d", &p->t[e].tarikhh.mois);
    printf("edit la date/annes\n");
    scanf("%d", &p->t[e].tarikhh.annes);
    printf("edit les notes\n");
    scanf("%d", &p->t[e].notes);
}
void listR(struct saveable *p){
    for (int i = 0; i < p->counter; i++) {
        printf("n.u:%d | nom:%s | age:%d | date:%d/%d/%d | notes:%d \n",p->t[i].nu,p->t[i].nom,p->t[i].age,p->t[i].tarikhh.jour,p->t[i].tarikhh.mois,p->t[i].tarikhh.annes,p->t[i].notes);
    }
    getchar();
}

void readData(saveable *t){
    FILE *dbfile = fopen(FILENAME,"rb");
    fread(t, sizeof(saveable ), 1, dbfile);
    fclose(dbfile);
}
void writeData(saveable *t){
    FILE *dbfile = fopen(FILENAME,"wb");
    fwrite( t,sizeof (saveable ),1,dbfile);
    fclose(dbfile);
}