//Lista Duplamente Encadeada - Inserção Ordenada
//Implemente uma lista duplamente encadeada onde os elementos são inseridos
//de forma ordenada. O usuário deve inserir um número e o programa deve
//posicioná-lo no local correto para manter a ordem crescente.

#include <iostream>

using namespace std;

typedef struct No {
    int dado;
    No *proximo;
    No *anterior;
}No;

No *cabeca = NULL;
No *fim = NULL;

bool vazia() {
    return cabeca == NULL;
}

void inserir(int valor) {
    No *novo = new No;
    novo->dado = valor;
    novo->proximo = NULL;

    if(vazia()) {
        cabeca = novo;
        fim = novo;
        novo->anterior = NULL;
        novo->proximo = NULL;
    }else {
        fim->proximo = novo;
        fim = novo;
        fim->anterior = cabeca;
    }
}

void imprimir() {
    No *temp = cabeca;
    cout << "Lista atual: ";
    while(temp!=NULL) {
        cout << temp->dado << " ";
        temp = temp->proximo;
    }
    cout << endl;
}


int main() {
    int opcao, valor;

    do {
        cout << "\n=== MENU FILA ===\n";
        cout << "1 - Inserir\n";
        cout << "2 - Imprimir\n";
        cout << "0 - Sair\n";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um valor: ";
            cin >> valor;
            inserir(valor);
            break;
        case 2:
        imprimir();
        break;
        case 0:
            cout << "Encerrando...\n";
            break;
        default:
            cout << "Opção inválida!\n";  
        }
   }while(opcao!= 0);

}