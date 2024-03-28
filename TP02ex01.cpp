#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    string mensagem;
    cout << "Digite a mensagem: ";
    getline(cin, mensagem);

    // limpa a tela
    cout << "\033[2J\033[H";

    int linhaAtual = 5;

    // apresenta a mensagem centralizada na linha 5
    int espacos = (80 - mensagem.length()) / 2;
    cout << string(espacos, ' ') << mensagem << endl;

    // simula a cascata
    for (int i = 0; i < mensagem.length(); ++i) {
        // move o cursor para a próxima linha
        for (int j = linhaAtual; j <= 20; ++j) {
            cout << "\033[" << j << ";1H" << string(80, ' ') << "\033[" << j << ";1H";
            // imprime a letra na posição
            cout << "\033[" << j << ";" << (espacos + i + 1) << "H" << mensagem[i] << endl;
            // espera para criar o efeito de cascata
            usleep(100000); // Espera 100 milissegundos (0.1 segundos)
        }
        // incrementa a linha atual para a próxima iteração
        linhaAtual++;
    }

    // move o cursor para a última linha
    cout << "\033[22;1H";
    
    return 0;
}
