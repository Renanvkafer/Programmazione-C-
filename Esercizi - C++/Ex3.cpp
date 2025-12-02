#include <iostream>

int push_pilha(float buffer[], int n, int* tos, float val);
int pop_pilha(float buffer[], int n, int* tos, float* val);

int main () {

    int chose = 0;
    float buf[100] = {0};
    int Nu = 100;
    int tos = 0;
    float element = 0;

    while (chose != 5) {

        std::cout<<" 1 - Inserire Elemento\n";
        std::cout<<" 2 - Estrazione di Elemento\n";
        std::cout<<" 3 - Stampa la pila\n";
        std::cout<<" 5 - Close\n\n";
        std::cin>>chose;

        switch (chose) {

            case 1:
                std::cout<<" Inserisci l'elemento: ";
                std::cin>>element;

                if (!push_pilha(buf, Nu, &tos, element)) {
                    std::cout<<"Buffer pieno\n";
                } else {
                    std::cout<<"Valore inserito\n";
                }
                break;

            case 2:
                if (!pop_pilha(buf, Nu, &tos, &element)) {
                    std::cout<<"Buffer vuoto\n";
                } else {
                    std::cout<<"Valore estratto: " << element << "\n";
                }
                break;

            case 3:
                std::cout << "\nContenuto della pila:\n";
                for (int i = 0; i < tos; i++) {
                    std::cout << buf[i] << "\n";
                }
                break;

            default:
                break;
        }
    }

    return 0;
}

int push_pilha(float buffer[], int ns, int* tos, float val) {
    if (*tos == ns) {
        return 0;
    }
    buffer[*tos] = val;
    (*tos)++;
    return 1;
}

int pop_pilha(float buffer[], int ns, int* tos, float* val) {
    if (*tos == 0) {
        return 0;
    }
    (*tos)--;
    *val = buffer[*tos];
    return 1;
}
