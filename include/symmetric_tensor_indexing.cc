#include "symmetric_tensor_indexing.hh"

#include <iostream>

int main()
{
    using namespace symmetric_tensor_indexing;

    size_t a = index(3, 3, 3);
    // 19 = (3 + 4 - 1) choose (3) - 1

    size_t b = index(6, 6, 6, 6);
    // 209 = (4 + 7 - 1) choose (4) - 1

    std::cout << a << ' ' << b << '\n';
}
