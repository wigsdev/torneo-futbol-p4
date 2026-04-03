#include <iostream>
#include <string>

using namespace std;

// ── VARIABLES GLOBALES ──────────────────────────────────────────────────────
const int MAX_EQUIPOS = 4;
int numEquipos = 0;

// equipo 01
string e1_nombre = "";
int e1_pj = 0, e1_pg = 0, e1_pe = 0, e1_pp = 0, e1_gf = 0, e1_gc = 0, e1_puntos = 0;

// equipo 02
string e2_nombre = "";
int e2_pj = 0, e2_pg = 0, e2_pe = 0, e2_pp = 0, e2_gf = 0, e2_gc = 0, e2_puntos = 0;

// equipo 03
string e3_nombre = "";
int e3_pj = 0, e3_pg = 0, e3_pe = 0, e3_pp = 0, e3_gf = 0, e3_gc = 0, e3_puntos = 0;

// equipo 04
string e4_nombre = "";
int e4_pj = 0, e4_pg = 0, e4_pe = 0, e4_pp = 0, e4_gf = 0, e4_gc = 0, e4_puntos = 0;

int main() {
    int opcion;

    do {
        cout << "\n=== SIMULADOR DE TORNEO ===" << endl;
        cout << "1. Registrar Equipo" << endl;
        cout << "2. Registrar Partido" << endl;
        cout << "3. Mostrar la tabla" << endl;
        cout << "4. Buscar equipo" << endl;
        cout << "5. Mostrar Campeón" << endl;
        cout << "0. Salir" << endl;
        cout << "\nElegir una opcion: ";
        cin >> opcion;

        switch (opcion) {

            // ✅ CASO 1 - Registrar equipo
            // Requisitos:
            //   - Validar que no haya más de MAX_EQUIPOS (4) registrados
            //   - Pedir el nombre del equipo
            //   - Validar que el nombre no esté repetido
            //   - Guardar en e1/e2/e3/e4 según numEquipos actual
            //   - Incrementar numEquipos
            case 1: {

                string nombreTemp;
                
                if (numEquipos >= MAX_EQUIPOS) {
                    cout << "Límite de equipos alcanzado" <<endl;
                    break;
                }                    
                    cout << "Ingrese el nombre del equipo: ";
                    cin >> nombreTemp;
                
                bool yaExiste = false;

                if (numEquipos >= 1 && nombreTemp == e1_nombre) {
                    yaExiste = true;
                }
                if (numEquipos >= 2 && nombreTemp == e2_nombre) {
                    yaExiste = true;
                }
                if (numEquipos >= 3 && nombreTemp == e3_nombre) {
                    yaExiste = true;
                }
                if (numEquipos >= 4 && nombreTemp == e4_nombre ) {
                    yaExiste = true;
                }
                
                if (yaExiste) {
                    cout << "Este equipo ya está registrado" <<endl;
                } else {
                    if (numEquipos == 0) {
                        e1_nombre = nombreTemp;
                    } else if (numEquipos == 1) {
                        e2_nombre = nombreTemp;
                    } else if (numEquipos == 2) {
                        e3_nombre = nombreTemp;
                    } else if (numEquipos == 3) {
                        e4_nombre = nombreTemp;
                    }

                    numEquipos++;
                    cout << "Equipo registrado exitosamente" << endl;                
                }

                break;
            }

            // ✅ CASO 2 - Registrar partido
            // Requisitos:
            //   - Mostrar los equipos registrados y pedir local y visitante
            //   - Validar que sean distintos y que estén registrados
            //   - Pedir goles del local y del visitante
            //   - Determinar ganador, perdedor o empate
            //   - Actualizar: PJ, PG, PE, PP, GF, GC, Puntos de cada equipo
            // Mejoras
            // 1. Fixture

            case 2: {
                if (numEquipos < 2) {
                    cout << "Se necesita al menos dos equipos";
                    break;
                }
                // Mostrar equipos disponibles
                if (numEquipos >= 1) {
                    cout << "1. " << e1_nombre << endl;
                }
                if (numEquipos >= 2) {
                    cout << "2. " << e2_nombre << endl;
                }
                if (numEquipos >= 3) {
                    cout << "3. " << e3_nombre << endl;
                }
                if (numEquipos >= 4) {
                    cout << "4. " << e4_nombre << endl;
                }

                int indiceE1, indiceE2, golesE1, golesE2;

                cout << "\nEquipo 1 (ingrese número): ";
                cin >> indiceE1;
                cout << "Equipo 2 (ingrese número): ";
                cin >> indiceE2;

                // Validad equipos

                if (indiceE1 < 1 || indiceE1 > numEquipos || indiceE2 < 1 || indiceE2 > numEquipos || indiceE1 == indiceE2) {
                    cout <<"Error en la seleccion de equipos";
                    break;
                }

                cout << "Ingrese goles del equipo 1: ";
                cin >> golesE1;
                cout << "Ingrese goles del equipo 2: ";
                cin >> golesE2;

                // Actualizar estadisticas del equipo local (indiceE1)

                if (indiceE1 == 1) {
                    e1_pj++;
                    e1_gf += golesE1;
                    e1_gc += golesE2;
                    if (golesE1 > golesE2) {
                        e1_pg++;
                        e1_puntos += 3;
                    } else if (golesE1 == golesE2) {
                        e1_pe++;
                        e1_puntos += 1;                    
                    } else {
                        e1_pp++;
                    }
                } else if (indiceE1 == 2) {
                    e2_pj++;
                    e2_gf += golesE1;
                    e2_gc += golesE2;
                    if (golesE1 > golesE2) {
                        e2_pg++;
                        e2_puntos += 3;
                    } else if (golesE1 == golesE2) {
                        e2_pe++;
                        e2_puntos += 1;                    
                    } else {
                        e2_pp++;
                    }
                } else if (indiceE1 == 3) {
                    e3_pj++;
                    e3_gf += golesE1;
                    e3_gc += golesE2;
                    if (golesE1 > golesE2) {
                        e3_pg++;
                        e3_puntos += 3;
                    } else if (golesE1 == golesE2) {
                        e3_pe++;
                        e3_puntos += 1;                    
                    } else {
                        e3_pp++;
                    }
                
                } else if (indiceE1 == 4) {
                    e4_pj++;
                    e4_gf += golesE1;
                    e4_gc += golesE2;
                    if (golesE1 > golesE2) {
                        e4_pg++;
                        e4_puntos += 3;
                    } else if (golesE1 == golesE2) {
                        e4_pe++;
                        e4_puntos += 1;                    
                    } else {
                        e4_pp++;
                    }
                }

                // Actualizar estadisticas del equipo visitantes (indiceE2)
                if (indiceE2 == 1) {
                    e1_pj++;
                    e1_gf += golesE2;
                    e1_gc += golesE1;
                    if (golesE2 > golesE1) {
                        e1_pg++;
                        e1_puntos += 3;
                    } else if (golesE2 == golesE1) {
                        e1_pe++;
                        e1_puntos += 1;                    
                    } else {
                        e1_pp++;
                    }
                } else if (indiceE2 == 2) {
                    e2_pj++;
                    e2_gf += golesE2;
                    e2_gc += golesE1;
                    if (golesE2 > golesE1) {
                        e2_pg++;
                        e2_puntos += 3;
                    } else if (golesE2 == golesE1) {
                        e2_pe++;
                        e2_puntos += 1;                    
                    } else {
                        e2_pp++;
                    }
                } else if (indiceE2 == 3) {
                    e3_pj++;
                    e3_gf += golesE2;
                    e3_gc += golesE1;
                    if (golesE2 > golesE1) {
                        e3_pg++;
                        e3_puntos += 3;
                    } else if (golesE2 == golesE1) {
                        e3_pe++;
                        e3_puntos += 1;                    
                    } else {
                        e3_pp++;
                    }
                
                } else if (indiceE2 == 4) {
                    e4_pj++;
                    e4_gf += golesE2;
                    e4_gc += golesE1;
                    if (golesE2 > golesE1) {
                        e4_pg++;
                        e4_puntos += 3;
                    } else if (golesE2 == golesE1) {
                        e4_pe++;
                        e4_puntos += 1;                    
                    } else {
                        e4_pp++;
                    }
                }

                cout << "Partido registrado exitosamente" << endl;
                break;

            }

            // ✅ CASO 3 - Mostrar tabla de posiciones
            // Requisitos:
            //   - Mostrar encabezado: Equipo | PJ | PG | PE | PP | GF | GC | Pts
            //   - Mostrar datos de cada equipo registrado
            //   - (Opcional avanzado: ordenar por puntos)
            // Mejoras
            // 1. Ordenar la tabla de acuerdo a los puntos
            case 3: {
                cout << "------------------------------------------------" << endl;
                cout << "Equipo \t| PJ | PG | PE | PP | GF  | GC  | Puntos |" << endl;
                cout << "------------------------------------------------" << endl;
                if (numEquipos >= 1) {
                    cout << e1_nombre << "\t| " << e1_pj << "  | " << e1_pg << "  | " << e1_pe << "  | " << e1_pp << "  | " << e1_gf << "  | " << e1_gc << "  | " << e1_puntos << "      | " << endl;              
                }
                if (numEquipos >= 2) { 
                    cout << e2_nombre << "\t| " << e2_pj << "  | " << e2_pg << "  | " << e2_pe << "  | " << e2_pp << "  | " << e2_gf << "  | " << e2_gc << "  | " << e2_puntos << "      | " << endl;              
                }
                if (numEquipos >= 3) { 
                    cout << e3_nombre << "\t| " << e3_pj << "  | " << e3_pg << "  | " << e3_pe << "  | " << e3_pp << "  | " << e3_gf << "  | " << e3_gc << "  | " << e3_puntos << "      | " << endl;              
                }
                if (numEquipos >= 4) { 
                    cout << e4_nombre << "\t| " << e4_pj << "  | " << e4_pg << "  | " << e4_pe << "  | " << e4_pp << "  | " << e4_gf << "  | " << e4_gc << "  | " << e4_puntos << "      | " << endl;              
                }
                break;
            }

            // ✅ CASO 4 - Buscar equipo
            // Requisitos:
            //   - Pedir nombre del equipo a buscar
            //   - Comparar con e1/e2/e3/e4 nombre
            //   - Si existe: mostrar sus estadísticas completas
            //   - Si no existe: mostrar mensaje de "no encontrado"
            case 4: {
                string nombreBuscado;
                cout << "Escriba el nombre a buscar: ";
                cin >> nombreBuscado;

                cout << "------------------------------------------------" << endl;
                cout << "Equipo \t| PJ | PG | PE | PP | GF  | GC  | Puntos |" << endl;
                cout << "------------------------------------------------" << endl;

                if (numEquipos >= 1 && nombreBuscado == e1_nombre) {
                    cout << e1_nombre << "  | " << e1_pj << "  | " << e1_pg << "  | " << e1_pe << "  | " << e1_pp << "  | " << e1_gf << "  | " << e1_gc << "  | " << e1_puntos << "      | " << endl;
                    
                } else if (numEquipos >= 2 && nombreBuscado == e2_nombre) {
                    cout << e2_nombre << "\t| " << e2_pj << "  | " << e2_pg << "  | " << e2_pe << "  | " << e2_pp << "  | " << e2_gf << "  | " << e2_gc << "  | " << e2_puntos << "      | " << endl;
                    
                
                } else if (numEquipos >= 3 && nombreBuscado == e3_nombre) {
                    cout << e3_nombre << "\t| " << e3_pj << "  | " << e3_pg << "  | " << e3_pe << "  | " << e3_pp << "  | " << e3_gf << "  | " << e3_gc << "  | " << e3_puntos << "      | " << endl;
                    
                } else if (numEquipos >= 4 && nombreBuscado == e4_nombre) {
                    cout << e4_nombre << "\t| " << e4_pj << "  | " << e4_pg << "  | " << e4_pe << "  | " << e4_pp << "  | " << e4_gf << "  | " << e4_gc << "  | " << e4_puntos << "      | " << endl;
                    
                } else {
                    cout << "Equipo no encontrado";
                }
                break;
            }

            // ✅ CASO 5 - Mostrar campeón
            // Requisitos:
            //   - Comparar puntos de todos los equipos registrados
            //   - Determinar cuál tiene más puntos
            //   - Mostrar nombre del campeón y sus estadísticas
            //   - Validar que haya al menos 1 equipo registrado
            // mejora
            // Mostrar tabla
            case 5: {
                if (numEquipos == 0) {
                    cout << "No hay equipos registrados";
                    break;
                }
                // Asumir que el primero es el campeón
                string campeon_nombre;
                int max_puntos;
                campeon_nombre = e1_nombre;
                max_puntos = e1_puntos;

                // comparar con los otros equipos si existen
                if (numEquipos >= 2 && e2_puntos > max_puntos) {
                    campeon_nombre = e2_nombre;
                    max_puntos = e2_puntos;
                }
                if (numEquipos >= 3 && e3_puntos > max_puntos) {
                    campeon_nombre = e3_nombre;
                    max_puntos = e3_puntos;
                }
                if (numEquipos >= 4 && e4_puntos > max_puntos) {
                    campeon_nombre = e4_nombre;
                    max_puntos = e4_puntos;
                }

                cout << "Campeón: " << campeon_nombre << endl;
                cout << "Puntos: " << max_puntos << endl;
               
                break;
            }

            case 0: {
                cout << "¡Hasta luego!" << endl;
                break;
            }

            default:
                cout << "Opción inválida, intente de nuevo" << endl;
        }

    } while (opcion != 0);

    return 0;
}
