// ---------------------------------------------
//
// Programa de Bubble Sort
// Ordena o vetor comparando elementos vizinhos e trocando suas posições
// quando estão fora de ordem. A cada passagem, o maior valor restante
// é levado para o final do vetor.
//
// ---------------------------------------------

#include <iostream>

using namespace std;

// Função de ordenação do Bubble Sort
void BubbleSort(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {

            // Compara o valor atual com o próximo
            if (vetor[j] > vetor[j + 1]) {

                // Troca de posição
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
};

// Mostra os valores do vetor
void imprimirVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
};
// Programa Principal
int main(){

    int numeros[] = {8, 3, 5, 7, 6, 1};
    int tamanho = 6;

    cout << "Antes da ordenacao: ";
    imprimirVetor(numeros, tamanho);

    BubbleSort(numeros, tamanho);

    cout << "Depois da ordenacao: ";
    imprimirVetor(numeros, tamanho);

    return 0;
}