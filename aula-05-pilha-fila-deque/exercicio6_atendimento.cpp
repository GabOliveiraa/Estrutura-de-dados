#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<string> atendimento;
    int opcao;
    string nome;

<<<<<<< HEAD
=======
    // Valores iniciais do seu teste para o sistema já começar preenchido
>>>>>>> 7a4bfeff7adaf7dfab2644a1560ca9acfa7a0944
    atendimento.push_back("Ana");
    atendimento.push_back("Bruno");
    atendimento.push_front("Carla");
    atendimento.push_back("Diego");
    atendimento.push_front("Elena");

    do {
<<<<<<< HEAD
=======
        // Exibição do Menu
>>>>>>> 7a4bfeff7adaf7dfab2644a1560ca9acfa7a0944
        cout << "\n===============================" << endl;
        cout << "    SISTEMA DE ATENDIMENTO     " << endl;
        cout << "===============================" << endl;
        cout << "1. Inserir Cliente Comum" << endl;
        cout << "2. Inserir Cliente Prioritario" << endl;
        cout << "3. Atender Proximo Cliente" << endl;
        cout << "4. Mostrar Fila Atual" << endl;
        cout << "0. Sair" << endl;
        cout << "===============================" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

<<<<<<< HEAD
=======
        // Limpa o buffer do teclado para evitar problemas com o getline
>>>>>>> 7a4bfeff7adaf7dfab2644a1560ca9acfa7a0944
        cin.ignore(); 

        switch (opcao) {
            case 1:
                cout << "Digite o nome do cliente comum: ";
                getline(cin, nome);
<<<<<<< HEAD
                atendimento.push_back(nome);
=======
                atendimento.push_back(nome); // Entra no fim da fila
>>>>>>> 7a4bfeff7adaf7dfab2644a1560ca9acfa7a0944
                cout << nome << " adicionado(a) no fim da fila." << endl;
                break;

            case 2:
                cout << "Digite o nome do cliente prioritario: ";
                getline(cin, nome);
<<<<<<< HEAD
                atendimento.push_front(nome);
=======
                atendimento.push_front(nome); // Passa na frente da fila
>>>>>>> 7a4bfeff7adaf7dfab2644a1560ca9acfa7a0944
                cout << nome << " adicionado(a) na frente da fila." << endl;
                break;

            case 3:
                if (!atendimento.empty()) {
                    cout << "Atendendo: " << atendimento.front() << endl;
<<<<<<< HEAD
                    atendimento.pop_front();
=======
                    atendimento.pop_front(); // Remove o primeiro da fila
>>>>>>> 7a4bfeff7adaf7dfab2644a1560ca9acfa7a0944
                } else {
                    cout << "Nenhum cliente na fila de espera." << endl;
                }
                break;

            case 4:
                if (!atendimento.empty()) {
                    cout << "Fila atual: ";
                    for (const string& cliente : atendimento) {
                        cout << "[" << cliente << "] ";
                    }
                    cout << endl;
                } else {
                    cout << "A fila esta vazia." << endl;
                }
                break;

            case 0:
                cout << "Encerrando o sistema..." << endl;
                break;

            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    return 0;
}