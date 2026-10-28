#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

struct Resultado {
    double tiempo;
    long long comparaciones;
    long long intercambios;
    long long desplazamientos;
    int profundidad;
};

void selectionSortRecursivo(vector<int>& A, int inicio, Resultado& r, int profundidad) {
    if (inicio >= A.size() - 1) {
        return;
    }

    if (profundidad > r.profundidad) {
        r.profundidad = profundidad;
    }

    int menor = inicio;

    for (int j = inicio + 1; j < A.size(); j++) {
        r.comparaciones++;

        if (A[j] < A[menor]) {
            menor = j;
        }
    }

    if (menor != inicio) {
        int aux = A[inicio];
        A[inicio] = A[menor];
        A[menor] = aux;
        r.intercambios++;
    }

    selectionSortRecursivo(A, inicio + 1, r, profundidad + 1);
}

Resultado selectionSort(vector<int>& A) {
    Resultado r = {0, 0, 0, 0, 0};
    
    auto inicio = chrono::steady_clock::now();
    selectionSortRecursivo(A, 0, r, 1);
    auto fin = chrono::steady_clock::now();
    
    r.tiempo = chrono::duration<double, milli>(fin - inicio).count();
    return r;
}

Resultado shellSort(vector<int>& A) {
    Resultado r = {0, 0, 0, 0, 0};
    auto inicio = chrono::steady_clock::now();

    int n = A.size();

    for (int gap = n / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < n; i++) {
            int aux = A[i];
            int j = i;

            while (j >= gap) {
                r.comparaciones++;

                if (A[j - gap] > aux) {
                    A[j] = A[j - gap];
                    r.desplazamientos++;
                    j = j - gap;
                } else {
                    break;
                }
            }

            if (j != i) {
                A[j] = aux;
                r.desplazamientos++;
            }
        }
    }

    auto fin = chrono::steady_clock::now();

    r.tiempo = chrono::duration<double, milli>(fin - inicio).count();

    return r;
}

vector<int> generarArreglo(int n, string patron, unsigned int semilla) {
    vector<int> A(n);

    if (patron == "aleatorio") {
        srand(semilla);

        for (int i = 0; i < n; i++) {
            A[i] = rand() % 100000;
        }
    }

    if (patron == "ascendente") {
        for (int i = 0; i < n; i++) {
            A[i] = i;
        }
    }

    if (patron == "descendente") {
        for (int i = 0; i < n; i++) {
            A[i] = n - i;
        }
    }

    return A;
}

bool estaOrdenado(vector<int>& A) {
    for (int i = 1; i < A.size(); i++) {
        if (A[i] < A[i - 1]) {
            return false;
        }
    }

    return true;
}

double calcularMedia(vector<double> datos) {
    double suma = 0;

    for (int i = 0; i < datos.size(); i++) {
        suma = suma + datos[i];
    }

    return suma / datos.size();
}

double calcularMediana(vector<double> datos) {
    sort(datos.begin(), datos.end());

    int n = datos.size();

    if (n % 2 == 0) {
        return (datos[n / 2 - 1] + datos[n / 2]) / 2.0;
    }

    return datos[n / 2];
}

double calcularDesviacion(vector<double> datos) {
    if (datos.size() < 2) {
        return 0;
    }

    double media = calcularMedia(datos);
    double suma = 0;

    for (int i = 0; i < datos.size(); i++) {
        suma = suma + pow(datos[i] - media, 2);
    }

    return sqrt(suma / (datos.size() - 1));
}

void guardarResumen(ofstream& archivo, string algoritmo, int n,
                    string patron, vector<double> tiempos) {
    double media = calcularMedia(tiempos);
    double mediana = calcularMediana(tiempos);
    double desviacion = calcularDesviacion(tiempos);

    double minimo = *min_element(tiempos.begin(), tiempos.end());
    double maximo = *max_element(tiempos.begin(), tiempos.end());

    archivo << algoritmo << ","
            << n << ","
            << patron << ","
            << media << ","
            << mediana << ","
            << desviacion << ","
            << minimo << ","
            << maximo << "\n";
}

int main() {
    int repeticiones = 30;
    unsigned int semillaBase = 12345;

    int tamanos[3] = {1000, 10000, 100000};

    string patrones[3] = {
        "aleatorio",
        "ascendente",
        "descendente"
    };

    ofstream resultados("resultados.csv");
    ofstream resumen("resumen.csv");

    if (!resultados.is_open() || !resumen.is_open()) {
        cout << "No se pudieron crear los archivos." << endl;
        return 1;
    }

    resultados << "algoritmo,n,patron,repeticion,tiempo_ms,"
               << "comparaciones,intercambios,desplazamientos,"
               << "profundidad_recursion,semilla,commit_hash,correcto"
               << endl;

    resumen << "algoritmo,n,patron,media_ms,mediana_ms,"
            << "desviacion_std_ms,minimo_ms,maximo_ms"
            << endl;

    string commitHash = "8e34ad8";

    for (int t = 0; t < 3; t++) {
        int n = tamanos[t];

        for (int p = 0; p < 3; p++) {
            string patron = patrones[p];

            vector<double> tiemposShell;
            vector<double> tiemposSelection;

            cout << "====================================" << endl;
            cout << "Tamano del arreglo: " << n << endl;
            cout << "Patron: " << patron << endl;
            cout << "Iniciando pruebas..." << endl;

            for (int rep = 1; rep <= repeticiones; rep++) {
                unsigned int semilla =
                    semillaBase + t * 100000 + p * 1000 + rep;

                vector<int> original =
                    generarArreglo(n, patron, semilla);

                vector<int> arregloShell = original;

                Resultado rs = shellSort(arregloShell);

                bool correctoShell = estaOrdenado(arregloShell);

                tiemposShell.push_back(rs.tiempo);

                resultados << "Shell Sort,"
                           << n << ","
                           << patron << ","
                           << rep << ","
                           << rs.tiempo << ","
                           << rs.comparaciones << ","
                           << rs.intercambios << ","
                           << rs.desplazamientos << ","
                           << rs.profundidad << ","
                           << semilla << ","
                           << commitHash << ","
                           << (correctoShell ? "SI" : "NO")
                           << endl;

                if (n <= 10000) {
                    vector<int> arregloSelection = original;

                    Resultado rr = selectionSort(arregloSelection);

                    bool correctoSelection =
                        estaOrdenado(arregloSelection);

                    tiemposSelection.push_back(rr.tiempo);

                    resultados << "Selection Sort recursivo,"
                               << n << ","
                               << patron << ","
                               << rep << ","
                               << rr.tiempo << ","
                               << rr.comparaciones << ","
                               << rr.intercambios << ","
                               << rr.desplazamientos << ","
                               << rr.profundidad << ","
                               << semilla << ","
                               << commitHash << ","
                               << (correctoSelection ? "SI" : "NO")
                               << endl;
                }

                cout << "Repeticion " << rep << " de "
                     << repeticiones << " terminada." << endl;
            }

            guardarResumen(
                resumen, "Shell Sort", n, patron, tiemposShell
            );

            if (n <= 10000) {
                guardarResumen(
                    resumen,
                    "Selection Sort recursivo",
                    n,
                    patron,
                    tiemposSelection
                );
            }

            cout << "Pruebas terminadas." << endl;
        }
    }

    resultados.close();
    resumen.close();

    cout << "====================================" << endl;
    cout << "Experimento terminado." << endl;
    cout << "Se creo el archivo resultados.csv." << endl;
    cout << "Se creo el archivo resumen.csv." << endl;

    return 0;
}

