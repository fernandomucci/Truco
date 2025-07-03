#ifndef RODADA_H
#define RODADA_H



#include <iostream>
#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"

class Partida;
class Truco;


class Rodada
{
    private:

    int PontoTime1;
    int PontoTime2;
    Jogador jogadores[2];
    int quemComeca;
    Carta mesa[2];
    Carta SalvarCarta;
    Baralho* baralho;
    int rodadaInterna;
    int VenceuPrimeira1;
    int VenceuPrimeira2;
    Truco* jogoDeTruco;
    Partida* partidaAtual;
    bool rodadaAcabou;

    int EmpateUltimaRodada;

    // Função privada que contém a lógica de interação do truco
    void gerenciarInteracaoTruco(int jogadorQuePedeIndex);

    public:
    //construtor
    Rodada();

    void prepararRodada();
    void distribuirCartas();
    void SalvaJogaColoca(Jogador &jogadores, int escolha, Carta &mesa);
    void iniciar();
    int jogarCarta(Jogador &jogadores, int jogadorIndex);
    void mostrarMesa(Carta mesa[]);
    int PegandoCartaMaisForte(int ordemJogadores[]);
    void DefinindoVencedor(int IndiceMaisForte);

    // Getters e Setters
    void setPontosTime1(int time1);
    void setPontosTime2(int time2);
    int getPontosTime1() const;
    int getPontosTime2() const;
    bool getRodadaAcabou() const;
    
    // Lógica de empate
    void Empate();
    void set1VenceuPrimeira(int VenceuPrimeira1);
    void set2VenceuPrimeira(int VenceuPrimeira2);

    void setPartida(Partida* partida); 
    void setBaralho(Baralho &baralhoRecebido);
    void setTruco(Truco* truco) ;
    void setRodadaInterna(int rodada);

    


    

};  

#endif