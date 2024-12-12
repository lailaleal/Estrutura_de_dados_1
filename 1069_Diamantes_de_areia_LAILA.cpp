// Como não tem valor específico do tamanho da pilha iremos utilizar a pilha dinamica
// A variável que queremos localizar é a <> é uma string
// colocar a biblioteca e trocar o value por char
#include <iostream>  // Inclui a biblioteca padrão de entrada e saída
#include <cstring>
using namespace std;  // Usa o namespace padrão para simplificar o uso de std

struct Node {

    char value; // valor armazenado no nó
    Node* next;// ponterio para o proximo da lista

    // construtor padrão com valor 0
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
        t = NULL; // pilha começa fazia
    }

    bool empty() { // O(1) // verificando se a pilha começa vazia
        return t == NULL;
    }

    void push(char value) { // O(1)  // adiciona um elemento no topo da pilha
        Node* n = new Node(value); // cria um nó com o valor dado
        if (empty()) {  // se a pilha estiver vazia
            t = n; // o topo será o novo valor digitado
            return;
        }
        n->next = t;// o next do novo nó aponta para o antigo topo
        t = n; // topo agora é o novo nó
    }
    //  REMOVE O TOPO DA PILHA
    void pop() { // O(1)
        if (empty()) { // se a pilha estiver vazia
            return;
        }
        if (t->next == NULL) { // se houver 1 unico elemento
            delete(t); // deleta o topo
            t = NULL; // o topo agora é null
            return;
        }
        Node* toDel = t;// armazena o topo atual na variável doDel
        t = t->next; // o tpo agora será o proximo elemento
        delete(toDel); // deleta a variavel q está no toDel
    }
    // RETORNA O VALOR DO TOPO DA PILHA
    int top() { // O(1) // se a pilha estiver vazia
        if (empty()) {
            cout << "Empty\n";
            return -1; // retorna -1 , pois da lista encadeada se inicia com a posição 0, -1 retorna sem posição
        }
        return t->value; // retorna o valor do topo.
    } // 2
      // <..><.<..>>  3   tam= 10                                 PILHA [<<<<<<<]
  };  // <<<..<......<<<<....> 1    tam= 20                       C =1

    int main(){
    char tmp[1001]; // formula que será digitada
    int n; //   QUANDO VAI RECEBER UM NUMERO DE VEZES QUE SERÁ DIGITADO
    cin >> n;
        while (n--){ // VAI DECREMENAR A QUANTIDADE QUE O USUÁRIO DIGITOU QUE IRIA ESCREVER AS FORMULAS
                cin >> tmp; // recebe a formula
                stack s; // cria a pilha
                int c = 0; // contador inicializa com 0
                    for(int i = 0; i < strlen(tmp); i++){   // menor por que se for maior não vai rodar o i sempre vai ser menor q o tamanho do vetor
                            if ( tmp[i] == '<'){
                                s.push('<');
                                continue;
                                // COLOCA O INCREMENTO QUANDO FECHAR
                                }if(tmp[i] == '>'){ // se não
                                    if(!s.empty()){
                                        c++;
                                        s.pop(); // apaga o ultimo termo da pilha
                                    }
                                }

                            }cout << c ;



        } return 0;
    }
