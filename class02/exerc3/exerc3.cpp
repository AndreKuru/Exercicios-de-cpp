#include <iostream>

void swap(int& i, int& j)
{
  auto aux = i;
  i = j;
  j = aux;
}

int main()
{
    auto i = 2, j = 3;
    swap(i, j);
    std::cout << i << "\n"; // deve imprimir 3
    std::cout << j << "\n"; // deve imprimir 2
}