// O codigo empilha as letras F A C E, o usuário irá inserir um conjunto de letras.
// ex: FACE   => ENFILEIRA AO CONTRARIO
//     AFCE, não bate, o programa deve emplilhar as letras digitadas na lista de comparação
// F A C E E C F A   PROX: ACEF  => EMPILHA NA ORDEM CORRETA
    //     F E C A  PROX;  F E C A
// F A C E A F C E A C E F
              //   A C E F    CERTO C = 1 PROX:
// F A C E A F C E   PROX: A F C E
// NÃO CONCORDO COM a logica por enquanto
// POR SER POSIÇÕES FIXAS, É MELHOR TRABALHAR COM A LISTA ESTATICA
// SE A LISTA ESTIVER FAZIA NO ÍNICIO DE CADA RODADA DEVEMOS COLOCAR AS QUATRO LETRAS POR PARAMETRO
// PEGAR A IMPLEMENTAÇÃO DA PILHA ESTATICA

//  ESTATICA POSSIBILITA PODER OLHAR AS POSIÇÕES ANTERIORES
#include <iostream>  // Inclui a biblioteca padrão de entrada e saída
using namespace std;  // Usa o namespace padrão para simplificar o uso de std
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

    bool empty() { // O(1)    Verificando se pilha está vazia
    return t == 0;
    }

      bool full() { // O(1) // Verificando se a pilha está cheia
        return t >= N;
    }

    void push(char value) { // O(1) INSERIR ELEMENTO A PILHA ESTATICA
        if (full()) { // se está cheia
            cout << "Full\n"; // está cheia
            return;
        }
        v[t++] = value; // vetor na posição t é igual ao valor digitado e t++ ando com o t
    }

    void pop() { // O(1) // REMOVER
        if (empty()) { // se está vazia
            cout << "Empty\n"; // está fazia
            return;
        }
        t--; // remova o primeiro prato da pilha
    }

    int top() { // O(1) O topo da pilha é o último valor inserido.
        if (empty()) { // Verifica se a pilha está vazia
            cout << "Empty\n"; // Exibe uma mensagem de erro
            return -1; // Retorna -1 para indicar que a pilha está vazia, a posição 1, normalmente é a representado como 0, então -1 indica que não tem nada
        }
        return v[t - 1]; // Retorna o topo da pilha (último elemento inserido), se a pilha possui 5 pratos, t= qnt de pratos, mas v[] insere a posição, que se inicia em 0.
        // t é o ultimo elemento inserido e topo da pilha, logo t-1.
    }
    void start () { // Se a pilha estiver vazia ela deve adicionar  as letras F A C E
        if (empty()){
            push('F');
            push('A');
            push('C');
            push('E');

        }
    }
    bool match( char c1, char c2,char c3,char c4){ // lembrando sempre contamos a proxima posição como t[n-1]
        // t -1, pois o primeiro a sair é o ultimo a ser colocado (pilha de pratos)
        return (c1 == v[t-1] && c2 == v[t-2] && c3 == v[t-3] && c4 == v[t-4]);
        // o valor digitado é igual a primeira posição da pilha, o segundo com o segundo da pilha assim por diante

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
        if (s.match(c1, c2, c3, c4)){ // Se o valor digitado é igual a primeira posição da pilha, o segundo com o segundo da pilha assim por diante
            c++; // conto um resultado e apago os quatro primeiros
            s.pop();
            s.pop();
            s.pop();
            s.pop();
        }else{ // se não coloco os quatro elementos dentro da fila
            s.push(c1);
            s.push(c2);
            s.push(c3);
            s.push(c4);
        }

    }cout << c << endl; // presentetion error normalmente e falta de um endl
    return 0;
}
