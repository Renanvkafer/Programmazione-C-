# include <iostream>

int main() {
      int i = 0;

      int mynums1[] = {1, 2, 3, 4, 5};
      int getArrayLength = sizeof(mynums1) / sizeof(mynums1[0]);

      int mynums2[getArrayLength];

      int aux_var = getArrayLength - 1;

      for (i = 0; i < getArrayLength ; i++) {
            mynums2[i] = mynums1[aux_var];
            aux_var--;
      }

      for (i = 0; i < getArrayLength ; i++) {
            printf("%d ", mynums2[i]);
      }

      for (i = 0; i < getArrayLength ; i++) {
                  printf("\n %d ", mynums1[i]);
      }


            return 0;
}