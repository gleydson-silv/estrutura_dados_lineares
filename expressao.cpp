//Pilha - Verificação de Expressão Matemática
//Escreva um algoritmo que utilize pilhas para verificar se uma expressão
//matemática possui parênteses balanceados. Exemplo:
//• Entrada: "((2+3) * (5/2))" Válido
//• Entrada: "((2+3) * (5/2)" Inválido

#include <iostream>

using namespace std;

struct No {
    char caractere;
    No* proximo;
};

void empilhar(No** topo, char c) {
    No* novo = new No;
    novo->caractere = c;
    novo->proximo = *topo;
    *topo = novo;
}

char desempilhar(No** topo) {
    if (*topo == nullptr) {
        return '\0'; // Pilha vazia
    }
    No* temp = *topo;
    char c = temp->caractere;
    *topo = temp->proximo;
    delete temp;
    return c;
}

bool parêntesesBalanceados(const char* expressao) {
    No* pilha = nullptr;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (c == '(') {
            empilhar(&pilha, c);
        } 
        else if (c == ')') {
            if (pilha == nullptr) {
                // Tentou fechar um parêntese que não foi aberto
                return false;
            }
            desempilhar(&pilha);
        }
    }

    // Se a pilha estiver vazia, todos os parênteses foram fechados corretamente
    bool valido = (pilha == nullptr);

    // Limpar pilha (caso tenha sobrado algo)
    while (pilha != nullptr) {
        desempilhar(&pilha);
    }

    return valido;
}

int main() {
    char expressao[100];

    cout << "Digite a expressão matemática: ";
    cin.getline(expressao, 100);

    if (parêntesesBalanceados(expressao)) {
        cout << "Expressão válida!" << endl;
    } else {
        cout << "Expressão inválida!" << endl;
    }

    return 0;
}