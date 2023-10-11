#include <iostream>

using namespace std;

struct No {
    int dado;
    No* proximo;
    
    No(int valor) : dado(valor), proximo(NULL) {}
};

void imprimirLista(No* head) {
    while (head != NULL) {
        cout << head->dado;
        cabeca = head->proximo;
        if (head != NULL) {
            cout << "->";
        }
    }
    cout << "NULL" << endl;
}

No* reverterIntervalo(No* head, int inicio, int fim) {
    No* dummy = new No(0);
    dummy->proximo = head;
    No* anterior = dummy;

    for (int i = 1; i < inicio; ++i) {
        anterior = anterior->proximo;
    }

    No* atual = anterior->proximo;
    No* proximoNo = atual->proximo;

    for (int i = inicio; i < fim; ++i) {
        atual->proximo = proximoNo->proximo;
        proximoNo->proximo = anterior->proximo;
        anterior->proximo = proximoNo;
        proximoNo = atual->proximo;
    }

    return dummy->proximo;
}

int main() {
    No* head = new No(10);
    head->proximo = new No(11);
    head->proximo->proximo = new No(12);
    head->proximo->proximo->proximo = new No(13);
    head->proximo->proximo->proximo->proximo = new No(14);
    head->proximo->proximo->proximo->proximo->proximo = new No(15); 
    
    int inicio = 3;
    int fim = 5;

    cout << "Lista ligada original: ";
    imprimirLista(head);

    head = reverterIntervalo(head, inicio, fim);

    cout << "Lista ligada após a reversão: ";
    imprimirLista(head);

    return 0;
}
