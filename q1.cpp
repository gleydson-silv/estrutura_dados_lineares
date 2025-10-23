1. Lista Encadeada Simples
Implemente uma lista encadeada simples em C++ contendo as operações
básicas:
• Inserir um elemento no início.
• Inserir um elemento no final.
• Remover um elemento específico da lista.
• Buscar um elemento na lista.
• Exibir os elementos da lista.

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

void inserir(int valor) {
    No *novo = new No;
    novo->dado = valor;
    novo->proximo = cabeca;
    cabeca = novo;

    cout << "O item inserido foi: " << novo->dado << endl;
}

void inserirFinal(int valor2) {
    No *novo = new No;
    novo->dado = valor2;
    novo->proximo = NULL; 

    if(vazia()) {
        cabeca = novo;
        fim = novo;
    }else {
        fim->proximo = novo;
        fim = novo;
    }
    cout << "O valor inserido no fim foi: " << valor2 << endl;
}

void removerItem(int posicao) {
if (cabeca == NULL) {
        cout << "Lista vazia! Não há itens para remover." << endl;
        return;
    }
    
    // Verifica se a posição é válida
    if (posicao < 1) {
        cout << "Posição inválida!" << endl;
        return;
    }
    
    // Caso especial: remover o primeiro elemento (cabeça)
    if (posicao == 1) {
        No *temp = cabeca;
        cout << "O item removido foi: " << temp->dado << endl;
        cabeca = cabeca->proximo;  // Atualiza a cabeça
        delete temp;  // Libera a memória
        return;
    }
    
    // Para posições > 1, precisamos do nó anterior
    No *anterior = cabeca;
    int contador = 1;
    
    // Navega até o nó anterior ao que será removido
    while (anterior != NULL && contador < posicao - 1) {
        anterior = anterior->proximo;
        contador++;
    }
    
    // Verifica se a posição existe na lista
    if (anterior == NULL || anterior->proximo == NULL) {
        cout << "Posição não existe na lista!" << endl;
        return;
    }
    
    // Remove o nó
    No *temp = anterior->proximo;  // Nó a ser removido
    cout << "O item removido foi: " << temp->dado << endl;
    anterior->proximo = temp->proximo;  // "Pula" o nó removido
    delete temp;  // Libera a memória
}

void buscar(int posicao) {
    if(vazia()) {
        cout << "A lista está vazia!" << endl;
        return;
    }
    
    if(posicao < 1) {
        cout << "Posição inválida!" << endl;
        return;
    }
    
    No *temp = cabeca;
    int contador = 1;
    
    while(temp != NULL) {
        if(posicao == contador) {
            cout << "O item na posição " << posicao << " é: " << temp->dado << endl;
            return;  // Encontrou, sai da função
        }
        temp = temp->proximo;  // Move DEPOIS de verificar
        contador++;  // Incrementa o contador
    }
    
    // Se chegou aqui, a posição não existe
    cout << "Posição " << posicao << " não existe na lista!" << endl;
}

void imprimir() {
    No *temp = cabeca;
    cout << "Fila atual: ";
    while(temp!= NULL) {
        cout << temp->dado << " ";
        temp = temp->proximo;
    }
    cout << endl;
}

int main() {
    int opcao, valor, valor2, posicao;

    do {
        cout << "\n=== MENU FILA ===\n";
        cout << "1 - Inserir Inicio\n";
        cout << "2 - Inserir fim\n";
        cout << "3 - Remover posicao\n";
        cout << "4 - Buscar item\n";
        cout << "5 - Imprimir\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            cout << "Digite um valor: ";
            cin >> valor;
            inserir(valor);
            break;
        case 2:
        cout << "Digite um valor: ";
        cin >> valor2;    
        inserirFinal(valor2);
            break;
        case 3:
        cout << "Digite uma posicao pra remover: ";
        cin >> posicao;    
        removerItem(posicao);
            break;
        case 4:
            cout << "Digite uma posicao para buscar: ";
            cin >> posicao;
            buscar(posicao);
            break;
        case 5:
        imprimir();
        default:
            cout << "Opção inválida!\n";
        }

    } while (opcao != 0);

    return 0;
}