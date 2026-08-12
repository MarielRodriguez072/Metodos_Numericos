# Métodos Numéricos en Computadoras

Implementaciones en C++ de los métodos numéricos estudiados en la materia de **Métodos Numéricos en Computadoras**. Este repositorio documenta y codifica las técnicas fundamentales para resolver problemas de ingeniería y matemáticas mediante aproximaciones computacionales, como la localización de raíces, la solución de sistemas de ecuaciones lineales, la interpolación, la regresión y el trazado de curvas.

## Tabla de contenidos

1. [Temas de la materia](#temas-de-la-materia)
   - [Localización de raíces](#1-localización-de-raíces)
   - [Sistemas de ecuaciones algebraicas lineales](#2-sistemas-de-ecuaciones-algebraicas-lineales)
   - [Interpolación](#3-interpolación)
   - [Regresión por cuadrados mínimos](#4-regresión-por-cuadrados-mínimos)
   - [Interpolación segmentaria (curvas spline)](#5-interpolación-segmentaria-curvas-spline)
2. [Estructura del repositorio](#estructura-del-repositorio)
3. [Compilación y ejecución](#compilación-y-ejecución)
4. [Lenguaje y herramientas](#lenguaje-y-herramientas)

## Temas de la materia

### 1. Localización de raíces

Consiste en encontrar los valores de *x* que hacen que una función *f(x) = 0*, es decir, las raíces o ceros de la función. Es la base para resolver ecuaciones no lineales que no tienen solución analítica. Los métodos se dividen en dos grandes grupos según la cantidad de información que requieren:

#### Métodos cerrados

También llamados de *acotamiento* o *intervalos*. Parten de un intervalo `[a, b]` donde la función cambia de signo (`f(a) * f(b) < 0`), lo que garantiza que existe al menos una raíz dentro del intervalo (Teorema del Valor Intermedio). Son métodos **convergentes garantizados**, pero más lentos.

- **Bisección:** Divide el intervalo a la mitad (`c = (a + b) / 2`) y conserva la mitad donde ocurre el cambio de signo, repitiendo el proceso hasta alcanzar el error deseado. Es el método más simple y robusto.
- **Regula Falsi (falsa posición):** Similar a la bisección, pero en lugar del punto medio usa la intersección de la recta que une los puntos `(a, f(a))` y `(b, f(b))` con el eje *x*. Converge más rápido que la bisección en la mayoría de los casos.

Ambos métodos están unificados en un único programa: al ejecutarlo se elige el método (bisección o regula falsi) y se ingresa el intervalo `[a, b]` y el error `e`. La función a la que se le buscan las raíces está definida (hardcodeada) en la función `f(x)` del código.

**Archivo:** `busqueda-de-raices/metodos-cerrados/MetodosCerrados.cpp`

#### Métodos abiertos

Requieren uno o dos valores iniciales no necesariamente que cerca de la raíz. Cuando convergen lo hacen más rápido que los métodos cerrados, pero **pueden divergir** si no se tienen algunas consideraciones.

- **Punto fijo:** Reescribe la ecuación `f(x) = 0` como `x = g(x)` y genera una sucesión `x_{n+1} = g(x_n)`. Converge si `|g'(x)| < 1` en la vecindad de la raíz.
- **Newton-Raphson:** Usa la recta tangente a la curva: `x_{n+1} = x_n - f(x_n) / f'(x_n)`. Converge cuadráticamente si el valor inicial es adecuado; requiere calcular la derivada.
- **Secante:** Aproxima la derivada de Newton-Raphson con una diferencia finita usando los dos últimos puntos, evitando calcular la derivada analíticamente. Convergencia más rápida que el punto fijo pero más lenta que Newton.

**Archivos:** `busqueda-de-raices/metodos-abiertos/puntoFijo.cpp`, `newtonRapson.cpp`, `secante.cpp`

### 2. Sistemas de ecuaciones algebraicas lineales

Se busca el vector solución *x* que satisface `A·x = b`, donde *A* es una matriz de coeficientes y *b* un vector de términos independientes. Este problema aparece constantemente en ingeniería (circuitos, estructuras, balances de materia y energía). Se resuelve con métodos directos e iterativos.

- **Eliminación gaussiana:** Transforma el sistema en una forma triangular superior mediante operaciones elementales entre filas (multiplicar, sumar, intercambiar) y luego lo resuelve por **sustitución hacia atrás**.
- **Pivoteo:** Técnica que mejora la eliminación gaussiana. El *pivoteo parcial* intercambia filas para colocar el elemento de mayor magnitud en la diagonal, evitando errores numéricos por división entre números muy pequeños (ceros o casi ceros).
- **Métodos iterativos:** A partir de una aproximación inicial, generan una sucesión que converge a la solución. Son preferibles para sistemas grandes y esparcidos.
  - **Jacobi:** Calcula cada variable usando los valores de la iteración anterior.
  - **Gauss-Seidel:** Igual que Jacobi, pero usa los valores ya actualizados en la misma iteración, lo que acelera la convergencia.
  - **Criterio de convergencia:** la matriz debe ser *diagonalmente dominante* (cada elemento de la diagonal mayor que la suma de los demás de su fila).

### 3. Interpolación

Dado un conjunto de puntos conocidos `(x_i, y_i)`, se busca una función que pase **exactamente** por todos ellos para estimar valores intermedios.

- **Polinomio interpolador:** Existe un único polinomio de grado `n-1` que pasa por `n` puntos. Permite evaluar la función en cualquier punto del intervalo, aunque puede presentar oscilaciones (fenómeno de Runge) en extremos con muchos puntos.
- **Interpolación de Lagrange:** Forma explícita del polinomio interpolador construida como combinación lineal de polinomios base `L_i(x)`, cada uno asociado a un punto, de modo que `P(x) = Σ y_i · L_i(x)`. No requiere resolver sistemas de ecuaciones, solo evaluar la fórmula.

### 4. Regresión por cuadrados mínimos

A diferencia de la interpolación, aquí la función **no tiene que pasar por los puntos**; busca la curva que mejor se ajusta a los datos minimizando la suma de los cuadrados de las diferencias entre los valores observados y los predichos. Es útil cuando los datos provienen de mediciones con error. La versión más común es la **regresión lineal** `y = a + b·x`, cuyos coeficientes se obtienen resolviendo las llamadas *ecuaciones normales*.

### 5. Interpolación segmentaria (curvas spline)

En lugar de usar un único polinomio de alto grado para todos los puntos, se divide el intervalo en subintervalos y se ajusta un polinomio de grado bajo en cada uno, uniendo los tramos con continuidad en los valores y en las derivadas. El caso clásico es el **spline cúbico**, que usa polinomios de grado 3 por tramo con primera y segunda derivada continuas. Evita las oscilaciones del polinomio interpolador global y produce curvas suaves y estables.

## Estructura del repositorio

```
Metodos_Numericos/
├── README.md
└── busqueda-de-raices/
    ├── metodos-cerrados/
    │   ├── MetodosCerrados.cpp   # Bisección y Regula Falsi en un solo programa
    │   └── Resultado.txt         # Salida de ejemplo
    └── metodos-abiertos/
        ├── puntoFijo.cpp       # Método de punto fijo
        ├── newtonRapson.cpp    # Método de Newton-Raphson
        └── secante.cpp         # Método de la secante
```

## Compilación y ejecución

Los programas están escritos en C++ y se compilan con un compilador estándar:

```bash
# Compilar
g++ busqueda-de-raices/metodos-cerrados/MetodosCerrados.cpp -o metodos-cerrados
g++ busqueda-de-raices/metodos-abiertos/newtonRapson.cpp -o newton

# Ejecutar
./metodos-cerrados
./newton
```

> Nota: algunos programas reciben los datos (intervalo, valor inicial, error) por consola; otros los tienen fijos en el código. Revisa el archivo antes de ejecutar.

## Lenguaje y herramientas

- **Lenguaje:** C++ (estándar C++11 o posterior)
- **Compiladores:** g++, gcc
- **Matemáticas:** librería estándar `<cmath>` / `<math.h>`
