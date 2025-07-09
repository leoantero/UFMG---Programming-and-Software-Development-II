#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

class Ponto {
    protected:
        double _x;
        double _y;
    
    public:
        Ponto() : Ponto(0, 0) {}
        Ponto(double x, double y) : _x(x), _y(y) {}
        
        void printcoordenadas() const {
            std::cout << static_cast<int>(_x) << " " << static_cast<int>(_y); 
        }
};

class FiguraGeometrica {
    protected:
        Ponto centro;
    
    public:
        FiguraGeometrica() : FiguraGeometrica(0, 0) {}
        FiguraGeometrica(double x, double y) : centro(x,y) {}
        virtual ~FiguraGeometrica() {}
        
        virtual void Desenha() const = 0;
        virtual float CalculaArea() const = 0;

};

class Circulo : public FiguraGeometrica {
    private:
        double raio;
    
    public:
        Circulo() : Circulo(0,0,0) {}
        Circulo(double x, double y, double r)
            : FiguraGeometrica(x,y), raio(r) {}
        
        void Desenha() const override {
            centro.printcoordenadas();
            std::cout << " CIRCULO" << std::endl;
        }
        
        float CalculaArea() const override {
            return M_PI * raio* raio;
        }
};

class Triangulo : public FiguraGeometrica {
    private:
        double base, altura;
    
    public:
        Triangulo() : Triangulo(0, 0, 0, 0) {}
        Triangulo(double x, double y, double b, double h)
            : FiguraGeometrica(x, y), base(b), altura(h) {}
        
        void Desenha() const override {
            centro.printcoordenadas();
            std::cout << " TRIANGULO" << std::endl;
        }
        
        float CalculaArea() const override {
            return (base * altura)/2;
        }
};

class Retangulo : public FiguraGeometrica {
    private:
        double lado1, lado2;
    
    public:
        Retangulo() : Retangulo(0, 0, 0, 0) {}
        Retangulo(double x, double y, double l1, double l2) 
            : FiguraGeometrica(x,y), lado1(l1), lado2(l2) {}
        
        void Desenha() const override {
            centro.printcoordenadas();
            std::cout << " RETANGULO" << std::endl;
        }
        float CalculaArea() const override {
            return lado1 * lado2;
        }
};

int main(){
    std::vector<FiguraGeometrica*> figuras;
    std::string comandoinit, comando;
    
    while(true){
        std::cin >> comando;
        
        if (comando == "R") {
            double x, y, l1, l2;
            std::cin >> x >> y >> l1 >> l2;
            figuras.push_back(new Retangulo(x, y, l1, l2));
        } else if (comando == "C") {
            double x, y, r;
            std::cin >> x >> y >> r;
            figuras.push_back(new Circulo(x, y, r));
        } else if (comando == "T") {
            double x, y, b, h;
            std::cin >> x >> y >> b >> h;
            figuras.push_back(new Triangulo(x, y, b, h));
        } else if (comando == "D") {
            for (const  auto& figura : figuras) {
                figura->Desenha();
            }
        } else if (comando == "A") {
            float AreaTotal = 0;
            for(const auto& figura:figuras){
                AreaTotal += figura->CalculaArea();
            }
            std::cout << std::fixed << std::setprecision(2) << AreaTotal << std::endl;
        } else if (comando == "E"){
            break;
        }
    }
    for (auto& figura : figuras) {
        delete figura;
    }
    return 0;
}