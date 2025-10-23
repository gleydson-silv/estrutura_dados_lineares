//4. Lista Duplamente Encadeada - Remoção
//Dada uma lista duplamente encadeada, implemente uma função para remover
//um nó específico e ajustar os ponteiros dos nós vizinhos corretamente.

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

void remover(int posicao) {
    if(cabeca == NULL) {
        cout << "Nao e possivel remover um item de uma lista vazia\n";
        return;
    }

    if(posicao < 1) {
        cout << "Posicao invalida ";
        return;
    }

    if (posicao == 1) {
        No *temp = cabeca;
        cout << "O item removido foi: " << temp->dado << endl;
        cabeca = cabeca->proximo;
        cabeca->anterior = NULL;
        delete temp;
        return;
    }

    No *anterior = cabeca;
    int contador = 1;

    while (anterior != NULL && contador < posicao - 1) {
        anterior = anterior->proximo;
        contador++;
    }

     if (anterior == NULL || anterior->proximo == NULL) {
        cout << "Posição não existe na lista!" << endl;
        return;
    }

     No *temp = anterior->proximo;  // Nó a ser removido
    cout << "O item removido foi: " << temp->dado << endl;
    anterior->proximo = temp->proximo;
    anterior->anterior = temp->anterior;  // "Pula" o nó removido
    delete temp;  // Libera a memória
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
    int opcao, valor,posicao;

    do {
        cout << "\n=== MENU FILA ===\n";
        cout << "1 - Inserir\n";
        cout << "2 - Remover\n";
        cout << "3 - Imprimir\n";
        cout << "0 - Sair\n";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um valor: ";
            cin >> valor;
            inserir(valor);
            break;
        case 2:
        cout << "Digite uma posicao para remover: ";
        cin >> posicao;
        remover(posicao);   
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
   }while(opcao!= 0);
}