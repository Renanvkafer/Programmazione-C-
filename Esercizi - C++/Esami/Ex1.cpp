#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <math.h>



struct Punto {
    float x;
    float y;
    float z;
    char h[20];
};


int carica_data(const char* filename, int n, Punto punto[]) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        return -1;
    }
    int count = 0;
    std::string line;
    while (count < n && std::getline(file, line) ) {
        std::istringstream iss(line);
        float x, y, z;
        char h[20];
        if (iss >> x >> y >> z >> h) {
            punto[count].y = y;
            punto[count].x = x;
            punto[count].z = z;
            strcpy(punto[count].h, h);
            count++;
        }else {
            std::cerr << "Error reading line " << filename << std::endl;
            break;
        }

    }
    file.close();
    return count;
}

int find_point_matrice(Punto puntinho[], int nu, float matrice[][3], char lettera) {
    int b = 0;
    std::string line;
    for (int i = 0; i < nu; i++) {

        if (strchr(puntinho[i].h, lettera)){
            matrice[b][0] = puntinho[i].x;
            matrice[b][1] = puntinho[i].y;
            matrice[b][2] = puntinho[i].z;
            b++;
        }

    }
    return b;
}


void calcula_distancia(const char* filename, Punto puntinho[], int nu, char lettera, float matrice[][3], float matricefinal[][100], int len) {
    float aux = 0;
    float aux2 = 0;
    int j = 0;
    for (int i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            for (int k = 0; k < 3; k++) {
                aux2 = matrice[i][k] - matrice[j][k];
                aux += pow(aux2, 2);
            }
            matricefinal[i][j] = sqrt(aux);
            aux = 0;
            aux2 = 0;
        }
    }
}


void print_final_matriz(float matricef[][100], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            std::cout << matricef[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    constexpr int MAX_POINT = 100;
    char letter;
    int a = 10;
    Punto punti[MAX_POINT];
    float matrice[MAX_POINT][3];
    float risultado[MAX_POINT][MAX_POINT];
    int punti_count = carica_data( "C:/Users/Cliente/Desktop/dados1.txt", MAX_POINT, punti);
    std::cout << punti_count << std::endl;

    if (punti_count == -1) {
        std::cerr << "Errore: impossibile aprire il file 'punti.txt'!" << std::endl;
        return 1;
    }

    for (int i = 0; i < punti_count; i++) {
        std::cout << punti[i].x << "  " << punti[i].y << "  " << punti[i].z << punti[i].h <<  std::endl;
    }


    while (a != 0){

            std::cout<<"\nEnter a letter:  ";
            std::cin>>letter;

            if (letter >= 'a' && letter <= 'z') {
                a = 0;
            }
            else {
                std::cout<<"Per favor inserire una lettera minuscula!";
            }

    }

    int select_point  = find_point_matrice(punti, punti_count, matrice, letter);
    calcula_distancia("C:/Users/Cliente/Desktop/dados1.txt", punti ,punti_count, letter, matrice, risultado, select_point);
    print_final_matriz(risultado, select_point);
    return 0;
}