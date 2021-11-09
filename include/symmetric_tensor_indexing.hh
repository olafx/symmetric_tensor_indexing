#pragma once
#include <cstddef>

namespace symmetric_tensor_indexing
{

template <size_t a, size_t b>
size_t A_upper(size_t i)
{   if constexpr (a == b)
        return i + a;
    else if constexpr (a == 0)
        return i * A_upper<a + 1, b>(i);
    else
        return (i + a) * A_upper<a + 1, b>(i);
}

template <size_t a, size_t b>
size_t A_lower(size_t n, size_t i)
{   if constexpr (b == 0)
        return i;
    else if constexpr (a == b)
        return a - 2 + 2 * n - i;
    else if constexpr (a == 0)
        return i * A_lower<a + 1, b>(n, i);
    else
        return (a - 2 + 2 * n - i) * A_lower<a + 1, b>(n, i);
}

template <size_t b>
size_t B(size_t i)
{   if constexpr (b == 0)
        return i;
    else
        return B<b - 1>(i / (b + 1));
}

template <size_t a, typename I, typename ...J>
size_t C_upper(I i, J... j)
{   if constexpr (sizeof...(j) == 0)
        return B<a>(A_upper<0, a>(i));
    else
        return B<a>(A_upper<0, a>(i)) + C_upper<a + 1>(j...);
}

template <size_t a, typename I, typename ...J>
size_t C_lower(size_t n, I i, J... j)
{   if constexpr (sizeof...(j) == 0)
        return B<a>(A_lower<0, a>(n, i));
    else
        return B<a>(A_lower<0, a>(n, i)) + C_lower<a + 1>(n, j...);
}

template <typename I, typename ...J>
size_t index_upper(I i, J... j)
{   return C_upper<0>(i, j...);
}

template <typename I, typename ...J>
size_t index_lower(size_t n, I i, J... j)
{   return C_lower<0>(n, i, j...);
}

}
