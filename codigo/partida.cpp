#include <iostream>
#include <time.h>
#include <algorithm>
#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "partida.hpp"
#include "apagar.hpp"

    void Partida::iniciarPartida()
    {

      
        //zera os pontos e partidas
        partidas = 0;
        PlacarTime1 = 0;
        PlacarTime2 = 0;

        RodadaAtual.setBaralho(baralho);

        while(PlacarTime1<12 && PlacarTime2<12)
        {
            jogarRodada();
        }
        
        //verifica quem foi o vencedor da primeira rodada
        RodadaAtual.setRodadaInterna(rodadaInterna);

        VerificarVencedorFinal();

    }

    void Partida::jogarRodada()
{
    //começa criando e embaralhando as cartas pra cada 3 rodadas
        baralho.PreencherBaralho();
        baralho.EmbaralharBaralho();

    //limpa o terminal antes de começar a partida
    limparTela();

    std::cout << "\n======= PARTIDA " << partidas + 1 << " =======\n";

    //atualiza o placar 
    atualizarPlacar();

    // Distribui cartas (uma mão de 3 cartas por jogador)
   RodadaAtual.distribuirCartas();

    // Zera contadores de vitórias dentro desta rodada
   RodadaAtual.setRodadaInterna(0); 
   RodadaAtual.setPontosTime1(0);
   RodadaAtual.setPontosTime2(0);
    int vitoriasTime1 = 0;
    int vitoriasTime2 = 0;
    this-> rodadaInterna = 0;

    while (vitoriasTime1 < 2 && vitoriasTime2 < 2 && rodadaInterna < 3)
    {
        std::cout << "\n--- RODADA " << rodadaInterna + 1 << " ---\n";

        // Define rodada interna correta antes de iniciar
         RodadaAtual.setRodadaInterna(rodadaInterna);
         

        RodadaAtual.iniciar(); // Jogadores jogam 1 carta cada

        if (RodadaAtual.getPontosTime1() > RodadaAtual.getPontosTime2())
        {
            vitoriasTime1++;
        }
        else if (RodadaAtual.getPontosTime2() > RodadaAtual.getPontosTime1())
        {
            vitoriasTime2++;
        }

         rodadaInterna++;

    }


    // Quem vencer 2 rodadas leva 1 ponto
    if (vitoriasTime1 == 2)
    {
        PlacarTime1++;
        std::cout << "\nTime 1 venceu a rodada e ganhou 1 ponto!\n";
    }
    else if (vitoriasTime2 == 2)
    {
        PlacarTime2++;
        std::cout << "\nTime 2 venceu a rodada e ganhou 1 ponto!\n";
    }



    partidas++;
    atualizarPlacar();

    //espera a confirmaçao para apagar a tela
    esperarEnter(); 
}



    
    void Partida::atualizarPlacar()
    {
      //std::cout<< "Placar parcial: Time 1 = " << PlacarTime1 << " | Time 2 = " << PlacarTime2 << std::endl;
      std::cout<<std::endl<< "<----- PLACAR PARCIAL ----->"<<std::endl;
      std::cout<<std::endl<<"Time 1 = "<<PlacarTime1<<std::endl;
      std::cout<<std::endl<<"Time 2 = "<<PlacarTime2<<std::endl;
      std::cout<<std::endl<<"<-------------------------->"<<std::endl;
    }



    void Partida::VerificarVencedorFinal()
    {

        if (PlacarTime1 >= 12) {
             std::cout << "Time 1 Venceu a Partida!" << std::endl;
        } else if (PlacarTime2 >= 12) 
          {
            std::cout << "Time 2 Venceu a Partida!" << std::endl;
          }

    }

