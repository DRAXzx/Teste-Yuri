#include <iostream>

using namespace std;

struct No {
    int dado;
    No* proximo;
};

class ListaEncadeada {
public:
    ListaEncadeada() : cabeca(NULL) {}

    void inserir(int valor) {
        No* novoNo = new No{valor, cabeca};
        cabeca = novoNo;
    }

    bool saoIdenticas(const ListaEncadeada& outra) const {
        No* atual1 = cabeca;
        No* atual2 = outra.cabeca;

        while (atual1 != NULL && atual2 != NULL) {
            if (atual1->dado != atual2->dado) {
                return false;
            }
            atual1 = atual1->proximo;
            atual2 = atual2->proximo;
        }

        return atual1 == NULL && atual2 == NULL;
    }

private:
    No* cabeca;
};

int main() {
    ListaEncadeada lista1;
    ListaEncadeada lista2;

    lista1.inserir(3);
    lista1.inserir(2);
    lista1.inserir(1);

    lista2.inserir(3);
    lista2.inserir(2);
    lista2.inserir(1);

    if (lista1.saoIdenticas(lista2)) {
        cout << "As listas s�o id�nticas." << endl;
    } else {
        cout << "As listas n�o s�o id�nticas." << endl;
    }

    return 0;
}
