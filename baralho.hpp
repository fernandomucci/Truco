#ifndef EMBARALHO_H
#define EMBARALHO_H

#include <iostream>
#include <time.h>
#include <algorithm>
#include "carta.hpp"



class Baralho
{
    private:

    Carta cartas[40];
    int indiceAtual;

     public:

     //construtor
     Baralho();

     //funcao de preencher o baralho 
     void PreencherBaralho();

     //funcao de embaralhar o baralho
     void EmbaralharBaralho();

     //pega sempre a proxima carta do baralho
     Carta pegarProximaCarta();

     Carta getCarta(int i);


};


#endif