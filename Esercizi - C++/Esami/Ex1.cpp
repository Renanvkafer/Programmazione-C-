#import <iostream>
#include <fstream>


int main(){

    std::ifstream file("dados.txt");

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir arquivo!" << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    std::cout << content << std::endl;

    file.close();
    return 0;


    return 0;
}