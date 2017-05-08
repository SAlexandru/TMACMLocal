# [Cow program](https://vjudge.net/problem/CodeForces-284D)

We can interpret the sequence of numbers as a directed graph with `N + 1` nodes.
Each node will have exactly one outgoing edge (assuming the value `A[1]` is
fixed and there is a single node `NIL` corresponding to all values less than `1`
or greater than `N`). `NIL` will be the only node with no outgoing edges.

For node `X`, the outgoing edge will be `G[x] = X + A[X] - A[X + A[X]]` if
both `X + A[X]` and `X + A[X] - A[X + A[X]]` are in the range `1..N`, or `NIL`
otherwise. The cost of this edge will be `A[X] + A[X + A[X]]` if `X + A[X]` is
in the range `1..N`, or `A[X]` otherwise.

The task is to find the cost of the path going from node `1` and ending in node
`NIL`, or to print `-1` if node `1` is on a cycle, for every value `A[1]` in the
range `1..N - 1`.

An important observation which allows us to ignore node `1` is to notice that if
any path starting from a node different than `1` visits node `1`, then it will
surely create a cycle. Thus, all we need to do is to find the cost of every path
starting from node `i` (or if it ends up in a cycle) and then analyze the
results for every value of `A[1]` in the range `1..N - 1`.

The time and space complexity will be `O(N)`.
