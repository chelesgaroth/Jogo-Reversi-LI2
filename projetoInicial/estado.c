//
// Created by edi8b on 16/04/2019.
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
    // função que avalia se é válido jogar numa dada posição

    int deixa = 0;
    int deixa1=0,deixa2=0,deixa3=0,deixa4=0,deixa5=0,deixa6=0,deixa7=0,deixa8=0;
    int posc = 0;
    if (e.grelha [l][c] == VAZIA) {
        // Este
        int i = l, j = c + 1;
        if (e.grelha[l][c+1]!=e.peca) {
            while ((j <= 7) && (e.grelha[i][j] != e.peca)) { j++; }
            posc = j;
            if ((j <= 7) && (e.grelha[i][j] == e.peca)) {
                j--;
                deixa1 = 1;
                while ((j != c) && (deixa1 == 1)) {
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
        }
        else deixa1=0;


        // Oeste
        i = l;
        j = c - 1;
        if (e.grelha[l][c-1]!=e.peca) {
            while ((j >= 0) && (e.grelha[i][j] != e.peca)) { j--; }
            posc = j;
            if ((j >= 0) && (e.grelha[i][j] == e.peca)) {
                j++;
                deixa2 = 1;
                while ((j != c) && (deixa2 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa2 = 1;
                    else deixa2 = 0;
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
        }
        else deixa2=0;


        //Sul
        i = l + 1;
        j = c;
        if (e.grelha[l+1][c]!=e.peca) {
            while ((i <= 7) && (e.grelha[i][j] != e.peca)) { i++; }
            posc = i;
            if ((i <= 7) && (e.grelha[i][j] == e.peca)) {
                i--;
                deixa3 = 1;
                while ((i != l) && (deixa3 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa3 = 1;
                    else deixa3 = 0;
                    i--;
                }
            }
            if (deixa3 == 1) {
                while (i != posc) {
                    if (e.peca == VALOR_O) e.grelha[i][c] = VALOR_O;
                    else if (e.peca == VALOR_X) e.grelha[i][c] = VALOR_X;
                    i++;
                }
            }
        }
        else deixa3=0;


        //Norte
        i = l - 1;
        j = c;
        if (e.grelha[l-1][c]!=e.peca) {
            while ((i >= 0) && (e.grelha[i][j] != e.peca)) { i--; }
            posc = i;
            if ((i >= 0) && (e.grelha[i][j] == e.peca)) {
                i++;
                deixa4 = 1;
                while ((i != l) && (deixa4 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa4 = 1;
                    else deixa4 = 0;
                    i++;
                }
            }
            if (deixa4 == 1) {
                while (i != posc) {
                    if (e.peca == VALOR_O) e.grelha[i][c] = VALOR_O;
                    else if (e.peca == VALOR_X) e.grelha[i][c] = VALOR_X;
                    i--;
                }
            }
        }
        else deixa4=0;

        // SudEste
        i = l + 1;
        j = c + 1;
        if (e.grelha[l+1][c+1]!=e.peca) {
            while ((i <= 7) && (j <= 7) && (e.grelha[i][j] != e.peca)) {
                i++;
                j++;
            }
            int posx = i;
            int posy = j;
            if ((i <= 7) && (j <= 7) && (e.grelha[i][j] == e.peca)) {
                i--;
                j--;
                deixa5 = 1;
                while ((i != l) && (j != c) && (deixa5 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa5 = 1;
                    else deixa5 = 0;
                    i--;
                    j--;
                }
            }
            if (deixa5 == 1) {
                while ((i != posx) && (j != posy)) {
                    if (e.peca == VALOR_O) e.grelha[i][j] = VALOR_O;
                    else if (e.peca == VALOR_X) e.grelha[i][j] = VALOR_X;
                    i++;
                    j++;
                }
            }
        }
        else deixa5=0;


        // NorOeste
        i = l - 1;
        j = c - 1;
        if (e.grelha[l-1][c-1]!=e.peca) {
            while ((i >= 0) && (j >= 0) && (e.grelha[i][j] != e.peca)) {
                i--;
                j--;
            }
            int posx = i;
            int posy = j;
            if ((i >= 0) && (j >= 0) && (e.grelha[i][j] == e.peca)) {
                i++;
                j++;
                deixa6 = 1;
                while ((i != l) && (j != c) && (deixa6 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa6 = 1;
                    else deixa6 = 0;
                    i++;
                    j++;
                }
            }
            if (deixa6 == 1) {
                while ((i != posx) && (j != posy)) {
                    if (e.peca == VALOR_O) e.grelha[i][j] = VALOR_O;
                    else if (e.peca == VALOR_X) e.grelha[i][j] = VALOR_X;
                    i--;
                    j--;
                }
            }
        }
        else deixa6=0;


        //SudOeste
        i = l + 1;
        j = c - 1;
        if (e.grelha[l+1][c-1]!=e.peca) {
            while ((i <= 7) && (j >= 0) && (e.grelha[i][j] != e.peca)) {
                i++;
                j--;
            }
            int posx = i;
            int posy = j;
            if ((i <= 7) && (j >= 0) && (e.grelha[i][j] == e.peca)) {
                i--;
                j++;
                deixa7 = 1;
                while ((i != l) && (j != c) && (deixa7 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa7 = 1;
                    else deixa7 = 0;
                    i--;
                    j++;
                }
            }
            if (deixa7 == 1) {
                while ((i != posx) && (j != posy)) {
                    if (e.peca == VALOR_O) e.grelha[i][j] = VALOR_O;
                    else if (e.peca == VALOR_X) e.grelha[i][j] = VALOR_X;
                    i++;
                    j--;
                }
            }
        }
        else deixa7=0;

        //NorEste
        i = l - 1;
        j = c + 1;
        if (e.grelha[l-1][c+1]!=e.peca) {
            while ((i >= 0) && (j <= 7) && (e.grelha[i][j] != e.peca)) {
                i--;
                j++;
            }
            int posx = i;
            int posy = j;
            if ((i >= 0) && (j <= 7) && (e.grelha[i][j] == e.peca)) {
                i++;
                j--;
                deixa8 = 1;
                while ((i != l) && (j != c) && (deixa8 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa8 = 1;
                    else deixa8 = 0;
                    i++;
                    j--;
                }
            }
            if (deixa8 == 1) { //troca as peças do tabuleiro
                while ((i != posx) && (j != posy)) {
                    if (e.peca == VALOR_O) e.grelha[i][j] = VALOR_O;
                    else if (e.peca == VALOR_X) e.grelha[i][j] = VALOR_X;
                    i--;
                    j++;
                }
            }
        }
        else deixa8=0;
        //final
        deixa = deixa1+deixa2+deixa3+deixa4+deixa5+deixa6+deixa7+deixa8;
    }
    else deixa=0;

    if (deixa==0){
        printf("Jogada Invalida!");
    }
    return e;
}


ESTADO joga (ESTADO e, int x, int y) {
    // independendo do modo, a funcao avalia se é permitido jogar naquela posição com recurso à função valida
    // troca a peça no final da jogada, para permitir que o outro jogador tenha a sua peça em jogo
        if (e.modo==0) {
            e = valida(e,x,y);
            if (e.peca == VALOR_X) {
                e.peca = VALOR_O;
                printf("\nM O\n");
            }
            else if (e.peca == VALOR_O) {
                e.peca = VALOR_X;
                printf("\nM X\n");
            }
        }
        else if (e.modo==1){
            printf(" no inicio da joga sou %c\n ",e.peca == VALOR_X ? 'X' : 'O');
            e=valida(e,x ,y);
            if (e.peca == VALOR_X) {
                e.peca = VALOR_O;
                printf("\nA O\n");
            }
            else if (e.peca == VALOR_O) {
                e.peca = VALOR_X;
                printf("\nA X\n");
            }
            printf(" no final da joga sou %c\n ",e.peca == VALOR_X ? 'X' : 'O');
        }
        return e;
    }
N


void undo (ESTADO e){}


ESTADO anula (ESTADO e){
    int i,j;

    for (i=0;i<8;i++) {
        for (j = 0; j < 8; j++) {
            e.grelha[i][j]=VAZIA;
        }}
    return e;
}

ESTADO load (ESTADO e,char c1[]) {
    char c;
    char linha[50];
    char t1,t2;
    int i = 0, j = 0;
    FILE *tabuleiro;

    e=anula(e);
    tabuleiro = fopen(c1, "r");


            // 1º linha
    fscanf(tabuleiro,"%c %c",&t1,&t2);
    e.modo = (t1 == 'M' ? 0 : 1);
    e.peca = (t2 == 'X' ? VALOR_X : VALOR_O);
    printf ("%c %c\n",t1, t2);

    for (i=0;i<8;i++) {
        for (j = 0; j < 8; j++) {

            fscanf(tabuleiro, "%s ", &c);
            switch (c) {
                case 'X': {
                    e.grelha[i][j] = VALOR_X;
                    break;
                }
                case 'O': {
                    e.grelha[i][j] = VALOR_O;
                    break;
                }

                case '-': {
                    e.grelha[i][j] = VAZIA;
                    break;
                }

               default:{break;}
            }
        }
    }
    fclose(tabuleiro);

    return e;
}

//escreve o ficheiro da grelha
void save (ESTADO e,char c1[])
{
    int i,j;
    char modo,jogador ;
    char c = ' ';
    FILE *fPointer;
    fPointer = fopen(c1,"w");
    modo= (e.modo == 0 ? 'M' : 'A');
    jogador = (e.peca == VALOR_X ? 'X' : 'O');
    fprintf (fPointer,"%c %c\n",modo,jogador);
    for (i=0;i<8;i++) {
       for (j=0;j<8;j++) {
          switch(e.grelha[i][j]) {
              case VALOR_X:
                  {
                  c = 'X';
                  break;}
              case VALOR_O:
                  {
                  c = 'O';
                  break;}
              case VAZIA:
                  {
                  c = '-';
                  break;}
          }
           fprintf(fPointer,"%c ",c);
       }
       fprintf(fPointer,"\n");
    }
    fclose(fPointer);
}

// Esta função diz-nos se é possível jogar na posiçao linha l e coluna c ; >= 1 é possível ; =0 nao é possível ;

int validar(ESTADO e,int l,int c) {
    int deixa = 0;
    if(e.grelha[l][c]== VAZIA) {
        int deixa1 = 0;
        // Este
        int i = l, j = c + 1;
        if (e.grelha[l][c+1]!=e.peca) {
            while ((j <= 7) && (e.grelha[i][j] != e.peca)) { j++; }
            if ((j <= 7) && (e.grelha[i][j] == e.peca)) {
                j--;
                deixa1 = 1;
                while ((j != c) && (deixa1 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa1 = 1;
                    else deixa1 = 0;
                    j--;
                }
            }
        }
        else deixa1=0;

        // Oeste
        int deixa2 = 0;
        i = l;
        j = c - 1;
        if (e.grelha[l][c-1]!=e.peca) {
            while ((j >= 0) && (e.grelha[i][j] != e.peca)) { j--; }
            if ((j >= 0) && (e.grelha[i][j] == e.peca)) {
                j++;
                deixa2 = 1;
                while ((j != c) && (deixa2 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa2 = 1;
                    else deixa2 = 0;
                    j++;
                }
            }
        }
        else deixa2=0;

        //Sul
        int deixa3 = 0;
        i = l + 1;
        j = c;
        if (e.grelha[l+1][c]!=e.peca) {
            while ((i <= 7) && (e.grelha[i][j] != e.peca)) { i++; }
            if ((i <= 7) && (e.grelha[i][j] == e.peca)) {
                i--;
                deixa3 = 1;
                while ((i != l) && (deixa3 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa3 = 1;
                    else deixa3 = 0;
                    i--;
                }
            }
        }
        else deixa3=0;

        //Norte
        int deixa4 = 0;
        i = l - 1;
        j = c;
        if (e.grelha[l-1][c]!=e.peca) {
            while ((i >= 0) && (e.grelha[i][j] != e.peca)) { i--; }
            if ((i >= 0) && (e.grelha[i][j] == e.peca)) {
                i++;
                deixa4 = 1;
                while ((i != l) && (deixa4 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa4 = 1;
                    else deixa4 = 0;
                    i++;
                }
            }
        }
        else deixa4=0;

        // SudEste
        int deixa5 = 0;
        i = l + 1;
        j = c + 1;
        if (e.grelha[l+1][c+1]!=e.peca) {
            while ((i <= 7) && (j <= 7) && (e.grelha[i][j] != e.peca)) {
                i++;
                j++;
            }
            if ((i <= 7) && (j <= 7) && (e.grelha[i][j] == e.peca)) {
                i--;
                j--;
                deixa5 = 1;
                while ((i != l) && (j != c) && (deixa5 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa5 = 1;
                    else deixa5 = 0;
                    i--;
                    j--;
                }
            }
        }
        else deixa5=0;

        // NorOeste
        int deixa6 = 0;
        i = l - 1;
        j = c - 1;
        if (e.grelha[l-1][c-1]!=e.peca) {
            while ((i >= 0) && (j >= 0) && (e.grelha[i][j] != e.peca)) {
                i--;
                j--;
            }
            if ((i >= 0) && (j >= 0) && (e.grelha[i][j] == e.peca)) {
                i++;
                j++;
                deixa6 = 1;
                while ((i != l) && (j != c) && (deixa6 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa6 = 1;
                    else deixa6 = 0;
                    i++;
                    j++;
                }
            }
        }
        else deixa6=0;

        //SudOeste
        int deixa7 = 0;
        i = l + 1;
        j = c - 1;
        if (e.grelha[l+1][c-1]!=e.peca) {
            while ((i <= 7) && (j >= 0) && (e.grelha[i][j] != e.peca)) {
                i++;
                j--;
            }
            if ((i <= 7) && (j >= 0) && (e.grelha[i][j] == e.peca)) {
                i--;
                j++;
                deixa7 = 1;
                while ((i != l) && (j != c) && (deixa7 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa7 = 1;
                    else deixa7 = 0;
                    i--;
                    j++;
                }
            }
        }
        else deixa7=0;

        //NorEste
        int deixa8 = 0;
        i = l - 1;
        j = c + 1;
        if (e.grelha[l-1][c+1]!=e.peca) {
            while ((i >= 0) && (j <= 7) && (e.grelha[i][j] != e.peca)) {
                i--;
                j++;
            }
            if ((i >= 0) && (j <= 7) && (e.grelha[i][j] == e.peca)) {
                i++;
                j--;
                deixa8 = 1;
                while ((i != l) && (j != c) && (deixa8 == 1)) {
                    if ((e.grelha[i][j] != e.peca) && (e.grelha[i][j] != VAZIA)) deixa8 = 1;
                    else deixa8 = 0;
                    i++;
                    j--;
                }
            }
        }
        else deixa8=0;

        deixa = deixa1 + deixa2 + deixa3 + deixa4 + deixa5 + deixa6 + deixa7 + deixa8;
    }
    else deixa=0;

    return deixa;
}

// printar todas a jogadas possíveis para o jogador em jogo

void printarmos(ESTADO e){
    char d = ' ';
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((e.grelha[i][j]== VAZIA) && (validar(e,i,j)!=0)) d= '*';
            else if ((e.grelha[i][j]==VAZIA) && (validar(e,i,j)==0)) d='-';
            else if (e.grelha[i][j]==VALOR_O) d = 'O';
            else if(e.grelha[i][j]==VALOR_X) d ='X';

            printf("%c ", d);
        }
        printf("\n");
    }
}


ESTADO sugestao (ESTADO e){
    if (e.peca == VALOR_O) printf("\nM O\n");
    else if (e.peca == VALOR_X) printf("\nM X\n");
    printarmos(e);
    return e;
}
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

int contador (ESTADO e) {
    int x=0;
    int o=0;
    int soma=0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (e.grelha[i][j]==VALOR_X) {
                x++;
            }
            else  if (e.grelha[i][j]==VALOR_O)
                o++;
        }
        }
    printf ("X:%d     ",x);
    printf ("    O:%d \n",o);
    soma = x+o;
    return soma;

}

int acabou (ESTADO e){
    int final=0;
    int validacao=0;
    int i,j;
    int contar;
    int x=0;
    int o=0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (e.grelha[i][j]==VALOR_X) {
                x++;
            }
            else  if (e.grelha[i][j]==VALOR_O)
                o++;
        }
    }
    contar =x+o;

    j=0;
    i=0;
    e.peca=VALOR_X;
    while ((validar(e, i, j) == 0) && (i<8) && (j<8)) {
        for (i = 0; i < 8; i++) {
            for (j = 0; (j < 8); j++) {
            }
        }
        validacao=0;
    }
    if(validar(e,i,j)!=0) validacao=1;
    e.peca=VALOR_O;
    i=0;
    j=0;
    while ((validacao==0)&&(validar(e, i, j) == 0) && (i<8) && (j<8)) {
        for (i = 0; i < 8; i++) {
            for (j = 0; (j < 8); j++) {
            }
        }
        validacao=0;
    }
    if(validar(e,i,j)!=0) validacao=1;

    if ((contar==64) || (validacao==0)) final=1;
    else final=0;
    return final;

}

// final=0 o jogo ainda nao acabou


ESTADO jogadorfacil (ESTADO e) {
    // com recurso aos comandos, esra função apenas permite alerta ao jogador para efetuar a sua jogada
    // através do comando J
    printf(" jogador joga es o %c\n ",e.peca == VALOR_X ? 'X' : 'O');
    e.modo=1;
    printf("Efetue a sua jogada, através do comando J\n");

    return e;
}


ESTADO botfacil (ESTADO e) {
    // Função onde o bot joga, estratégia: percorre todos as posições, a primeira onde for valido jogar, efetua a jogada
    // e sai do ciclo, ou seja, passa a vez ao jogador;
    printf(" no inicio do bot sou %c\n ",e.peca == VALOR_X ? 'X' : 'O');
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if (validar(e,i,j)!= 0) {
                e=joga(e,i,j);
                printa(e);
                i=8; j=8;


            }
        }
    }
    contador(e);
    e=jogadorfacil(e);
    printf(" no final do bot sou %c \n",e.peca == VALOR_X ? 'X' : 'O');
    return e;
}



ESTADO facil (ESTADO e, char c2) {
    printf(" na funcao facil sou %c\n ",e.peca == VALOR_X ? 'X' : 'O');
    // já selecionado o nível, dependendo da peça que a pessoa selecionou para o bot, começa o jogo pelo jogador ou pelo bot
    // se selecionou X entao o bot começa, caso contrário sera o jogador
    if (c2=='X') {e.peca=VALOR_X;
    e=botfacil(e);}
    else if (c2=='O') {e.peca=VALOR_X;
    e=jogadorfacil(e);}
    return e;
}

ESTADO medio (ESTADO e, char c2){
    return e;
}
ESTADO dificil (ESTADO e, char c2){
    return e;
}

ESTADO bot (ESTADO e, char c2, int c3) {
    // dependendo do nível selecionado pela pessoa, vai a cada auxiliar; é smp acompanhado pela peça que a pessoa
    // selecionou para o bot
    printf(" na funcao bot sou %c \n",e.peca == VALOR_X ? 'X' : 'O');
    if (c3==1)  e=facil(e,c2);
    else if (c3==2) e=medio(e,c2);
    else if (c3==3) e=dificil(e,c2);
    else printf("Nível Inválido\n");
    printf(" no final da funcao bot sou %c \n",e.peca == VALOR_X ? 'X' : 'O');
    return e;

}





