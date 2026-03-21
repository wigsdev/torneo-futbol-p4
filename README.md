# 🏆 Proyecto 4: Simulador de Torneo de Fútbol

> Programa en C++ que simula un torneo de fútbol: registra equipos y partidos, genera la tabla de posiciones, permite buscar equipos y determina el campeón.

**Materia:** Fundamentos de Programación  
**Equipo:**

| Integrante | Funciones asignadas |
|------------|---------------------|
| Wilmer Gulcochía | `registrarEquipo()` + `buscarEquipo()` |
| Marco Chile | `registrarPartido()` + `mostrarCampeon()` |
| Miriam Huamán | `mostrarTabla()` |

---

## 📋 Funcionalidades

| # | Opción | Descripción |
|---|--------|-------------|
| 1 | Registrar equipo | Agrega un nuevo equipo al torneo |
| 2 | Registrar partido | Ingresa resultado y actualiza estadísticas |
| 3 | Tabla de posiciones | Muestra PJ, PG, PE, PP, GF, GC y Puntos |
| 4 | Buscar equipo | Consulta las estadísticas de un equipo por nombre |
| 5 | Mostrar campeón | Muestra el equipo con más puntos |
| 0 | Salir | Cierra el programa |

---

## ⚙️ Requerimientos Técnicos

El programa implementa los siguientes elementos del enunciado:

- `const` → `MAX_EQUIPOS = 10`
- Variables globales → `equipos[]`, `numEquipos`
- Variables locales → dentro de cada función (`n1`, `g1`, `idx1`, etc.)
- `if-else` → lógica de victoria/empate/derrota y validaciones
- `switch` → menú principal
- `for` → búsqueda de equipos y tabla de posiciones
- `while` → búsqueda en `buscarEquipo()`
- `do-while` → ciclo del menú principal

**Conceptos adicionales utilizados:**
- `struct` → estructura `Equipo` que agrupa todos los datos de un equipo
- Arreglos → `Equipo equipos[MAX_EQUIPOS]`
- Funciones → modularización del código para trabajo en equipo

---

## 🚀 Compilar y Ejecutar

```bash
# Compilar
g++ proyecto4.cpp -o proyecto4

# Ejecutar
./proyecto4
```

> ⚠️ **Nota:** Los nombres de equipos no deben tener espacios. Usa guion bajo si necesitas dos palabras: `Real_Madrid`

---

## 📁 Estructura del Proyecto

```
torneo-futbol-p4/
├── proyecto4.cpp          ← Código fuente principal
├── .gitignore             ← Excluye binarios y backups
├── README.md              ← Este archivo
└── docs/
    ├── projecto4.md       ← Guía del proyecto (Scrum, diagramas, pseudocódigo)
    ├── funciones.md       ← Explicación de struct, arreglos y funciones
    └── github-workflow.md ← Flujo de trabajo con Git y GitHub
```

---

## 📚 Documentación

| Documento | Contenido |
|-----------|-----------|
| [📘 Guía del Proyecto](docs/projecto4.md) | Backlog, Sprint Planning, ramas Git, diagramas de flujo y pseudocódigo completo |
| [📗 Conceptos Técnicos](docs/funciones.md) | Explicación de funciones, struct y arreglos con ejemplos del proyecto |
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

Cada integrante trabaja en su rama y abre un **Pull Request** cuando termina su función.

---

## 📦 Entregables del Proyecto

| # | Entregable | Ubicación | Estado |
|---|-----------|-----------|--------|
| 1 | Diagrama de flujo — Registro de partidos | [projecto4.md → FASE 3](docs/projecto4.md) | ✅ Listo |
| 2 | Diagrama de flujo — Actualización de puntos | [projecto4.md → FASE 4](docs/projecto4.md) | ✅ Listo |
| 3 | Pseudocódigo del sistema completo | [projecto4.md → FASE 5](docs/projecto4.md) | ✅ Listo |
| 4 | Código C++ | `proyecto4.cpp` | 🔨 En desarrollo |
| 5 | Ejecución del programa | Se graba al finalizar el código | ⏳ Pendiente |

> 💡 Los entregables 1, 2 y 3 ya están documentados en `docs/projecto4.md`. El equipo debe enfocarse en completar el código C++ (entregable 4).

---

## 📝 Estado del Proyecto

- [x] Scaffold base: struct, globales, prototipos, main, mostrarMenu
- [ ] HU-01: `registrarEquipo()` — Wilmer
- [ ] HU-02: `registrarPartido()` — Marco
- [ ] HU-03: `mostrarTabla()` — Miriam
- [ ] HU-04: `buscarEquipo()` — Wilmer
- [ ] HU-05: `mostrarCampeon()` — Marco
