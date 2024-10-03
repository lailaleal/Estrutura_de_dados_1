// 5. Crie uma função que receba por parâmetro um vetor de números inteiros, o tamanho do vetor e os endereços de
// duas variáveis inteiras (que podemos chamar de min e max). Ao passar essas variáveis para a função seu programa
// deverá analisar qual é o maior e o menor elemento do vetor e depositar esses elementos nas variáveis do parâmetro.

#include <iostream>
#include <vector>
using namespace std;

// Função para encontrar o menor e o maior valor em um vetor
void MinMax(const vector<int>&vetor, int *min, int *max) { // const vector<int>&vetor, const = o conteúdo do vector não será
    // modificado dentro da função, função só de leitura não altera o valor do vetor. &vetor = referência, está informando a
    // função para não fazer uma cópia, mas sim trabalhar diretamente com a variavel vetor original.


    // Inicializamos min e max com o primeiro elemento do vetor
    *min = vetor[0]; // inicia com o primeiro termo digitado
    *max = vetor[0]; // inicia com o primeiro termo digitado

    // Percorre o vetor para encontrar o menor e o maior valor
    for (int i = 1; i < vetor.size(); i++) { // vetor.size() = retorna a quantidade de elementos que foram adcionados ao vetor
    // esse for será iniciado no segundo elemento digitado e terminará assim que chegar no ultimo digitado.
        if (vetor[i] < *min) {
            *min = vetor[i];  // Atualiza o valor mínimo
        }
        if (vetor[i] > *max) {
            *max = vetor[i];  // Atualiza o valor máximo
        }
    }
}

int main() {
    vector<int>numeros; // vector que irá receber valores inteiros, inicialmente vazio.
     int numero, min, max;
     cout << "Digite os elementos do vetor " << endl;
     cout << "Para fechar o vetor digite -1" << endl;
     // Para adicionar cada termo digitado ao vetor, faremos uma while.


     while (true) { // enquanto a condição for verdadeira, será obedecido o comando
            cin >> numero; // o valor digitado pelo usuário será armazenado em numero, enquanto
            if (numero == -1){
                break;}
            numeros.push_back(numero); // O valor que foi armazenado na variável numero, será adicionado a função numeros.
            // a função push.back deve ser adicionada apos interromper o looping do while, caso não ela irá armazenar o valor -1
            // condição para interromper o loomping.
     }
    if (!numeros.empty()){ // empty retorna um valor booleano V ou F, () significa vazio. ! negação. Logo, se o vetor numeros NÂO
    // estiver vazio, irá chamar a função MinMax.
    MinMax (numeros,&min, &max); // a função MinMax irá acessar o vector numeros e o valor armazenado nos endereços de memória
    // min e max, por esta razão estão antecedidos de &.

    // Exibe os resultados
    cout << "Menor valor: " << min << endl;
    cout << "Maior valor: " << max << endl;
    cout << "Quantidade de elementos: " << numeros.size() << endl; // numeros.size() retorna a quantidade de elementos que foram
    // adicionados ao vector.
    }else{
    cout << "Alimente o vetor, para que seja possivel realizar os cálculos" << endl;
    }

    return 0;
}
// Calcula o número de elementos no vetor
    //int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    // O operador sizeof(vetor) retorna o número de bytes ocupados pelo array 'vetor'.
    // O operador sizeof(vetor[0]) retorna o número de bytes do primeiro elemento do array (um int, que tem 4 bytes).
    // A divisão sizeof(vetor) / sizeof(vetor[0]) dá o número total de elementos no array.

