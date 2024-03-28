#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    string m; // mensagem

    cout << "Digite a mensagem: ";
    getline(cin, m); // pega toda a linha
    m.erase(remove_if(m.begin(), m.end(), ::isspace), m.end()); // remove espaço

    string mr = m; // mensagem ao contrário
    reverse(mr.begin(), mr.end()); // reverte a mensagem

    if (m == mr) { // ve se é igual
        cout << "Essa mensagem é um palíndromo." << endl; 
    } else {
        cout << "Essa mensagem não é um palíndromo." << endl; 
    }

    return 0;
}