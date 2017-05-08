# [Ideal path](https://vjudge.net/problem/UVA-1599)

We will compute the length of the shortest path from each node to the
destination (node `N`) using a breadth-first search starting from the
destination.

Let `Dmin` be the length of a shortest path from the source (node `1`) to the
destination. To find the lexicographically minimal shortest path, we will build
the set `V[d]` of nodes placed at distance `d` from the destination and which
belong to any lexicographically minimal shortest path from the source.

Initially, `V[Dmin] = {1}`. Having the set `V[d]` computed, we can find
`V[d - 1]` in the following way:
- find the edges `(u, v, c)` such that `u` belongs to `V[d]` and the length of
a shortest path from `v` to the destination is `d - 1`
- keep only those edges with the minimally lexicographic color `c`
- the set `V[d - 1]` will contain the nodes `v` of the selected edges

Thus, a shortest and lexicographically minimal path will pass only through the
nodes from the sets `V[Dmin]`, `V[Dmin - 1]`, ..., `V[1]`, `{N}` (the
destination).

The space and time complexity is `O(N + M)`.
