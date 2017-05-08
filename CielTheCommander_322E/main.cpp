/**
 * Author: Andrei Heidelbacher
 * Task: Ciel the commander
 * Time complexity: O(N * log(N))
 * Space complexity: O(N)
 */

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Tree;

const int NIL = -1;

void sizeDfs(
        const Tree& tree,
        const vector<bool>& isErased,
        const int x,
        const int father,
        vector<int>& sizes) {
    sizes[x] = 1;
    for (const auto& y : tree[x]) {
        if (y != father && !isErased[y]) {
            sizeDfs(tree, isErased, y, x, sizes);
            sizes[x] += sizes[y];
        }
    }
}

void centerDfs(
        const Tree& tree,
        const vector<bool>& isErased,
        const vector<int>& sizes,
        const int root,
        const int x,
        const int father,
        int& center,
        int& bestSplitSize) {
    int splitSize = sizes[root] - sizes[x];
    for (const auto& y : tree[x]) {
        if (y != father && !isErased[y]) {
            centerDfs(tree, isErased, sizes, root, y, x, center, bestSplitSize);
            splitSize = max(splitSize, sizes[y]);
        }
    }
    if (splitSize < bestSplitSize) {
        center = x;
        bestSplitSize = splitSize;
    }
}

int findCenter(
        const Tree& tree,
        const vector<bool>& isErased,
        const int root,
        vector<int>& sizes) {
    sizeDfs(tree, isErased, root, NIL, sizes);
    int center = root;
    int bestSplitSize = sizes[root];
    centerDfs(tree, isErased, sizes, root, root, NIL, center, bestSplitSize);
    return center;
}

void solve(
        const Tree& tree,
        const int root,
        const char rank,
        vector<bool>& isErased,
        vector<int>& sizes,
        vector<char>& ranks) {
    const int center = findCenter(tree, isErased, root, sizes);
    isErased[center] = true;
    for (const auto& y : tree[center]) {
        if (!isErased[y]) {
            solve(tree, y, rank + 1, isErased, sizes, ranks);
        }
    }
    ranks[center] = rank;
}

vector<char> solve(const Tree& tree) {
    const int size = int(tree.size());
    auto isErased = vector<bool>(size, false);
    auto sizes = vector<int>(size);
    auto ranks = vector<char>(size);
    solve(tree, 0, 'A', isErased, sizes, ranks);
    return ranks;
}

int main() {
    int size;
    cin >> size;
    auto tree = Tree(size);
    for (int i = 1; i < size; i++) {
        int x, y;
        cin >> x >> y;
        tree[x - 1].push_back(y - 1);
        tree[y - 1].push_back(x - 1);
    }
    const auto ranks = solve(tree);
    for (int x = 0; x < size; x++) {
        cout << ranks[x] << (x + 1 < size ? " " : "\n");
    }
    return 0;
}

