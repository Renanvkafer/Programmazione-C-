#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

struct Vole {
  char IDA[10];
  char VOLTA[10];
};


int load_data(const char* filename, int len, Vole vole[], int count) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
  }
  std::string line;
  while (count < len && std::getline(file, line) ) {
    std::istringstream iss(line);
    char x[10], y[10];
    if (iss >> x >> y) {
      strcpy(vole[count].IDA, x);
      strcpy(vole[count].VOLTA, y);
      count++;
    }else {
      std::cerr << "Error reading line " << filename << std::endl;
      break;
    }
  }
  file.close();
  for (int i = 0; i < count; i++) {
      std::cout << vole[i].IDA << " - " << vole[i].VOLTA << std::endl;
  }
  return count;
}


int tratte_andata_ritorno(Vole vole[], char matriz[][100][20], int count_tratte_func, int cont) {
  for (int i = 0; i < count_tratte_func; i++) {
    for (int j = i + 1; j < count_tratte_func; j++) {
      if (strcmp(vole[i].IDA, vole[j].VOLTA) == 0 && strcmp(vole[i].VOLTA, vole[j].IDA) == 0) {
          strcpy(matriz[i][j], vole[i].IDA);
          strcat(matriz[i][j], "-");
          strcat(matriz[i][j], vole[i].VOLTA);
          cont++;
      }
    }
  }
  return  cont;
}

void visualizza_tratte (int len, char matriz[][100][20], int count_tratte_func1) {
  std::cout << std::endl;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (matriz[i][j][0] != '\0') {
        std::cout << matriz[i][j] << "\t";
        std::cout << std::endl;
      }
    }
  }
  std::cout << "numero di tratte di andata e ritorno: " << count_tratte_func1 << std::endl;
}


int main() {
  constexpr int MAX_RESULT = 100;
  Vole voli[MAX_RESULT];
  int count_tratte = 0;
  int count = 0;
  char matriz_vole[MAX_RESULT][MAX_RESULT][20] = {0};;
  count_tratte = load_data("C:/Users/Cliente/Downloads/file_essempio2.txt", MAX_RESULT, voli, count_tratte);
  count = tratte_andata_ritorno(voli, matriz_vole, count_tratte, count);
  visualizza_tratte(MAX_RESULT, matriz_vole, count);
  return 0;
}