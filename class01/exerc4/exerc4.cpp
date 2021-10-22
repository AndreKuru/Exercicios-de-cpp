#include <iostream>
#include <string>

std::string check_palindrome(std::string const& word)
{
  for(auto i = 0; i < word.size(); ++i) {
    if(word[i] != word[word.size() - 1 - i]) {
      return "not a palindrome";
    }
  }
  return "palindrome";
}

int main()
{
  using namespace std::string_literals;

  std::cout << "arara is "s << check_palindrome("arara"s) << '\n';
  std::cout << "banana is "s << check_palindrome("banana"s) << '\n';
}
