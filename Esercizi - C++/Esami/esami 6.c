#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void stampa_stat(int matriz[][100], char arr[], char patt[]) {
    int patt_len = (int)strlen(patt);
    int arr_len = (int)strlen(arr);

    printf("Matriz binaria:\n");
    for (int i = 0; i < patt_len; i++) {
        char pc = (char)toupper((unsigned char)patt[i]);
        printf("%c: ", pc);
        for (int j = 0; j < arr_len; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

bool calcola_stat(int matriz_b[][100], int lenMax, char patt[], char arr[]) {
    int patt_len = (int)strlen(patt);
    int arr_len = (int)strlen(arr);

    for (int i = 0; i < patt_len; i++) {
        bool found = false;
        for (int j = 0; j < arr_len; j++) {
            if (matriz_b[i][j] == 1) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

void processa_matriz(int matriz_b[][100], char arr[], char patt[]) {
    int patt_len = (int)strlen(patt);
    int arr_len = (int)strlen(arr);

    for (int i = 0; i < patt_len; ++i) {
        char pc = (char)toupper((unsigned char)patt[i]);
        for (int j = 0; j < arr_len; ++j) {
            char ac = (char)toupper((unsigned char)arr[j]);
            matriz_b[i][j] = (ac == pc) ? 1 : 0;
        }
    }
}

int main() {
    const int MAX_LEN = 100;
    int matrix_binari[MAX_LEN][100];
    char sequencia[200];
    char pattern[] = "abcd";

    FILE* file = fopen("C:/Users/Cliente/Downloads/esami6.txt", "r");
    if (!file) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int n;
    if (fscanf(file, "%d", &n) != 1) {
        printf("Erro ao ler o numero de sequencias!\n");
        fclose(file);
        return 1;
    }

    printf("Numero de sequencias: %d\n", n);
    printf("Pattern: %s\n\n", pattern);

    fgetc(file);

    for (int seq_num = 0; seq_num < n; seq_num++) {
        if (fgets(sequencia, sizeof(sequencia), file) == NULL) {
            break;
        }

        sequencia[strcspn(sequencia, "\r\n")] = '\0';

        printf("=== Sequencia %d ===\n", seq_num + 1);
        printf("Conteudo: %s\n", sequencia);

        processa_matriz(matrix_binari, sequencia, pattern);

        bool is_or_not = calcola_stat(matrix_binari, MAX_LEN, pattern, sequencia);

        if (is_or_not) {
            printf("✓ Todos os caracteres do pattern foram encontrados!\n");
            stampa_stat(matrix_binari, sequencia, pattern);
        } else {
            printf("✗ Pattern nao encontrado completamente\n");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}