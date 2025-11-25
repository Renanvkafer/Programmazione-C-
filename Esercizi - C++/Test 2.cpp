# include <iostream>

int main() {
    int x;

    std::cout<<"Quant numbers: ";
    std::cin>>x;

    x--;
    int a[x];
    int pari[x];

    for (int i = 0; i <= x; i++) {
        std::cout<<"Press a number: ";
        std::cin>>a[i];
    }


    int count_pari = 0;

    for (int i = 0; i <= x; i++) {
        if (a[i] % 2 == 0){
            pari[i] = a[i];
             count_pari++;
        }
    }

    std::cout << count_pari;

    for (int i = 0; i < count_pari; i++) {
        printf("[%d] ", pari[i]);
    }


}