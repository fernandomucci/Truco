#include <iostream>
#include <cstdlib> 
#include "apagar.hpp"

void esperarEnter() {
    std::cout << "\nPressione Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}