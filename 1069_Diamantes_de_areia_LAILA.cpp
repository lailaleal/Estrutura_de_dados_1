// Como n�o tem valor espec�fico do tamanho da pilha iremos utilizar a pilha dinamica
// A vari�vel que queremos localizar � a <> � uma string
// colocar a biblioteca e trocar o value por char
#include <iostream>  // Inclui a biblioteca padr�o de entrada e sa�da
#include <cstring>
using namespace std;  // Usa o namespace padr�o para simplificar o uso de std

struct Node {

    char value; // valor armazenado no n�
    Node* next;// ponterio para o proximo da lista

    // construtor padr�o com valor 0
    Node() {
        value = 0;
        next = NULL;
    }
    // construtor com valor fornecido pelo usuario
    Node(char _value) {
        value = _value;
        next = NULL;
    }
};

struct stack {

    Node* t; // ponteiro para o ultimo termo da lista e topo da pilha

    stack() {
        t = NULL; // pilha come�a fazia
    }

    bool empty() { // O(1) // verificando se a pilha come�a vazia
        return t == NULL;
    }

    void push(char value) { // O(1)  // adiciona um elemento no topo da pilha
        Node* n = new Node(value); // cria um n� com o valor dado
        if (empty()) {  // se a pilha estiver vazia
            t = n; // o topo ser� o novo valor digitado
            return;
        }
        n->next = t;// o next do novo n� aponta para o antigo topo
        t = n; // topo agora � o novo n�
    }
    //  REMOVE O TOPO DA PILHA
    void pop() { // O(1)
        if (empty()) { // se a pilha estiver vazia
            return;
        }
        if (t->next == NULL) { // se houver 1 unico elemento
            delete(t); // deleta o topo
            t = NULL; // o topo agora � null
            return;
        }
        Node* toDel = t;// armazena o topo atual na vari�vel doDel
        t = t->next; // o tpo agora ser� o proximo elemento
        delete(toDel); // deleta a variavel q est� no toDel
    }
    // RETORNA O VALOR DO TOPO DA PILHA
    int top() { // O(1) // se a pilha estiver vazia
        if (empty()) {
            cout << "Empty\n";
            return -1; // retorna -1 , pois da lista encadeada se inicia com a posi��o 0, -1 retorna sem posi��o
        }
        return t->value; // retorna o valor do topo.
    } // 2
      // <..><.<..>>  3   tam= 10                                 PILHA [<<<<<<<]
  };  // <<<..<......<<<<....> 1    tam= 20                       C =1

    int main(){
    char tmp[1001]; // formula que ser� digitada
    int n; //   QUANDO VAI RECEBER UM NUMERO DE VEZES QUE SER� DIGITADO
    cin >> n;
        while (n--){ // VAI DECREMENAR A QUANTIDADE QUE O USU�RIO DIGITOU QUE IRIA ESCREVER AS FORMULAS
                cin >> tmp; // recebe a formula
                stack s; // cria a pilha
                int c = 0; // contador inicializa com 0
                    for(int i = 0; i < strlen(tmp); i++){   // menor por que se for maior n�o vai rodar o i sempre vai ser menor q o tamanho do vetor
                            if ( tmp[i] == '<'){
                                s.push('<');
                                continue;
                                // COLOCA O INCREMENTO QUANDO FECHAR
                                }if(tmp[i] == '>'){ // se n�o
                                    if(!s.empty()){
                                        c++;
                                        s.pop(); // apaga o ultimo termo da pilha
                                    }
                                }

                            }cout << c ;



        } return 0;
    }
