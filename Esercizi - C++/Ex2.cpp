#include <cstring>
# include <iostream>

int lenChar(const char *mesagg) {
    int i = 0;
    while (mesagg[i] != '\0') {
        i++;
    }
    return i;
}


void cesare(char * messagio, int key1, int len) {
    for (int i = 0; i < len; i++) {
        char c = messagio[i];
        if (c >= 'a' && c <= 'z') {
            messagio[i] = ((c - 'a' + key1) % 26) + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            messagio[i] = ((c - 'A' + key1) % 26) + 'A';
        }
    }
}


int main() {

    char message[256];
    int key;

    std::cout<<"Message:  ";
    std::cin>>message;

    std::cout<<"Secret Key:  ";
    std::cin>>key;

    cesare(message, key, lenChar(message));

    std::cout<<message;

    cesare(message, -key, lenChar(message));

    std::cout<<"\n"<<message;

    return 0;
}