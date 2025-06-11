#include <iostream>
#include <ctime>
#include <random>
#include "baralho.hpp"
#include "carta.hpp"

    //construtor
     Baralho::Baralho()
     {
        indiceAtual = 0;
     }

    //funcao de preencher o baralho 
  void   Baralho::PreencherBaralho()
    {
        //declaracao das cartas com naipes e valores
       std::string naipes[4] = {"Copas", "Espadas", "Ouros", "Paus"};
       std::string valores[10] = {"4", "5", "6", "7", "Q", "J", "K", "A", "2", "3"};


       int index = 0;

       //cada naipe vai ter 10 valores
        for(int i =0; i<4; i++)
        {
            for(int j =0; j<10; j++)
            {
                //manda as cartas para a class carta
                Carta carta(naipes[i], valores[j]);


                //salva carta no vetor
                this->cartas[index] = carta;

                index++;
            }
        }
        indiceAtual = 0;
    }


    //funcao de embaralhar o baralho
   void  Baralho::EmbaralharBaralho()
    {
        //pega um numero aleatorio com base no horario
         std::seed_seq seed{ static_cast<unsigned int>(time(0)), static_cast<unsigned int>(clock()) };

         //faz uma maquina que gera vario numero aleatorios
         std::mt19937 g(seed);

         //troca as cartas em um intervalo de 0 a 40 de forma aleatoria
         std::shuffle(cartas, cartas + 40, g);
    }


    //pega sempre a proxima carta do baralho
   Carta  Baralho::pegarProximaCarta() {
            if(indiceAtual < 40)
            {
                return cartas[indiceAtual++];
            }
            else
            {
                return Carta();
            }
        }

    Carta Baralho::getCarta(int i)
    {
        if(i>= 0 && i<40)
        {
        return this->cartas[i];
        }
        else
        {
            return Carta();
        }

    }

