#include <iostream>  // Inclui a biblioteca padr�o de entrada e sa�da
using namespace std;  // Usa o namespace padr�o para simplificar o uso de std

// Estrutura do n� para a lista encadeada
struct Node {
    int value;    // Armazena o valor do n�
    Node* next;   // Ponteiro para o pr�ximo n�

    // Construtor padr�o (sem par�metros) que inicializa o n� com valor 0 e ponteiro nulo
    Node() {
        value = 0;
        next = NULL;
    }

    // Construtor que recebe um valor e inicializa o n� com esse valor e ponteiro nulo
    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

// Estrutura da lista encadeada
struct List {
    Node* inicio;  // Ponteiro para o primeiro n� da lista
    Node* fim;   // Ponteiro para o �ltimo n� da lista
    int c;        // Contador de elementos na lista

    // Construtor da lista, inicializa uma lista vazia
    List() {
        inicio = NULL;  // Nenhum n� no in�cio
        fim = NULL;   // Nenhum n� no final
        c = 0;         // Contador de elementos come�a em zero
    }

    // M�todo para verificar se a lista est� vazia
    bool empty() {
        return inicio == NULL;  // Retorna true se o primeiro n� for nulo (lista vazia)
    }

    // Insere um valor no in�cio da lista
    void pushInicio(int value) {
        Node *n = new Node(value);  // Cria um novo n� com o valor dado
        c++;  // Incrementa o contador de elementos
        if (empty()) {  // Caso a lista esteja vazia
            inicio = n;  // O novo n� ser� o primeiro
            fim = n;   // E tamb�m o �ltimo
            return;     // Sai do m�todo
        }
        n->next = inicio;  // O pr�ximo do novo n� aponta para o antigo primeiro
        inicio = n;        // Atualiza o primeiro para o novo n�
    }

    // Insere um valor no final da lista
    void pushFim(int value) {
        Node *n = new Node(value);  // Cria um novo n� com o valor dado
        c++;  // Incrementa o contador de elementos
        if (empty()) {  // Caso a lista esteja vazia
            inicio = n;  // O novo n� ser� o primeiro
            fim = n;   // E tamb�m o �ltimo
            return;     // Sai do m�todo
        }
        fim->next = n;  // Atualiza o pr�ximo do �ltimo n� para o novo n�
        fim = n;        // Atualiza o �ltimo n� para o novo n�
    }

    // Imprime todos os valores da lista
    void print() {
        Node* aux = inicio;  // Ponteiro auxiliar come�a no primeiro n�
        while (aux != NULL) {  // Continua at� o final da lista
            cout << aux->value << " -> ";  // Imprime o valor do n� atual
            aux = aux->next;  // Avan�a para o pr�ximo n�
        }
        cout << "NULL" << endl;  // Indica o fim da lista com NULL
    }

    // Retorna o tamanho da lista em O(1)
    int size() {
        return c;  // Retorna o contador de elementos
    }

    // Remove o primeiro elemento da lista
    void removeInicio() {
        if (empty()) return;  // Se a lista estiver vazia, n�o faz nada
        if (c == 1) {  // Se a lista tiver apenas um elemento
            delete inicio;  // Deleta o �nico n�
            inicio = NULL;  // Define o primeiro como nulo
            fim = NULL;   // Define o �ltimo como nulo
            c = 0;         // Reseta o contador
            return;
        }
        Node* toDel = inicio;  // Armazena o primeiro n� para deletar
        inicio = inicio->next;  // Atualiza o primeiro para o pr�ximo n�
        delete toDel;  // Deleta o n� antigo
        c--;  // Decrementa o contador
    }

    // Remove o �ltimo elemento da lista
    void removeFim() {
        if (empty()) return;  // Se a lista estiver vazia, n�o faz nada
        if (c == 1) {  // Se a lista tiver apenas um elemento
            delete inicio;  // Deleta o �nico n�
            inicio = NULL;  // Define o primeiro como nulo
            fim = NULL;   // Define o �ltimo como nulo
            c = 0;         // Reseta o contador
            return;
        }
        Node* toDel = fim;  // Armazena o �ltimo n� para deletar
        Node* aux = inicio;   // Ponteiro auxiliar para encontrar o pen�ltimo n�
        while (aux->next != fim) {  // Percorre at� o pen�ltimo n�
            aux = aux->next;
        } // Caso o proximo seja igual ao fim
        fim = aux;  // Atualiza o �ltimo n� para o pen�ltimo
        fim->next = NULL;  // Define o pr�ximo do �ltimo como NULL
        delete toDel;  // Deleta o n� antigo
        c--;  // Decrementa o contador
    }

