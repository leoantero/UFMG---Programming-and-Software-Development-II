#ifndef VETOR_H
#define VETOR_H

#include <iostream>
#include <vector>

template <typename T>
class Vetor {
private:
    unsigned int tam_max;
    std::vector<T> elementos;

public: 
    Vetor(int n) : tam_max(n) {elementos.reserve(n);}
    Vetor(std::vector<T>& received) : elementos(received), tam_max(received.size()) {}
    
    void SetElemento(int i, T x) {
        elementos[i] = x;   
    }
    T GetElemento(int i) {
        return elementos[i];   
    }
    void AdicionaElemento(T x) {
        if(elementos.size() < tam_max) elementos.push_back(x);
    }
    void Imprime() {
        for(auto& elemento : elementos){
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
    ~Vetor() {} 
};

#endif 