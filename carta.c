#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Carta.h"



// Arrays de naipes e valores
char *naipes[4] = {"Copas", "Espadas", "Ouros", "Paus"};
char *valores[10] = {"4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"};


// Função que cria o baralho
void CriarBaralho(Carta baralho[40])
{
    int index = 0;
    for (int i = 0; i < 4; i++) // naipes
    {
        for (int j = 0; j < 10; j++) // valores
        {
            strcpy(baralho[index].naipe, naipes[i]);
            strcpy(baralho[index].valor, valores[j]);
            index++;
        }
    }
}

// Função que embaralha o baralho
void EmbaralharBaralho(Carta baralho[40])
{
    for (int i = 0; i < 40; i++)
    {
        int r = rand() % 40;
        Carta temp = baralho[i];
        baralho[i] = baralho[r];
        baralho[r] = temp;
    }
}




//mostras as cartas sorteadas
void MostrarCarta(Carta jogador[4][3],int i)
{
    printf("\n<-----MENU DE CARTAS----->\n\n");
    for(int k=0;k<3;k++)
    {
    printf("[%d] %s de %s\n",k+1,jogador[i][k].valor,jogador[i][k].naipe);
    }
    printf("\n<------------------------>\n");

}


//sistema para comparar qual carta tem mais peso
int PesoCartas(Carta c)
{
    int peso=0;

  //cartas mais fortes,vulgo manilha
  if(strcmp(c.valor,"4")==0 && strcmp(c.naipe,"Paus")==0)peso=14;

  else if(strcmp(c.valor,"7")==0 && strcmp(c.naipe,"Copas")==0)peso=13;

  else if(strcmp(c.valor,"A")==0 && strcmp(c.naipe,"Espadas")==0)peso=12;

  else if(strcmp(c.valor,"7")==0 && strcmp(c.naipe,"Ouros")==0)peso=11;

  //cartas padrao
   else if(strcmp(c.valor,"3")==0)peso=10;

   else if(strcmp(c.valor,"2")==0)peso=9;

   else if(strcmp(c.valor,"A")==0)peso=8;

   else if(strcmp(c.valor,"K")==0)peso=7;

   else if(strcmp(c.valor,"J")==0)peso=6;

   else if(strcmp(c.valor,"Q")==0)peso=5;

   else if(strcmp(c.valor,"7")==0)peso=4;

   else if(strcmp(c.valor,"6")==0)peso=3;

   else if(strcmp(c.valor,"5")==0)peso=2;
   
   else if(strcmp(c.valor,"4")==0)peso=1;

   return peso;
}
