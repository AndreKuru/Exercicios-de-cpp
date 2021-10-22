#include <iostream>

/*
fib_previous = 0
fib_current = 1
i = 0

fib_previous = 0
fib_current = 1
i = 1

fib_previous = 0
fib_current = 1
i = 2

fib_previous = 1
fib_current = 1
i = 3

fib_previous = 1
fib_current = 2
i = 4


*/
void fib_up_to(int n)
{
    auto fib_current = 0;
    auto fib_next = 1;

    for (auto i = 0; i < n; ++i) {
        std::cout << fib_current << '\n';

        auto fib_aux = fib_next + fib_current;
        fib_current = fib_next;
        fib_next = fib_aux;
    }
}

void fib_less_than(int n)
{
    auto fib_current = 0;
    auto fib_next = 1;

    while (fib_current < n) {
        std::cout << fib_current << '\n';

        auto fib_aux = fib_next + fib_current;
        fib_current = fib_next;
        fib_next = fib_aux;
    }
}

int main()
{
    fib_up_to(10);
    fib_less_than(1024);
}