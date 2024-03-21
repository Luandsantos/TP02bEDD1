#include <iostream>
#include <string>
#include <unistd.h> // Para usar sleep() em sistemas Unix-like (Linux, macOS)

using namespace std;

int main() {
    string mensagem;
    cout << "Digite a mensagem: ";
    getline(cin, mensagem);

    // Limpa a tela
    cout << "\033[2J\033[H";

    int linhaAtual = 5;

    // Apresenta a mensagem centralizada na linha 5
    int espacos = (80 - mensagem.length()) / 2;
    cout << string(espacos, ' ') << mensagem << endl;

    // Simula a cascata
    for (int i = 0; i < mensagem.length(); ++i) {
        // Move o cursor para a próxima linha
        for (int j = linhaAtual; j <= 20; ++j) {
            // Limpa a linha anterior
            cout << "\033[" << j << ";1H" << string(80, ' ') << "\033[" << j << ";1H";
            // Imprime a letra na posição correta
            cout << "\033[" << j << ";" << (espacos + i + 1) << "H" << mensagem[i] << endl;
            // Espera um curto período de tempo para criar o efeito de cascata
            usleep(100000); // Espera 100 milissegundos (0.1 segundos)
        }
        // Incrementa a linha atual para a próxima iteração
        linhaAtual++;
    }

    // Move o cursor para a última linha
    cout << "\033[22;1H";
    
    return 0;
}
