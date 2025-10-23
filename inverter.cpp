6. Pilha - Inversão de String
Utilizando a estrutura de pilha, implemente um programa que receba uma string e
a inverta. Exemplo:
Entrada: "Estrutura"
Saída: "aruturtsE"

#include <iostream>
#include <cstring>

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
        return '\0';
    }
    No* temp = *topo;
    char c = temp->caractere;
    *topo = temp->proximo;
    delete temp;
    return c;
}

void inverter(char* texto) {
    No* pilha = nullptr;
    int tamanho = strlen(texto);

    for (int i = 0; i < tamanho; i++) {
        empilhar(&pilha, texto[i]);
    }

    for (int i = 0; i < tamanho; i++) {
        texto[i] = desempilhar(&pilha);
    }
}

int main() {
    char texto[100];

    cout << "Digite uma palavra: ";
    cin.getline(texto, 100);

    inverter(texto);

    cout << "Invertido: " << texto << endl;

    return 0;
}