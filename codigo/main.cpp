#include "Main.hpp"

int main()
{
    int escolha = -1;
    Partida iniciar;

  do{
    
    

    std::cout<<"\n quantos jogadores vao jogar:\n[1]4 jogadores\n[2]2 jogadores\n[3]jogar contra maquina\n[0]sair "<<std::endl;
    std::cin>>escolha;
     
    switch (escolha)
    {
       case 1: std::cout<<"AINDA NAO FOI IMPLEMENTADO";
             
        break;
    
       case 2:iniciar.iniciarPartida();

        break;

        case 3: std::cout<<"AINDA NAO FOI IMPLEMENTADO";

        break;
    }

    }while(escolha!=0);

    
 

      std::cout<<"OBRIGADO POR USAR"<<std::endl;


}