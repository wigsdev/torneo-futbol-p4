/*
 * ============================================================
 *  PROYECTO 4: Simulador de Torneo de Fútbol
 * ============================================================
 *  Materia : Fundamentos de Programación
 *  Equipo  : Wilmer Gulcochía | Marco Chile | Miriam Huamán
 * ============================================================
 *
 *  DISTRIBUCIÓN DE TRABAJO:
 *  - Wilmer Gulcochía → registrarEquipo() + buscarEquipo()
 *  - Marco Chile      → registrarPartido() + mostrarCampeon()
 *  - Miriam Huamán    → mostrarTabla()
 *
 *  REQUERIMIENTOS TÉCNICOS:
 *  const | variables globales y locales | if-else | switch | for | while |
 * do-while
 *
 *  CONCEPTOS ADICIONALES (ver funciones.md):
 *  struct | arreglos | funciones
 * ============================================================
 */

#include <iostream>
#include <string>

using namespace std;

// ============================================================
//  CONSTANTE (requerimiento técnico: const)
//  Define el máximo de equipos permitidos. No cambia nunca.
// ============================================================
const int MAX_EQUIPOS = 10;

// ============================================================
//  ESTRUCTURA: Equipo
//  Agrupa toda la información de un equipo en un bloque.
//  Todos los campos numéricos se inicializan en 0.
//
//  pj = Partidos Jugados    pg = Partidos Ganados
//  pe = Partidos Empatados  pp = Partidos Perdidos
//  gf = Goles a Favor       gc = Goles en Contra
// ============================================================
struct Equipo {
  string nombre;
  int pj = 0;
  int pg = 0;
  int pe = 0;
  int pp = 0;
  int gf = 0;
  int gc = 0;
  int puntos = 0;
};

// ============================================================
//  VARIABLES GLOBALES (requerimiento técnico: variables globales)
//  Son accesibles desde TODAS las funciones del programa.
//
//  equipos[]  → El arreglo principal. Acceso: equipos[i].nombre
//  numEquipos → Cuántos equipos hay. Empieza en 0.
// ============================================================
Equipo equipos[MAX_EQUIPOS];
int numEquipos = 0;

// ============================================================
//  PROTOTIPOS DE FUNCIONES
//  Declaración anticipada. Van ANTES del main().
// ============================================================
void mostrarMenu();
void registrarEquipo();  // Wilmer
void registrarPartido(); // Marco
void mostrarTabla();     // Miriam
void buscarEquipo();     // Wilmer
void mostrarCampeon();   // Marco

// ============================================================
//  main(): controla el flujo del programa.
//  *** NO MODIFICAR ESTA FUNCIÓN ***
//  Usa do-while + switch (requerimientos técnicos)
// ============================================================
int main() {

  int opcion; // Variable LOCAL

  do {
    mostrarMenu();
    cin >> opcion;

    switch (opcion) {
    case 1:
      registrarEquipo();
      break;
    case 2:
      registrarPartido();
      break;
    case 3:
      mostrarTabla();
      break;
    case 4:
      buscarEquipo();
      break;
    case 5:
      mostrarCampeon();
      break;
    case 0:
      cout << "\nSaliendo del sistema..." << endl;
      break;
    default:
      cout << "\nOpcion invalida. Intente de nuevo." << endl;
    }

  } while (opcion != 0);

  return 0;
}

// ============================================================
//  DEFINICIÓN DE FUNCIONES
//  Cada integrante desarrolla SU función aquí abajo.
//  NO modificar las funciones de los demás.
// ============================================================

// ------------------------------------------------------------
//  mostrarMenu() — YA ESTÁ COMPLETA, no modificar.
// ------------------------------------------------------------
void mostrarMenu() {
  cout << "\n=== SIMULADOR DE TORNEO DE FUTBOL ===" << endl;
  cout << "1. Registrar equipo" << endl;
  cout << "2. Registrar partido" << endl;
  cout << "3. Mostrar tabla de posiciones" << endl;
  cout << "4. Buscar equipo" << endl;
  cout << "5. Mostrar campeon" << endl;
  cout << "0. Salir" << endl;
  cout << "Seleccione: ";
}

