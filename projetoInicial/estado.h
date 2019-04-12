//
// Created by raquelcosta on 29-03-2019.
//

#ifndef PROJETOINICIAL_ESTADO_H
#define PROJETOINICIAL_ESTADO_H



/*
estado.h
Definição do estado i.e. tabuleiro. Representação matricial do tabuleiro.
*/


// definição de valores possiveis no tabuleiro
typedef enum {VAZIA, VALOR_X, VALOR_O} VALOR;

/*
Estrutura que armazena o estado do jogo
*/
typedef struct estado {
    VALOR peca; // peça do jogador que vai jogar!
    VALOR grelha[8][8];
    char modo; // modo em que se está a jogar! 0-> manual, 1-> contra computador
} ESTADO;


void printa(ESTADO);
ESTADO inicia (ESTADO e,VALOR v);
ESTADO valida(ESTADO e,int l,int c);

ESTADO joga (ESTADO e, int x, int y);
void undo (ESTADO e);
void load (ESTADO e);
void save (ESTADO e,char c1);
void sugestao (ESTADO e);
void help (ESTADO e);
int menu ();


#endif //PROJETOINICIAL_ESTADO_H
