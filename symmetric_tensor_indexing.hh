#pragma once
#include <cstddef>

namespace symmetric_tensor_indexing
{

template <size_t a, size_t b>
size_t A(size_t i)
{   if constexpr (a == b)
        return i;
    else
        return A<a + 1, b>(i) * (i + a + 1);
}

template <size_t b>
size_t B(size_t i)
{   if constexpr (b == 0)
        return i;
    else
        return B<b - 1>(i / (b + 1));
}

template <size_t a>
size_t C(size_t i)
{   return B<a>(A<0, a>(i));
}

template <size_t a, typename I, typename ...J>
size_t D(I i, J... j)
{   if constexpr (sizeof...(j) == 0)
        return C<a>(i);
    else
        return C<a>(i) + D<a + 1>(j...);
}

template <typename ...I>
size_t index(I... i)
{   return D<0>(i...);
}

}
