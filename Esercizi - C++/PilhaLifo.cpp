#include <iostream>


int enqueue(float buffer[], int n, int* tos, float val);
int dequeue(float buffer[], int n, int* tos, float* val);

int main() {
    int tos = -1;
    float buf[5] = {0};
    float element = 0;
    int chose = 0;

    while (chose != 5) {

        std::cout<<" 1 - Enqueue\n";
        std::cout<<" 2 - Dequeue\n";
        std::cout<<" 3 - See all\n";
        std::cout<<" 5 - Close\n\n";
        std::cin>>chose;

        switch (chose) {

            case 1:
                std::cout<<" Inserisci l'elemento: ";
                std::cin>>element;

                if (!enqueue(buf, 5, &tos, element)){
                    std::cout<<"Errore: coda piena\n";
                } else {
                    std::cout<<"Elemento inserito: " << element << "\n";
                }
                break;

            case 2:
                if (!dequeue(buf, 5, &tos, &element)) {
                } else {
                    std::cout<<"Elemento estratto: " << element << "\n";
                }
                break;

            case 3:
                std::cout << "\nContenuto della coda:\n";
                for (int i = tos; i >= 0; i--) {
                    std::cout << buf[i] << "\n";
                }
                break;

            default:
                break;
        }
    }

    return 0;

}


int enqueue(float buffer[], int n, int* tos, float val) {
    if (*tos >= n - 1) return 0;
    (*tos)++;
    buffer[*tos] = val;
    return 1;
}

int dequeue(float buffer[], int n, int* tos, float* val) {
    if (*tos == -1) return 0;
    *val = buffer[*tos];
    (*tos)--;
    return 1;
}