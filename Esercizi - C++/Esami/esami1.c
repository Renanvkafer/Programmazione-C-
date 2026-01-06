#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINT 10


typedef struct {
    float x;
    float y;
    float z;
    char color[20];
}Punti;


int carica_dati(FILE *file, Punti punti[][20], int len) {
    char line[20];
    int count = 0;
    float x, y, z;
    char color[20];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%f %f %f %19s", &x, &y, &z, color) == 4) {
            punti[count][0].x = x;
            punti[count][0].y = y;
            punti[count][0].z = z;
            strcpy(punti[count][0].color, color);
            count++;
        }
    }
    return count;
}

int calcula_punti(Punti punti[][20], int len, char lettera, Punti punti1[][MAX_POINT]) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if(strchr(punti[i][0].color, lettera) != NULL) {
               punti1[count][0].x = punti[i][0].x;
               punti1[count][1].y = punti[i][0].y;
               punti1[count][2].z = punti[i][0].z;
               count++;
        }
    }
    return count;
}

void calculo_real(float matrice[][MAX_POINT], int len, Punti punti[][MAX_POINT]) {
    float aux, aux2 = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            aux = pow((punti[i][0].x - punti[j][0].x), 2) + pow((punti[i][1].y - punti[j][1].y), 2) + pow((punti[i][2].z - punti[j][2].z), 2);
            aux2 = sqrt(aux);
            matrice[i][j] = aux2;
        }
    }
}

void stampa(float matrice[][MAX_POINT], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf("%f\t", matrice[i][j]);
        }
        printf("\n");
    }

}

int main() {
    Punti punti[MAX_POINT][20];
    Punti calculo[MAX_POINT][MAX_POINT];
    int n_punti;
    char lettera;

    FILE *file = fopen("C:/Users/Cliente/Desktop/dados1.txt", "r");
    if (!file) {
        printf("Error\n");
        return -1;
    }

    n_punti = carica_dati(file, punti, MAX_POINT);

    fclose(file);

    int aux = 1;

    while(aux != 0) {
        printf("Inserire una lettera: \n");
        scanf(" %c", &lettera);
        if (lettera >= 'a' && lettera <= 'z') {
            aux = 0;
        }
        else {
            printf("per favore insere una lettera valida: \n");
        }
    }


    int z = calcula_punti(punti, n_punti, lettera, calculo);

    float matrice[z][z];

    calculo_real(matrice, z, calculo);

    stampa(matrice, z);

    return 0;

}