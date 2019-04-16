//
// Created by raquelcosta on 29-03-2019.
//

#include <stdio.h>
#include "estado.h"
#include <ctype.h>
#include <stdlib.h>
const VALOR inv[] = {VAZIA,VALOR_O,VALOR_X};

void printa(ESTADO e)
{
    char c = ' ';


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }

}

ESTADO inicia (ESTADO e, VALOR v){
    e.peca=v;
    e.modo=0;
    int i;
    int j=0;
    for(i=0;i <= 7;i++){
        for(j=0;j<=7;j++)
        e.grelha[i][j]=VAZIA;
    }
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;
    //printa(e);
    return e;
}

ESTADO valida(ESTADO e,int l,int c) {
    int deixa = 0;
    int deixa1=0;
    int posc = 0;
    // Este
    int i = l, j = c + 1;
    while ((j <= 7)&&(e.grelha[i][j] != e.peca)) { j++; }
    posc = j;
    if ((j <= 7)&&(e.grelha[i][j] == e.peca)) {
        j--;
        while (j != c){
            if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa1 = 1;
            else deixa1 = 0;
            j--;
        }
    }
    if (deixa1 == 1) {
        while (j != posc) {
            if (e.peca == VALOR_O) e.grelha[l][j] = VALOR_O;
            else if (e.peca == VALOR_X) e.grelha[l][j] = VALOR_X;
            j++;
        }
    }
    // Oeste
    int deixa2=0;
    i=l;j=c-1;
    while ((j>=0)&&(e.grelha[i][j] != e.peca)){j--;}
    posc=j;
    if((j>=0)&&(e.grelha[i][j]==e.peca)){
        j++;
        while(j!=c){
            if ((e.grelha[i][j] != e.peca)&&(e.grelha[i][j] != VAZIA)) deixa2=1;
            else deixa2=0;
            j++;
        }
    }
    if (deixa2 == 1) {
        while (j != posc) {
            if (e.peca == VALOR_O) e.grelha[l][j] = VALOR_O;
            else if (e.peca == VALOR_X) e.grelha[l][j] = VALOR_X;
            j--;
        }
    }
    //Sul
    int deixa3=0;
    i=l+1;j=c;
    while ((i<=7)&&(e.grelha[i][j] != e.peca)){i++;}
    posc=i;
    if((i<=7)&&(e.grelha[i][j]==e.peca)){
        i--;
        while(i!=l){
            if ((e.grelha[i][j] != e.peca)&&(e.grelha[i][j] != VAZIA)) deixa3=1;
            else deixa3=0;
            i--;
        }
    }
    if (deixa3==1){
        while (i != posc){
            if (e.peca==VALOR_O) e.grelha[i][c] = VALOR_O;
            else if (e.peca==VALOR_X) e.grelha[i][c] = VALOR_X;
            i++;
        }
    }
    //Norte
    int deixa4=0;
    i=l-1;j=c;
    while ((i>=0)&&(e.grelha[i][j] != e.peca)){i--;}
    posc=i;
    if((i>=0)&&(e.grelha[i][j]==e.peca)){
        i++;
        while(i!=l){
            if ((e.grelha[i][j] != e.peca)&&(e.grelha[i][j] != VAZIA)) deixa4=1;
            else deixa4=0;
            i++;
        }
    }
    if (deixa4==1){
        while (i != posc){
            if (e.peca==VALOR_O) e.grelha[i][c] = VALOR_O;
            else if (e.peca==VALOR_X) e.grelha[i][c] = VALOR_X;
            i--;
        }
    }
    // SudEste
    int deixa5=0;
    i=l+1;j=c+1;
    while ((i<=7)&&(j<=7)&&(e.grelha[i][j] != e.peca)){i++;j++;}
    int posx=i;
    int posy=j;
    if((i<=7)&&(j<=7)&&(e.grelha[i][j]==e.peca)){
        i--;
        j--;
        while((i!=l)&&(j!=c)){
            if ((e.grelha[i][j] != e.peca)&&(e.grelha[i][j] != VAZIA)) deixa5=1;
            else deixa5=0;
            i--;
            j--;
        }
    }
    if (deixa5==1){
        while ((i != posx)&&( j!= posy)){
            if (e.peca==VALOR_O) e.grelha[i][j] = VALOR_O;
            else if (e.peca==VALOR_X) e.grelha[i][j] = VALOR_X;
            i++;
            j++;
        }
    }
    // NorOeste
    int deixa6=0;
    i=l-1;j=c-1;
    while ((i>=0)&&(j>=0)&&(e.grelha[i][j] != e.peca)){i--;j--;}
    posx=i;
    posy=j;
    if((i>=0)&&(j>=0)&&(e.grelha[i][j]==e.peca)){
        i++;
        j++;
        while((i!=l)&&(j!=c)){
            if ((e.grelha[i][j] != e.peca)&&(e.grelha[i][j] != VAZIA)) deixa6=1;
            else deixa6=0;
            i++;
            j++;
        }
    }
    if (deixa6==1){
        while ((i != posx)&&( j!= posy)){
            if (e.peca==VALOR_O) e.grelha[i][j] = VALOR_O;
            else if (e.peca==VALOR_X) e.grelha[i][j] = VALOR_X;
            i--;
            j--;
        }
    }
    //SudOeste
    int deixa7=0;
    i=l+1;j=c-1;
    while ((i<=7)&&(j>=0)&&(e.grelha[i][j] != e.peca)){i++;j--;}
    posx=i;
    posy=j;
    if((i<=7)&&(j>=0)&&(e.grelha[i][j]==e.peca)){
        i--;
        j++;
        while((i!=l)&&(j!=c)){
            if ((e.grelha[i][j] != e.peca)&&(e.grelha[i][j] != VAZIA)) deixa7=1;
            else deixa7=0;
            i--;
            j++;
        }
    }
    if (deixa7==1){
        while ((i != posx)&&( j!= posy)){
            if (e.peca==VALOR_O) e.grelha[i][j] = VALOR_O;
            else if (e.peca==VALOR_X) e.grelha[i][j] = VALOR_X;
            i++;
            j--;
        }
    }
    //NorEste
    int deixa8=0;
    i=l-1;j=c+1;
    while ((i>=0)&&(j<=7)&&(e.grelha[i][j] != e.peca)){i--;j++;}
    posx=i;
    posy=j;
    if((i>=0)&&(j<=7)&&(e.grelha[i][j]==e.peca)){
        i++;
        j--;
        while((i!=l)&&(j!=c)){
            if ((e.grelha[i][j] != e.peca)&&(e.grelha[i][j] != VAZIA)) deixa8=1;
            else deixa8=0;
            i++;
            j--;
        }
    }
    if (deixa8==1){
        while ((i != posx)&&( j!= posy)){
            if (e.peca==VALOR_O) e.grelha[i][j] = VALOR_O;
            else if (e.peca==VALOR_X) e.grelha[i][j] = VALOR_X;
            i--;
            j++;
        }
    }
    deixa = deixa1+deixa2+deixa3+deixa4+deixa5+deixa6+deixa7+deixa8;
    if (deixa==0){
        printf("Jogada Invalida!");
        if(e.peca==VALOR_X) e.peca=VALOR_O;
        else if(e.peca==VALOR_O) e.peca=VALOR_X;
    }
    return e;
}


