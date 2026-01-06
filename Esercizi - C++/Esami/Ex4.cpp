#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

struct  Element {
    int num_at;
    char name[20];
    char abbrev[20];
    float mass_atom;
};


void scan_table(Element tav[], const int len_element[], float risutaldo, int len) {
    std::cout << "Peso atomico del composto ";
    for (int i = 0; i < len; i++) {
        std::cout << tav[i].abbrev << len_element[i];
    }
    std::cout << ": " << risutaldo << std::endl;
}

float scan_request(Element tavfinal[], int len, const int len_element[]) {
    float result = 0;
    for (int i = 0; i < len; i++) {
        result += tavfinal[i].mass_atom * static_cast<float>(len_element[i]);
    }
    return result;
}

void print_table(int len, Element tavv[]) {
    for (int i = 0; i < len; i++) {
        std::cout << tavv[i].num_at << " ";
        std::cout << tavv[i].name << " ";
        std::cout << tavv[i].abbrev << " ";
        std::cout << tavv[i].mass_atom << std::endl;
    }
}

int load_element(const char* filename, int len, Element tav[]) {
   std::ifstream file(filename);
   if (!file.is_open()) {
       return -1;
   }
   std::string line;
   std::getline(file, line);
   int count = 0;
    while(count < len && std::getline(file, line)){
    int x;
    char y[20], z [20];
    float h;
    std::istringstream iss(line);
    if (iss >> x >> y >> z >> h) {
       tav[count].num_at = x;
       strcpy(tav[count].name, y);
       strcpy(tav[count].abbrev, z);
       tav[count].mass_atom = h;
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
+

int main() {
    constexpr int MAX_LEN = 100;
    int len_total_elements;
    Element tavola[MAX_LEN];
    Element tavola_tasq[MAX_LEN];
    char risposta_tasquiera;
    int count = 0;
    int aux = 0;
    int volte_add[MAX_LEN];
    float risultado_finale;

    len_total_elements = load_element("C:/Users/Cliente/Downloads/tavola_elementi.txt", MAX_LEN, tavola);
    print_table(len_total_elements, tavola);

    std::cout << std::endl;
    while (count < len_total_elements) {
        std::cout << std::endl;
        std::cout << "Vuoi inserire questo elemento: " << std::endl << tavola[count].abbrev << " " << tavola[count].mass_atom << std::endl;
        std::cout << "y - yes n - no: " << std::endl;
        std::cout << " " << std::endl;
        std::cin >> risposta_tasquiera;
        if (!(risposta_tasquiera == 'y' ||  risposta_tasquiera == 'n')) {
            std::cout << "Per cortesia inserire un caractere valido: " << std::endl;
        }
        if (risposta_tasquiera == 'y') {
            std::cout << "Quante volte vuoi inserire questo elemento: " << std::endl;
            std::cin >> volte_add[aux];
            if (std::cin.fail() || volte_add[aux] == 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Inserire un numero valido e non zero!\n";
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

    risultado_finale = scan_request(tavola_tasq, aux, volte_add);

    scan_table(tavola_tasq, volte_add, risultado_finale, aux);

    return 0;

}