// ------------------------------------------------------------
//  registrarEquipo() → WILMER GULCOCHÍA
//
//  PISTA:
//  1. Verifica con if-else que numEquipos < MAX_EQUIPOS
//  2. Si hay espacio: pide el nombre con cin
//     Guarda en: equipos[numEquipos].nombre
//     Luego: numEquipos++
//  3. Si no hay espacio: muestra un mensaje de error
// ------------------------------------------------------------
void registrarEquipo() {
  // TODO: Wilmer - escribe tu código aquí
  if (numEquipos < MAX_EQUIPOS) {
    cout << "Ingrese el nombre del equipo: ";
    cin >> equipos[numEquipos].nombre;
    numEquipos++;
    cout << "Equipo registrado exitosamente." << endl;
  } else {
    cout << "No se pueden registrar mas equipos." << endl;
  }
}

// ------------------------------------------------------------
//  registrarPartido() → MARCO CHILE
//
//  PISTA:
//  1. Verifica que numEquipos >= 2 (necesitas al menos 2 equipos)
//  2. Muestra la lista de equipos con un FOR
//  3. Pide el nombre del Equipo 1 y Equipo 2
//  4. Busca sus índices en el arreglo con FOR (idx1 e idx2, inician en -1)
//  5. Valida con if-else que ambos existan y no sean el mismo
//  6. Pide los goles (g1, g2)
//  7. Actualiza: gf, gc, pj de ambos equipos
//  8. Determina el resultado con if-else:
//     g1 > g2 → Equipo1 gana (+3 pts), Equipo2 pierde
//     g1 < g2 → Equipo2 gana (+3 pts), Equipo1 pierde
//     g1 == g2 → Empate (+1 pt cada uno)
// ------------------------------------------------------------
void registrarPartido() {
  // TODO: Marco - escribe tu código aquí
  int equipo1, equipo2;
  cout << "=== Registro de partidos ===" << endl;
  cout << "elige una opcion para ejecutar\n 1. registrar equipo 1 " << endl;
  cin >> equipo1;
  cout << "elige una opcion para ejecutar\n 2. registrar equipo 2 " << endl;
  cin >> equipo2;
}

// ------------------------------------------------------------
//  mostrarTabla() → MIRIAM HUAMÁN
//
//  PISTA:
//  1. Imprime el encabezado de la tabla:
//     EQUIPO  PJ  PG  PE  PP  GF  GC  PTS
//  2. Usa un FOR desde i=0 hasta i<numEquipos
//  3. En cada vuelta imprime todos los datos de equipos[i]
//  4. Usa '\t' (tabulador) para separar columnas y alinearlas
// ------------------------------------------------------------
void mostrarTabla() {
  // TODO: Miriam - escribe tu código aquí
}

// ------------------------------------------------------------
//  buscarEquipo() → WILMER GULCOCHÍA
//
//  PISTA:
//  1. Pide el nombre a buscar con cin
//  2. Declara: bool encontrado = false; int i = 0;
//     ('bool' es un tipo que solo puede ser true o false)
//  3. Usa WHILE: while (i < numEquipos && !encontrado)
//     '!' significa "no". !encontrado = "aún no fue encontrado"
//  4. Si equipos[i].nombre == buscado:
//     Muestra los datos del equipo y pon encontrado = true
//  5. SIEMPRE incrementa i++ dentro del while
//  6. Si !encontrado al salir, muestra "No encontrado"
// ------------------------------------------------------------
void buscarEquipo() {
  // TODO: Wilmer - escribe tu código aquí
  // Nota: 'bool' es el tipo de dato para valores true/false,
  // se vio en clase como tipo de dato básico de C++.
}

// ------------------------------------------------------------
//  mostrarCampeon() → MARCO CHILE
//
//  PISTA:
//  1. Verifica que numEquipos > 0
//  2. Declara: int c = 0; (c es el índice del campeón actual)
//  3. Usa FOR desde i=1 hasta i<numEquipos
//  4. Si equipos[i].puntos > equipos[c].puntos → c = i
//  5. Al terminar el for, equipos[c] es el campeón
//  6. Muestra el nombre y los puntos del campeón
// ------------------------------------------------------------
void mostrarCampeon() {
  // TODO: Marco - escribe tu código aquí
}
