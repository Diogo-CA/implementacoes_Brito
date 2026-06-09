#include <iostream>
#include <iomanip>
#include <cmath>     // Para usar std::abs()
#include <algorithm> // Para usar std::max()

using namespace std;

void resolverGaussSeidel() {
    double a1, b1, c1, d1;
    double a2, b2, c2, d2;
    double a3, b3, c3, d3;

    cout << "\n-=-=- Cálculo Numérico: Método de Gauss-Seidel -=-=-\n";

    cout << "--- Leitura Equação 1 (a1*X + b1*Y + c1*Z = d1) ---\n";
    cout << "a1: "; cin >> a1;
    cout << "b1: "; cin >> b1;
    cout << "c1: "; cin >> c1;
    cout << "d1: "; cin >> d1;

    cout << "\n--- Leitura Equação 2 (a2*X + b2*Y + c2*Z = d2) ---\n";
    cout << "a2: "; cin >> a2;
    cout << "b2: "; cin >> b2;
    cout << "c2: "; cin >> c2;
    cout << "d2: "; cin >> d2;

    cout << "\n--- Leitura Equação 3 (a3*X + b3*Y + c3*Z = d3) ---\n";
    cout << "a3: "; cin >> a3;
    cout << "b3: "; cin >> b3;
    cout << "c3: "; cin >> c3;
    cout << "d3: "; cin >> d3;

    // Condição de parada
    double epsilon;
    cout << "\nDigite a tolerância (Epsilon, ex: 0.05): ";
    cin >> epsilon;

    double x_old = 0, y_old = 0, z_old = 0;
    double x_new, y_new, z_new;

    int iteracao = 1;
    int max_iteracoes = 100;

    cout << "\n--- Iniciando Iteracoes ---\n";

    while (iteracao <= max_iteracoes) {
        x_new = (d1 - b1 * y_old - c1 * z_old) / a1;
        y_new = (d2 - a2 * x_new - c2 * z_old) / b2;
        z_new = (d3 - a3 * x_new - b3 * y_new) / c3;

        double diff_x = std::abs(x_new - x_old);
        double diff_y = std::abs(y_new - y_old);
        double diff_z = std::abs(z_new - z_old);

        double maior_diff = std::max({diff_x, diff_y, diff_z});

        double maior_val = std::max({std::abs(x_new), std::abs(y_new), std::abs(z_new)});

        double erro_relativo = maior_diff / maior_val;

        cout << "Iteração " << iteracao << ":" << endl;
        cout << "  X = " << x_new << " | Y = " << y_new << " | Z = " << z_new << endl;
        cout << "  Erro Relativo (ER) = " << erro_relativo << "\n" << endl;

        if (erro_relativo <= epsilon) {
            cout << "=> CONDICAO DE PARADA ATINGIDA (ER <= " << epsilon << ") <=\n";
            cout << "Resultado Final (Aproximado):\n";
            cout << "Vetor X = (\n  " << x_new << "\n  " << y_new << "\n  " << z_new << "\n)" << endl;
            break;
        }

        x_old = x_new;
        y_old = y_new;
        z_old = z_new;
        iteracao++;
    }

    if (iteracao > max_iteracoes) {
        cout << "\nAVISO: O limite de iterações (" << max_iteracoes << ") foi atingido sem chegar na tolerância.\n";
        cout << "A matriz pode não ser diagonalmente estritamente dominante (pode nao convergir).\n";
    }
}

int main() {
    cout << fixed << setprecision(5);
    resolverGaussSeidel();
    return 0;
}