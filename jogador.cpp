#include <iostream>
#include "jogador.hpp"
#include "baralho.hpp"
#include "carta.hpp"


    
    void Jogador::distribuirCarta(Baralho &baralho)
    {
        for(int i =0; i<3; i++)
        {
          cartas[i] = baralho.pegarProximaCarta();
        }
    }

    void Jogador::MostrarCarta()const
    {
        std::cout<<"\n<-----MENU DE CARTAS----->\n\n";
        for(int i = 0; i<3; i++)
        {
            if(cartas[i].getValor() == "X")
            {
                std::cout<<"["<<i + 1<<"]"<<Carta()<<"\n";
            }
            else
            {
                std::cout<<"["<<i + 1<<"]"<<cartas[i]<<std::endl;
            }
        }
        std::cout<<"\n<------------------------>\n";
    }

    Carta Jogador::getCarta(int i)const
    {
        return this-> cartas[i];
    }

    void Jogador::usarCarta(int i)
    {
        if(i>=0 && i<3)
        {
        cartas[i] = Carta();
        }
    }



