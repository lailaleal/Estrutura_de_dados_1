//4. Implemente uma fun��o que calcule a �rea da superf�cie e o volume de uma esfera de raio R. A area da superf�cie e o volume s�o dados,
//respectivamente, por:   A = 4 * p * R^2         V = 4/3 * p * R^3

#include <iostream>
#include <cmath>  // Usar fun��o de matem�tica pi.
using namespace std;

// Fun��o para calcular a �rea da superf�cie e o volume de uma esfera
void Esfera(double R, double &area, double &volume) { // &area local onde ir� receber o resultado, &volume local onde ir� receber o resultado
    // F�rmula da �rea da superf�cie: A = 4 * pi * R^2
    area = 4 * M_PI * pow(R,2);

    // F�rmula do volume: V = (4/3) * pi * R^3
    volume = (4.0 / 3.0) * M_PI * pow(R,3);
}

int main() {
    double raio, area, volume;

    // Entrada do raio da esfera
    cout << "Digite o raio da esfera: ";
    cin >> raio;

    // Chama a fun��o para calcular a �rea e o volume
    Esfera(raio, area, volume);

    // Exibir os resultados
    cout << "�rea da superf�cie da esfera: " << area <<" m�" << endl;
    cout << "Volume da esfera: " << volume <<" m�" << endl;

    return 0;
}
