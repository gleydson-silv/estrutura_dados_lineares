#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct No {
    int dado;
    No *proximo;
}No;


No *inicio = NULL;
No *fim = NULL;

bool empty() {
    return inicio == NULL;
}

void enqueue(int valor) {
    No *novo = new No;
    novo->dado = valor;
    novo->proximo = NULL;

    if(empty()) {
        inicio = novo;
        fim = novo;
    }else {
        fim->proximo = novo;
        fim = novo;
    }
    cout << "Elemento " << valor << " inserido na fila.\n";
}

void dequeue() {
    if (empty()) {
        cout << "Não é possivel remover um elemento de uma fila vazia.\n";
        return;
    }else {
        No *temp = inicio;
        inicio = inicio->proximo;
        cout << "Elemento" << temp->dado << " removido da fila.\n";
        delete temp;

        if (inicio == NULL) {
            fim = NULL;
        }
    }
}

void imprimir() {
    if(empty()) {
        cout << "A fila esta vazia.\n";
        return;
    }

    No *temp  = inicio;
    cout << "Fila: ";
    while(temp != NULL) {
        cout << temp->dado << " ";
        temp = temp->proximo;
    }
    cout << endl;
}

int main() {
    int opcao, valor;

    do {
        cout << "\n=== MENU FILA ===\n";
        cout << "1 - Enfileirar\n";
        cout << "2 - Desenfileirar\n";
        cout << "3 - Imprimir\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um valor: ";
            cin >> valor;
            enqueue(valor);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            imprimir();
            break;
        case 0:
            cout << "Encerrando...\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}

