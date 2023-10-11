#include <iostream>

using namespace std;

struct No {
    int dado;
    No* proximo;
    
    No(int valor) : dado(valor), proximo(NULL) {}
};

void imprimirLista(No* cabeca) {
    while (cabeca != NULL) {
        cout << cabeca->dado;
        cabeca = cabeca->proximo;
        if (cabeca != NULL) {
            cout << "->";
        }
    }
    cout << "NULL" << endl;
}

No* reverterIntervalo(No* cabeca, int inicio, int fim) {
    No* dummy = new No(0);
    dummy->proximo = cabeca;
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
    No* cabeca = new No(10);
    cabeca->proximo = new No(11);
    cabeca->proximo->proximo = new No(12);
    cabeca->proximo->proximo->proximo = new No(13);
    cabeca->proximo->proximo->proximo->proximo = new No(14);
    cabeca->proximo->proximo->proximo->proximo->proximo = new No(15); 
    
    int inicio = 3;
    int fim = 5;

    cout << "Lista ligada original: ";
    imprimirLista(cabeca);

    cabeca = reverterIntervalo(cabeca, inicio, fim);

    cout << "Lista ligada após a reversão: ";
    imprimirLista(cabeca);

    return 0;
}
