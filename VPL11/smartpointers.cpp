#include <memory>
#include <iostream>

using namespace std;

class Teste {
    public:
    int origin;
    
    Teste() : origin(0) {
        cout << "Construtor " << origin << endl;
    }
    Teste(int received) : origin(received) {
        cout << "Construtor " << origin << endl;
    }
    
    ~Teste(){
        cout << "Destrutor " << origin << endl;
    }
};

int main() {
    int n;
    cin >> n;
    
    if(n % 2 == 0){
        for(int i = 1; i <= n; i++){
            Teste* trad_ptr = new Teste(i);
            unique_ptr<Teste> other_object(new Teste(i));
        }
        
    } else {
        shared_ptr<Teste> shared_object_1(new Teste(0));
        for(int j = 1; j <= n; j++) {
            shared_ptr<Teste> shared_object_2 = shared_object_1; 
            shared_object_1->origin = j;
        }
        cout << shared_object_1.use_count() << endl;
    }
    
    
    return 0;
}