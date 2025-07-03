#include <iostream>
#include "partida.hpp"
#include "apagar.hpp"
#include "truco.hpp"

Partida::Partida() {
    partidas = 0;
    PlacarTime1 = 0;
    PlacarTime2 = 0;
    partidaEmAndamento = true;
}

void Partida::iniciarPartida() {
    // Configura os objetos uma única vez antes de iniciar o loop do jogo
    RodadaAtual.setBaralho(baralho);
    RodadaAtual.setTruco(&jogoDeTruco);
    RodadaAtual.setPartida(this);
    
    // O loop principal do jogo, que continua até um time atingir 12 pontos
    while (PlacarTime1 < 12 && PlacarTime2 < 12) {
        jogarRodada();
    }
    VerificarVencedorFinal();
}

void Partida::jogarRodada() {
    // Prepara tudo para uma nova rodada
    baralho.PreencherBaralho();
    baralho.EmbaralharBaralho();
    jogoDeTruco.Resetar();
    partidaEmAndamento = true;

    limparTela();
    std::cout << "\n======= PARTIDA " << partidas + 1 << " =======\n";
    atualizarPlacar();

    // Prepara as mãos dos jogadores
    RodadaAtual.prepararRodada();

    int vitoriasTime1 = 0;
    int vitoriasTime2 = 0;

    // Loop para as 3 "mãos" da rodada
    for (int i = 0; i < 3; ++i) {
        // Se alguém já venceu a rodada (melhor de 3), ou se alguém correu, para.
        if (vitoriasTime1 >= 2 || vitoriasTime2 >= 2) break;
        if (!partidaEmAndamento) break;

        std::cout << "\n--- MAO " << i + 1 << " ---\n";
        RodadaAtual.setRodadaInterna(i);
        // Zera os pontos da mão para a comparação
        RodadaAtual.setPontosTime1(0);
        RodadaAtual.setPontosTime2(0);

        RodadaAtual.iniciar();

        // Se a rodada foi interrompida por uma fuga, sai da função imediatamente
        if (RodadaAtual.getRodadaAcabou()) {
            return; 
        }

        // Contabiliza quem venceu a mão
        if (RodadaAtual.getPontosTime1() > RodadaAtual.getPontosTime2()) {
            vitoriasTime1++;
        } else if (RodadaAtual.getPontosTime2() > RodadaAtual.getPontosTime1()) {
            vitoriasTime2++;
        } else {
            // Em caso de empate na mão, os dois "ganham" para fins de desempate
            vitoriasTime1++;
            vitoriasTime2++;
        }
    }

    // Se a rodada terminou normalmente (sem fugas), calcula os pontos
    if (partidaEmAndamento) {
        int valorDaRodada = jogoDeTruco.getValorDaAposta();
        std::cout << "\n--- FIM DA RODADA ---\n";

        if (vitoriasTime1 > vitoriasTime2) {
            PlacarTime1 += valorDaRodada;
            std::cout << "Time 1 venceu a rodada e ganhou " << valorDaRodada << " ponto(s)!\n";
        } else if (vitoriasTime2 > vitoriasTime1) {
            PlacarTime2 += valorDaRodada;
            std::cout << "Time 2 venceu a rodada e ganhou " << valorDaRodada << " ponto(s)!\n";
        } else {
             // Aqui entra a regra de quem ganhou a primeira mão em caso de empate na rodada
             // Implemente sua lógica de desempate se necessário
             std::cout << "\nRodada empatou (CANGOU)! Ninguem marcou pontos.\n";
        }
        partidas++;
        atualizarPlacar();
        esperarEnter();
    }
}

void Partida::finalizarRodadaPorFuga() {
    int pontosGanhos = jogoDeTruco.getValorDaFuga();
    // Quem pediu o truco é o time vencedor, pois o outro correu
    int timeVencedor = jogoDeTruco.getQuemPediu();

    if (timeVencedor == 0) { // Time 1 ganhou
        PlacarTime1 += pontosGanhos;
        std::cout << "Time 1 ganhou " << pontosGanhos << " ponto(s) por fuga!\n";
    } else { // Time 2 ganhou
        PlacarTime2 += pontosGanhos;
        std::cout << "Time 2 ganhou " << pontosGanhos << " ponto(s) por fuga!\n";
    }

    partidaEmAndamento = false; // Sinaliza para `jogarRodada` que a rodada acabou
    partidas++;
    atualizarPlacar();
    esperarEnter();
}

void Partida::atualizarPlacar() {
    std::cout << std::endl << "<----- PLACAR PARCIAL ----->" << std::endl;
    std::cout << "Time 1 = " << PlacarTime1 << std::endl;
    std::cout << "Time 2 = " << PlacarTime2 << std::endl;
    std::cout << "<-------------------------->" << std::endl << std::endl;
}

void Partida::VerificarVencedorFinal() {
    std::cout << "\n======= FIM DE JOGO =======\n";
    if (PlacarTime1 >= 12) {
        std::cout << "Time 1 VENCEU A PARTIDA!" << std::endl;
    } else if (PlacarTime2 >= 12) {
        std::cout << "Time 2 VENCEU A PARTIDA!" << std::endl;
    }
}