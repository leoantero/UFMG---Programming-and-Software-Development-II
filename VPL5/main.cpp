#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <fstream>

using namespace std;

void processaPalavra(string& palavra, map<string, int>& contagemPalavras) {
    string cleanword;
    
    size_t position = 0;
    while ((position = palavra.find('-')) != string::npos) {
        string primeiraParte = palavra.substr(0, position);
        
        for (char c : primeiraParte) {
            if (isalnum(c)) {
                cleanword += tolower(c);
            }
        }

        if (!cleanword.empty()) {
            contagemPalavras[cleanword]++;
        }
        
        palavra.erase(0, position + 1);
        cleanword.clear(); 
    }

    for (char c : palavra) {
        if (isalnum(c)) {
            cleanword += tolower(c);
        }
    }

    if (!cleanword.empty()) {
        contagemPalavras[cleanword]++;
    }
}

int main() {
    string nomeArquivo;

    cin >> nomeArquivo;

    ifstream arquivo(nomeArquivo);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    map<string, int> contagemPalavras;
    string palavra;

    while (arquivo >> palavra) {
        processaPalavra(palavra, contagemPalavras);
    }

    for (const auto& par : contagemPalavras) {
        cout << par.first << " " << par.second << endl;
    }

    arquivo.close();
    return 0;
}
