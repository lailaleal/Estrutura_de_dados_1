//1. Escreva um programa que contenha duas variaveis inteiras. Leia essas vari�veis do teclado. Em seguida, compare seus endere�os e exiba
// o conteudo do maior endere�o.

#include <iostream>
using namespace std;

int main() {
    int a, b;


    cout << "Digite o primeiro valor inteiro: ";
    cin >> a; // ir� armazenar o valor digitado em algum endere�o de mem�ria
    cout << "Digite o segundo valor inteiro: ";
    cin >> b; // ir� armazenar o valor em algum endere�o de mem�ria

    cout << "endereco de a: " << *a << "   endereco de b: " << *b << endl;

    if (&a > &b) { // & se refere ao endere�o de mem�ria que foi armazenado a vari�vel  - endere�o de a > endere�o de b -
        cout << "O maior endere�o � o de 'a' e seu conte�do �: " << a << "   e seu endere�o �: " << *a << endl;
    } else {
        cout << "O maior endere�o � o de 'b' e seu conte�do �: " << b << "   e seu endere�o �: " << *b << endl;
    }

    return 0;
}
