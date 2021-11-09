# symmetric_tensor_indexing

Showcase of a recursive symmetric tensor indexing algorithm. It is written for upper UPLO='U column major storage (or equivalently lower UPLO='L' row major storage) and lower UPLO='L' column major storage (or equivalently upper UPLO='U' row major storage). The minimum order allowed is 1 (symmetric vectors are just plain vectors).

This is essentially a generalization of the usual upper packed matrix indexing formula for column major storage; see LAPACK user's guide 3rd edition section 5.3.2. Just like the original it's based on, the upper formula makes no sense to use in the lower region and vice versa. (However just like the original, it won't point to memory that doesn't belong to the tensor either way.)

Symmetric tensors of order n and dimension d have size (n + d - 1) choose (order). (This in itself is obscure and opaque, let alone full indexing.) A comprehensible way to test this algorithm is to check that the last index corresponds to memory location size - 1. Simple matrix examples can also be tested.

Using template programming, the optimal formula for a tensor of some order is evaluated at compile time. (Correct is useless if it isn't optimal.) In other words, this algorithm is perfectly practical. For 2nd order tensors, it reduces to exactly the original formula it's based on.

An alternative derivation is made [here](https://0fps.net/2011/08/30/multidimensional-taylor-series-and-symmetric-tensors/) from a very different vantage point, with [this](https://github.com/mikolalysenko/symmetric-tensor-index) code. (Only column major upper tho.) Whereas this project generates the index formula along the way using inline compile time recursion, mikolalysenko opts for a more direct solution using factorials.
