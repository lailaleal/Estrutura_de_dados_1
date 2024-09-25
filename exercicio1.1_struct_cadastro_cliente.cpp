#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Strcut Cliente

struct Cliente
{
    string nome;
    int dianasc, mesnasc, anonasc;
    int idade;
    char sexo;
};

// Função para calcular a data atual

void Data_atual ( int&diaatual, int&mesatual, int&anoatual)  //  & = permite que a função modifique o valor destas variáveis
{
    time_t atual = time(0); // retorna tempo atual em segundos
    tm tempo = *localtime(&atual); // converte o tempo em segundos para tempo atual
    diaatual = tempo.tm_mday;
    mesatual = tempo.tm_mon + 1; // o valor vai de 0 a 11, como os meses são representados de 1 a 12, somamos 1.
    anoatual = tempo.tm_year + 1900; // Armazena o numero a anos após 1990, se for 2024 irá armazenar 124, por isso somamos 1900.
}

// Função calcular idade

int Cal_idade (int dianasc,  int mesnasc, int anonasc, int diaatual, int mesatual, int anoatual)
{
    int idade = anoatual - anonasc;
    if (mesnasc > mesatual || dianasc > diaatual)
        {
        idade --;
        } return idade;
}

// Função Cadastrar Cliente
void Cadastro (Cliente &c)
{
    int diaatual, mesatual, anoatual;
    Data_atual (diaatual, mesatual, anoatual); // obtem a data atual

    cout << "Nome: " << endl;
    cin >> ws; // ignora espaços em branco
    getline(cin, c.nome); // permite espaços para nomes compostos
    cout << "Sexo (M/F): " << endl;
    cin >> c.sexo;
    cout << "Data de nascimento: (DIA/MES/ANO) " << endl;
    cin >> c.dianasc >> c.mesnasc >> c.anonasc;

    c.idade = Cal_idade (c.dianasc, c.mesnasc, c.anonasc, diaatual, mesatual, anoatual);
}

// Função Listar Clientes
void Listar(Cliente c[], int totalc)
{
      for (int i = 0; i < totalc; i++) {
        cout << "\nCliente " << i + 1 << ":" << endl;
        cout << "Nome: " << c[i].nome << endl;
        cout << "Sexo: " << c[i].sexo << endl;
        cout << "Data de nascimento: " << c[i].dianasc << "/"
             << c[i].mesnasc << "/" << c[i].anonasc << endl;
        cout << "Idade: " << c[i].idade << " anos" << endl;
    }
}

void Menu ()
{
    cout << "\n---   MENU   --- \n";
    cout << "1. Cadastrar cliente\n";
    cout << "2. Listar clientes\n";
    cout << "3. Sair\n";
}
int main()
{
    Cliente c[50]; // Máximo de 50 clientes
    int totalc = 0;
    int opcao;

do
{
    Menu();
    cout << "-----ESCOLHA UMA OPÇÃO ----" << endl;
    cin >> opcao;
    switch (opcao)
    {
         case 1:
                if (totalc < 50)
                {
                    Cadastro(c[totalc]);
                    totalc++;
                } else
                {
                    cout << "Capacidade maxima de cadrastro atingida!\n";
                }
                break;

          case 2:
                if (totalc > 0) {
                    Listar(c, totalc);
                } else {
                    cout << "Nenhum cliente cadastrado!\n";
                }
                break;
          case 3:
                cout << "ENCERRADO";
                break;

            default:
                cout << "INVALIDO \n";
    }
    } while (opcao != 3);

    return 0;
}
