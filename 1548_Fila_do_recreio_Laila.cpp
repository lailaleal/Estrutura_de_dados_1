// neste exercício, o usuário irá digitar quantas notas de alunos irá inseri, o qual o programa deverá ordená-las
// e retornar ao usuário quantas notas ele mudou de posição. O exercício deixa claro que é uma fila de recreio.
// opcoes: fila, pilha e lista. Fila = primeiro a entrar primeiro a sair, Pilha= ultimo a entrar, primeiro a sair,
// lista pode entrar e sair pelas extremidades facilmente.

#include <iostream>  // Inclui a biblioteca padrão de entrada e saída
using namespace std;  // Usa o namespace padrão para simplificar o uso de std

struct Node {
    int value;  // Armazena o valor do nó.
    Node* next; // Ponteiro para o próximo nó na fila.

    Node() {
        next = NULL; // Inicializa o ponteiro como NULL.
    }

    Node(int _value) {
        value = _value; // Define o valor do nó.
        next = NULL;    // Inicializa o ponteiro como NULL.
    }
};
struct queue {
    Node* first; // Ponteiro para o primeiro nó da fila (início).
    Node* last;  // Ponteiro para o último nó da fila (final).

    queue() {
        first = NULL; // Inicializa a fila como vazia.
        last = NULL;  // Ambos apontam para NULL.
    }
    bool empty() {
        return first == NULL; // Retorna verdadeiro se a fila estiver vazia.
    }
   // ADICIONAR UM NOVO VALOR A FILA
    void enqueue(int value) {
        Node* n = new Node(value); // Cria um novo nó com o valor fornecido.
        if (empty()) { // Se a fila está vazia:
            first = n; // O novo nó é o primeiro.
            last = n;  // O novo nó também é o último.
            return;
        }
        last->next = n; // O nó atual no final aponta para o novo nó, seu next irá conter o endereço de memoria do no criado
        last = n;       // O ultimo da lista será o no criado
    }
    // REMOVER TERMO DA FILA
        void dequeue() {
        if (empty()) return; // Se a fila está vazia, não há nada a remover.
        if (first == last) { // Se há apenas um nó na fila:
            delete(first);   // Libera a memória do nó.
            first = NULL;    // Atualiza os ponteiros para NULL.
            last = NULL;
            return;
        }
        Node* toDel = first;   // Salva o ponteiro do nó a ser removido.
        first = first->next;   // Atualiza o início para o próximo nó.
        delete(toDel);         // Libera a memória do nó removido.
    }

    // RETORNA O VALOR DO PRIMEIRO ELEMENTO DA FILA
        int front() {
        if (empty()) { // Se a fila está vazia:
            printf("Empty queue\n"); // Informa que não há elementos.
            return -1;               // Retorna um valor padrão (-1).
        }
        return first->value; // Retorna o valor do primeiro nó.
    }
};

// FUNÇÃO BUBBLE SORT = ORDENAÇÃO CRESCENTE (menor para o maior)
        void C_bubbleSort(int v[], int n){ // a estrutura recebe v[] = vetor, n = tamanho do vetor
           for(int i = 0; i < n - 1; i++){ // adicionar os termos ao vetor
                for (int j = 0; j < n - 1; j ++){
                      if(v[j] > v[j + 1]) { // Se o vetor na posição j for maior que o vetor na posição j + 1
                            int tmp = v[j];// temporário será o vetor na posição j, posição da frente
                            v[j] = v[j +1]; // REALIZANDO A TROCA DE POSIÇÕES, a posição sucessora, de menor sinal,
                            // vai para a posição da frente
                            v[j+1] = tmp; // a posição da frente vai para posição sucessora.
                      }

                }
           }
        };


// FUNÇÃO BUBBLE SORT = ORDENAÇÃO DECRESCENTE (maior para o menor)
        void D_bubbleSort(int v[], int n){ // a estrutura recebe v[] = vetor, n = tamanho do vetor
           for(int i = 0; i < n - 1; i++){ // adicionar os termos ao vetor
                for (int j = 0; j < n - 1; j ++){
                      if(v[j] < v[j + 1]) { // Se o vetor na posição j for maior que o vetor na posição j + 1
                            int tmp = v[j];// temporário será o vetor na posição j, posição da frente
                            v[j] = v[j +1]; // REALIZANDO A TROCA DE POSIÇÕES, a posição sucessora, de menor sinal,
                            // vai para a posição da frente
                            v[j+1] = tmp; // a posição da frente vai para posição sucessora.
                      }

                } // vetor original -> lista [100 80 90]
           } // vetor ordenado pelo bubbleSort [100 90 80]
        }; // 100 = 100 80 != 90 , 90!= 80
// Para cada caso de teste imprima uma linha, contendo um inteiro, indicando o número de alunos
// que NÃO precisaram trocar de lugar mesmo após a fila ser reordenada.
// portanto o programa deve avaliar quais deles são iguais, pois se são iguais não
// precisam ordenar.

int main (){
    // CASOS DE TESTE
    int n, m;// n = casos de teste, m = número de alunos e qnt de notas
    cin >> n;
    while(n--){ // casos de teste quantas filas do recreio que irei analisar
        cin >> m; // recebendo o numero de notas e alunos
        int v[m]; // vetor do tamanho da quantidade de alunos para armazenar as notas.
        queue q;// criando a fila para colocar os elementos ordenados
        for(int i=0; i < m; i++){ // para receber e guardar os elementos dentro do vetor
                cin >> v[i];// guardei dentro do vetor
                q.enqueue(v[i]);// enfileirar como inicialmente está sendo digitado dentro da fila
                // FECHA O FOR POIS SUA UTILIZADE AQ É SOMENTE ADICIONAR OS TERMOS DENTRO DA LISTA E VETOR
        }
        // ESTRUTURA DE ORDENAÇÃO BUBBLE SHORT
        // usar a função dentro do while para evitar problemas com declaração de variáveis
    D_bubbleSort(v, m);// ORDENOU O VETOR, A LISTA CONTINUA FORA DE ORDEM
    int c = 0; // contador quantas vezes que as posições da lista deve ser trocada, para ficar como o vetor ordenado?
    for (int i = 0; i < m; i++){ // rodar a fila para fazer a verificação.
    // Se a posição da fila é igual ao do vetor é sinal que não trocaram.
        if (q.front() == v[i]){
            c++;// quantos são iguais na primeira e na segunda
        }
        q.dequeue(); // para andar com as proximas posições desenfilero.
        // REMOVE O ELEMENTO QUE FOI O PRIMEIRO A ENTRAR NA ESTRUTURA
    }cout << c;
    } // EX: 100 120 30 50 (original )  120 100 50 30  C = (SOMENTE QND FOR IGUAL, POIS SIGNIFICA QUE NÃO TROCOU)
     // 120 != 100, 100 != 120, 50 != 30, 30!= 50  C = 0, POIS NENHUM DEU IGUAL


    return 0;
}





