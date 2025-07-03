#include <iostream>
#include <time.h>
#include <algorithm>
#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "rodada.hpp"
#include "partida.hpp"
#include "truco.hpp"
#include "apagar.hpp"

Rodada::Rodada()
 {
    quemComeca = 0;
    partidaAtual = nullptr;
    jogoDeTruco = nullptr;
    baralho = nullptr;
}

// Setters para configurar a rodada
void Rodada::setPartida(Partida* partida) { this->partidaAtual = partida; }
void Rodada::setBaralho(Baralho &baralhoRecebido) { baralho = &baralhoRecebido; }
void Rodada::setTruco(Truco* truco) { this->jogoDeTruco = truco; }
void Rodada::setRodadaInterna(int rodada) { this->rodadaInterna = rodada; }


    void Rodada::distribuirCartas()
    {
        for(int i = 0; i < 2; i++)
        {
            jogadores[i].distribuirCarta(*baralho);
        }
    }

    void Rodada::prepararRodada() 
    {
        distribuirCartas();
        PontoTime1 = 0;
        PontoTime2 = 0;
        VenceuPrimeira1 = 0;
        VenceuPrimeira2 = 0;
        rodadaAcabou = false;
    }

    bool Rodada::getRodadaAcabou() const 
    {
    return rodadaAcabou;
    }

void Rodada::gerenciarInteracaoTruco(int jogadorQuePedeIndex) 
{
    int oponenteIndex = (jogadorQuePedeIndex + 1) % 2;

    // Flag booleana para controlar o loop de forma explícita
    bool apostaEmAndamento = true;

    
    while (apostaEmAndamento) 
    {
        bool pediuComSucesso = jogoDeTruco->Pedir(jogadorQuePedeIndex);

        if (!pediuComSucesso) {
            apostaEmAndamento = false; // Condição de saída: não era possível pedir
            
        }
        limparTela();

        std::cout << "Jogador " << (jogadorQuePedeIndex + 1) << " pediu " << jogoDeTruco->getEstado() << "!" << std::endl;

        // Oponente precisa responder
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Jogador " << (oponenteIndex + 1) << ", voce foi trucado!\n";
        jogadores[oponenteIndex].MostrarCarta();
        std::cout << "[1] Aceitar\n[2] Correr\n";
        if (jogoDeTruco->getEstado() != DOZE) 
        {
            EstadoTruco proximo;
            EstadoTruco estadoAtual = jogoDeTruco->getEstado();

            if (estadoAtual == TRUCO) 
            {
                proximo = SEIS;
            } 
            else if (estadoAtual == SEIS) 
            {
                proximo = NOVE;
            } 
            else // Se não for TRUCO nem SEIS, só pode ser NOVE (pois ja exclui o DOZE no if principal)
            {
                proximo = DOZE;
            }

            std::cout << "[3] Pedir " << proximo << std::endl;
        }

        int resposta;
        std::cin >> resposta;

        if (resposta == 1) 
        { // ACEITAR
            std::cout << "Jogador " << (oponenteIndex + 1) << " aceitou!"<< std::endl;
            jogoDeTruco->Responder(resposta);
            apostaEmAndamento = false; // Condição de saída: aposta foi aceita
        }
        else if (resposta == 2) 
        { // CORRER
            std::cout << "Jogador " << (oponenteIndex + 1) << " correu!" << std::endl;
            jogoDeTruco->Responder(resposta);
            this->rodadaAcabou = true;
            partidaAtual->finalizarRodadaPorFuga();
            apostaEmAndamento = false; // Condição de saída: alguém correu
        }
        else if (resposta == 3 && jogoDeTruco->getEstado() != DOZE) 
        {  // AUMENTAR A APOSTA
            // Inverte os papéis e o loop continua (apostaEmAndamento continua true)
            int temp = jogadorQuePedeIndex;
            jogadorQuePedeIndex = oponenteIndex;
            oponenteIndex = temp;
        } else {
             std::cout << "Opcao invalida. Considerando como 'Correr'." << std::endl;
             jogoDeTruco->Responder(2); // Trata como se tivesse corrido
             this->rodadaAcabou = true;
             partidaAtual->finalizarRodadaPorFuga();
             apostaEmAndamento = false; // Condição de saída: opção inválida
        }

        std::cout<<"Partida valendo "<<jogoDeTruco->getEstado()<<std::endl;
    }
}

void Rodada::iniciar() {
    int ordemJogadores[2] = {quemComeca, (quemComeca + 1) % 2};



    // Loop simples para cada jogador jogar sua carta
    for (int i = 0; i < 2; i++) {
        int jogadorIndex = ordemJogadores[i];

        // A lógica de truco 
    if (jogoDeTruco->getEstado() == NORMAL) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Jogador " << (ordemJogadores[i] + 1) << ", sua vez.\n";
        jogadores[ordemJogadores[i]].MostrarCarta();

        std::cout << "Deseja pedir TRUCO? [1] Sim | [2] Nao\n";
        int escolhaTruco;
        std::cin >> escolhaTruco;
        if (escolhaTruco == 1) {
            gerenciarInteracaoTruco(ordemJogadores[i]);
            // Se alguém correu, a flag rodadaAcabou será true e a função deve parar.
            if (rodadaAcabou) return;
        }

        jogadores[jogadorIndex].MostrarCarta();
        int escolha = jogarCarta(jogadores[jogadorIndex], jogadorIndex);
        SalvaJogaColoca(jogadores[jogadorIndex], escolha, mesa[jogadorIndex]);
        limparTela();
        std::cout << "O jogador " << jogadorIndex + 1 << " jogou: " << SalvarCarta.getValor() << " de " << SalvarCarta.getNaipe() << std::endl;
    }

    mostrarMesa(mesa);
    int vencedorIndiceRelativo = PegandoCartaMaisForte(ordemJogadores);
    quemComeca = ordemJogadores[vencedorIndiceRelativo]; // Vencedor da mão começa a próxima
}
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
        limparTela();

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

     void Rodada::SalvaJogaColoca(Jogador &jogador, int escolha, Carta &cartaDaMesa) {
    // 1. Pega a carta da mão do jogador
    SalvarCarta = jogador.getCarta(escolha - 1); // Salva a carta para referência

    // 2. Coloca a carta na mesa
    cartaDaMesa = SalvarCarta; 
    
    // 3. Marca a carta na mão do jogador como "jogada"
    jogador.usarCarta(escolha - 1); 
}
