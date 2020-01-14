#include <iostream>
#include <vector>

void lambda()
{
    // [] - capture clause
    // () - parameters
    // {} - body

    // [&] - capture by reference
    // [=] - capture by value

    std::vector<int> v{1, 2, 3, 4};
    std::for_each(v.begin(), v.end(),
        [](int n)
        {
            std::cout << n << " ";
        });

    int x = 0;
    int y = 0;
    auto print = [&](){std::cout << x << y << std::endl; };

    std::vector<int> doubleV(v.size());
    transform(begin(v), end(v), begin(doubleV),
        [](int e){return e*2;}
    );
}