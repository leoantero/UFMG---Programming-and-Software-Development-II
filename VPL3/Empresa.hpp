#ifndef EMPRESA_H
#define EMPRESA_H
#include "Onibus.hpp"

#include <string>

using namespace std;

struct Empresa {
    int total_onibus_cadastrados;
    Onibus* onibus[20];

    Empresa();

    Onibus* adicionar_onibus(string placa, int capacidade_max);
    Onibus* busca_onibus(string placa);
    void imprimir_estado();
};

#endif