    // Insere um valor em uma posi��o espec�fica da lista // value = valor digitado, pos = posi��o na lista
    void insert(int value, int pos) {
        if (pos <= 0) {  // Caso a posi��o seja menor ou igual a 0
            pushInicio(value);  // Insere no in�cio
            return;
        }
        if (pos >= c) {  // Caso a posi��o seja maior ou igual ao tamanho da lista
            pushFim(value);  // Insere no final
            return;
        }
        Node* aux = inicio;  // Ponteiro auxiliar para encontrar a posi��o desejada
        for (int i = 0; i < pos - 1; i++) {  // Avan�a at� a posi��o anterior, come�a na posi��o 0 e vai at� chegar na posi��o anterior
            // na posi��o anterior, pq o aux-> next vai apontar para a posi��o onde iremos inserir.
            aux = aux->next; // Encontrou a posi��o anterior a posi��o desejada.
        }
        Node* n = new Node(value);  // Cria um novo n� com o valor dado
        n->next = aux->next;  // O pr�ximo do novo n� � o pr�ximo do auxiliar
        aux->next = n;  // Insere o novo n� na posi��o
        c++;  // Incrementa o contador
    }

    // Remove um n� que possui o valor especificado
    void remove(int value) {
        if (empty()) return;  // Primeiro, verifica se a lista est� vazia usando a fun��o empty(). Se estiver, a fun��o termina imediatamente,
        //pois n�o h� nada para remover.

        Node *aux = inicio;  // Define um ponteiro aux para o in�cio da lista. Esse ponteiro � usado para percorrer cada n� da lista
        Node *prev = NULL;  // Declara prev, que aponta para o n� anterior ao aux. Inicialmente, � NULL porque aux come�a no primeiro n�,
        // e n�o h� nenhum n� antes dele.
        for (int i = 0; i < c; i++) {  // Inicia um loop para percorrer toda a lista. O loop usa c como limite, que � o contador do n�mero de n�s na lista.
            if (aux->value == value) {  // Verifica se o valor do n� atual (aux->value) � igual ao valor que queremos remover.
                if (prev == NULL) {  // Caso prev seja NULL, significa que o n� atual (aux) � o primeiro da lista.
                   removeInicio();  // Se for o primeiro, chama a fun��o removeInicio() para remov�-lo de maneira adequada.
                   // Se o n� a ser removido estiver no meio ou final da lista.
                } else { // Caso contr�rio, estamos em um n� interno ou final, e precisamos ajust�-lo manualmente
                    prev->next = aux->next;  // Atualiza o ponteiro next do n� anterior (prev) para apontar para o pr�ximo n� de aux, "pulando" o n� atual.
                    delete aux;  // Remove o n� atual da mem�ria para evitar vazamentos.
                    c--;  // Decrementa o contador c para refletir a remo��o.
                    aux = prev;  // Define aux novamente para o n� anterior (prev) e continua o loop
                    // Ao deletar aux, o c�digo define aux como prev para garantir que o pr�ximo ciclo do for ocorra sem pular nenhum n� da lista.
                    // Se aux fosse simplesmente movido para aux->next logo ap�s a remo��o, o pr�ximo n� ap�s o que foi deletado seria ignorado no loop
                }
            }
            prev = aux;  // Define prev para o n� atual (aux), para que ele se torne o anterior no pr�ximo ciclo.
            // No final de cada itera��o, prev � atualizado para o valor de aux. Isso move prev para "uma posi��o atr�s" de aux, de modo que no
            // pr�ximo ciclo prev sempre ser� o n� anterior ao atual aux. Objetivo: Manter prev sincronizado com aux, para que prev aponte para o
            // n� correto ao pular um n� no caso de remo��o.
            aux = aux->next;  // Avan�a aux para o pr�ximo n� da lista, continuando a busca.
            // aux = aux->next; // Avan�a aux para o pr�ximo n� da lista, continuando a busca.
    // Esse comando final move aux para o pr�ximo n� da lista para que o loop possa continuar verificando cada n�.
    // Objetivo: Essa linha permite que o for percorra a lista de maneira sequencial.
        }
    }
};

int main() {
    List l;  // Cria uma nova lista

    l.pushInicio(10);  // Insere 10 no in�cio da lista
    l.pushInicio(3);   // Insere 3 no in�cio da lista
    l.pushFim(5);    // Insere 5 no final da lista

    l.removeFim();      // Remove o �ltimo elemento da lista

    l.print();  // Imprime todos os elementos da lista

    return 0;  // Fim do programa
}

