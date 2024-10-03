// 2. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de cada posição do array.

#include <iostream>
using namespace std;

int main() {
    // Declaração do array de 10 floats
    float a[10];

    // Preenchendo o array suponhamos que seja prograssão aritmetica
    for (int i = 0; i < 10; i++) {
        a[i] = (i + 1) * 2; // 2,4,6,8,10 ..
    }

    // Imprimindo o array
    for (int i = 0; i < 10; i++) {
        cout << "Valor do conteudo da posição:" << i << ": " << a[i] << " Endereço de memória:  "<< &a[i] << endl; // & = endereço de memória na posição ..
    }

    return 0;
}

