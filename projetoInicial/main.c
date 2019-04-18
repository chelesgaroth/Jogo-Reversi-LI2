#include <stdio.h>
#include <ctype.h>
#include "estado.h"





void comandos ()
{
    ESTADO e = {0};
    char linha[50];
    char c1,c2;
    int x,y;
    do{fgets(linha,50,stdin);
        switch (toupper(linha [0])){
            case 'N': {
                sscanf(linha, "%c %c",&c1,&c2);
                if (c2=='X'){
                    printf("M X\n");
                    e = inicia(e,VALOR_X);

                }
                else if (c2 == 'O'){
                    printf("M O\n");
                    e = inicia (e,VALOR_O);
                }
                printa(e);
                break;
            }
            case 'J' : {
                sscanf(linha," %c %d %d", &c1 ,&x ,&y);
                e = joga (e,x-1,y-1);
                printa(e);
                break;
            }
            case 'Q' : break;
            case 'U': undo(e);
            case 'L': load(e);
            case 'E': {
                sscanf(linha,"%c %c", &c1, &c2);
                save(e,c2);
                 break;}

            case 'S': sugestao(e);
            case 'H': help(e);
            case 'A': /*fazer bot ,e em H tbm.*/ ;

            default: {printf("Comando Inválido!\n");
                break;
            }

        }
    }
    while ((toupper(linha[0]) != 'Q'));
}



int main()
{

    menu();

    printf("\n");
    printf("\n");

    comandos();
    return 0;
}#include <stdio.h>
#include <ctype.h>
#include "estado.h"





void comandos ()
{
    ESTADO e = {0};
    char linha[50];
    char c1,c2;
    int x,y;
    do{fgets(linha,50,stdin);
        switch (toupper(linha [0])){
            case 'N': {
                sscanf(linha, "%c %c",&c1,&c2);
                if (c2=='X'){
                    printf("M X\n");
                    e = inicia(e,VALOR_X);

                }
                else if (c2 == 'O'){
                    printf("M O\n");
                    e = inicia (e,VALOR_O);
                }
                printa(e);
                break;
            }
            case 'J' : {
                sscanf(linha," %c %d %d", &c1 ,&x ,&y);
                e = joga (e,x-1,y-1);
                printa(e);
                break;
            }
            case 'Q' : break;
            case 'U': undo(e);
            case 'L': {
                sscanf (linha,"%c %s", &c1,&c2);
                load(e,c2);

            }

            case 'E': {
                sscanf(linha,"%c %s", &c1, &c2);
                save(e,c2);
                break;}

            case 'S': sugestao(e);
            case 'H': help(e);
            case 'A': /*fazer bot ,e em H tbm.*/ ;

            default: {printf("Comando Inválido!\n");
                break;
            }

        }
    }
    while ((toupper(linha[0]) != 'Q'));
}



int main()
{

    menu();

    printf("\n");
    printf("\n");

    comandos();
    return 0;
}
