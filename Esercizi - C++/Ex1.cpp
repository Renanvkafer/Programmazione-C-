# include <iostream>



double calcolo_area(double lato, double lato1) {
    return lato * lato1;
}

void disegna(double l1, double l2) {
    int i,j;
    for (i=0; i<l1; i++) {
        for (j=0; j<l2; j++) {
            printf("*");
        }
        printf("\n");
    }
}

double calcolo_maggiore(double lato4, double lato3) {
    if (lato4 > lato3) return lato4;
    return lato3;
}

int main() {
    double x;
    double y;


    std::cout<<"Base Rettangolo:  ";
    std::cin>>x;

    std::cout<<"Altura Rettangolo:  ";
    std::cin>>y;

    double area = calcolo_area(x,y);

    std::cout<<area<<"cm^2\n";

    std::cout<<"\n";

    disegna(x, y);

    std::cout<<"\n";

    double maggiore =  calcolo_maggiore(x,y);

    std::cout<< "Maggiore Lato: " << maggiore;
    std::cout<<"\n";
    printf("%f\n", maggiore);

    return 0;
}