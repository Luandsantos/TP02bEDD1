#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");
    ifstream arq("lista1.txt");

    string nome;
    string nomes[100];
    int i = 0;

    ofstream arquivoSaida("saida1.txt"); 

    if (arq.is_open() && arquivoSaida.is_open()) {
        string linha;
        while (getline(arq, linha)) {
            istringstream iss(linha);
            i = 0; // reinicialize i para cada linha
            while (getline(iss, nome, ' ')) {
                nomes[i] = nome; // armazene cada palavra em nomes
                i++;
            }

            arquivoSaida << nomes[i - 1] << ", "; // escreve o �ltimo nome no arquivo de sa�da

            for (int n = 0; n < i; ++n) {
                if (n == 0) {
                    arquivoSaida << nomes[n];
                } else if (n != i - 1) {
                    arquivoSaida << " " << nomes[n]; // adiciona espa�o entre os nomes
                }
            }
            arquivoSaida << endl; // adiciona uma nova linha ao arquivo de sa�da
        }
        arq.close();
        arquivoSaida.close(); // fecha o arquivo de sa�da ap�s a conclus�o da escrita
    } else {
        cout << "Erro ao abrir o arquivo";
    }

    return 0;
}
