#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Aluno;

class Aluno{
private:
    string nome;
    int matricula;
    vector<int> notas;
        
public:

    Aluno(int matricula, const string& nome);

    void adicionarNota(int nota);
    float calcularMediaNotas() const;
    float notaMaxima() const;
    float notaMinima() const;
    void imprimirDados() const;

    string getNome() const {return nome;}
    int getMatricula() const { return matricula; }
    const vector<int>& getNotas() const { return notas; }

    bool operator<(const Aluno& outro) const{
        return nome < outro.nome;
    }
        
};

#endif