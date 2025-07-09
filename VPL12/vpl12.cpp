#include <iostream>
#include <vector>
#include <exception>

class NegativeResultException : public std::exception {
private:
    int valor;
    
public:
    NegativeResultException(int received) : valor(received) {}
    const char* what() const noexcept override {
        return "Erro: Resultado Negativo.";
    }
    int get_valor() const{
        return valor;
    }
};

int main() {
    std::vector<int> vetor = {-20, -10, 0, 10, 20};
    
    try {
        std::size_t posicao;
        std::cin >> posicao;
        
        if(posicao >= vetor.size()){
            throw std::out_of_range("Erro: Parametro Invalido.");
        }
        
        int valor = vetor.at(posicao);
        
        if (valor < 0){
            throw NegativeResultException(valor);
        } else if (valor == 0) {
            throw std::logic_error("Erro: O resultado nao deve ser zero.");
        } else {
            std::cout << valor << std::endl;
        }
        
    } catch (const NegativeResultException& e) {
        std::cout << e.what() << std::endl;
        std::cout << e.get_valor() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    } catch (const std::logic_error& e) {
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}