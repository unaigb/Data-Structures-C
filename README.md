<div align="center">

# 🧱 Estructuras de Datos y Algoritmos en C

**Tipos abstractos de datos, ordenación por inserción y organización de ficheros con hashing e índices**

[![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=black)]()
[![GCC](https://img.shields.io/badge/GCC-make-1F7A8C?style=flat&logo=gnu&logoColor=white)]()
[![Estructuras de datos](https://img.shields.io/badge/Estructuras_de_datos-listas%2C_pilas%2C_colas-0F172A?style=flat)]()

[Descripción](#-sobre-el-proyecto) · [Tipos abstractos](#-parte-1--tipos-abstractos-de-datos) · [Memoria secundaria](#-parte-2--memoria-secundaria) · [Cómo ejecutarlo](#-cómo-ejecutarlo) · [Estructura](#-estructura-del-repositorio) · [Stack](#-stack-tecnológico)

</div>

---

## 📖 Sobre el proyecto

Dos entregas de la asignatura de *Estructuras de Datos y Algoritmos*, ambas en **C puro**: primero, construir los **tipos abstractos de datos** clásicos desde cero y usarlos para ordenar; después, trabajar con **ficheros en memoria secundaria**, con acceso directo por dispersión (*hashing*) y búsqueda por índice.

> 📌 **Proyecto académico** de la asignatura de *Estructuras de Datos y Algoritmos I y II* (2.º curso, Universidad de Salamanca).

---

## 🧩 Parte 1 · Tipos abstractos de datos

Implementaciones con **celdas enlazadas** de tres estructuras, cada una con su `.h` (interfaz) y su `.c` (implementación):

| Estructura | Operaciones |
| :--- | :--- |
| **Lista** | `creaVacia`, `anula`, `vacia`, `inserta`, `suprime`, `localiza`, `recupera`, `primero`, `siguiente`, `anterior`, `fin`, `imprime`, `destruye`, `recuperaUltimo` |
| **Pila** | `pilaCreaVacia`, `pilaVacia`, `pilaInserta`, `pilaSuprime` |
| **Cola** | `colaCreaVacia`, `colaVacia`, `colaInsertaC`, `colaSuprime` |

Sobre la lista se programa la **ordenación por inserción** (`insercion`), dividiendo la lista en una parte ordenada y otra por ordenar y trasladando nodos entre ambas. El programa de prueba, `pruebaInsercion`, genera listas aleatorias de distintos tamaños y **mide el tiempo y el número de iteraciones** de los bucles externo e interno. Una muestra del resultado está en [`resultados.txt`](abstract-data-types/resultados.txt).

---

## 💾 Parte 2 · Memoria secundaria

Gestión de un fichero de **registros de alumnos** (`tipoAlumno`: DNI, nombre, apellidos y provincia) con dos técnicas de acceso:

- **Organización directa por dispersión** (`dispersion.c`): el fichero se reparte en **20 cubos** de **5 registros** y se reserva un **área de desborde de 4 cubos** para las colisiones. Permite crear el fichero hash, **buscar** un registro por DNI (indicando en qué cubo está), **modificar** registros y gestionar el desborde.
- **Búsqueda con índice** (`indice.c`): un fichero índice ordenado por número de matrícula permite localizar al alumno con **búsqueda binaria**.

`prueba.c` ofrece un menú interactivo para probar ambos ejercicios.

> ⚠️ **Datos no incluidos.** El fichero de entrada (`alumnos.dat`) y los ficheros generados a partir de él (`.hash`, `.idx`) contenían datos de alumnos reales y por eso no se publican. Para probar el código, genera un fichero binario con registros `tipoAlumno` (ver `dispersion.h`) y colócalo en `secondary-memory/`.

---

## 🚀 Cómo ejecutarlo

**Requisitos:** `gcc` y `make` (Linux, macOS o WSL).

```bash
# Parte 1: tipos abstractos y ordenación por inserción
cd abstract-data-types
make
./pruebaInsercion

# Parte 2: memoria secundaria (necesita el fichero de datos, ver arriba)
cd ../secondary-memory
make
./ejercicio1y2
```

---

## 📂 Estructura del repositorio

```
Data-Structures-C/
├── abstract-data-types/
│   ├── listas/   lista.h · lista.c
│   ├── pilas/    pila.h · pila.c
│   ├── colas/    cola.h · cola.c
│   ├── insercion.h · insercion.c     # Ordenación por inserción sobre listas
│   ├── pruebaInsercion.c             # Mide tiempos y contadores
│   ├── resultados.txt                # Muestra de mediciones
│   └── makefile
├── secondary-memory/
│   ├── dispersion.h · dispersion.c   # Organización directa con cubos y desborde
│   ├── indice.h · indice.c           # Índice y búsqueda binaria
│   ├── prueba.c                      # Menú de pruebas
│   └── makefile
└── docs/Memoria-TAD.pdf              # Memoria de la parte 1 (con los datos personales tapados)
```

---

## 🖥️ Stack tecnológico

| Categoría | Herramientas |
| :--- | :--- |
| **Lenguaje** | C |
| **Estructuras** | Listas enlazadas · pilas · colas · tablas hash en fichero · índices |
| **Algoritmos** | Ordenación por inserción · dispersión con desborde · búsqueda binaria |
| **Compilación** | `gcc` · `make` |

---

## 🎓 Qué aprendí

- A **separar interfaz e implementación** en C con ficheros de cabecera.
- A **gestionar memoria dinámica** a mano sin perder nodos.
- Que **medir** (tiempo y contadores) es la manera honesta de comparar algoritmos.
- Cómo se organiza un fichero para que **buscar un registro no obligue a leerlo entero**.

---

## 👤 Autoría

**Unai García** — Grado en Ingeniería Informática (Universidad de Salamanca)

- 🐙 GitHub: [@unaigb](https://github.com/unaigb)

---

<div align="center">

**⭐ Si este repositorio te resulta útil, considera darle una estrella.**

</div>
