# Comparación experimental de Selection Sort recursivo y Shell Sort iterativo

# 1. Descripción del proyecto

El presente proyecto tiene como objetivo comparar el rendimiento de dos algoritmos de ordenación: Selection Sort recursivo y Shell Sort iterativo. Se evalúa su comportamiento utilizando diferentes tamaños y patrones de entrada registrando el tiempo de ejecución y la cantidad de operaciones realizadas.

# 2. Datos del estudiante

- Estudiante: Rodrigo Jhoel Llano Capia
- Universidad: Universidad Nacional Jorge Basadre Grohmann
- Facultad: Facultad de Ingeniería
- Escuela profesional: Ingeniería en Informática y Sistemas
- Asignatura: Programación Avanzada
- Semestre: 2026-II

# 3. Algoritmos seleccionados

*Selection Sort recursivo

Este algoritmo busca el elemento menor de la parte no ordenada y lo coloca en su posición correspondiente. El procedimiento se repite mediante llamadas recursivas hasta ordenar el arreglo.

- Complejidad temporal: O(n²).
- Memoria auxiliar: O(n) por la pila de recursión en esta implementación.
- Estabilidad: no es estable en su versión implementada.

*Shell Sort iterativo

Este algoritmo ordena los elementos utilizando intervalos o saltos (*gaps*), que se reducen progresivamente hasta llegar a uno.

- Complejidad temporal: depende de la secuencia de saltos utilizada.
- Memoria auxiliar: O(1).
- Estabilidad: no es estable en su versión implementada.
- Secuencia de saltos: comienza en n/2 y se divide entre dos en cada iteración.

# 4. Requisitos para compilar y ejecutar

- Sistema operativo: Windows.
- Entorno de desarrollo: Dev-C++.
- Compilador compatible con C++11 o superior.
- Bibliotecas estándar utilizadas: `iostream`, `vector`, `cstdlib`, `chrono`, `fstream`, `string`, `algorithm` y `cmath`.

Para ejecutar el proyecto:

1. Abrir el archivo `src/TrabajoFinal.cpp` en Dev-C++.
2. Compilar el programa.
3. Ejecutar el programa.
4. Esperar a que terminen las pruebas.
5. Revisar los archivos CSV generados.

# 5. Instrucciones para reproducir los experimentos

El programa ejecuta pruebas automatizadas y registra los resultados en archivos CSV.

1. Utilizar el mismo código fuente y el mismo entorno de ejecución.
2. Ejecutar el programa sin modificar los parámetros experimentales.
3. Esperar a que terminen las repeticiones.
4. Revisar los archivos 'resultados.csv' y 'resumen.csv'.
5. Comprobar que los algoritmos ordenen correctamente los arreglos.

El tiempo medido corresponde a la ejecución del algoritmo sin incluir la generación ni la copia inicial del arreglo.

# 6. Tamaños, patrones y semillas

Se utilizan los siguientes tamaños de entrada:

- 1 000 elementos.
- 10 000 elementos.
- 100 000 elementos.

Los patrones evaluados son:

- Aleatorio: números generados mediante 'rand() % 100000'.
- Ascendente: elementos organizados de menor a mayor.
- Descendente: elementos organizados de mayor a menor.

Se realizan 30 repeticiones por cada condición experimental.

La semilla base es 12345. Para las repeticiones se calcula una semilla a partir del tamaño, el patrón y el número de repetición.

Selection Sort recursivo se ejecuta únicamente con tamaños de 1 000 y 10 000 elementos, para 100 000 elementos el experimento considera solamente Shell Sort debido a las limitaciones prácticas de tiempo y profundidad de recursión.

# 7. Archivos de resultados

# resultados.csv

Contiene los resultados individuales de cada repetición, incluyendo:

- Algoritmo.
- Tamaño del arreglo.
- Patrón de entrada.
- Número de repetición.
- Tiempo de ejecución en milisegundos.
- Comparaciones.
- Intercambios.
- Desplazamientos.
- Profundidad de recursión.
- Semilla.
- Hash del commit del código experimental.
- Indicador de ordenación correcta.

# resumen.csv

Contiene las estadísticas calculadas a partir de los tiempos registrados:

- Media.
- Mediana.
- Desviación estándar.
- Tiempo mínimo.
- Tiempo máximo.

# 8. Principales resultados y conclusiones

Los resultados experimentales se analizarán comparando los tiempos de ejecución y las operaciones realizadas por ambos algoritmos en los tamaños y patrones evaluados.

Se espera que Selection Sort recursivo presente un crecimiento cuadrático en el número de comparaciones, Shell Sort puede mostrar un mejor rendimiento práctico para arreglos grandes aunque su comportamiento depende de la secuencia de saltos.

Las conclusiones definitivas se completarán utilizando los valores reales obtenidos en los archivos CSV sin asumir resultados que todavía no hayan sido analizados.

# 9. Video de demostración

- Enlace de YouTube: 

# 10. Identificación del commit

- Hash del commit del código experimental: `8e34ad8`
