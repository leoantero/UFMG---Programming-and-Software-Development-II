#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm> // Função find

using namespace std;

void verificaLetras(const string& entrada, const string& palavraEscolhida, string& letrasErradas){
    string resultado = entrada;
    
    for(int contador = 0; contador < 5; contador++){
        if(entrada[contador] == palavraEscolhida[contador]){
          
          resultado[contador] = toupper(entrada[contador]);
        } else if (palavraEscolhida.find(entrada[contador]) != string::npos){
           
          resultado[contador] = tolower(entrada[contador]);
        } else {
            
           resultado[contador] = '*';
           bool inserida = false;
           for (char letra : letrasErradas){
               if (letra == entrada[contador]) {
                   inserida = true;
                   break;
               }
           }
           if (!inserida){
               letrasErradas+=entrada[contador];
           }
            
        }
    }
    
    cout << resultado << " (";
    for (char letra : letrasErradas){
        cout << letra;
    }
    cout << ")" << endl;
}

int main(){
    
    // Operando com o arquivo 
    ifstream arq;
    string linha;
    vector<string> listadePalavras;
    
    arq.open("palavras.txt");
    if(!arq.is_open()){
        cout << "Não foi possível abrir o arquivo" << endl;
        return 1;
    }
    
     while(getline(arq, linha)){
            listadePalavras.push_back(linha);
            // Salvando as palavbras em um array para facilitar 
        }
        
    arq.close();
    
    int numero;
    cin >> numero;
    
    string palavraEscolhida = listadePalavras[numero];
    string letrasErradas;
    string tentativa;
    int tentativas = 5;
    
    // Iniciando o jogo
    
    while(tentativas > 0){
        cin >> tentativa;
        
        if(tentativa.length() != 5) {
            cout << "Palavra inválida, a palavra deve ter 5 letras." << endl;
            continue;
        }
        
        verificaLetras(tentativa, palavraEscolhida, letrasErradas);
        
        if (tentativa == palavraEscolhida){
            cout << "GANHOU!" << endl;
            return 0;
        }
        tentativas--;
        
    }
    
    cout << "PERDEU! " << palavraEscolhida << endl;
    return 0;
}