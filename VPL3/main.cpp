#include <iostream>
#include <sstream>
#include "Onibus.hpp"
#include "Empresa.hpp"

using namespace std;

int main() {
    Empresa empresa;
    string entrada;

    while (getline(cin, entrada)) {
        istringstream linha(entrada);
        char comando;
        linha >> comando;

        string placa, placa2;
        int capacidade, quantidade;

        if (comando == 'C') {
            linha >> placa >> capacidade;
            if (empresa.adicionar_onibus(placa, capacidade) != nullptr) {
                cout << "novo onibus cadastrado" << endl;
            } else {
                cout << "ERRO : onibus repetido" << endl;
            }
        } else if (comando == 'S') {
            linha >> placa >> quantidade;
            Onibus* onibus = empresa.busca_onibus(placa);
            if (onibus != nullptr) {
                if (onibus->subir_passageiros(quantidade)) {
                    cout << "passageiros subiram com sucesso" << endl;
                } else {
                    cout << "ERRO : onibus lotado" << endl;
                }
            } else {
                cout << "ERRO : onibus inexistente" << endl;
            }
        } else if (comando == 'D') {
            linha >> placa >> quantidade;
            Onibus* onibus = empresa.busca_onibus(placa);
            if (onibus != nullptr) {
                if (onibus->descer_passageiros(quantidade)) {
                    cout << "passageiros desceram com sucesso" << endl;
                } else {
                    cout << "ERRO : faltam passageiros" << endl;
                }
            } else {
                cout << "ERRO : onibus inexistente" << endl;
            }
        } else if (comando == 'T') {
            linha >> placa >> placa2 >> quantidade;
            Onibus* onibus1 = empresa.busca_onibus(placa);
            Onibus* onibus2 = empresa.busca_onibus(placa2);
            if (onibus1 != nullptr && onibus2 != nullptr) {
                if (onibus1->transferir_passageiros(onibus2, quantidade)) {
                    cout << "transferencia de passageiros efetuada" << endl;
                } else {
                    cout << "ERRO : transferencia cancelada" << endl;
                }
            } else {
                cout << "ERRO : onibus inexistente" << endl;
            }
        } else if (comando == 'I') {
            empresa.imprimir_estado();
        } else if (comando == 'F') {
            return 0;
        }
    }

    return 0;
}
