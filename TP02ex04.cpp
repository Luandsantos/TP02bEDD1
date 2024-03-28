#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");
    ifstream arq("lista2.txt");

    string nome;
    string nomes[100];
    int i = 0;

    ofstream arquivoSaida("saida2.txt"); 

    if (arq.is_open() && arquivoSaida.is_open()) {
        string linha;
        while (getline(arq, linha)) {
            istringstream iss(linha);
            i = 0; // reinicialize i para cada linha
            while (getline(iss, nome, ' ')) {
                nomes[i] = nome; // armazene cada palavra em nomes
                i++;
            }

            for (int j = 0; j < i - 1; ++j) {
                nomes[j][0] = toupper(nomes[j][0]); // transforma a primeira letra dos sobrenomes em mai�scula
            }

            arquivoSaida << nomes[i - 1] << ", "; // escreve o �ltimo sobrenome no arquivo de sa�da

            arquivoSaida << nomes[0]; // escreve o primeiro nome sem abrevia��o

            for (int k = 1; k < i - 1; ++k) {
                arquivoSaida << " " << nomes[k][0] << "."; // adiciona os nomes abreviados (exceto o �ltimo) seguidos de um ponto
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
