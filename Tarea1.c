//Juan José Espinosa y Sofía Martínez

#include <stdio.h>

int main() {
    float notas[5][3];
    int i, j;
    float suma=0, mayornota, menornota;
    float promedioest[5];
    float promediomat[3];
    int aprobados[3] = {0, 0, 0};
    int reprobados[3] = {0, 0, 0};
    char nombres[5][20];
    char materia[3][20];
   

    for (i = 0; i < 5 ; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf("%s", nombres[i]);
    }

    printf( "\n" );    

    for (j = 0; j < 3 ; j++) {
        printf("Ingres el nombre de la materia %d: ", j + 1);
        scanf("%s", materia[j]);

    }
 

    // Ingresar calificaciones
    for (i = 0; i < 5; i++) {
        printf("Ingrese las calificación del estudiante %s:\n", nombres[i]);
        for (j = 0; j < 3; j++) {
            do {
                printf("Materia %s (0-10): ",materia[j]);
                scanf("%f", &notas[i][j]);
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }

    printf("\n");

    // Calcular Promedio de Cada Estudiante
    for (i = 0; i < 5; i++) {
        suma = 0;
        for (j = 0; j < 3; j++) {
            suma += notas[i][j];
        }
        promedioest[i] = suma / 3.0;
        printf("El promedio del estudiante %s es: %.2f\n", nombres[i], promedioest[i]);
    }

      printf("\n");

    // Calcular Promedio de Cada Materia
    for (j = 0; j < 3; j++) {
        suma = 0;  
        for (i = 0; i < 5; i++) {
            suma += notas[i][j];
            if (notas[i][j] >= 6) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
        promediomat[j] = suma / 5.0;
        printf("El promedio de la materia %s es: %.2f\n", materia[j], promediomat[j]);
        printf("Materia %s: %d aprobados, %d reprobados\n", materia[j], aprobados[j], reprobados[j]);
    }
   
    printf("\n");
   
    // Calcular Nota Max y Min por Estudiante
    for(i = 0; i < 5; i++) {
        mayornota = notas[i][0];
        menornota = notas[i][0];
        for(j = 0; j < 3; j++) {
            if(mayornota < notas[i][j]) {
                mayornota = notas[i][j];
            }
            if(menornota > notas[i][j]) {
                menornota = notas[i][j];
            }
        }
        printf("Estudiante %s: Máxima Nota = %.2f, Mínima Nota = %.2f\n", nombres[i], mayornota, menornota);
    }
   
    printf("\n");
   
    // Calcular Nota Max y Min por Materia
    for(j = 0; j < 3; j++) {
        mayornota = notas[0][j];
        menornota = notas[0][j];
        for(i = 0; i < 5; i++) {
            if(mayornota < notas[i][j]) {
                mayornota = notas[i][j];
            }
            if(menornota > notas[i][j]) {
                menornota = notas[i][j];    
            }
        }
        printf("Materia %s: Máxima Nota = %.2f, Mínima Nota = %.2f\n", materia[j], mayornota, menornota);  
    }

    return 0;
}
