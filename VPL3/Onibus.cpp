#include "Onibus.hpp"
#include <iostream>
#include <string>

using namespace std;

void Onibus::inicializar( string placa, int capacidade_max) {
    this->placa = placa;
    this->capacidade_max = capacidade_max;
    this->lotacao_atual = 0;
}
    
bool Onibus::subir_passageiros(int quantidade) {
    if (this->lotacao_atual + quantidade > capacidade_max) {
        return false;
    }
    this->lotacao_atual += quantidade;
    return true;
}
       

bool Onibus::descer_passageiros(int quantidade){
    if (this->lotacao_atual - quantidade < 0){
        return false;
    } 
    this->lotacao_atual -=  quantidade;
    return true;
}

bool Onibus::transferir_passageiros(Onibus* outro_onibus, int quantidade) {
    if (this->lotacao_atual < quantidade || outro_onibus->lotacao_atual + quantidade > outro_onibus->capacidade_max){
        return false;
    }
    this->lotacao_atual -= quantidade;
    outro_onibus->lotacao_atual += quantidade;
    return true;
}

void Onibus::imprimir_estado() const {
    cout << placa << " (" << lotacao_atual << "/" << capacidade_max << ")" << endl;
}