ESTADO joga (ESTADO e, int x, int y) {
    e = valida(e,x,y);
    if (e.peca == VALOR_X) {
        e.peca = VALOR_O;
        printf("\nM O\n");
    }
    else if (e.peca == VALOR_O) {
        e.peca = VALOR_X;
        printf("\nM X\n");
    }
    return e;
}


void undo (ESTADO e){}
void load (ESTADO e){}
void save (ESTADO e,char c1){
    FILE *arq;
   // char matriz[8][8];
    //int i,j;
    arq= fopen ("c1.txt","w");
    /*for (j=0;j<8;j++){
        for (i=0;i<8;i++) {
        matriz[i][j]= e.grelha[i][j];
        fputc (matriz[i][j],arq);
        }
    } */
    fputs ("ola",arq);
    fclose(arq);
}

void sugestao (ESTADO e){}
void help (ESTADO e) {}


int menu () {
    printf("Lista de comandos\n");
    printf("N: Iniciar o jogo\n");
    printf("J: Efetuar uma jogada\n");
    printf("U: Desfazer jogada\n");
    printf("L: Carregar jogo\n");
    printf("E: Salvar jogo\n");
    printf("S: Sugestão de jogada\n");
    printf("H: Ajuda\n");
    printf("A: Jogador vs Bot\n");
    printf("Q: Sair do jogo\n");
    printf("\nEscolha uma opção:");
}
