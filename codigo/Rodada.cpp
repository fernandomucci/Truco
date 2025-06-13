#include <iostream>
#include <time.h>
#include <algorithm>
#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "rodada.hpp"
#include "partida.hpp"


    void Rodada::setBaralho(Baralho &baralhoRecebido)
    {
      baralho = &baralhoRecebido;
    }

    void Rodada::distribuirCartas()
    {
        for(int i = 0; i < 2; i++)
        {
            jogadores[i].distribuirCarta(*baralho);
        }
    }

    void Rodada::iniciar()
    {   

        // ordem dos jogadores baseada em quemComeca
        int ordemJogadores[2] = {quemComeca, (quemComeca + 1) % 2};

        for(int i = 0; i < 2; i++)
        {
            int jogadorIndex = ordemJogadores[i];


            jogadores[jogadorIndex].MostrarCarta();

            int escolha = jogarCarta(jogadores[jogadorIndex],jogadorIndex);

            SalvaJogaColoca(jogadores[jogadorIndex],escolha,mesa[jogadorIndex]);

            system("cls");

            std::cout<<"o jogador "<<jogadorIndex+1<<" jogou: "<<SalvarCarta.getValor()<<" de "<<SalvarCarta.getNaipe()<<std::endl;
            
        }
            mostrarMesa(mesa);

           int vencedorIndice = PegandoCartaMaisForte(ordemJogadores);



           // Atualizar quem começa na próxima rodada
           quemComeca = ordemJogadores[vencedorIndice];
    }

    void Rodada::SalvaJogaColoca(Jogador &jogadores,int escolha,Carta &mesa)
    {
            //salva carta antes dela ser jogada
            SalvarCarta = jogadores.getCarta(escolha - 1);

            //joga a carta
            jogadores.usarCarta(escolha - 1);

            //salva na mesa a carta certa
            mesa = SalvarCarta;
    }

    int Rodada::jogarCarta(Jogador &jogadores,int jogadorIndex)
    {
        int escolha = 0;

            do
            {

            std::cout<<"jogador "<<jogadorIndex + 1<<" qual carta vc quer jogar?(1 - 3)"<<std::endl;
            std::cin>>escolha;

            if(escolha<1 || escolha>3)
            {
                std::cout<<"carta invalida,jogue outra"<<std::endl;
            }
            else if(jogadores.getCarta(escolha - 1).getValor() == "X")
            {
                std::cout<<"essa carta ja foi jogada,escolha outra"<<std::endl;
            }

            }while(escolha<1 || escolha>3 || jogadores.getCarta(escolha - 1).getValor() == "X" );

          

            return escolha;

    }

    void  Rodada::mostrarMesa(Carta mesa[])
    {
        system("cls");

        std::cout<<std::endl<<"<-----MESA----->"<<std::endl;
        for(int i = 0; i<2; i++)
        {
            std::cout<<std::endl<<"O Jogador "<<i+1<<" jogou: "<<mesa[i]<<std::endl;
        }
         std::cout<<std::endl<<"<-------------->"<<std::endl;

    }

    int  Rodada::PegandoCartaMaisForte(int ordemJogadores[])
    {
        int indiceJogadorMaisForteAtual = quemComeca;
        int PesoMaisForte = 0;
        int vencedorDaRodada = 0;

        for(int i = 0; i< 2;i++)
        {
            int jogadorIndex = ordemJogadores[i];

            int PesoAtual = mesa[jogadorIndex].getPeso();

            if(PesoAtual > PesoMaisForte)
            {
                PesoMaisForte = PesoAtual;
                indiceJogadorMaisForteAtual = jogadorIndex;
                vencedorDaRodada = i;
            }
            else if(PesoAtual == PesoMaisForte && indiceJogadorMaisForteAtual != jogadorIndex)
            {
                     // Verifica se é a terceira rodada (índice 2)
                    if(rodadaInterna == 2) 
                    {
                        EmpateUltimaRodada = 1;
                    }
                    /*else 
                    {
                                // Em outras rodadas, o jogador que jogou por último vence
                                PesoMaisForte = PesoAtual;
                                indiceJogadorMaisForteAtual = jogadorIndex;
                                vencedorDaRodada = i;
                  }*/
            }
        }

        
        DefinindoVencedor(indiceJogadorMaisForteAtual);

        return vencedorDaRodada;

    }

    void  Rodada::DefinindoVencedor(int indiceJogadorMaisForteAtual)
    {

        //jogador 0 é Time 1 e jogador 1 é Time 2

        if(EmpateUltimaRodada == 1)
        {
            Empate();
            EmpateUltimaRodada = -1; // Reseta o kenga para a próxima rodada
        }

        else
        {
           

             if(indiceJogadorMaisForteAtual == 0)
            {
                PontoTime1++;
                setPontosTime1(PontoTime1);
            
                if(rodadaInterna == 0) //1 rodada o indice é 0
                {
                    VenceuPrimeira1++;

                 set1VenceuPrimeira(VenceuPrimeira1);

                }

             std::cout<<std::endl<<"VENCEDOR FOI O TIME 1"<<std::endl;
        }
            else
            {
                 PontoTime2++;
                 setPontosTime2(PontoTime2);

                if(rodadaInterna == 0)
                {
                    VenceuPrimeira2++;

                     set2VenceuPrimeira(VenceuPrimeira2);

             }

             std::cout<<std::endl<<"VEMCEDOR FOI O TIME 2"<<std::endl;
        }

        std::cout<<std::endl<<"a carta mais fortes jogada foi pelo jogador "<<indiceJogadorMaisForteAtual + 1<<std::endl;

    }

    
}

    void  Rodada::setPontosTime1(int PontoTime1)
    {
        this->PontoTime1 = PontoTime1;
    }

    void  Rodada::setPontosTime2(int PontoTime2)
    {
        this->PontoTime2 = PontoTime2;
    }

     int  Rodada::getPontosTime1() const
    {
        return this->PontoTime1;
    }

    int  Rodada::getPontosTime2() const
    {
        return this->PontoTime2;
    }

    void Rodada::set1VenceuPrimeira(int VenceuPrimeira1)
    {
        if( VenceuPrimeira1 > 0)
        {
            this->VenceuPrimeira1 = VenceuPrimeira1;
        }
    }

    void Rodada::set2VenceuPrimeira(int VenceuPrimeira2)
    {
        if( VenceuPrimeira2 > 0)
        {
            this->VenceuPrimeira2 = VenceuPrimeira2;
        }
    }

   

    void Rodada::Empate()
    {
        if (rodadaInterna == 2) // Se for a terceira rodada
        {
            if (VenceuPrimeira1 == 1)
            {
                 PontoTime1++;
                 setPontosTime1(PontoTime1);
                std::cout << std::endl << "EMPATE! Time 1 venceu por ter ganho a primeira rodada." << std::endl;
            }
            else if (VenceuPrimeira2 == 1)
            {
                 PontoTime2++;
                 setPontosTime2(PontoTime2);
                 std::cout << std::endl << "EMPATE! Time 2 venceu por ter ganho a primeira rodada." << std::endl;
            }
        }
        
    }

     void Rodada::setRodadaInterna(int rodadaInterna)
     {
        this->rodadaInterna = rodadaInterna;
     }