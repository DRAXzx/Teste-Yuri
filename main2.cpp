#include <iostream>

using namespace std;

struct Nodo {
    int dado;
    Nodo* proximo;
    Nodo(int dado) : dado(dado), proximo(NULL) {}
};

void imprimirLista(Nodo* cabeca) {
    Nodo* atual = cabeca;
    while (atual != NULL) {
        cout << atual->dado << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL" << endl;
}

Nodo* inverterLista(Nodo* cabeca) {
    Nodo* anterior = NULL;
    Nodo* atual = cabeca;

    while (atual != NULL) {
        Nodo* proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior; 
}

int main() {
    Nodo* cabeca = new Nodo(1);
    cabeca->proximo = new Nodo(2);
    cabeca->proximo->proximo = new Nodo(3);
    cabeca->proximo->proximo->proximo = new Nodo(4);

    cout << "Lista original: ";
    imprimirLista(cabeca);

    cabeca = inverterLista(cabeca);

    cout << "Lista revertida: ";
    imprimirLista(cabeca);

    return 0;
}
