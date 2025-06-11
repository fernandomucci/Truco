#ifndef PARTIDA_H
#define PARTIDA_H

#include "rodada.hpp"
#include "baralho.hpp"
#include <iostream>

class Partida
{
    private:

    int partidas = 0;
    int PlacarTime1 = 0;
    int PlacarTime2 = 0;
    Rodada RodadaAtual;
    Baralho baralho;
    int rodadaInterna = 0;

    public:

    void iniciarPartida();

    void jogarRodada();

    void atualizarPlacar();

    void VerificarVencedorFinal();

    

};    



#endif