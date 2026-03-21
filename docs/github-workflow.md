# 🚀 Guía Completa: De GitHub a Entrega del Proyecto con Scrum

> Esta guía cubre el flujo completo: desde crear la cuenta hasta hacer el último commit del proyecto.

---

## PARTE 1: Configuración Inicial (Solo el Product Owner)

### Paso 1 — Crear el Repositorio en GitHub

1. Ve a [github.com](https://github.com) e inicia sesión.
2. Haz clic en el botón verde **"New"** (o el `+` en la esquina superior derecha → "New repository").
3. Completa el formulario:
   - **Repository name:** `torneo-futbol-p4`
   - **Description:** `Simulador de Torneo de Fútbol - Fundamentos de Programación`
   - **Visibility:** Public (para que el docente pueda verlo)
   - ✅ Marca: **Add a README file**
   - ✅ Marca: **Add .gitignore** → busca y selecciona `C++`
4. Haz clic en **"Create repository"**.

---

### Paso 2 — Crear los Milestones (= Sprints)

1. En tu repositorio, ve a **Issues** → **Milestones** → **New milestone**.
2. Crea el **Sprint 1:**
   - Title: `Sprint 1 - Registro de datos`
   - Due date: *(poner fecha límite del equipo)*
3. Crea el **Sprint 2:**
   - Title: `Sprint 2 - Consultas y campeón`
   - Due date: *(fecha posterior al Sprint 1)*

---

### Paso 3 — Crear las Etiquetas (Labels)

En **Issues** → **Labels** → **New label**, crea estas etiquetas:

| Label | Color | Uso |
|-------|-------|-----|
| `HU` | Azul `#0075ca` | Historia de Usuario |
| `Sprint 1` | Verde `#0e8a16` | Tareas del Sprint 1 |
| `Sprint 2` | Naranja `#e4e669` | Tareas del Sprint 2 |
| `en-progreso` | Amarillo `#fbca04` | Tarea activa |
| `en-revision` | Morado `#d93f0b` | Esperando Pull Request |

---

### Paso 4 — Crear los Issues (= Historias de Usuario)

Para cada HU, ve a **Issues** → **New Issue** y llena así:

#### Issue #1
```
Título: [HU-01] Registrar equipos

Como usuario, quiero registrar equipos para el torneo
para poder simular partidos entre ellos.

Criterios de aceptación:
- [ ] El equipo tiene: nombre, PJ, PG, PE, PP, GF, GC, Puntos
- [ ] No se puede superar MAX_EQUIPOS (10)
- [ ] Se muestra confirmación al registrar

Requerimientos técnicos: struct, arreglo global, const
```
- **Assignee:** Wilmer Gulcochía
- **Labels:** `HU`, `Sprint 1`
- **Milestone:** Sprint 1

#### Issue #2
```
Título: [HU-02] Registrar partido

Como usuario, quiero registrar el resultado de un partido
para actualizar automáticamente las estadísticas de los equipos.

Criterios de aceptación:
- [ ] Pide nombre de ambos equipos y goles de cada uno
- [ ] Victoria = 3 puntos, Empate = 1 punto, Derrota = 0 puntos
- [ ] Actualiza: PJ, PG, PE, PP, GF, GC, Puntos de ambos equipos

Requerimientos técnicos: if-else, variables locales
```
- **Assignee:** Marco Chile
- **Labels:** `HU`, `Sprint 1`
- **Milestone:** Sprint 1

#### Issue #3
```
Título: [HU-03] Mostrar tabla de posiciones

Como usuario, quiero ver la tabla de posiciones
para conocer el rendimiento de cada equipo.

Criterios de aceptación:
- [ ] Muestra columnas: Equipo | PJ | PG | PE | PP | GF | GC | Puntos
- [ ] Muestra todos los equipos registrados

Requerimientos técnicos: for, cout formateado
```
- **Assignee:** Miriam Huamán
- **Labels:** `HU`, `Sprint 2`
- **Milestone:** Sprint 2

#### Issue #4
```
Título: [HU-04] Buscar equipo por nombre

Como usuario, quiero buscar un equipo por su nombre
para ver sus estadísticas individuales.

Criterios de aceptación:
- [ ] Pide el nombre a buscar
- [ ] Si existe, muestra todos sus datos
- [ ] Si no existe, informa al usuario

Requerimientos técnicos: while
```
- **Assignee:** Wilmer Gulcochía
- **Labels:** `HU`, `Sprint 2`
- **Milestone:** Sprint 2

#### Issue #5
```
Título: [HU-05] Mostrar equipo campeón

Como usuario, quiero ver el equipo con más puntos
para conocer al ganador del torneo.

Criterios de aceptación:
- [ ] Identifica el equipo con mayor número de puntos
- [ ] Muestra su nombre y puntos

Requerimientos técnicos: for, comparación
```
- **Assignee:** Marco Chile
- **Labels:** `HU`, `Sprint 2`
- **Milestone:** Sprint 2

---

### Paso 5 — Crear el Tablero Kanban (GitHub Projects)

1. Ve a la pestaña **Projects** → **New project**.
2. Selecciona la plantilla **"Board"** → Nombra: `Torneo Fútbol - Scrum Board`.
3. Modifica las columnas para que queden así:

```
| 📥 Backlog | 🏃 Sprint Actual | 🔨 En Progreso | 👀 En Revisión | ✅ Hecho |
```

4. En la vista del tablero, haz clic en el `+` de cada columna para **conectar los Issues** ya creados.
5. **Mueve los Issues del Sprint 1** a la columna `🏃 Sprint Actual`.

---

## PARTE 2: Invitar al Equipo

### Paso 6 — Agregar colaboradores

1. En tu repositorio → **Settings** → **Collaborators** → **Add people**.
2. Busca por nombre de usuario GitHub de cada integrante.
3. Envía la invitación. Ellos deben aceptarla en su correo.

---

## PARTE 3: Cada Integrante — Configuración Local

### Paso 7 — Clonar el repositorio

Cada integrante abre Git Bash y ejecuta:

```bash
git clone https://github.com/[usuario]/torneo-futbol-p4.git
cd torneo-futbol-p4
```

### Paso 8 — Crear el archivo base (Solo Product Owner una vez)

El Product Owner crea la estructura base del `.cpp` con el `struct`, las variables globales y el `main()` vacío, y lo sube:

```bash
git add proyecto4.cpp
git commit -m "Estructura base: struct Equipo, variables globales y main()"
git push origin main
```

Los demás integrantes actualizan su copia local:
```bash
git pull origin main
```

---

## PARTE 4: Flujo de Desarrollo por Integrante

### Paso 9 — Crear tu rama de trabajo

Cada uno crea su rama para la HU asignada:

```bash
# Wilmer Gulcochía (HU-01 + HU-04):
git checkout -b feature/HU-01-registro-equipos

# Marco Chile (HU-02 + HU-05):
git checkout -b feature/HU-02-registro-partidos

# Miriam Huamán (HU-03):
git checkout -b feature/HU-03-tabla-posiciones
```

> 💡 Mueve tu Issue en el tablero a **"🔨 En Progreso"** cuando empieces.

### Paso 10 — Programar y hacer commits frecuentes

Mientras programas, guarda tu avance con commits:

```bash
git add proyecto4.cpp
git commit -m "HU-01: Función registrarEquipo() - validación de nombre"
git commit -m "HU-01: Función registrarEquipo() completada - closes #1"
```

> 💡 Al escribir `closes #1`, GitHub cerrará el Issue #1 automáticamente al hacer merge.

### Paso 11 — Subir tu rama y abrir un Pull Request

```bash
git push origin feature/HU-01-registro-equipos
```

Luego en GitHub:
1. Aparecerá un banner amarillo → haz clic en **"Compare & pull request"**.
2. Llena el formulario:
   - **Title:** `[HU-01] Función registrarEquipo() implementada`
   - **Description:** Describe qué hiciste y cómo probarlo.
3. Asigna como **Reviewer** a otro integrante del equipo.
4. Haz clic en **"Create pull request"**.

> 💡 Mueve tu Issue en el tablero a **"👀 En Revisión"**.

### Paso 12 — Revisar el Pull Request (otro integrante)

El revisor:
1. Va a la pestaña **Pull requests** → abre el PR.
2. Revisa el código en la pestaña **Files changed**.
3. Si está bien → **"Approve"** → **"Merge pull request"**.
4. Si hay comentarios → deja comentarios en las líneas específicas.

> El Issue se cierra automáticamente y pasa a **"✅ Hecho"** en el tablero.

### Paso 13 — Actualizar rama local antes del siguiente trabajo

Antes de empezar la siguiente HU, todos sincronizan:

```bash
git checkout main
git pull origin main
```

---

## PARTE 5: Sprint Review y Retrospectiva

### Al final del Sprint 1:
1. Revisen el tablero: ¿Están HU-01 y HU-02 en "✅ Hecho"?
2. **Sprint Review:** demuestren el programa funcionando (registrar equipos y partidos).
3. **Retrospectiva (5 minutos):**
   - ✅ ¿Qué salió bien?
   - 🔧 ¿Qué mejoraríamos?
4. Muevan los Issues del Sprint 2 a `🏃 Sprint Actual`.

### Al final del Sprint 2:
1. Misma dinámica con HU-03, HU-04 y HU-05.
2. **Demo final:** el programa completo funcionando.
3. Último commit de cierre:
```bash
git commit -m "Proyecto 4 finalizado - Torneo de Fútbol ✅"
git push origin main
```

---

## 📊 Resumen Visual del Flujo Completo

```
[GitHub] Crear repo → Milestones → Labels → Issues → Project Board
                                                        ↓
[Local] git clone → git pull → git checkout -b feature/HU-XX
                                                        ↓
                           Programar → git add → git commit
                                                        ↓
                           git push → Pull Request en GitHub
                                                        ↓
                           Otro integrante revisa y aprueba
                                                        ↓
                           Merge a main → Issue se cierra ✅
                                                        ↓
                           git checkout main → git pull → siguiente HU
```

---

## 🔗 Links útiles

| Recurso | URL |
|---------|-----|
| Crear repositorio | https://github.com/new |
| Documentación Git | https://git-scm.com/docs |
| GitHub Issues guide | https://docs.github.com/issues |
| GitHub Projects guide | https://docs.github.com/projects |
