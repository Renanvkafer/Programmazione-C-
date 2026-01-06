#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TESTE 100

typedef struct {
    char teso[50];
    int lung;
} Parola;


int carica_dizionario(const char* filename, int len, Parola p[]) {
    FILE* file = fopen(filename, "r");
    if (!file) return -1;

    char line[100];
    int count = 0;

    fgets(line, sizeof(line), file);

    while (count < len && fgets(line, sizeof(line), file)) {
        char parola[50];
        if (sscanf(line, "%49s", parola) == 1) {
            strcpy(p[count].teso, parola);
            p[count].lung = strlen(parola);
            count++;
        } else {
            fclose(file);
            return -1;
        }
    }

    fclose(file);
    return count;
}

void stampa_dizionario(Parola parola[], int len) {
    int total = 0;
    for (int i = 0; i < len; i++) {
        printf("%d: %s\n", i, parola[i].teso);
        total += parola[i].lung;
    }
    printf(">>> Totale caratteri: %d\n", total);
}

int componi_frase(Parola parole[], int len, int indices[], Parola out[]) {
    int num, count = 0;

    while (1) {
        printf("Inserisci un numero (negativo per terminare): ");
        scanf("%d", &num);

        if (num < 0) break;

        if (num < len) {
            indices[count] = num;
            strcpy(out[count].teso, parole[num].teso);
            out[count].lung = strlen(out[count].teso);
            count++;
        } else {
            printf("Numero ignorato\n");
        }
    }

    return count;
}

Parola* trova_parola_lunga(Parola parola[], int len) {
    Parola* maxPtr = &parola[0];
    for (int i = 1; i < len; i++) {
        if (parola[i].lung > maxPtr->lung) {
            maxPtr = &parola[i];
        }
    }

    return maxPtr;
}


int main() {
    const int MAX_LEN = 50;
    Parola parole[MAX_LEN];
    Parola frase[MAX_LEN];
    int indices[MAX_LEN];

    int len_parola = carica_dizionario("C:/Users/Cliente/Downloads/diz.txt",MAX_LEN, parole);

    stampa_dizionario(parole, len_parola);

    int frase_len = componi_frase(parole, len_parola, indices, frase);

    for (int i = 0; i < frase_len; i++)
        printf("%s ", frase[i].teso);

    printf("\n");

    Parola* lunga = trova_parola_lunga(frase, frase_len);

    if (lunga != NULL) {
        printf("\nParola piu lunga: %s (%d caratteri)\n",
               lunga->teso, lunga->lung);
    }

    return 0;
}
