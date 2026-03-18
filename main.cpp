#include <iostream>
#include <string>

using namespace std;

class SensorNivel {
private:
    string tag;
    double minimo;
    double maximo;
    double valorAtual;

public:
    SensorNivel(string tagSensor) {
        tag = tagSensor;
        minimo = 0.0;
        maximo = 100.0;
        valorAtual = 0.0;
    }

    SensorNivel(string tagSensor, double min, double max, double valor) {
        tag = tagSensor;
        minimo = min;
        maximo = max;
        valorAtual = valor;
    }

    void exibirResumo() const {
        cout << "[SensorNivel] " << tag
             << " | faixa: " << minimo << " a " << maximo
             << " | valor atual: " << valorAtual << "\n";
    }
};

class Bomba {
private:
    string tag;
    double velocidade;

public:
    Bomba(string tagBomba) {
        tag = tagBomba;
        velocidade = 0.0;
    }

    Bomba(string tagBomba, double vel) {
        tag = tagBomba;
        velocidade = vel;
    }

    void exibirResumo() const {
        cout << "[Bomba] " << tag
             << " | velocidade: " << velocidade << "%\n";
    }
};

class ControladorTanque {
private:
    string tag;
    double setpoint;
    double kp;

public:
    ControladorTanque(string tagControlador) {
        tag = tagControlador;
        setpoint = 50.0;
        kp = 1.0;
    }

    ControladorTanque(string tagControlador, double sp, double ganho) {
        tag = tagControlador;
        setpoint = sp;
        kp = ganho;
    }

    void exibirResumo() const {
        cout << "[ControladorTanque] " << tag
             << " | SP=" << setpoint
             << " | Kp=" << kp << "\n";
    }
};

int main() {
    // Sensores
    SensorNivel sn1("LT-401");
    SensorNivel sn2("LT-402", 0.0, 5000.0, 2780.0);

    // Bombas
    Bomba b1("P-101");
    Bomba b2("P-102", 75.0);

    // Controladores
    ControladorTanque c1("LIC-201");
    ControladorTanque c2("LIC-202", 80.0, 2.5);

    sn1.exibirResumo();
    sn2.exibirResumo();

    b1.exibirResumo();
    b2.exibirResumo();

    c1.exibirResumo();
    c2.exibirResumo();

    return 0;
}