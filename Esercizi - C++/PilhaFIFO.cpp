#include <iostream>


//Pilha de FIFO

int enqueue(float buffer[], int n, int* tail, int head, float val);
int dequeue(float buffer[], int n, int head, int* tail, float* val);

int main() {
    int head = 0;
    int tail = 0;
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

                if (!enqueue(buf, 5, &tail, head, element)) {
                    std::cout<<"Errore: coda piena\n";
                } else {
                    std::cout<<"Elemento inserito: " << element << "\n";
                }
                break;

            case 2:
                if (!dequeue(buf, 5, head, &tail, &element)) {
                    std::cout<<"Errore: coda vuota\n";
                } else {
                    std::cout<<"Elemento estratto: " << element << "\n";
                }
                break;

            case 3:
                std::cout << "\nContenuto della coda:\n";
                for (int i = head; i != tail; i = (i + 1) % 5) {
                    std::cout << buf[i] << "\n";
                }
                break;

            default:
                break;
        }
    }

    return 0;
}

int enqueue(float buffer[], int n, int* tail, int head, float val) {
    if ((*tail + 1) % n == head) {
        return 0;
    }
    buffer[*tail] = val;
    *tail = (*tail + 1) % n;
    return 1;
}

int dequeue(float buffer[], int n, int* head, int tail, float* val) {
    if (*head == tail) {
        return 0;
    }

    *val = buffer[*head];
    *head = (*head + 1) % n;
    return 1;
}
