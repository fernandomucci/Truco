#ifndef RODADA_H
#define RODADA_H



#include <iostream>
#include "carta.hpp"
#include "baralho.hpp"
#include "jogador.hpp"
#include "partida.hpp"


class Rodada
{
    private:

    int PontoTime1 = 0;
    int PontoTime2 = 0;
    Jogador jogadores[2];
    int quemComeca = 0;
    Carta mesa[2];
    Carta SalvarCarta;
    Baralho* baralho;
    int EmpateUltimaRodada = -1;
    int rodadaInterna = 0;
    int VenceuPrimeira1 = 0;
    int VenceuPrimeira2 = 0;

    public:

    //passar baralho criado em partida
    void setBaralho(Baralho &baralhoRecebido);

     // Distribui cartas para os jogadores
     void distribuirCartas();

     //salva a carta que o usuario escolheu,guarda ela em mesa,e jogue ela "fora"
     void SalvaJogaColoca(Jogador &jogadores,int escolha,Carta &mesa);

     // Inicia a rodada (embaralha, distribui, joga, define vencedor)
     void iniciar();

     // Método para o jogador jogar uma carta (passa o objeto jogador e a carta escolhida)
     int  jogarCarta(Jogador &jogadores,int jogadorIndex);

     // Mostra as cartas jogadas na mesa
     void mostrarMesa(Carta mesa[]);

     // Verifica qual carta foi a mais forte e define o vencedor da rodada
     int PegandoCartaMaisForte(int ordemJogadores[]);

     // Atualiza os pontos de acordo com o índice do jogador vencedor
     void DefinindoVencedor(int IndiceMaisForte);

    // Setters e getters para pontos dos times
     void setPontosTime1(int time1);
     void setPontosTime2(int time2);

     int getPontosTime1() const;
     int getPontosTime2() const;


     void Empate();

    //pega o valor de quem venceu a primeira
     void set1VenceuPrimeira(int VenceuPrimeira1);
     void set2VenceuPrimeira(int VenceuPrimeira2);

     void setRodadaInterna(int rodadaInterna);

     int getRodadaInterna() const;

    


    

};  

#endif