#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100


typedef struct  {
    int num_at;
    char name[20];
    char abbrev[20];
    float mass_atom;
}Element;


void scan_table(Element tav[], const int len_element[], float risutaldo, int len) {
    printf("Peso atomico del composto ");

    for (int i = 0; i < len; i++) {
        printf("%s%d", tav[i].abbrev, len_element[i]);
    }

    printf(": %.3f\n", risutaldo);
}

float scan_request(Element tavfinal[], int len, const int len_element[]) {
    float result = 0;
    for (int i = 0; i < len; i++) {
        result += tavfinal[i].mass_atom * (float)len_element[i];
    }
    return result;
}

void print_table(int len, Element tavv[]) {
    for (int i = 0; i < len; i++) {
        printf("%d %s %s %f\n",
               tavv[i].num_at,
               tavv[i].name,
               tavv[i].abbrev,
               tavv[i].mass_atom);
    }
}

int load_element(FILE* file, int len, Element tav[]) {

    int count = 0;
    char line[100];
    fgets(line, sizeof(line), file);

    while (count < len && fgets(line, sizeof(line), file)) {

        if (sscanf(line, "%d %19s %19s %f",
                   &tav[count].num_at,
                   tav[count].name,
                   tav[count].abbrev,
                   &tav[count].mass_atom) == 4) {

            count++;
                   } else {
                       fclose(file);
                       return -1;
                   }
    }

    return count;
}


int main() {
    int len_total_elements;
    Element tavola[MAX_LEN];
    Element tavola_tasq[MAX_LEN];
    char risposta_tasquiera;
    int count = 0;
    int aux = 0;
    int volte_add[MAX_LEN];
    float risultado_finale;

    FILE* file = fopen("C:/Users/Cliente/Downloads/tavola_elementi.txt", "r");
    if (!file) {
        printf("Error open the txt!\n");
        return 1;
    }

    int count_t = load_element(file, MAX_LEN, tavola);

    print_table(count_t, tavola);

    while (count < count_t) {

        printf("\n");
        printf("Vuoi inserire questo elemento:\n");
        printf("%s %.3f\n", tavola[count].abbrev, tavola[count].mass_atom);
        printf("y - yes  n - no:\n\n");

        scanf(" %c", &risposta_tasquiera);

        if (!(risposta_tasquiera == 'y' || risposta_tasquiera == 'n')) {
            printf("Per cortesia inserire un carattere valido:\n");
            continue;
        }

        if (risposta_tasquiera == 'y') {

            printf("Quante volte vuoi inserire questo elemento:\n");

            if (scanf("%d", &volte_add[aux]) != 1 || volte_add[aux] == 0) {
                printf("Inserire un numero valido e non zero!\n");
                while (getchar() != '\n');
                continue;
            }

            tavola_tasq[aux].num_at = tavola[count].num_at;
            strcpy(tavola_tasq[aux].name, tavola[count].name);
            strcpy(tavola_tasq[aux].abbrev, tavola[count].abbrev);
            tavola_tasq[aux].mass_atom = tavola[count].mass_atom;

            aux++;
            count++;
        }

        if (risposta_tasquiera == 'n') {
            count++;
        }
    }


    risultado_finale = scan_request(tavola_tasq, count_t, volte_add);
    scan_table(tavola_tasq, volte_add, risultado_finale, aux);


    fclose(file);



}