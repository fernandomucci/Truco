#include <stdio.h>
#include "embaralho.h"


//distribui as cartas para uma rodada de 4 pessoas,vulgo 2 grupos com duas pessoas
void DistribuirCartas4(Carta Jogadores[4][3],Carta Baralho[40])
{
    int index = 0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                Jogadores[i][j] = Baralho[index++];
            }
        }
}


//distribui as cartas para uma rodada de 2 pessoas
void DistribuirCartas2(Carta Jogadores[2][3],Carta Baralho[40])
{
    int index = 0;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                Jogadores[i][j] = Baralho[index++];
            }
        }
}