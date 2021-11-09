#include "symmetric_tensor_indexing.hh"
#include <iostream>

int main()
{
    using namespace symmetric_tensor_indexing;
    using std::cout;

    for (size_t i= 0; i < 4; i++)
    {   cout << index_upper(i) << ' ';
    }
    cout << "\n\n";

    for (size_t i= 0; i < 4; i++)
    {   cout << index_lower(4, i) << ' ';
    }
    cout << "\n\n";

    for (size_t i= 0; i < 4; i++)
    {   for (size_t j = 0; j < 4; j++)
            cout << index_upper(i, j) << ' ';
        cout << '\n';
    }
    cout << '\n';

    for (size_t i= 0; i < 4; i++)
    {   for (size_t j = 0; j < 4; j++)
            cout << index_lower(4, i, j) << ' ';
        cout << '\n';
    }
    cout << '\n';

    cout << index_upper(6, 6, 6, 6) << ' ' << index_lower(7, 6, 6, 6, 6) << '\n';
}
