#include <stdio.h>
#include <stdlib.h>
#include "f.h"

saveable p;
int  main(){
         p.counter =0;
    int choix=0;
    readData(&p);
    do {
        system("cls");
        printf("MENU\n1:add per\n2:remove per\n3:edit per\n4:list\n5:quite");
        scanf("%d",&choix);
        switch(choix){
            case 1:
               add(&p);
                break;
            case 2:
                removeP(&p);
                getchar();
                break;
            case 3:
                editR(&p);
                getchar();
                break;
            case 4:
                listR(&p);
                getchar();
                break;
            case 5:
                writeData(&p);
                break;
            default:
                printf("invalid option\n");
                break;
        }

    }while(choix != 5);
}