#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "embaralho.h"
#include "rodada4.h"
#include "partida4.h"

//inicio das partidas,vulgo ate 12 pontos
void Partida4()
{
    Carta jogadores[4][3];
    Carta baralho[40];
 

    int PontosTime1=0;
    int PontosTime2=0;
    int Time1 = 0;
    int Time2 = 0;
     int Rodada=0;

    //inicio das partidas,valor de 12 pontos
    while(Time1 < 12 && Time2 < 12)
    {
       CriarBaralho(baralho);
       EmbaralharBaralho(baralho);
       DistribuirCartas4(jogadores,baralho);
       RodadaPartida4(jogadores,&PontosTime1,&PontosTime2);

        if(PontosTime1 > PontosTime2)
        {
        printf("\n VENCEDOR DA %d RODADA E O TIME 1",Rodada+1);
        Time1++;
        }
    else if(PontosTime2  > PontosTime1)
        {
            printf("\n VENCEDOR DA %d RODADA E O TIME 2",Rodada+1);
            Time2++;
        }

        Rodada++;
    }



    printf("\n===========================\n");
       if (Time1 >= 12)
           printf("VENCEDOR FINAL: TIME 1\n");
          else if (Time2 >= 12)
            printf("VENCEDOR FINAL: TIME 2\n");

    printf("PLACAR FINAL: TIME 1 = %d | TIME 2 = %d\n", Time1, Time2);
}