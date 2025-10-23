#include <iostream>

using namespace std;

typedef struct No {
    int dado;
    No *proximo;
}No;

No *cabeca = NULL;
No *fim = NULL;

bool vazia() {
    return cabeca == NULL;
}

void inserirInicio(int valor) {
    No *novo = new No;
    novo->dado = valor;
    novo->proximo = cabeca;
    cabeca = novo;

    cout << "O item inserido foi: " << novo->dado << endl;
}

void inserirFim(int valor) {
    No *novo = new No;
    novo->dado = valor;
    novo->proximo = NULL;

    if(vazia()) {
        cabeca = novo;
        fim = novo;
    }else {
        fim->proximo = novo;
        fim = novo;
    }
    cout << "Elemento " << valor << " inserido na lista.\n";
}

void removerDuplicados() {
        if (cabeca == NULL) {
            cout << "Lista vazia!" << endl;
            return;
        }
        
        No *atual = cabeca;
        
        while (atual != NULL) {
            No *verificador = atual;
            
            while (verificador->proximo != NULL) {
                if (verificador->proximo->dado == atual->dado) {
                    No *duplicado = verificador->proximo;
                    verificador->proximo = duplicado->proximo;
                    delete duplicado;
                } else {
                    verificador = verificador->proximo;
                }
            }
            
            atual = atual->proximo;
        }
        
        cout << "Duplicados removidos!" << endl;
    }


void imprimir() {
    No *temp = cabeca;
    cout << "Lista atual: ";
    while(temp!= NULL) {
        cout << temp->dado << " ";
        temp = temp->proximo;
    }
    cout << endl;
}

int main() {
    int opcao, valor;

    do {
        cout << "\n=== MENU FILA ===\n";
        cout << "1 - Inserir no inicio\n";
        cout << "2 - Inserir no fim\n";
        cout << "3 - Remover Duplicados\n";
        cout << "4 - Imprimir\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um valor: ";
            cin >> valor;
            inserirInicio(valor);
            break;
        case 2:
            cout << "Digite um valor: ";
            cin >> valor;
            inserirFim(valor);  
        case 3:
            removerDuplicados();
            break;
        case 4:
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
