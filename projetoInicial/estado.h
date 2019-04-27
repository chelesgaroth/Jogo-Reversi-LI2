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
ESTADO load (ESTADO ,char []);
void save (ESTADO ,char []);
int validar(ESTADO e,int l,int c);
void printarmos(ESTADO e);
ESTADO sugestao (ESTADO e);
void help (ESTADO e);
int contador (ESTADO e);
ESTADO bot (ESTADO e, char c2,char c3);
ESTADO facil (ESTADO e,char c3);
ESTADO medio (ESTADO e,char c3);
ESTADO dificil (ESTADO e,char c3);
int acabou (ESTADO e);
ESTADO jogabot (ESTADO e,int x, int y);
ESTADO jogadorfacil (ESTADO e);
ESTADO botfacil (ESTADO e);
int menu ();


#endif //PROJETOINICIAL_ESTADO_H
