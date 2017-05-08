# [Bits equalizer](https://vjudge.net/problem/UVA-12545)

If the number of ones in `S` is greater than the number of ones in `T`, because
no operation can transform a one into a zero, there will be no solution.
Otherwise, we will use a greedy strategy to achieve the minimum number of
operations.

As long as `S` contains less ones than `T`:
- transform a pair of characters `(S[i], T[i])` with values `(?, 1)` into the
pair `(1, 1)`
- otherwise, transform a pair of characters `(S[i], T[i])` with values `(0, 1)`
into the pair `(1, 1)`
- otherwise, transform a pair of characters `(S[i], T[i])` with values `(?, 0)`
into the pair `(1, 0)`

The first two operations make the `i`-th characters from `S` and `T` equal with
a single operation, while increasing the number of ones in `S`. As a result,
they are optimal operations. If no such operations are available, because we
still have to increase the number of ones in `S`, we apply the third operation.
The resulting `(1, 0)` pair will be solved later with a swap operation.

Now, we transform the pairs of characters `(S[i], T[i])` with values `(?, 0)`
into the pair `(0, 0)`. This makes the `i`-th characters in `S` and `T`, while
decreasing the number of `?` characters in `S`. Thus, it is an optimal
operation.

The pairs of characters `(S[i], T[i])` with values `(?, 1)` will be transformed
into the pair `(0, 1)`. Because all `?` characters must be eliminated from `S`
and because we can't create any more ones in `S`, these operations must be
performed. The pairs will be solved later with swap operations.

Finally, we will solve the remaining `(0, 1)` and `(1, 0)` pairs using swap
operations.

Simulating the operations on `S` and `T` is not required, we only need to work
with the number of pairs of characters `(S[i], T[i])` with values `(0, 1)`,
`(1, 0)`, `(?, 0)` or `(?, 1)`. Such a solution will have a space and time
complexity of `O(|S| + |T|)`.
