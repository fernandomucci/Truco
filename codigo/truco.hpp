#ifndef TRUCO_HPP
#define TRUCO_HPP


enum EstadoTruco
{
    NORMAL = 1,
    TRUCO = 3,  
    SEIS = 6,
    NOVE = 9,
    DOZE = 12,
    CORRER = 0 
};

class Truco
{
private:
    // Índice do último jogador que pediu/aumentou
    int quemPediu;
    EstadoTruco estadoAtual;

public:
    Truco();
    void Resetar();

    // Funções de estado
    EstadoTruco getEstado() const;
    int getQuemPediu() const;
    bool AlguemCorreu() const;

    // Funções de pontuação
    int getValorDaAposta() const;
    int getValorDaFuga() const;

    // Ações do jogo
    bool Pedir(int jogadorIndex);
    void Responder(int escolha);
};

#endif 