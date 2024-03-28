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
    m.erase(remove_if(m.begin(), m.end(), ::isspace), m.end()); // remove espa�o

    string mr = m; // mensagem ao contr�rio
    reverse(mr.begin(), mr.end()); // reverte a mensagem

    if (m == mr) { // ve se � igual
        cout << "Essa mensagem � um pal�ndromo." << endl; 
    } else {
        cout << "Essa mensagem n�o � um pal�ndromo." << endl; 
    }

    return 0;
}