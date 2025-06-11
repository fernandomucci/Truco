#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include "carta.hpp"
#include "baralho.hpp"


class Jogador
{
    private:
     Carta cartas[3];

    public:

    void distribuirCarta(Baralho &baralho);

     void MostrarCarta()const;

     Carta getCarta(int i)const;
     
     void usarCarta(int i);

};


#endif
    