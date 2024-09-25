#include <iostream>
#include <string>
using namespace std;

struct Livro
    {
    string titulo;
    string autor;
    int numPaginas;
    };

// Fun��o para ler os dados de um livro
void LerLivro(Livro &l)
    {
    cout << "T�tulo: ";
    cin.ignore(); // Limpa o buffer de entrada
    getline(cin, l.titulo); // permite que a vari�vel digitada possa ter espa�o
    cout << "Autor: ";
    getline(cin, l.autor);
    cout << "N�mero de p�ginas: ";
    cin >> l.numPaginas;
    }

// Fun��o para imprimir os dados de um livro
void ImprimirLivro(const Livro &l)
    {
    cout << "T�tulo: " << l.titulo << endl;
    cout << "Autor: " << l.autor << endl;
    cout << "N�mero de p�ginas: " << l.numPaginas << endl;
    }

struct Biblioteca
    {
    Livro livros[10]; // Vetor de at� 10 livros
    int totalLivros;  // Quantidade de livros armazenados
    };

// Fun��o para adicionar um livro na biblioteca
void AdicionarLivro(Biblioteca &b)
    {
    if (b.totalLivros < 10)
        {
        LerLivro(b.livros[b.totalLivros]);
        b.totalLivros++;
        } else
        {
        cout << "A capacidade m�xima da biblioteca foi atingida." << endl;
        }
    }

// Fun��o para imprimir todos os livros da biblioteca
void ImprimirBiblioteca(const Biblioteca &b)
    {
    if (b.totalLivros == 0)
        {
        cout << "A biblioteca n�o cont�m nenhum livro cadastrado." << endl;
        } else
        {
        for (int i = 0; i < b.totalLivros; i++)
        {
            cout << "\nLivro " << i + 1 << ":" << endl;
            ImprimirLivro(b.livros[i]);
        }
        }
    }

// Fun��o para imprimir o livro com o maior n�mero de p�ginas
void ImprimirMaiorLivro(const Biblioteca &b)
    {
    if (b.totalLivros == 0)
        {
        cout << "A biblioteca n�o cont�m nenhum livro cadastrado." << endl;
        return;
        }

    int iMaior = 0;

    for (int i = 1; i < b.totalLivros; i++)
        {
        if (b.livros[i].numPaginas > b.livros[iMaior].numPaginas)
        {
            iMaior = i;
        }
        }

    cout << "\nLivro com o maior n�mero de p�ginas: " << endl;
    ImprimirLivro(b.livros[iMaior]);
    }

int main() {
    Biblioteca b;
    b.totalLivros = 0; // Inicializa a biblioteca com 0 livros
    int opcao;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Adicionar livro" << endl;
        cout << "2. Imprimir todos os livros" << endl;
        cout << "3. Imprimir livro com o maior n�mero de p�ginas" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch(opcao)
        {
            case 1:
                AdicionarLivro(b);
                break;
            case 2:
                ImprimirBiblioteca(b);
                break;
            case 3:
                ImprimirMaiorLivro(b);
                break;
            case 4:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Op��o inv�lida!" << endl;
        }
        } while (opcao != 4);

    return 0;
}
