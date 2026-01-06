#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_RESULT 200

typedef struct {
    char andata[20];
    char ritorno[20];
}Voli;


int load_data(FILE* file, Voli voli[][20], int len) {
    char line[100];
    int count = 0;

    while (count < len && fgets(line, sizeof(line), file)) {
        char x[20];
        char y[20];

        if (sscanf(line, "%19s %19s", x, y) == 2) {
            strcpy(voli[count][0].andata, x);
            strcpy(voli[count][0].ritorno, y);
            count++;
        } else {
            fclose(file);
            return -1;
        }
    }
    return count;
}

int tratte_andata_ritorno(Voli voli[][20], int len, Voli voli_final[][20]) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (strcmp(voli[i][0].andata, voli[j][0].ritorno) == 0 &&
                strcmp(voli[i][0].ritorno, voli[j][0].andata) == 0) {
                strcpy(voli_final[count][0].andata, voli[i][0].andata);
                strcpy(voli_final[count][0].ritorno, voli[i][0].ritorno);
                count++;
                }
        }
    }
    return count;
}


void visualizza_tratte(Voli voli_final[][20], int len) {
    printf("numero di tratte di andata e ritorno: %d", len);
    for (int i = 0; i < len; i++) {
        printf("\n");
        printf("%s", voli_final[i][0].andata);
        printf(" - ");
        printf("%s", voli_final[i][0].ritorno);
    }

}


int main() {
    Voli voli[MAX_RESULT][20];
    int len_voli;
    Voli voli_final[MAX_RESULT][20];


    FILE *file = fopen("C:/Users/Cliente/Downloads/file_essempio2.txt", "r");
        if (!file) {
            printf("Error opening input file!\n");
            return 1;
        }

    len_voli = load_data(file, voli, MAX_RESULT);
    int count_final = tratte_andata_ritorno(voli, len_voli, voli_final);

    visualizza_tratte(voli_final, count_final);

    return 0;
    }


