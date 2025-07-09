#include <iostream>
#include <string>
#include <list>

class Puzzle {
private:
	int id;
	static int contador;
	static int idPadrao;

public:
	Puzzle() {
		id = idPadrao++;
		contador++;
	}

    Puzzle(int idInput) {
        if(idInput < 0) {
            id = idInput;
            contador++;
        } else {
            id = -1;
        }
    }

    ~Puzzle() {
        if(id != -1) {
            contador--;
        }
    }

    int getId() const{
        return id;
    }

	static int getContador(){
        return contador;
	}

	const void* getEndereco() const {
        return static_cast<const void*>(this);
	}
};

int Puzzle::contador = 0;
int Puzzle::idPadrao = 1;

int main(){
	std::list<Puzzle*> lista;
	std::string comando;

	while(std::cin >> comando){

		if (comando == "A") {
			Puzzle* novoId = new Puzzle();
			lista.push_back(novoId);
			std::cout << novoId->getId() << " " << novoId->getEndereco() << std::endl;

        } else if (comando == "C") {
            int idInput;
            std::cin >> idInput;

            if(idInput > -1) {
                std::cout << "ERRO" << std::endl;
                
                
            } else {
                Puzzle* novoId = new Puzzle(idInput);
                lista.push_front(novoId);
                std::cout << novoId->getId() << " " << novoId->getEndereco() << std::endl;
                
            }

		} else if (comando == "R") {
			if (lista.empty()) {
				std::cout << "ERRO" << std::endl;
			} else {
			    Puzzle* firstId = lista.front();
				std::cout << firstId->getId() << " " << firstId->getEndereco() << std::endl;
				lista.pop_front();
				delete firstId;
			}

		} else if (comando == "N") {
			std::cout << Puzzle::getContador() << std::endl;

		} else if (comando == "P") {
		    int i;
		    std:: cin >> i;

			if (i < 1 || i > static_cast<int>(lista.size())) {
				std::cout << "ERRO" << std::endl;
			} else {
			    auto it = lista.begin();
			    std::advance(it, i-1);
				std::cout << (*it)->getId() << " " << (*it)->getEndereco() << std::endl;
			}

		} else if (comando == "L") {
			for (Puzzle* item : lista) {
				std::cout << item->getId() << " " << item->getEndereco() << std::endl;
			}

		} else if (comando == "E") {
			break;
        }
    }

    for(Puzzle* id : lista) {
        delete id;
    }

	return 0;
}
