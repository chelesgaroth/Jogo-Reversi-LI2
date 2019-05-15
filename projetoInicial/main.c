#include <stdio.h>
#include <ctype.h>
#include "estado.h"



void comandos () {
    ESTADO e = {0};

    char linha[50];
    char c1,c2,nome[40];
    int x,y,c3;
    do{fgets(linha,50,stdin);
        switch (toupper(linha [0])){
            case 'N': {
                e.modo=0;
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
                push(e);
                break;
            }
            case 'J' : {
                // permite efetuar uma jogada tanto em modo 1 ou 0;
                printf("tenho %d jogadas 2",passar(e));
                sscanf(linha,"%c %d %d", &c1 ,&x ,&y);
                if (acabou (e)==1) {
                    if (contadorX(e) > contadorO(e)) printf("Jogo acabou! Vencedor: X!");
                    else if (contadorX(e) < contadorO(e)) printf("Jogo acabou! Vencedor: O!");
                    else printf ("Empate!");

                }
                else {
                    if (e.modo == 0) {
                        if (passar(e)!=0) {
                            e = joga(e, x - 1, y - 1);
                            printa(e);
                            contador(e);
                        }
                        else {
                            printf("Sem Jogadas.Passou a vez.");
                            if (e.peca==VALOR_X)e.peca=VALOR_O;
                            else if(e.peca==VALOR_O)e.peca=VALOR_X;
                        }
                    }
                    else if (e.modo != 0) {
                        printf("tenho %d jogadas",passar(e));
                        // se for "permitido" jogar naquela posição, irá jogar, printar o tabuleiro e passar a jogada ao bot
                        if (passar(e) == 0) {
                            printf("Sem Jogadas.Passou a vez.");
                            if (e.peca == VALOR_X) e.peca = VALOR_O;
                            else if (e.peca == VALOR_O)e.peca = VALOR_X;

                            if (e.modo == 1) botfacil(e);
                            else if (e.modo == 2) botmedio(e);
                            else if (e.modo == 3) botdificil(e);

                        } else {

                            if (validar(e, x - 1, y - 1) != 0) {
                                e = joga(e, x - 1, y - 1);
                                printa(e);
                                contador(e);
                                if (e.modo == 1) e = botfacil(e);
                                else if (e.modo == 2) e = botmedio(e);
                                else if (e.modo == 3) e = botdificil(e);
                            } else {
                                // se nao for "permitido" jogar, imprime no ecrã uma mensagem para o jogador voltar a jogar: NÃO VAI À
                                // FUNÇÂO JOGA
                                jogador(e);

                                if (e.peca == VALOR_X) printf("Try again X\n");
                                else if (e.peca == VALOR_O) printf("Try again O\n");


                            }
                        }
                    }
                    }


                push(e);
                break;
            }
            case 'Q' :
                break;
            case 'U': {
                pop();
                e=undo();
                break;
            }
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
            case 'H':{
                help(e);
                contador (e);
            }
            case 'A': {
                // A peça que inicia é a X.
                e.peca=VALOR_X;
                // Vai à função bot para distribuir pelos diversos níveis
                sscanf(linha,"%c %c %d", &c1 ,&c2 ,&c3);
                if ((c2=='X') || (c2=='O')) {

                    e = bot(e,c2,c3);

                }

                else printf("Jogador Inválido\n");
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



int main(){

    menu();

    printf("\n");
    printf("\n");


    comandos();
    return 0;
}
