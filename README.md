# 🏆 Proyecto 4: Simulador de Torneo de Fútbol

> Programa en C++ que simula un torneo de fútbol: registra equipos y partidos, genera la tabla de posiciones, permite buscar equipos y determina el campeón.

**Materia:** Fundamentos de Programación

| Integrante | Casos asignados |
|------------|-----------------|
| Wilmer Gulcochía | CASO 1 (Registrar equipo) + CASO 4 (Buscar equipo) |
| Marco Chile | CASO 2 (Registrar partido) + CASO 5 (Mostrar campeón) |
| Miriam Huamán | CASO 3 (Tabla de posiciones) |

---

## 📋 Funcionalidades

| # | Opción | Descripción |
|---|--------|-------------|
| 1 | Registrar equipo | Agrega un nuevo equipo al torneo (máx. 4) |
| 2 | Registrar partido | Ingresa resultado y actualiza estadísticas de ambos equipos |
| 3 | Tabla de posiciones | Muestra PJ, PG, PE, PP, GF, GC y Puntos de todos los equipos |
| 4 | Buscar equipo | Consulta las estadísticas de un equipo por nombre |
| 5 | Mostrar campeón | Muestra el equipo con más puntos acumulados |
| 0 | Salir | Cierra el programa |

---

## ⚙️ Requerimientos Técnicos

El programa implementa **exclusivamente** los siguientes elementos, sin uso de arreglos, structs ni funciones externas:

| Elemento | Uso en el programa |
|---|---|
| `const` | `MAX_EQUIPOS = 4` como límite fijo del torneo |
| Variables globales | 32 variables atómicas (`e1_nombre`, `e1_pj` ... `e4_puntos`) + `numEquipos` |
| `do-while` | Validación de entrada (registro de equipos y datos de partidos) |
| `while` | Validación del tipo de selección de equipos en el menú |
| `if-else` | Lógica de victoria/empate/derrota y asignación de equipos |
| `if-else if` en cascada | Sustituto de arreglos para mapear cada equipo individualmente |
| `switch` | Menú principal de opciones |

> ⚠️ **Restricción del enunciado:** No se usan `struct`, arreglos, ni funciones externas al `main()`. Toda la lógica está dentro del `switch-case` monolítico.

---

## 🚀 Compilar y Ejecutar

```bash
# Compilar
g++ project_04.cpp -o project_04

# Ejecutar
./project_04
```

> ⚠️ **Nota:** Los nombres de equipos no deben tener espacios. Usa guion bajo si necesitas dos palabras: `Real_Madrid`

---

## 📁 Estructura del Proyecto

```
torneo-futbol-p4/
├── project_04.cpp         ← Código fuente principal (implementación completa)
├── .gitignore             ← Excluye binarios y backups
├── README.md              ← Este archivo
└── docs/
    ├── projecto4.md       ← Guía del proyecto (Scrum, diagramas, pseudocódigo)
    └── github-workflow.md ← Flujo de trabajo con Git y GitHub
```

---

## 📚 Documentación

| Documento | Contenido |
|-----------|-----------|
| [📘 Guía del Proyecto](docs/projecto4.md) | Backlog, Sprint Planning, ramas Git, diagramas de flujo y pseudocódigo completo |
| [📙 Flujo de Trabajo Git](docs/github-workflow.md) | Paso a paso de cómo trabajar con ramas, commits y Pull Requests |

---

## 🌿 Estrategia de Ramas

```bash
main
├── feature/HU-01-registro-equipos     ← Wilmer
├── feature/HU-02-registro-partidos    ← Marco
├── feature/HU-03-tabla-posiciones     ← Miriam
├── feature/HU-04-buscar-equipo        ← Wilmer
└── feature/HU-05-mostrar-campeon      ← Marco
```

Cada integrante trabaja en su rama y abre un **Pull Request** cuando termina su caso asignado.

---

## 📦 Entregables del Proyecto

| # | Entregable | Ubicación | Estado |
|---|-----------|-----------|--------|
| 1 | Diagrama de flujo — Registro de partidos | [projecto4.md → FASE 3](docs/projecto4.md) | ✅ Listo |
| 2 | Diagrama de flujo — Actualización de puntos | [projecto4.md → FASE 4](docs/projecto4.md) | ✅ Listo |
| 3 | Pseudocódigo del sistema completo | [projecto4.md → FASE 5](docs/projecto4.md) | ✅ Listo |
| 4 | Código C++ | `project_04.cpp` | ✅ Completado |
| 5 | Ejecución del programa | Se graba al presentar | ⏳ Pendiente |

---

## 📝 Estado del Proyecto

- [x] Variables globales: 32 variables atómicas + `MAX_EQUIPOS` + `numEquipos`
- [x] CASO 1: Registrar equipo con validación de límite y duplicados
- [x] CASO 2: Registrar partido con actualización de estadísticas cruzadas
- [x] CASO 3: Tabla de posiciones con todos los equipos registrados
- [x] CASO 4: Búsqueda de equipo por nombre con estadísticas completas
- [x] CASO 5: Determinación del campeón por mayor puntaje
- [x] Menú principal con `do-while` + `switch`
