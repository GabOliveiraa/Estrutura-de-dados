// ---------------------------------------------
//
// Programa de Bubble Sort
// Ordena o vetor comparando elementos vizinhos e trocando suas posições
// quando estão fora de ordem. A cada passagem, o maior valor restante
// é levado para o final do vetor.
//
// ---------------------------------------------

#include <iostream>
#include <cctype>

using namespace std;

struct vetorDinamico {
    int* dados;
    size_t capacidade;
    size_t tamanho;
};

// Função para ler os valores digitados pelo usuário
void lerNumeros(vetorDinamico& vetor){
    char continuar;

    do{
        if(vetor.tamanho == vetor.capacidade) {
            vetor.capacidade *= 2;
            int* novoArray = new int[vetor.capacidade];
            for(size_t i = 0; i < vetor.tamanho; i++) novoArray[i] = vetor.dados[i];
            delete[] vetor.dados;
            vetor.dados = novoArray;
        }

        cout << "Digite um numero: ";
        cin >> vetor.dados[vetor.tamanho];
        vetor.tamanho++;

        cout << "Deseja continuar digitando? (s/n): ";
        cin >> continuar;
        cin.ignore(80, '\n');
    } while(toupper(continuar) == 'S');
};

// Função de ordenação do Bubble Sort
void BubbleSort(int vetor[], size_t tamanho)
{
    for (size_t i = 0; i < tamanho; i++) {
        for (size_t j = 0; j < tamanho - 1 - i; j++) {

            // Compara o valor atual com o próximo
            if (vetor[j] > vetor[j + 1]) {

                // Troca de posição
                int x = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = x;
            }
        }
    }
};

// Mostra os valores do vetor
void imprimirVetor(int vetor[], size_t tamanho){
    for (size_t i = 0; i < tamanho; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
};

// Programa Principal
int main(){

    vetorDinamico lista;
    lista.capacidade = 2;
    lista.tamanho = 0;
    lista.dados = new int[lista.capacidade];

    lerNumeros(lista);

    if(lista.tamanho == 0) {
        cout << "\nNenhum numero foi digitado." << endl;
        delete[] lista.dados;
        return 0;
    }

    cout << "\nAntes da ordenacao: ";
    imprimirVetor(lista.dados, lista.tamanho);

    BubbleSort(lista.dados, lista.tamanho);

    cout << "Depois da ordenacao: ";
    imprimirVetor(lista.dados, lista.tamanho);

    delete[] lista.dados;
    return 0;
}