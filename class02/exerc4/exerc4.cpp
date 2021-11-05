#include <iostream>
#include <vector>

std::vector<int> remove_duplicates(std::vector<int> const& vec)
{
  std::vector<int> aux{vec[0]};

  for(int i = 1; i < vec.size(); ++i) {
    if(aux.back() != vec[i]) {
      aux.push_back(vec[i]);
    }
  }

  return aux;
}

int main()
{
    for (auto i: remove_duplicates({1, 1, 1, 2, 3, 3, 4, 1, 1})) {
        std::cout << i << '\n';
    }
}
