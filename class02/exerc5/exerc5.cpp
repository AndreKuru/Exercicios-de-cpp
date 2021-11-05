#include <iostream>
#include <vector>

void remove_duplicates(std::vector<int>& ints)
{
  std::vector<int> aux{ints[0]};

  for(int i = 1; i < ints.size(); ++i) {
    if(aux.back() != ints[i]) {
      aux.push_back(ints[i]);
    }
  }

  ints = aux;
}

int main()
{
    auto ints = std::vector<int>{1, 1, 1, 2, 3, 3, 4, 1, 1} ;

    remove_duplicates(ints);

    for (auto i: ints) {
        std::cout << i << '\n';
    }
}