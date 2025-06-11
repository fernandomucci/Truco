#include <iostream>
#include "carta.hpp"


    //construtor padrao
    Carta::Carta()
    {
        naipe = "-";
        valor = "X";
        peso = 0;
    }

    //costrutor com valores
    Carta::Carta(std::string naipe,std::string valor)
    {
        this->valor = valor;
        this->naipe = naipe;
        this->peso = this->CalculoPesoCartas();
    }


    // Construtor de cópia
    Carta::Carta(const Carta& outra) 
    : naipe(outra.naipe), valor(outra.valor), peso(outra.peso)
    {
   
   /*Depois do ) que fecha os parâmetros do construtor, você coloca :.

    Depois do : vem a lista de inicialização, que diz:

    o atributo naipe será inicializado com outra.naipe

    o atributo valor será inicializado com outra.valor

    o atributo peso será inicializado com outra.peso*/

    //de acordo com a internet e melhor desse jeito,pq poupa tempo
    //isso e como se ja criasse  o objeto cheio

    //talvez eu mude depois 

    //codigo antigo se eu quiser mudar 

    /*naipe = outra.naipe;  
    valor = outra.valor;   
    peso = outra.peso;*/

    }




    //peso das cartas
    int Carta::CalculoPesoCartas()
    {

        //manilhas
        if(valor == "4" && naipe == "Paus")peso=14;

        else if(valor == "7" && naipe == "Copas")peso=13;

        else if(valor == "A" && naipe == "Espadas")peso=12;

        else if(valor == "7" && naipe == "Ouros")peso=11;

        //cartas padrao
        else if(valor == "3")peso=10;

        else if(valor == "2")peso=9;

        else if(valor == "A")peso=8;

        else if(valor == "K")peso=7;

        else if(valor == "J")peso=6;

        else if(valor == "Q")peso=5;

        else if(valor == "7")peso=4;

        else if(valor == "6")peso=3;

        else if(valor == "5")peso=2;
   
        else if(valor == "4")peso=1;

        return peso;

    }


    //gets para mostrar as cartas para o usuario


    std::string Carta::getValor()const
    {
        return this->valor;
    }

    std::string Carta::getNaipe()const
    {
        return this->naipe;
    }

    int Carta::getPeso()const
    {
        return this->peso;
    }


    //sobrecarga do operador
    std::ostream& operator<<(std::ostream& os, const Carta& carta) 
    {
    /*std::string emoji;

    if (carta.getNaipe() == "Copas") emoji = "♥️";
    else if (carta.getNaipe() == "Espadas") emoji = "♠️";
    else if (carta.getNaipe() == "Ouros") emoji = "♦️";
    else if (carta.getNaipe() == "Paus") emoji = "♣️";*/

    os << carta.getValor() << " de " << carta.getNaipe();
    return os;
    }

