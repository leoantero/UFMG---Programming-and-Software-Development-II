#include "Empresa.hpp"
#include <iostream>

using namespace std;

Empresa::Empresa() {
    this->total_onibus_cadastrados = 0;
    for (int i = 0; i < 20; ++i) {
        onibus[i] = nullptr;
    }
}

Onibus* Empresa::adicionar_onibus(string placa, int capacidade_max) {
    for (int i = 0; i < total_onibus_cadastrados; i++) {
        if (onibus[i] && onibus[i]->placa == placa) {
            return nullptr; 
        }
    }

    if (total_onibus_cadastrados < 20) {
        Onibus* novo_onibus = new Onibus;
        novo_onibus->inicializar(placa, capacidade_max);
        onibus[total_onibus_cadastrados] = novo_onibus;
        total_onibus_cadastrados++;
        return novo_onibus;
    } else {
        return nullptr; 
    }
}

Onibus* Empresa::busca_onibus(string placa) {
    for (int i = 0; i < total_onibus_cadastrados; i++) {
        if (onibus[i]->placa == placa) {
            return onibus[i];
        }
    }
    return nullptr;
}

void Empresa::imprimir_estado(){
    for (int i = 0; i < total_onibus_cadastrados; i++) {
        onibus[i]->imprimir_estado();
    }
}
