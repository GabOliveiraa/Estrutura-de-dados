// ---------------------------------------------
//
// Programa de Selection Sort
// Ordena o vetor procurando o menor valor na parte ainda não ordenada
// e trocando sua posição com a posição atual. A cada passagem,
 // uma nova posição do início do vetor fica ordenada.
//
// ---------------------------------------------

#include <iostream>

using namespace std;

void SelectionSort(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        int menor = i; // assume que o primeiro elemento é o menor

        // Busca o menor elemento do restante do vetor
        for(int j = i + 1; j < tamanho; ++j){
            if(vetor[j] < vetor[menor]){
                menor = j; // muda para o menor vetor encontrado
            }
        }

        if(menor != i) {
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
};

void imprimirVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
};

// Programa principal
int main() {
    int numeros[] = {6, 9, 4, 1, 8, 5};
    int tamanho = 6;

    cout << "Antes da ordenacao: ";
    imprimirVetor(numeros, tamanho);

    SelectionSort(numeros, tamanho);

    cout << "Depois da ordenacao: ";
    imprimirVetor(numeros, tamanho);

    return 0;
}