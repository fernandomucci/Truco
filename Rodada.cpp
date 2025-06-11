#include <iostream>
#include <time.h>
#include <algorithm>
#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "rodada.hpp"


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
        int IndiceMaisForte = quemComeca;
        int PesoMaisForte = 0;
        int vencedorDaRodada = 0;

        for(int i = 0; i< 2;i++)
        {
            int jogadorIndex = ordemJogadores[i];

            int PesoAtual = mesa[jogadorIndex].getPeso();

            if(PesoAtual > PesoMaisForte)
            {
                PesoMaisForte = PesoAtual;
                IndiceMaisForte = jogadorIndex;
                vencedorDaRodada = i;
            }
        }
        std::cout<<std::endl<<"a carta mais fortes jogada foi pelo jogador "<<IndiceMaisForte + 1<<std::endl;

        
        DefinindoVencedor(IndiceMaisForte);

        return vencedorDaRodada;

    }

    void  Rodada::DefinindoVencedor(int IndiceMaisForte)
    {

        //jogador 0 é Time 1 e jogador 1 é Time 2

        if(IndiceMaisForte == 0)
        {
            PontoTime1++;

            setPontosTime1(PontoTime1);

            std::cout<<std::endl<<"VEMCEDOR FOI O TIME 1"<<std::endl;
        }
        else
        {
            PontoTime2++;
            setPontosTime2(PontoTime2);

             std::cout<<std::endl<<"VEMCEDOR FOI O TIME 2"<<std::endl;
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

    void Rodada::Kenga()
    {
        //ainda a ser adcionado
    }
