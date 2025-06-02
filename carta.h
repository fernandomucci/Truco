#ifndef CARTA_H
#define CARTA_H

typedef struct 
{
    char naipe[10];  
    char valor[3];  

} Carta;


// Arrays de naipes e valores
char *naipes[4];
char *valores[10];



//declarando as funções


// Função que cria o baralho
void CriarBaralho(Carta baralho[40]);

// Função que embaralha o baralho
void EmbaralharBaralho(Carta baralho[40]);

//mostras as cartas sorteadas
void MostrarCarta(Carta jogador[4][3],int i);

//sistema para comparar qual carta tem mais peso
int PesoCartas(Carta c);

  

#endif 