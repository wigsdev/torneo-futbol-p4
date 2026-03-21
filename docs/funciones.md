# 📚 Guía de Conceptos Adicionales para el Proyecto 4

> Esta guía cubre los tres conceptos que van más allá de los requerimientos técnicos básicos del enunciado, pero que son necesarios para implementar el proyecto de forma organizada y que el equipo pueda trabajar en paralelo.

---

## 📌 Índice

1. [Funciones](#1-funciones)
2. [Struct (Estructura)](#2-struct-estructura)
3. [Arreglos (Arrays)](#3-arreglos-arrays)

---

## 1. Funciones

### ¿Qué es una función?
Una función es un **bloque de código con nombre** que realiza una tarea específica. Se puede "llamar" desde cualquier parte del programa las veces que necesites, sin repetir código.

### Anatomía
```cpp
tipo_retorno nombre_funcion() {
    // código que se ejecuta cuando se llama la función
}
```

### Tipos usados en este proyecto
En este proyecto usamos funciones `void`, lo que significa que **no devuelven ningún valor**, solo ejecutan acciones (imprimir, guardar datos, etc.).

```cpp
void mostrarMenu() {         // 'void' = no devuelve nada
    cout << "1. Registrar equipo" << endl;
    cout << "2. Registrar partido" << endl;
}
```

### Los 3 pasos obligatorios

| Paso | ¿Qué es? | ¿Dónde va? | Ejemplo |
|------|----------|-----------|---------|
| **1. Prototipo** | Le avisa al compilador que la función existe | **Antes** del `main()` | `void registrarEquipo();` |
| **2. Definición** | El código real de la función | **Después** del `main()` | `void registrarEquipo() { ... }` |
| **3. Llamada** | Ejecuta la función | **Dentro** del `main()` o de otra función | `registrarEquipo();` |

### ¿Por qué usamos funciones en este proyecto?

Permiten dividir el trabajo entre los 3 integrantes del equipo. Cada uno trabaja en su propia función sin interferir con el código del compañero:

```
Wilmer  →  registrarEquipo()  +  buscarEquipo()
Marco   →  registrarPartido() +  mostrarCampeon()
Miriam  →  mostrarTabla()
```

---

## 2. Struct (Estructura)

### ¿Qué es un struct?
Un `struct` es una herramienta para **agrupar variables relacionadas bajo un mismo nombre**. En lugar de tener 8 variables separadas para cada equipo, las agrupamos en un bloque llamado `Equipo`.

### Sin struct (complicado y propenso a errores)
```cpp
// Para 3 equipos necesitaríamos:
string nombre1, nombre2, nombre3;
int puntos1, puntos2, puntos3;
int goles1, goles2, goles3;
// ... y así para cada estadística. Imposible de mantener.
```

### Con struct (organizado)
```cpp
struct Equipo {
    string nombre;
    int puntos = 0;
    int gf = 0;
    // ... todas las estadísticas juntas
};
```

### ¿Cómo se define?
```cpp
struct NombreDelStruct {
    tipo campo1;
    tipo campo2;
    // ...
};  // ← El punto y coma al final es OBLIGATORIO
```

### ¿Cómo se usa?
Después de definir el `struct`, lo usamos como si fuera un tipo de dato nuevo (como `int` o `string`):

```cpp
Equipo miEquipo;            // Crea una variable de tipo Equipo
miEquipo.nombre = "Peru";   // Accede a un campo con el punto '.'
miEquipo.puntos = 3;
cout << miEquipo.nombre;    // Imprime: Peru
```

### En nuestro proyecto
```cpp
struct Equipo {
    string nombre;
    int pj = 0;       // Partidos Jugados   (inicia en 0)
    int pg = 0;       // Partidos Ganados
    int pe = 0;       // Partidos Empatados
    int pp = 0;       // Partidos Perdidos
    int gf = 0;       // Goles a Favor
    int gc = 0;       // Goles en Contra
    int puntos = 0;   // Puntos acumulados
};
```

> 💡 **Nota:** Inicializar los campos en `= 0` es una buena práctica en C++ para evitar valores inesperados de la memoria.

---

## 3. Arreglos (Arrays)

### ¿Qué es un arreglo?
Un arreglo es una **colección de variables del mismo tipo**, agrupadas bajo un solo nombre y accesibles por un índice numérico. Piénsalo como una tabla de una sola columna.

### Declaración
```cpp
tipo nombre[tamaño];

// Ejemplos:
int edades[5];          // 5 enteros
string ciudades[10];    // 10 strings
Equipo equipos[10];     // 10 variables de tipo Equipo
```

### Acceso por índice
Los índices **siempre empiezan en 0**, no en 1:

```cpp
Equipo equipos[3];       // Arreglo de 3 equipos

equipos[0].nombre = "Peru";      // Primer equipo
equipos[1].nombre = "Brasil";    // Segundo equipo
equipos[2].nombre = "Chile";     // Tercer equipo

cout << equipos[0].nombre;       // Imprime: Peru
```

### Cómo recorrer un arreglo con FOR
La combinación más común: un `for` que va desde 0 hasta el tamaño del arreglo.

```cpp
int numEquipos = 3;

for (int i = 0; i < numEquipos; i++) {
    cout << equipos[i].nombre << endl;
}
// Imprime: Peru, Brasil, Chile
```

### En nuestro proyecto
```cpp
const int MAX_EQUIPOS = 10;      // Tamaño máximo del arreglo
Equipo equipos[MAX_EQUIPOS];     // Arreglo global de equipos
int numEquipos = 0;              // Cuántos hay registrados actualmente

// Para agregar un equipo nuevo:
equipos[numEquipos].nombre = "Peru";
numEquipos++;   // Ahora hay uno más

// Para recorrerlos todos:
for (int i = 0; i < numEquipos; i++) {
    cout << equipos[i].nombre << endl;
}
```

> ⚠️ **Regla de oro:** Nunca accedas a un índice mayor o igual al tamaño del arreglo. Si `MAX_EQUIPOS = 10`, el último índice válido es `equipos[9]`, nunca `equipos[10]`.

---

## Resumen: Cómo se conectan los tres conceptos

```cpp
// 1. STRUCT: define el "molde" de un equipo
struct Equipo {
    string nombre;
    int puntos = 0;
};

// 2. ARREGLO: guarda hasta 10 equipos usando ese molde
const int MAX = 10;
Equipo equipos[MAX];    // Variable GLOBAL
int numEquipos = 0;     // Variable GLOBAL

// 3. FUNCIÓN: trabaja con el arreglo usando variables LOCALES
void registrarEquipo() {
    string nombre;      // Variable LOCAL (solo existe aquí)
    cout << "Nombre: ";
    cin >> nombre;
    equipos[numEquipos].nombre = nombre;  // Guarda en el arreglo global
    numEquipos++;
}
```

Estos tres conceptos trabajan juntos y son la base de `proyecto4.cpp`.
