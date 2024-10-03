// 3. Escreva uma função que dado um número real passado como parâmetro, retorne a parte inteira e a parte fracionária deste número.
// Escreva um programa que chama esta função.



// OBS: O codigo so funciona se o usuário digitar o numero separando inteiro de fracionário com ".", ponto. Se utilizar virgula, apresentará erro.

#include <iostream>
using namespace std;

// Função para separar a parte inteira e a parte fracionária sem usar funções extras
void Separar (double numero, int &parteInteira, double &parteFracionaria) { // & referencia, a função não fará copia das variaveis parteInteira e
    // parteFracionaria, ao modificar, os valores serão adicionados no endereço de memória destas varáveis.

    // Separando a parte inteira

        parteInteira = static_cast<int>(numero);  // static_cast<int>(numero), a variável numero foi atribuida como tipo double, esta função modifica a
        // variavel para inteiro, armazenando na variável parteInteira so a parte inteira do número digitado.
        parteFracionaria = numero - parteInteira;

        // Número < 0, ex: -1.123 parteInteira: -1; parteFracionaria: -0.123, pois -1 + (-0,123)= -1.123

    }

int main() {
    double num;
    int parteInteira;
    double parteFracionaria;

    // Entrada do número real
    cout << "Digite um número real: ";
    cin >> num;

    // Chama a função Separar
    Separar (num, parteInteira, parteFracionaria);

    // Exibe os resultados
    cout << "Parte inteira: " << parteInteira << endl;
    cout << "Parte fracionária: " << parteFracionaria << endl;

    return 0;
}

