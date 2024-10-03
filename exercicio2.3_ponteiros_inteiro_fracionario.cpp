// 3. Escreva uma fun��o que dado um n�mero real passado como par�metro, retorne a parte inteira e a parte fracion�ria deste n�mero.
// Escreva um programa que chama esta fun��o.



// OBS: O codigo so funciona se o usu�rio digitar o numero separando inteiro de fracion�rio com ".", ponto. Se utilizar virgula, apresentar� erro.

#include <iostream>
using namespace std;

// Fun��o para separar a parte inteira e a parte fracion�ria sem usar fun��es extras
void Separar (double numero, int &parteInteira, double &parteFracionaria) { // & referencia, a fun��o n�o far� copia das variaveis parteInteira e
    // parteFracionaria, ao modificar, os valores ser�o adicionados no endere�o de mem�ria destas var�veis.

    // 1. Separando a parte inteira
    if (numero >= 0) {
        parteInteira = static_cast<int>(numero);  // static_cast<int>(numero), a vari�vel numero foi atribuida como tipo double, esta fun��o modifica a
        // variavel para inteiro, armazenando na vari�vel parteInteira so a parte inteira do n�mero digitado.
        parteFracionaria = numero - parteInteira;
    } else {
        parteInteira = static_cast<int>(numero);  // Parte inteira para n�meros negativos (truncamento para baixo)
        parteFracionaria = (numero - parteInteira) * -1;
        }
    }

int main() {
    double num;
    int parteInteira;
    double parteFracionaria;

    // Entrada do n�mero real
    cout << "Digite um n�mero real: ";
    cin >> num;

    // Chama a fun��o Separar
    Separar (num, parteInteira, parteFracionaria);

    // Exibe os resultados
    cout << "Parte inteira: " << parteInteira << endl;
    cout << "Parte fracion�ria: " << parteFracionaria << endl;

    return 0;
}

