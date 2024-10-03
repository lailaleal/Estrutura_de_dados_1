//4. Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio R. A area da superfície e o volume são dados,
//respectivamente, por:   A = 4 * p * R^2         V = 4/3 * p * R^3

#include <iostream>
#include <cmath>  // Usar função de matemática pi.
using namespace std;

// Função para calcular a área da superfície e o volume de uma esfera
void Esfera(double R, double &area, double &volume) { // &area local onde irá receber o resultado, &volume local onde irá receber o resultado
    // Fórmula da área da superfície: A = 4 * pi * R^2
    area = 4 * M_PI * pow(R,2);

    // Fórmula do volume: V = (4/3) * pi * R^3
    volume = (4.0 / 3.0) * M_PI * pow(R,3);
}

int main() {
    double raio, area, volume;

    // Entrada do raio da esfera
    cout << "Digite o raio da esfera: ";
    cin >> raio;

    // Chama a função para calcular a área e o volume
    Esfera(raio, area, volume);

    // Exibir os resultados
    cout << "Área da superfície da esfera: " << area <<" m²" << endl;
    cout << "Volume da esfera: " << volume <<" m³" << endl;

    return 0;
}
