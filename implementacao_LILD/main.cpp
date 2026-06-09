#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Vec2 {
    double x, y;
};

struct Vec3 {
    double x, y, z;
};

//  ==========================
//  RESOLUÇÃO 2x2
//  ==========================

double calcularDeterminante2D(const double a11, const double a12, const double a21, const double a22) {
    return (a11 * a22) - (a12 * a21);
}

void resolverSistema2D() {
    Vec2 v1, v2, vRes;
    cout << "\n-=-=- Modo 2D -=-=-\n";
    cout << "--- Leitura Vetor 1 ---\n";
    cout << "Posição X: ";
    cin >> v1.x;
    cout << "\nPosição Y: ";
    cin >> v1.y;

    cout << "\n--- Leitura Vetor 2 ---\n";
    cout << "Posição X: ";
    cin >> v2.x;
    cout << "\nPosição Y: ";
    cin >> v2.y;

    cout << "\n--- Leitura Vetor Resultante ---\n";
    cout << "Posição X: ";
    cin >> vRes.x;
    cout << "\nPosição Y: ";
    cin >> vRes.y;

    double det = calcularDeterminante2D(v1.x, v2.x, v1.y, v2.y);

    if (det == 0) {
        cout << "\nDeterminante = 0";
        cout << "\nOs vetores são Linearmente Dependentes (LD), \nlogo não formam base!" << endl;
        return;
    }

    cout << "\nDeterminante => " << det << " != 0 (Formam base!)";

    double detA = calcularDeterminante2D(vRes.x, v2.x, vRes.y, v2.y);
    double detB = calcularDeterminante2D(v1.x, vRes.x, v1.y, vRes.y);

    double a = detA/det;
    double b = detB/det;

    cout << "\nCoeficientes encontrados:" << endl;
    cout << "a = " << a << " | b = " << b << endl;
    cout << "Equacao: V = (" << a << ") * V1 + (" << b << ") * V2" << endl;
}

//  ==========================
//  RESOLUÇÃO 3x3
//  ==========================

double calcularDeterminante3D(Vec3 c1, Vec3 c2, Vec3 c3) {
    return c1.x * (c2.y * c3.z - c3.y * c2.z)
         - c2.x * (c1.y * c3.z - c3.y * c1.z)
         + c3.x * (c1.y * c2.z - c2.y * c1.z);
}

void resolverSistema3D() {
    Vec3 v1, v2, v3, vRes;

    cout << "\n-=-=- Modo 3D -=-=-\n";

    cout << "--- Leitura Vetor 1 ---\n";
    cout << "Posição X: ";
    cin >> v1.x;
    cout << "\nPosição Y: ";
    cin >> v1.y;
    cout << "\nPosição Z: ";
    cin >> v1.z;

    cout << "\n--- Leitura Vetor 2 ---\n";
    cout << "Posição X: ";
    cin >> v2.x;
    cout << "\nPosição Y: ";
    cin >> v2.y;
    cout << "\nPosição Z: ";
    cin >> v2.z;

    cout << "\n--- Leitura Vetor 3 ---\n";
    cout << "Posição X: ";
    cin >> v3.x;
    cout << "\nPosição Y: ";
    cin >> v3.y;
    cout << "\nPosição Z: ";
    cin >> v3.z;

    cout << "\n--- Leitura Vetor Resultante ---\n";
    cout << "Posição X: ";
    cin >> vRes.x;
    cout << "\nPosição Y: ";
    cin >> vRes.y;
    cout << "\nPosição Z: ";
    cin >> vRes.z;

    double det = calcularDeterminante3D(v1, v2, v3);

    if (det == 0) {
        cout << "\nDeterminante = 0";
        cout << "\nOs vetores são Linearmente Dependentes (LD), \nlogo não formam base no R3!" << endl;
        return;
    }

    cout << "\nDeterminante => " << det << " != 0 (Formam base!)";

    double detA = calcularDeterminante3D(vRes, v2, v3);
    double detB = calcularDeterminante3D(v1, vRes, v3);
    double detC = calcularDeterminante3D(v1, v2, vRes);

    double a = detA/det;
    double b = detB/det;
    double c = detC/det;

    cout << "\nCoeficientes encontrados:" << endl;
    cout << "a = " << a << " | b = " << b << " | c = " << c << endl;
    cout << "Equação: V = (" << a << ") * V1 + (" << b << ") * V2 + (" << c << ") * V3" << endl;
}

int main() {
    int opcao = 0;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "\n===================================" << endl;
        cout << "   CALCULADORA DE BASE VETORIAL" << endl;
        cout << "===================================" << endl;
        cout << "1. Analisar e resolver 2 Vetores (2D)" << endl;
        cout << "2. Analisar e resolver 3 Vetores (3D)" << endl;
        cout << "3. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        if (opcao == 1) {
            resolverSistema2D();
        } else if (opcao == 2) {
            resolverSistema3D();
        } else if (opcao == 3) {
            cout << "Encerrando o programa..." << endl;
            break;
        } else {
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }

    return 0;
}