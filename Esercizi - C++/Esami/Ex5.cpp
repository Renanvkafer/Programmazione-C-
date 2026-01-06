#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#define  MAX_TESTE 100




struct Parola {
    char teso[50];
    int lung;

};


int carica_dizionario(const char* filename, int len, Parola p[]) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    std::string line;
    std::getline(file, line);
    int count = 0;
    int lung_aux = 0;
    while(count < len && std::getline(file, line)){
        char x[20];
        int y;
        std::istringstream iss(line);
        if (iss >> x) {
            strcpy(p[count].teso, x);
            for (int j = 0; p[count].teso[j] != '\0'; j++) {
                lung_aux++;
            }
            p[count].lung = lung_aux;
            lung_aux = 0;
            count++;
        }
        else {
            std::cout << "File is wrong" << "\n";
            return -1;
        }
    }
    file.close();
    return count;
}

void stampa_dizionario(Parola parola[], int len) {
    int t_lung = 0;
    for (int i = 0; i < len; i++) {
        std::cout << i << ": " << parola[i].teso << "\n";
        t_lung += parola[i].lung;
    }
    std::cout << ">>> Totale caratteri: " <<  t_lung <<"\n";
}

int componi_frase(Parola parola[], int len, int n_parole[], Parola p[]) {
    int param = 0;
    int aux = 0;
    while (param > -1) {
        std::cout << "Per cortesia inserire un numero: " << std::endl;
        std::cin >> param;
        if (len >= param) {
            n_parole[aux] = param;
            aux++;
        }
        else {
            std::cout << "Numero ignorato" << std::endl;
        }
    }
    int lung_aux = 0;
    for (int i = 0; i < aux; i++) {
        int a = n_parole[i];
        strcpy(p[i].teso, parola[a].teso);
        p[i].lung = strlen(parola[a].teso);
        lung_aux = 0;
    }
    return aux;
}

Parola* trova_parola_lunga(Parola parola[],  int len) {
    int aux = 0;
    char parola_piu_grande[20];
    Parola* maxPtr = &parola[0];
    for (int i = 0; i < len; i++) {
        if (parola[i].lung > aux){
            aux = parola[i].lung;
            strcpy(parola_piu_grande, parola[i].teso);
            maxPtr = &parola[i];
        }
    }
    std::cout << "Parola piu grande: " << parola_piu_grande <<std::endl;
    std::cout << "Len parola: " << len << std::endl;
    return maxPtr;
}


int main() {
    constexpr int MAX_LEN = 50;
    Parola parole[MAX_LEN];
    int sg_parole[MAX_LEN];
    Parola ut_parola[MAX_LEN];
    int auxx = 0;
    int len_parola;
    len_parola = carica_dizionario("C:/Users/Cliente/Downloads/diz.txt", MAX_LEN, parole);
    stampa_dizionario(parole, len_parola);
    auxx = componi_frase(parole, len_parola, sg_parole, ut_parola);
    for (int i = 0; i < auxx; i++) {
        std::cout << ut_parola[i].teso << " ";
    }
    std::cout << std::endl;
    Parola* punt_parola_piu_grande = trova_parola_lunga(ut_parola, auxx);
    if (punt_parola_piu_grande != nullptr) {
        std::cout << "\nParola piu lunga: " << punt_parola_piu_grande->teso
                  << " (" << punt_parola_piu_grande->lung << " caratteri)" << std::endl;
    }
    return 0;
}