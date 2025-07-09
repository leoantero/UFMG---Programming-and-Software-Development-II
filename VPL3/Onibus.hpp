#ifndef ONIBUS_H
#define ONIBUS_H

#include <string>
using namespace std;


struct Onibus {
    string placa;
    int capacidade_max;
    int lotacao_atual;

    void inicializar(string placa, int capacidade);

    bool subir_passageiros(int quantidade);
    bool descer_passageiros(int quantidade);
    bool transferir_passageiros(Onibus* outro_onibus, int quantidade);
    void imprimir_estado() const;
};

#endif