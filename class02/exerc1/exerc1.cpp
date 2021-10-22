#include <vector>
#include <iostream>

bool balanced (std::string s)
{
  using namespace std::string_literals;

  auto stack = ""s;

  for (auto c: s) {
    if (c == '(' or c == '[' or c == '{') {
      stack.push_back(c);
      continue;
    }

    if (c == ')') {
      if (stack.back() != '(') {
        return false;
      }
      stack.pop_back();
    }

    if (c == ']') {
      if (stack.back() != '[') {
        return false;
      }
      stack.pop_back();
    }

    if (c == '}') {
      if (stack.back() != '{') {
        return false;
      }
      stack.pop_back();
    }

  }

  if (stack.size() == 0) {
    return true;
  }
  return false;
}

int main()
{
    using namespace std::string_literals;

    auto cases = std::vector<std::string>{
        "int main(int argv, char** argv) { std::cout << argv[0] << '\n'; }"s,
        "([[]]{[]}{()})"s,
        ""s,
        ")"s,
        "([)()(])({}{)(})"s,
        "[[](){](()"s,
    };

    for (auto c: cases) {
        std::cout << "Case " << c << " is "
                  << (balanced(c) ? "balanced" : "not balanced")
                  << '\n';

    }
}