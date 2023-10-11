#include <iostream>

using namespace std;

struct No {
    int dado;
    No* proximo;
    No(int dado) : dado(dado), proximo(NULL) {}
};

void imprimirLista(No* head) {
    No* atual = head;
    while (atual != NULL) {
        cout << atual->dado << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL" << endl;
}

No* inverterLista(No* head) {
    No* anterior = NULL;
    No* atual = head;

    while (atual != NULL) {
        No* proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    return anterior; 
}

int main() {
    No* head = new No(1);
    head->proximo = new No(2);
    head->proximo->proximo = new No(3);
    head->proximo->proximo->proximo = new No(4);

    cout << "Lista original: ";
    imprimirLista(head);

    cabeca = inverterLista(head);

    cout << "Lista revertida: ";
    imprimirLista(head);

    return 0;
}
