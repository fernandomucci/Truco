#ifndef PARTIDA_H
#define PARTIDA_H

#include "rodada.hpp"
#include "baralho.hpp"
#include "truco.hpp"

class Partida
{
private:
    int partidas;
    int PlacarTime1;
    int PlacarTime2;
    Rodada RodadaAtual;
    Baralho baralho;
    Truco jogoDeTruco;
    bool partidaEmAndamento;

public:
    Partida();
    void iniciarPartida();
    void jogarRodada();
    void atualizarPlacar();
    void VerificarVencedorFinal();
    void finalizarRodadaPorFuga();
};

#endif 