#include <iostream>
using namespace std;

typedef struct Lista {
    int dado;
    Lista *prox;
} celula;

celula *topo = NULL;

void imprimir();
void push(int);
void pop();

int main() {
    int number, opcao;
    
    do {
        cout << "\n---- MENU ----\n";
        cout << "1 - Imprimir a pilha\n";
        cout << "2 - Inserir (push)\n";
        cout << "3 - Remover (pop)\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                imprimir();
                break;
            case 2:
                cout << "Digite um numero para inserir: ";
                cin >> number;
                push(number);
                break;
            case 3:
                pop();
                break;
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida!\n";
        }
    } while (opcao != 0);
    
    return 0;
}

void push(int item) {
    celula *novo = new celula; //aloca espaço pra nova celula
    novo->dado = item; //dado da celula recebe o argumento
    novo->prox = topo; //ponteiro do novo recebe o topo
    topo = novo;
    cout << "Valor empilhado: " << item << endl;
}

void pop() {
    if (topo == NULL) {
        cout << "A pilha esta vazia!\n";
    } else {
        celula *temp = topo; // cria uma celula dado + ponteiro prox que recebe o topo
        topo = topo->prox; // topo recebe o ponteiro para o proximo
        cout << "Item desempilhado: " << temp->dado << endl;
        delete temp; 
    }
}

void imprimir() {
    if (topo == NULL) {
        cout << "A pilha esta vazia!\n";
        return;
    }
    
    cout << "Pilha atual: ";
    celula *temp = topo; // tipo celula recebe o topo
    while (temp != NULL) {
        cout << temp->dado << " ";
        temp = temp->prox;
    }
    cout << endl;
}