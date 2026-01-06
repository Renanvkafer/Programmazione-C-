#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_RESULT 50

typedef struct {
    int nq;
    char abc[20];
} Domanda;

int fget_answer(FILE *file, Domanda idStud[], Domanda rispoStud[][20],
                Domanda rispo[][20], int len, Domanda *lens) {
    char line[100];
    int count = 0;

    while (count < len && fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        int x;
        char y[20];

        if (sscanf(line, "%d %19s", &x, y) == 2) {
            if (count == 0) {
                strcpy(rispo[count]->abc, y);
                lens->nq = x;
                count++;
            } else {
                idStud[count - 1].nq = x;
                strcpy(rispoStud[count - 1][0].abc, y);
                count++;
            }
        }
    }
    return count;
}

void get_wrong(Domanda rispotStud[][20], int len, Domanda rispota_giusta[][20], float Get_Wrong[]) {
    for (int j = 0; j < 20; j++) {
        Get_Wrong[j] = 0;
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; rispota_giusta[0][0].abc[j] != '\0'; j++) {
            if (rispota_giusta[0][0].abc[j] != rispotStud[i][0].abc[j]) {
                Get_Wrong[j] += 1;
            }
        }
    }

    for (int j = 0; rispota_giusta[0][0].abc[j] != '\0'; j++) {
        Get_Wrong[j] = (Get_Wrong[j] / (float)len) * 100.0;
    }
}

void fwrite_report(FILE *file, Domanda len, Domanda rispott[][20], float Wrong[]) {
    fprintf(file, "Exam Report\n");

    fprintf(file, "Question ");
    for (int i = 0; i < len.nq; i++) {
        fprintf(file, "%d ", i + 1);
    }
    fprintf(file, "\n");

    fprintf(file, "Answer ");
        for (int j = 0; rispott[0][0].abc[j] != '\0'; j++) {
            fprintf(file, "%c ", rispott[0][0].abc[j]);
        }
    fprintf(file, "\n");

    fprintf(file, "Wrong(%%) ");
    for (int i = 0; i < len.nq; i++) {
        fprintf(file, "%.2f ", Wrong[i]);
    }
    fprintf(file, "\n");
}

int main() {
    Domanda id_students[MAX_RESULT];
    Domanda answers[MAX_RESULT][20];
    Domanda coor_answers[MAX_RESULT][20];
    Domanda len_answers;
    float GEt_wrong[MAX_RESULT];

    FILE *file = fopen("C:/Users/Cliente/Downloads/file_essempio3.txt", "r");
    if (!file) {
        printf("Error opening input file!\n");
        return 1;
    }

    int len_students = fget_answer(file, id_students, answers, coor_answers,
                                    MAX_RESULT, &len_answers);

    fclose(file);

    if (len_students < 0) {
        return 1;
    }

    len_students--;

    get_wrong(answers, len_students, coor_answers, GEt_wrong);
    FILE *fileR = fopen("secxo20.txt", "w");
    if (!fileR) {
        printf("Error opening output file!\n");
        return 1;
    }

    fwrite_report(fileR, len_answers, coor_answers, GEt_wrong);

    fclose(fileR);

    return 0;
}