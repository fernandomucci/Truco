#ifndef CARTA_H
#define CARTA_H



#include <iostream>




class Carta
{
    private:

    std::string naipe;
    std::string valor;
    int peso;

    public:

    //construtor padrao
    Carta();

    //costrutor com valores
    Carta(std::string naipe,std::string valor);

    // Construtor de cópia
    Carta(const Carta& outra);
    
    //peso das cartas
      int CalculoPesoCartas();

      //gets para mostrar as cartas para o usuario

      std::string getValor()const;

      std::string getNaipe()const;
       
      int getPeso()const;

};

//sobrecarga do operador
std::ostream& operator<<(std::ostream& os, const Carta& carta);

#endif