#include "aluno.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>


using namespace std;

int main(){
    vector<Aluno> alunos;
    string nome;
    int matricula;
    
    while(true){
        getline(cin, nome);
        if (nome == "END") break;
        
        cin >> matricula;
        Aluno aluno(matricula, nome);
        
        int nota;
        while(cin >> nota && nota!=-1){
            aluno.adicionarNota(nota);
        }
        
        cin.ignore();
        alunos.push_back(aluno);
    
    }
    
    sort(alunos.begin(), alunos.end());
    
    for (const Aluno& aluno : alunos){
        cout << aluno.getMatricula() << " " << aluno.getNome() << " ";
        for (int nota : aluno.getNotas()) {
            cout << nota << " ";
        }
        cout << endl;
        cout << fixed << setprecision(2) << aluno.calcularMediaNotas() << " ";
        cout.unsetf(ios::fixed);
        cout.precision(6);
        cout << " " << aluno.notaMaxima() << " " << aluno.notaMinima() << endl;
    }
    return 0;
}