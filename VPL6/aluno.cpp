#include "aluno.hpp"
#include <iomanip>


Aluno::Aluno(int matricula, const string& nome) : nome(nome),  matricula(matricula) {}

void Aluno::adicionarNota(int nota){
    notas.push_back(nota);
}

float Aluno::notaMaxima() const{
    if (notas.empty()) return 0;
    return *max_element(notas.begin(), notas.end());
}

float Aluno::notaMinima() const{
    if (notas.empty()) return 0;
    return *min_element(notas.begin(), notas.end());
}
    
float Aluno::calcularMediaNotas() const{
    if(notas.empty()) return 0.0;
    int soma = 0;
    for (int nota : notas){
        soma += nota;
    }
    return static_cast<float>(soma) / notas.size();
}   
    
    
void Aluno::imprimirDados() const{
        cout << matricula << " " << nome << " ";
        for (int nota : notas){
            cout << nota << " ";
        }
        cout << endl;
        
        cout << fixed <<setprecision(2) << calcularMediaNotas();
        cout.unsetf(ios::fixed);
        cout.precision(6);
        cout << " " << notaMaxima() << " " << notaMinima() << endl;
        
}