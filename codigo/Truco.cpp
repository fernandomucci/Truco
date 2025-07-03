#include "truco.hpp"

// Construtor e Resetar
Truco::Truco()
 {
    Resetar();
 }

void Truco::Resetar() 
{
    quemPediu = -1;
    estadoAtual = NORMAL;
}

// Funções de estado
EstadoTruco Truco::getEstado() const
 {
    return estadoAtual;
}

int Truco::getQuemPediu() const {
    return quemPediu;
}

bool Truco::AlguemCorreu() const {
    return estadoAtual == CORRER;
}


// Retorna o valor em pontos se a rodada for até o fim
int Truco::getValorDaAposta() const
 {
    int valorDaRodada = 1; // Inicia com o valor padrão

    switch (estadoAtual) {
        case TRUCO:
            valorDaRodada = 3;
            break;
        case SEIS:
            valorDaRodada = 6;
            break;
        case NOVE:
            valorDaRodada = 9;
            break;
        case DOZE:
            valorDaRodada = 12;
            break;
        
        case NORMAL:
        case CORRER:
        default:
            
            break;
    }

    return valorDaRodada; 
}

// Retorna o valor em pontos quando alguém corre
int Truco::getValorDaFuga() const
 {
    int pontosGanhos = 1;
    switch (estadoAtual) {
       
        case TRUCO: // Se correu do pedido de TRUCO, vale 1
            pontosGanhos = 1;
            break;
        case SEIS:  // Se correu do pedido de SEIS, a aposta anterior (TRUCO) valia 3
            pontosGanhos = 3;
            break;
        case NOVE:  // Se correu do pedido de NOVE, a aposta anterior (SEIS) valia 6
            pontosGanhos = 6;
            break;
        case DOZE:  // Se correu do pedido de DOZE, a aposta anterior (NOVE) valia 9
            pontosGanhos = 9;
            break;
        default:
            
            break;
    }

    return pontosGanhos; 
}

// O jogador tenta pedir/aumentar a aposta
bool Truco::Pedir(int jogadorIndex) {
    bool sucesso = false; 

    // Não pode pedir se ele mesmo foi o último a pedir
    if (this->quemPediu != jogadorIndex) {
        EstadoTruco novoEstado = estadoAtual;
        switch (estadoAtual) {
            case NORMAL: novoEstado = TRUCO; break;
            case TRUCO:  novoEstado = SEIS;  break;
            case SEIS:   novoEstado = NOVE;  break;
            case NOVE:   novoEstado = DOZE;  break;
            default: break;//nao aumenta se estiver em DOZE ou CORRER
        }

        // Se o estado mudou
        if (novoEstado != estadoAtual) {
            estadoAtual = novoEstado;
            this->quemPediu = jogadorIndex;
            sucesso = true;
        }
    }
    
    return sucesso; 
}

// Processa a resposta do jogador desafiado
void Truco::Responder(int escolha) {
    if (escolha == 2) { // CORRER
        this->estadoAtual = CORRER;
    }
    //a escolha 1 é aceitar, não precisa fazer nada,pois ja esta sendo tratada em pedir()
}