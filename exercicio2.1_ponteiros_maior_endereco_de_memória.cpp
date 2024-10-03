//1. Escreva um programa que contenha duas variaveis inteiras. Leia essas variáveis do teclado. Em seguida, compare seus endereços e exiba
// o conteudo do maior endereço.

#include <iostream>
using namespace std;

int main() {
    int a, b;


    cout << "Digite o primeiro valor inteiro: ";
    cin >> a; // irá armazenar o valor digitado em algum endereço de memória
    cout << "Digite o segundo valor inteiro: ";
    cin >> b; // irá armazenar o valor em algum endereço de memória

    cout << "endereco de a: " << *a << "   endereco de b: " << *b << endl;

    if (&a > &b) { // & se refere ao endereço de memória que foi armazenado a variável  - endereço de a > endereço de b -
        cout << "O maior endereço é o de 'a' e seu conteúdo é: " << a << "   e seu endereço é: " << *a << endl;
    } else {
        cout << "O maior endereço é o de 'b' e seu conteúdo é: " << b << "   e seu endereço é: " << *b << endl;
    }

    return 0;
}
