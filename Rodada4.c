
#include <stdio.h>
#include "rodada4.h"
#include <string.h>
#include <stdlib.h>



//rodadas,vulgo 3,vao rodar dentro da partida
void RodadaPartida4(Carta Jogador[4][3],int* time1,int* time2)
{
     int Rodada = 0;
       Carta mesa[4];
       *time1 = 0;
       *time2 = 0;
       int kenga = -1;
       int quemComeca = 0;
        int jogadorKenga = -1;

       //começo das rodadas
        while(Rodada<3 && *time1 < 2 && *time2 < 2)
        {


            //verificação do kenga
                if (kenga == 1) {
                     if (Rodada > 0) {
                        }
                     quemComeca = (quemComeca + 1) % 4;
                        printf("\nDevido ao KENGA, o jogador %d comeca e deve jogar sua maior carta.\n", quemComeca + 1);
                    }


            printf("\n<-----%da RODADA----->\n",Rodada+1);

            //cada jogador joga uma vez
            for(int i = 0; i<4;i ++)
            {
                int jogador = (quemComeca + i) % 4;
                 int escolha=0;

                 //mostra a carta e logo apos pergunta qual quer escolher
                MostrarCarta(Jogador,jogador);


                // Se for quem começa após kenga, joga a carta mais forte
            if (kenga == 1 && i == 0)
            {
                int maiorPeso = -1;
                int indiceMaior = -1;

                for (int c = 0; c < 3; c++)
                {
                    if (strcmp(Jogador[jogador][c].valor, "x") != 0) // carta válida
                    {
                        int peso = PesoCartas(Jogador[jogador][c]);
                        if (peso > maiorPeso)
                        {
                            maiorPeso = peso;
                            indiceMaior = c;
                        }
                    }
                }

                escolha = indiceMaior + 1;
                printf("Jogador %d jogou automaticamente sua maior carta.\n", jogador + 1);
            }
            else{
                
                 
                do {
                         printf("\n jogador %d: qual carta vc quer jogar: ", jogador+1);
                        scanf("%d", &escolha);
    
                        if(escolha < 1 || escolha > 3) {
                         printf("Escolha inválida! Digite um número entre 1 e 3.\n");
                         }
                                else if(strcmp(Jogador[jogador][escolha-1].valor, "x") == 0) {
                                printf("\nEssa carta ja foi jogada! Escolha outra.\n");
                                escolha = 0; 
                         }
                    } while(escolha < 1 || escolha > 3 || strcmp(Jogador[jogador][escolha-1].valor, "x") == 0);

                }//fim do else

                 //coloca a carta na mesa
               mesa[jogador] = Jogador[jogador][escolha-1];


               //exclui a carta da mao do jogador
               strcpy(Jogador[jogador][escolha-1].valor,"x");
               strcpy(Jogador[jogador][escolha-1].naipe,"-");


               printf("\n o Jogador %d jogou: %s de %s\n",jogador+1,mesa[jogador].valor,mesa[jogador].naipe);

               

            }

            int IndiceMaisForte=quemComeca;
            int PesoMaisForte = PesoCartas(mesa[quemComeca]);
        

            //mostra as cartas e pega a mais forte e se de empate 
            printf("\n as cartas jogadas foram: \n");
            for(int i=0;i<4;i++)
            {
                int jogador = (quemComeca + i) % 4;

                printf("\n jogador %d: %s de %s\n",jogador+1,mesa[jogador].valor,mesa[jogador].naipe);

                int pesoAtual = PesoCartas(mesa[jogador]);

                if(pesoAtual > PesoMaisForte)
                {
                        PesoMaisForte = pesoAtual;
                        IndiceMaisForte = jogador;
                        kenga = 0;
                }

                //se dois jogadores jogarem as mesmas cartas e essas cartas sao as mais forte da mesa
                 else if(pesoAtual == PesoMaisForte)
                    {
                        // Só kenga se forem de times diferentes
                         if((IndiceMaisForte % 2) != (jogador % 2))
                          {
                            IndiceMaisForte = jogador;
                            kenga = 1;
                            jogadorKenga = jogador;
                          }
                    }


            }
            printf("Carta mais forte jogada pelo Jogador %d com peso %d.\n", IndiceMaisForte + 1, PesoMaisForte);



            int timeVencedor=0;

            //desocbrir qual time venceu,se for par e o time 2,se for impar e o time 1
          if(IndiceMaisForte % 2 == 0)
                 timeVencedor = 1;
                else
                    timeVencedor = 2;


            // Se kenga ocorreu na primeira rodada, o jogador que causou kenga ganha a rodada
        if(Rodada == 0 && kenga == 1)
        {

            if(jogadorKenga % 2 == 0)
                (*time2)++;
            else
                (*time1)++;

            quemComeca = (jogadorKenga + 1) % 4; // próximo jogador que começará a próxima rodada jogando maior carta
            kenga = 1; // ativa para o próximo começar com maior carta
            Rodada++;
        }


        if (!(Rodada == 0 && kenga == 1))  // Se não foi kenga na primeira rodada
        {
            //atribuindo pontos ao times vencedores
             if(timeVencedor==2)
            {
                (*time2)++;
            }
            else if(timeVencedor==1)
            {
                (*time1)++;
            }

            printf("\n O VENCEDOR E DA RODADA E O TIME %d\n",timeVencedor);

            
            quemComeca = IndiceMaisForte; // jogador vencedor começa a próxima rodada

            Rodada++;
        }
    }
    system("cls"); 
}