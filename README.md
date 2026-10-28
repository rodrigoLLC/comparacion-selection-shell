# Comparación experimental de Selection Sort recursivo y Shell Sort iterativo

## 1. Descripción del proyecto

El presente proyecto tiene como objetivo comparar experimentalmente el rendimiento de dos algoritmos de ordenación: Selection Sort recursivo y Shell Sort iterativo. Se evalúa su comportamiento utilizando diferentes tamaños y patrones de entrada, registrando el tiempo de ejecución y la cantidad de operaciones realizadas.

El experimento permite analizar las diferencias entre ambos algoritmos en términos de tiempo de ejecución, comparaciones, intercambios, desplazamientos y profundidad de recursión.

## 2. Datos del estudiante

- **Estudiante:** Rodrigo Jhoel Llano Capia
- **Universidad:** Universidad Nacional Jorge Basadre Grohmann
- **Facultad:** Facultad de Ingeniería
- **Escuela profesional:** Ingeniería en Informática y Sistemas
- **Asignatura:** Programación Avanzada
- **Semestre académico:** 2026-II

## 3. Algoritmos seleccionados

### 3.1. Selection Sort recursivo

Selection Sort busca el elemento menor de la parte no ordenada del arreglo y lo intercambia con el elemento ubicado al inicio de dicha parte. El procedimiento continúa mediante llamadas recursivas hasta completar la ordenación.

- **Complejidad temporal:** O(n²).
- **Memoria auxiliar:** O(n) en esta implementación, debido a la pila de recursión.
- **Estabilidad:** no es estable en la implementación utilizada.
- **Operaciones registradas:** comparaciones e intercambios.
- **Profundidad de recursión:** se registra durante la ejecución.

### 3.2. Shell Sort iterativo

Shell Sort ordena los elementos utilizando intervalos o saltos (*gaps*) que disminuyen progresivamente. En cada intervalo se aplica un procedimiento de ordenación por inserción hasta llegar a un salto de uno.

- **Complejidad temporal:** depende de la secuencia de saltos utilizada.
- **Memoria auxiliar:** O(1) para el proceso de ordenación, sin contar el almacenamiento del arreglo.
- **Estabilidad:** no es estable en la implementación utilizada.
- **Secuencia de saltos:** comienza en n/2 y se divide entre dos en cada iteración.
- **Operaciones registradas:** comparaciones y desplazamientos.

## 4. Requisitos del entorno

- **Sistema operativo:** Windows 11 Pro, versión 26H2.
- **Entorno de desarrollo:** Dev-C++.
- **Compilador:** TDM-GCC 4.9.2 de 64 bits.
- **Estándar del lenguaje:** C++11.
- **Opción de compilación del estándar:** `-std=c++11`.

El código utiliza las siguientes bibliotecas estándar:

- `iostream`
- `vector`
- `cstdlib`
- `chrono`
- `fstream`
- `string`
- `algorithm`
- `cmath`

## 5. Compilación y ejecución

1. Clonar o descargar el repositorio.
2. Abrir el archivo `src/TrabajoFinal.cpp` en Dev-C++.
3. Configurar el compilador para utilizar el estándar C++11.
4. Compilar el programa.
5. Ejecutar el programa y esperar a que finalicen las pruebas experimentales.
6. Revisar los archivos `resultados.csv` y `resumen.csv` generados en el directorio de trabajo.

El programa genera automáticamente ambos archivos CSV. Si ya existen, se sobrescriben al iniciar una nueva ejecución.

## 6. Diseño experimental

### 6.1. Tamaños de entrada

Se utilizan los siguientes tamaños:

- 1 000 elementos.
- 10 000 elementos.
- 100 000 elementos.

### 6.2. Patrones de entrada

Se evalúan tres patrones:

- **Aleatorio:** números enteros generados mediante `rand() % 100000`.
- **Ascendente:** elementos organizados de menor a mayor.
- **Descendente:** elementos organizados de mayor a menor.

### 6.3. Número de repeticiones

Se realizan 30 repeticiones para cada combinación de tamaño y patrón.

### 6.4. Generación de semillas

La semilla base utilizada es `12345`. Para cada repetición se calcula una semilla mediante la siguiente expresión:

`semilla = semillaBase + t * 100000 + p * 1000 + rep`

Donde:

- `t` representa el índice del tamaño de entrada.
- `p` representa el índice del patrón.
- `rep` representa el número de repetición, desde 1 hasta 30.

La semilla utilizada se registra en `resultados.csv`. Los patrones ascendente y descendente se construyen directamente; la semilla solo afecta a la generación de arreglos aleatorios.

