#include <iostream>

using namespace std;

struct No {
    int dado;
    No* proximo;

    No(int val) : dado(val), proximo(NULL) {}
};

int main() {
    No* head = NULL;
    int n, valor;

    for (int i = 0; i < 6; i++) {
        cout << "Digite o valor a ser inserido: ";
        cin >> valor;

        No* novoNo = new No(valor);
        novoNo->proximo = head;
        head = novoNo;
    }

    cout << "Lista encadeada: ";
    No* atual = head;
    while (atual != NULL) {
        cout << atual->dado << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL" << endl;

    cout << "Digite o número a ser contado: ";
    cin >> valor;

    int ocorrencias = 0;
    atual = head;
    while (atual != NULL) {
        if (atual->dado == valor) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }

    cout << "O número " << valor << " ocorre " << ocorrencias << " vezes na lista encadeada." << endl;

    atual = head;
    
    return 0;
}
