#include <iostream>
#include <chrono>
using namespace std;

void selectionSort(int A[], int n);
void shellSort(int A[], int n);
void mostrarArreglo(int A[], int n);

int main() {
    int A[5] = {5, 2, 4, 1, 3};
    int B[5] = {5, 2, 4, 1, 3};
    int n = 5;

    cout << "COMPARACION DE ALGORITMOS" << endl;

    cout << "\nArreglo original: ";
    mostrarArreglo(A, n);

    chrono::steady_clock::time_point inicio =
        chrono::steady_clock::now();

    selectionSort(A, n);

    chrono::steady_clock::time_point fin =
        chrono::steady_clock::now();

    cout << "SelectionSort: ";
    mostrarArreglo(A, n);

    cout << "Tiempo: "
         << chrono::duration_cast<chrono::microseconds>(
                fin - inicio).count()
         << " us" << endl;

    inicio = chrono::steady_clock::now();

    shellSort(B, n);

    fin = chrono::steady_clock::now();

    cout << "\nShellSort: ";
    mostrarArreglo(B, n);

    cout << "Tiempo: "
         << chrono::duration_cast<chrono::microseconds>(
                fin - inicio).count()
         << " us" << endl;

    return 0;
}

void selectionSort(int A[], int n) {
    int menor, k;

    for (int i = 0; i < n - 1; i++) {
        menor = A[i];
        k = i;

        for (int j = i + 1; j < n; j++) {
            if (A[j] < menor) {
                menor = A[j];
                k = j;
            }
        }

        A[k] = A[i];
        A[i] = menor;
    }
}

void shellSort(int A[], int n) {
    int k = n;
    int aux, j;

    while (k > 1) {
        k = k / 2;

        for (int i = k; i < n; i++) {
            aux = A[i];
            j = i;

            while (j - k >= 0 && A[j - k] > aux) {
                A[j] = A[j - k];
                j = j - k;
            }

            A[j] = aux;
        }
    }
}


void mostrarArreglo(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << endl;
}