### 6.5. Condiciones de ejecución

Para cada condición experimental se genera un arreglo original y se utiliza una copia independiente para cada algoritmo. De esta manera, ambos algoritmos procesan la misma entrada en cada repetición.

El tiempo se mide mediante `std::chrono::steady_clock` y se expresa en milisegundos. La medición incluye la ejecución del algoritmo, pero excluye la generación del arreglo y su copia inicial.

Selection Sort recursivo se ejecuta únicamente para tamaños de 1 000 y 10 000 elementos. Para 100 000 elementos se ejecuta solamente Shell Sort, debido al elevado costo temporal y a la profundidad de recursión de Selection Sort.

## 7. Archivos de resultados

### 7.1. `resultados.csv`

Contiene los registros individuales de cada repetición experimental.

Las columnas son:

- `algoritmo`: algoritmo ejecutado.
- `n`: tamaño del arreglo.
- `patron`: patrón de entrada.
- `repeticion`: número de repetición.
- `tiempo_ms`: tiempo de ejecución en milisegundos.
- `comparaciones`: número de comparaciones contabilizadas.
- `intercambios`: número de intercambios registrados.
- `desplazamientos`: número de desplazamientos registrados.
- `profundidad_recursion`: profundidad máxima registrada para la ejecución recursiva.
- `semilla`: semilla asociada a la repetición.
- `commit_hash`: identificador del commit consignado en el código experimental.
- `correcto`: indica si el arreglo quedó ordenado correctamente (`SI` o `NO`).

### 7.2. `resumen.csv`

Contiene estadísticas descriptivas de los tiempos de ejecución para cada algoritmo, tamaño y patrón.

Las columnas son:

- `algoritmo`
- `n`
- `patron`
- `media_ms`
- `mediana_ms`
- `desviacion_std_ms`
- `minimo_ms`
- `maximo_ms`

La desviación estándar se calcula utilizando el denominador n − 1, correspondiente a la desviación estándar muestral.

## 8. Resultados y análisis

El análisis experimental compara los tiempos de ejecución y las operaciones registradas para los distintos tamaños y patrones de entrada.

Se consideran especialmente las siguientes observaciones:

- El crecimiento del número de comparaciones de Selection Sort recursivo conforme aumenta el tamaño del arreglo.
- Las diferencias de tiempo de ejecución entre Selection Sort recursivo y Shell Sort iterativo.
- La influencia de los patrones aleatorio, ascendente y descendente.
- La cantidad de desplazamientos realizados por Shell Sort.
- La profundidad de recursión alcanzada por Selection Sort.
- La corrección de los arreglos ordenados al finalizar cada ejecución.

Para el análisis se utilizan los datos individuales de `resultados.csv` y las estadísticas descriptivas de `resumen.csv`. Las conclusiones se basan en los resultados medidos bajo las condiciones experimentales descritas.

## 9. Reproducibilidad

Para repetir el experimento:

1. Utilizar el código fuente del repositorio y el entorno de compilación documentado.
2. Configurar el estándar C++11.
3. Ejecutar el programa sin modificar los tamaños, patrones, número de repeticiones ni fórmula de semillas.
4. Esperar a que finalicen todas las pruebas.
5. Examinar los archivos `resultados.csv` y `resumen.csv`.
6. Comprobar que la columna `correcto` indique `SI` en todos los registros.
7. Comparar los resultados obtenidos con los registros de la ejecución anterior.

Las mediciones de tiempo pueden variar entre ejecuciones debido a las condiciones del sistema, los procesos en segundo plano y otros factores del entorno.

La función `rand()` depende de la implementación de la biblioteca estándar. Por ello, para reproducir exactamente los arreglos aleatorios, se recomienda utilizar el mismo compilador y entorno de ejecución.

## 10. Figuras y tablas

Las tablas estadísticas pueden elaborarse a partir de `resumen.csv`, mientras que las gráficas de comparación pueden construirse utilizando los datos de `resultados.csv` y `resumen.csv`.

El programa principal genera los dos archivos CSV; la generación de figuras requiere un procedimiento adicional de procesamiento y visualización de los datos.

## 11. Video de demostración

La demostración debe mostrar la compilación y ejecución del programa, la generación de los archivos CSV y una explicación de los resultados experimentales.

## 12. Identificación del código experimental

El programa registra un identificador de commit en la columna `commit_hash` de `resultados.csv`. Para que este identificador permita rastrear la versión evaluada, debe corresponder al commit real del código fuente utilizado para producir los resultados.

**Repositorio:** https://github.com/rodrigoLLC/comparacion-selection-shell.git
