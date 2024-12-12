// O codigo empilha as letras F A C E, o usu�rio ir� inserir um conjunto de letras.
// ex: FACE   => ENFILEIRA AO CONTRARIO
//     AFCE, n�o bate, o programa deve emplilhar as letras digitadas na lista de compara��o
// F A C E E C F A   PROX: ACEF  => EMPILHA NA ORDEM CORRETA
    //     F E C A  PROX;  F E C A
// F A C E A F C E A C E F
              //   A C E F    CERTO C = 1 PROX:
// F A C E A F C E   PROX: A F C E
// N�O CONCORDO COM a logica por enquanto
// POR SER POSI��ES FIXAS, � MELHOR TRABALHAR COM A LISTA ESTATICA
// SE A LISTA ESTIVER FAZIA NO �NICIO DE CADA RODADA DEVEMOS COLOCAR AS QUATRO LETRAS POR PARAMETRO
// PEGAR A IMPLEMENTA��O DA PILHA ESTATICA

//  ESTATICA POSSIBILITA PODER OLHAR AS POSI��ES ANTERIORES
#include <iostream>  // Inclui a biblioteca padr�o de entrada e sa�da
using namespace std;  // Usa o namespace padr�o para simplificar o uso de std
#define N 500 // pilha ESTATICA TAMANHO DEFINIDO
struct Value {
   char symbol;
   int line;

};
struct stack {
   char v[N];
   int t; // ponteiro

   stack(){
        t = 0;
   }

    bool empty() { // O(1)    Verificando se pilha est� vazia
    return t == 0;
    }

      bool full() { // O(1) // Verificando se a pilha est� cheia
        return t >= N;
    }

    void push(char value) { // O(1) INSERIR ELEMENTO A PILHA ESTATICA
        if (full()) { // se est� cheia
            cout << "Full\n"; // est� cheia
            return;
        }
        v[t++] = value; // vetor na posi��o t � igual ao valor digitado e t++ ando com o t
    }

    void pop() { // O(1) // REMOVER
        if (empty()) { // se est� vazia
            cout << "Empty\n"; // est� fazia
            return;
        }
        t--; // remova o primeiro prato da pilha
    }

    int top() { // O(1) O topo da pilha � o �ltimo valor inserido.
        if (empty()) { // Verifica se a pilha est� vazia
            cout << "Empty\n"; // Exibe uma mensagem de erro
            return -1; // Retorna -1 para indicar que a pilha est� vazia, a posi��o 1, normalmente � a representado como 0, ent�o -1 indica que n�o tem nada
        }
        return v[t - 1]; // Retorna o topo da pilha (�ltimo elemento inserido), se a pilha possui 5 pratos, t= qnt de pratos, mas v[] insere a posi��o, que se inicia em 0.
        // t � o ultimo elemento inserido e topo da pilha, logo t-1.
    }
    void start () { // Se a pilha estiver vazia ela deve adicionar  as letras F A C E
        if (empty()){
            push('F');
            push('A');
            push('C');
            push('E');

        }
    }
    bool match( char c1, char c2,char c3,char c4){ // lembrando sempre contamos a proxima posi��o como t[n-1]
        // t -1, pois o primeiro a sair � o ultimo a ser colocado (pilha de pratos)
        return (c1 == v[t-1] && c2 == v[t-2] && c3 == v[t-3] && c4 == v[t-4]);
        // o valor digitado � igual a primeira posi��o da pilha, o segundo com o segundo da pilha assim por diante

    }
};

int main(){
    stack s;
    int n, c = 0;
    cin >> n;

    while (n--){
        s.start();// se estiver vazia faz a leitura dos FACE.
        char c1, c2, c3, c4;
        cin >> c1 >> c2 >> c3 >> c4;
        if (s.match(c1, c2, c3, c4)){ // Se o valor digitado � igual a primeira posi��o da pilha, o segundo com o segundo da pilha assim por diante
            c++; // conto um resultado e apago os quatro primeiros
            s.pop();
            s.pop();
            s.pop();
            s.pop();
        }else{ // se n�o coloco os quatro elementos dentro da fila
            s.push(c1);
            s.push(c2);
            s.push(c3);
            s.push(c4);
        }

    }cout << c << endl; // presentetion error normalmente e falta de um endl
    return 0;
}
