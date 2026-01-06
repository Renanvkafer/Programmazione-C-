# include <iostream>

int main() {

   int a = 10;
   int *b = &a;
   std::cout << *b << std::endl;

   a = 30;

  std::cout << *b << std::endl;

  *b = 40;

   std::cout << *b << std::endl;
   std::cout << a << std::endl;

}