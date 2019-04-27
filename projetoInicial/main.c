#include <stdio.h>
#include <ctype.h>
#include "estado.h"





void comandos ()
{
    ESTADO e = {0};
    char linha[50];
    char c1,c2,nome[40];
    int x,y,c3;
    int escolha=0;
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
                contador (e);
                break;
            }
            case 'J' : {
                sscanf(linha," %c %d %d", &c1 ,&x ,&y);
                e = joga (e,x-1,y-1);
                printa(e);
                contador (e);
                break;
            }
            case 'Q' : break;
            case 'U': undo(e);
            contador (e);
            case 'L': {
                sscanf (linha,"%c %s", &c1,nome);
                e=load(e,nome);
                printa(e);
                contador(e);
                break;

            }

            case 'E': {
                sscanf(linha,"%c %s", &c1, nome);
                save(e,nome);
                printf("Jogo Guardado!\n");
                break;}

            case 'S': {
                sugestao(e);
                contador (e);
                break;
            }
            case 'H': help(e);
            contador (e);
            case 'A': {
                sscanf (linha, "%c %c %d", &c1, &c2, &c3);
                e=bot (e,c1,c2);
                break;
            }


            default: {
                printf("Comando Inválido!\n");
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
