// 5. Crie uma fun��o que receba por par�metro um vetor de n�meros inteiros, o tamanho do vetor e os endere�os de
// duas vari�veis inteiras (que podemos chamar de min e max). Ao passar essas vari�veis para a fun��o seu programa
// dever� analisar qual � o maior e o menor elemento do vetor e depositar esses elementos nas vari�veis do par�metro.

#include <iostream>
#include <vector>
using namespace std;

// Fun��o para encontrar o menor e o maior valor em um vetor
void MinMax(const vector<int>&vetor, int *min, int *max) { // const vector<int>&vetor, const = o conte�do do vector n�o ser�
    // modificado dentro da fun��o, fun��o s� de leitura n�o altera o valor do vetor. &vetor = refer�ncia, est� informando a
    // fun��o para n�o fazer uma c�pia, mas sim trabalhar diretamente com a variavel vetor original.


    // Inicializamos min e max com o primeiro elemento do vetor
    *min = vetor[0]; // inicia com o primeiro termo digitado
    *max = vetor[0]; // inicia com o primeiro termo digitado

    // Percorre o vetor para encontrar o menor e o maior valor
    for (int i = 1; i < vetor.size(); i++) { // vetor.size() = retorna a quantidade de elementos que foram adcionados ao vetor
    // esse for ser� iniciado no segundo elemento digitado e terminar� assim que chegar no ultimo digitado.
        if (vetor[i] < *min) {
            *min = vetor[i];  // Atualiza o valor m�nimo
        }
        if (vetor[i] > *max) {
            *max = vetor[i];  // Atualiza o valor m�ximo
        }
    }
}

int main() {
    vector<int>numeros; // vector que ir� receber valores inteiros, inicialmente vazio.
     int numero, min, max;
     cout << "Digite os elementos do vetor " << endl;
     cout << "Para fechar o vetor digite -1" << endl;
     // Para adicionar cada termo digitado ao vetor, faremos uma while.


     while (true) { // enquanto a condi��o for verdadeira, ser� obedecido o comando
            cin >> numero; // o valor digitado pelo usu�rio ser� armazenado em numero, enquanto
            if (numero == -1){
                break;}
            numeros.push_back(numero); // O valor que foi armazenado na vari�vel numero, ser� adicionado a fun��o numeros.
            // a fun��o push.back deve ser adicionada apos interromper o looping do while, caso n�o ela ir� armazenar o valor -1
            // condi��o para interromper o loomping.
     }
    if (!numeros.empty()){ // empty retorna um valor booleano V ou F, () significa vazio. ! nega��o. Logo, se o vetor numeros N�O
    // estiver vazio, ir� chamar a fun��o MinMax.
    MinMax (numeros,&min, &max); // a fun��o MinMax ir� acessar o vector numeros e o valor armazenado nos endere�os de mem�ria
    // min e max, por esta raz�o est�o antecedidos de &.

    // Exibe os resultados
    cout << "Menor valor: " << min << endl;
    cout << "Maior valor: " << max << endl;
    cout << "Quantidade de elementos: " << numeros.size() << endl; // numeros.size() retorna a quantidade de elementos que foram
    // adicionados ao vector.
    }else{
    cout << "Alimente o vetor, para que seja possivel realizar os c�lculos" << endl;
    }

    return 0;
}
// Calcula o n�mero de elementos no vetor
    //int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    // O operador sizeof(vetor) retorna o n�mero de bytes ocupados pelo array 'vetor'.
    // O operador sizeof(vetor[0]) retorna o n�mero de bytes do primeiro elemento do array (um int, que tem 4 bytes).
    // A divis�o sizeof(vetor) / sizeof(vetor[0]) d� o n�mero total de elementos no array.

