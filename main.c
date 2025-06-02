#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "partida4.h"
#include "carta.h"
#include "embaralho.h"
#include "rodada4.h"


int main()
{

    srand(time(NULL)); 
    
    int escolha=-1;

    do{
    
    printf("\n quantos jogadores vao jogar:\n[1]4 jogadores\n[2]2 jogadores\n[3]jogar contra maquina\n[0]sair ");
    scanf("%d",&escolha);
     
    switch (escolha)
    {
       case 1:Partida4();
             
        break;
    
       case 2:printf("\n AINDA NAO FOI IMPLEMENTADO");

        break;

        case 3:printf("\n AINDA NAO FOI IMPLEMENTADO");

        break;
    }

    }while(escolha!=0);

    
 

       printf("\nOBRIGADO POR USARR :)\n");


}


