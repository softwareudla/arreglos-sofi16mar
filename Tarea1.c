// Juan José Espinosa y Sofía Martínez

#include <stdio.h>
 
int main() {
    int notas[5][3];
    int i, j, suma, mayornota, menornota;
    float promedioest[5];
    float promediomat[3];
    int aprobados[3] = {0, 0, 0};
    int reprobados[3] = {0, 0, 0};
 
    // Ingresar notas
    for (i = 0; i < 5; i++) {
        printf("Ingrese las calificación del estudiante %d:\n", i+1);
        for (j = 0; j < 3; j++) {
            do {
                printf("Materia %d (0-10): ", j+1);
                scanf("%d", &notas[i][j]);
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
    printf("\n");
    // Calcular el promedio de cada estudiante
    for (i = 0; i < 5; i++) {
        suma = 0;
        for (j = 0; j < 3; j++) {
            suma += notas[i][j];
        }
        promedioest[i] = suma / 3.0;
        printf("El promedio del estudiante %d es: %.2f\n", i+1, promedioest[i]);
    }
    printf("\n");
   
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
        printf("El promedio de la materia %d es: %.2f\n", j+1, promediomat[j]);
        printf("Materia %d: %d aprobados, %d reprobados\n", j+1, aprobados[j], reprobados[j]);
    }
    printf("\n");
    // Calcular nota max y min por estudiante
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
        printf("Estudiante %d: Máxima Nota = %d, Mínima Nota = %d\n", i+1, mayornota, menornota);
    }
    printf("\n");
    // Calcular nota max y min por materia
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
        printf("Materia %d: Máxima Nota = %d, Mínima Nota = %d\n", j+1, mayornota, menornota);  
    }
 
    return 0;
}