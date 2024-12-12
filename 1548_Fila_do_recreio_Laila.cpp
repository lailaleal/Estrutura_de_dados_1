// neste exerc�cio, o usu�rio ir� digitar quantas notas de alunos ir� inseri, o qual o programa dever� orden�-las
// e retornar ao usu�rio quantas notas ele mudou de posi��o. O exerc�cio deixa claro que � uma fila de recreio.
// opcoes: fila, pilha e lista. Fila = primeiro a entrar primeiro a sair, Pilha= ultimo a entrar, primeiro a sair,
// lista pode entrar e sair pelas extremidades facilmente.

#include <iostream>  // Inclui a biblioteca padr�o de entrada e sa�da
using namespace std;  // Usa o namespace padr�o para simplificar o uso de std

struct Node {
    int value;  // Armazena o valor do n�.
    Node* next; // Ponteiro para o pr�ximo n� na fila.

    Node() {
        next = NULL; // Inicializa o ponteiro como NULL.
    }

    Node(int _value) {
        value = _value; // Define o valor do n�.
        next = NULL;    // Inicializa o ponteiro como NULL.
    }
};
struct queue {
    Node* first; // Ponteiro para o primeiro n� da fila (in�cio).
    Node* last;  // Ponteiro para o �ltimo n� da fila (final).

    queue() {
        first = NULL; // Inicializa a fila como vazia.
        last = NULL;  // Ambos apontam para NULL.
    }
    bool empty() {
        return first == NULL; // Retorna verdadeiro se a fila estiver vazia.
    }
   // ADICIONAR UM NOVO VALOR A FILA
    void enqueue(int value) {
        Node* n = new Node(value); // Cria um novo n� com o valor fornecido.
        if (empty()) { // Se a fila est� vazia:
            first = n; // O novo n� � o primeiro.
            last = n;  // O novo n� tamb�m � o �ltimo.
            return;
        }
        last->next = n; // O n� atual no final aponta para o novo n�, seu next ir� conter o endere�o de memoria do no criado
        last = n;       // O ultimo da lista ser� o no criado
    }
    // REMOVER TERMO DA FILA
        void dequeue() {
        if (empty()) return; // Se a fila est� vazia, n�o h� nada a remover.
        if (first == last) { // Se h� apenas um n� na fila:
            delete(first);   // Libera a mem�ria do n�.
            first = NULL;    // Atualiza os ponteiros para NULL.
            last = NULL;
            return;
        }
        Node* toDel = first;   // Salva o ponteiro do n� a ser removido.
        first = first->next;   // Atualiza o in�cio para o pr�ximo n�.
        delete(toDel);         // Libera a mem�ria do n� removido.
    }

    // RETORNA O VALOR DO PRIMEIRO ELEMENTO DA FILA
        int front() {
        if (empty()) { // Se a fila est� vazia:
            printf("Empty queue\n"); // Informa que n�o h� elementos.
            return -1;               // Retorna um valor padr�o (-1).
        }
        return first->value; // Retorna o valor do primeiro n�.
    }
};

// FUN��O BUBBLE SORT = ORDENA��O CRESCENTE (menor para o maior)
        void C_bubbleSort(int v[], int n){ // a estrutura recebe v[] = vetor, n = tamanho do vetor
           for(int i = 0; i < n - 1; i++){ // adicionar os termos ao vetor
                for (int j = 0; j < n - 1; j ++){
                      if(v[j] > v[j + 1]) { // Se o vetor na posi��o j for maior que o vetor na posi��o j + 1
                            int tmp = v[j];// tempor�rio ser� o vetor na posi��o j, posi��o da frente
                            v[j] = v[j +1]; // REALIZANDO A TROCA DE POSI��ES, a posi��o sucessora, de menor sinal,
                            // vai para a posi��o da frente
                            v[j+1] = tmp; // a posi��o da frente vai para posi��o sucessora.
                      }

                }
           }
        };


// FUN��O BUBBLE SORT = ORDENA��O DECRESCENTE (maior para o menor)
        void D_bubbleSort(int v[], int n){ // a estrutura recebe v[] = vetor, n = tamanho do vetor
           for(int i = 0; i < n - 1; i++){ // adicionar os termos ao vetor
                for (int j = 0; j < n - 1; j ++){
                      if(v[j] < v[j + 1]) { // Se o vetor na posi��o j for maior que o vetor na posi��o j + 1
                            int tmp = v[j];// tempor�rio ser� o vetor na posi��o j, posi��o da frente
                            v[j] = v[j +1]; // REALIZANDO A TROCA DE POSI��ES, a posi��o sucessora, de menor sinal,
                            // vai para a posi��o da frente
                            v[j+1] = tmp; // a posi��o da frente vai para posi��o sucessora.
                      }

                } // vetor original -> lista [100 80 90]
           } // vetor ordenado pelo bubbleSort [100 90 80]
        }; // 100 = 100 80 != 90 , 90!= 80
// Para cada caso de teste imprima uma linha, contendo um inteiro, indicando o n�mero de alunos
// que N�O precisaram trocar de lugar mesmo ap�s a fila ser reordenada.
// portanto o programa deve avaliar quais deles s�o iguais, pois se s�o iguais n�o
// precisam ordenar.

int main (){
    // CASOS DE TESTE
    int n, m;// n = casos de teste, m = n�mero de alunos e qnt de notas
    cin >> n;
    while(n--){ // casos de teste quantas filas do recreio que irei analisar
        cin >> m; // recebendo o numero de notas e alunos
        int v[m]; // vetor do tamanho da quantidade de alunos para armazenar as notas.
        queue q;// criando a fila para colocar os elementos ordenados
        for(int i=0; i < m; i++){ // para receber e guardar os elementos dentro do vetor
                cin >> v[i];// guardei dentro do vetor
                q.enqueue(v[i]);// enfileirar como inicialmente est� sendo digitado dentro da fila
                // FECHA O FOR POIS SUA UTILIZADE AQ � SOMENTE ADICIONAR OS TERMOS DENTRO DA LISTA E VETOR
        }
        // ESTRUTURA DE ORDENA��O BUBBLE SHORT
        // usar a fun��o dentro do while para evitar problemas com declara��o de vari�veis
    D_bubbleSort(v, m);// ORDENOU O VETOR, A LISTA CONTINUA FORA DE ORDEM
    int c = 0; // contador quantas vezes que as posi��es da lista deve ser trocada, para ficar como o vetor ordenado?
    for (int i = 0; i < m; i++){ // rodar a fila para fazer a verifica��o.
    // Se a posi��o da fila � igual ao do vetor � sinal que n�o trocaram.
        if (q.front() == v[i]){
            c++;// quantos s�o iguais na primeira e na segunda
        }
        q.dequeue(); // para andar com as proximas posi��es desenfilero.
        // REMOVE O ELEMENTO QUE FOI O PRIMEIRO A ENTRAR NA ESTRUTURA
    }cout << c;
    } // EX: 100 120 30 50 (original )  120 100 50 30  C = (SOMENTE QND FOR IGUAL, POIS SIGNIFICA QUE N�O TROCOU)
     // 120 != 100, 100 != 120, 50 != 30, 30!= 50  C = 0, POIS NENHUM DEU IGUAL


    return 0;
}





