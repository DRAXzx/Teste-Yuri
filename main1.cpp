#include <iostream>

using namespace std;

struct No {
    int dado;
    No* proximo;
};

class ListaEncadeada {
public:
    ListaEncadeada() : head(NULL) {}

    void inserir(int valor) {
        No* novoNo = new No{valor, head};
        head = novoNo;
    }

    bool saoIdenticas(const ListaEncadeada& outra) const {
        No* atual1 = head;
        No* atual2 = outra.head;

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
    No* head;
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
        cout << "As listas são idênticas." << endl;
    } else {
        cout << "As listas não são idênticas." << endl;
    }

    return 0;
}
