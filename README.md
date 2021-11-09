# symmetric_tensor_indexing

Showcase of a recursive symmetric tensor indexing algorithm. It is written for upper (UPLO='U' equivalent) column major storage, or equivalently lower (UPLO='L' equivalent) row major storage. A similar algorithm can be used for lower column major storage or upper row major storage, but isn't worked out here.

This is essentially a generalization of the usual upper packed matrix indexing formula for column major storage; see LAPACK user's guide 3rd edition section 5.3.2. Just like the original it's based on, this formula makes no sense to use in the lower region (or equivalent thereof for tensors), which conveniently means a set of indexes that are *not* sorted. However just like the original, it won't point to memory that doesn't belong to the tensor either way.

Symmetric tensors of order n and dimension d have size (n + d - 1) choose (order). (This in itself is obscure and opaque, let alone full indexing.) A comprehensible way to test this algorithm is to check that the last index corresponds to memory location size - 1.

Using template programming, the optimal formula for a tensor of some order is evaluated at compile time. (Correct is useless if it isn't optimal.) In other words, this algorithm is perfectly practical. For 2nd order tensors, it reduces to exactly the original formula it's based on.

An alternative derivation is made [here](https://0fps.net/2011/08/30/multidimensional-taylor-series-and-symmetric-tensors/) from a very different vantage point, with [this](https://github.com/mikolalysenko/symmetric-tensor-index) code. Whereas this project generates the index formula along the way using recursion, mikolalysenko opts for a more direct solution using factorials, which unfortunately leads to an unoptimally compiled formula. Nonetheless, correct is impressive!
