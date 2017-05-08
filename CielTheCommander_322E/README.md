# [Ciel the commander](https://vjudge.net/problem/CodeForces-322E)

We will use a divide-and-conquer approach to solve the problem.

Solving a tree with a single node is simple (we can assign any rank to the
node). If the tree contains more than a node, we can pick any node `X` which
will be considered the root of the tree. We will assign the highest available
rank to this node (initially, `'A'`). Obviously, there will be a single node
assigned with the highest available rank.

Any path which passes through the root will respect the imposed rule, because
all the other nodes will have ranks which are less than the root rank. The
remaining problem is to impose the rule on every path which doesn't pass
through the root. This leads to independently and recursively solving all the
subtrees `T1`, `T2`, ..., `Tk` of the root.

The remaining problem is the depth of the recursion, because it can exceed `26`
(the number of available ranks). If we always choose as root the centroid of the
tree (for which the maximum size of a subtree is minimized), the recursion depth
will be `log(N)`, which is less than `26`.

We will prove the existence of a node which, if removed from a tree of size `N`,
will split the tree in subtrees of size at most `N / 2`.

Initially, we can pick any arbitrary node. If this node already splits the tree
accordingly, our search is done. Otherwise, there will be exactly one subtree
of size greater than `N / 2`, and the cumulated sizes of all the other subtrees
is strictly less than `N / 2`. The next node we pick will be the adjacent node
from the subtree with size greater than `N / 2`. At this step, the size of the
biggest subtree will decrease by `1`, and the cumulated sizes of all the other
subtrees will be less than or equal to `N / 2`. Repeating the process, we will
reach a point when all subtrees have size less than or equal to `N / 2`.

At every step of the recursion, the maximum size of a resutling subtree after
splitting the tree along the centroid will be `N / 2`. As a result, the maximum
depth of the recursion will be `log(N)`.

In the worst case, at every depth of the recursion, all the nodes of the initial
tree will be visited. Thus, the time complexity will be `O(N * log(N))` and the
space complexity will be `O(N)`.
