// 2. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endere�o de cada posi��o do array.

#include <iostream>
using namespace std;

int main() {
    // Declara��o do array de 10 floats
    float a[10];

    // Preenchendo o array suponhamos que seja prograss�o aritmetica
    for (int i = 0; i < 10; i++) {
        a[i] = (i + 1) * 2; // 2,4,6,8,10 ..
    }

    // Imprimindo o array
    for (int i = 0; i < 10; i++) {
        cout << "Valor do conteudo da posi��o:" << i << ": " << a[i] << " Endere�o de mem�ria:  "<< &a[i] << endl; // & = endere�o de mem�ria na posi��o ..
    }

    return 0;
}

