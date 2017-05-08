/**
 * Author: Andrei Heidelbacher
 * Task: Cow program
 * Time complexity: O(N)
 * Space complexity: O(N)
 */

#include <iostream>
#include <vector>

#define v first
#define c second

using namespace std;

typedef long long int64;
typedef pair<int, int64> Edge;
typedef vector<Edge> Graph;

const int NIL = -1;

Edge getNext(const vector<int>& values, const int u) {
    const int size = int(values.size());
    int v = u + values[u];
    int64 c = values[u];
    if (v >= 0 && v < size) {
        c += values[v];
        v -= values[v];
        if (v < 0 || v >= size) {
            v = NIL;
        }
    } else {
        v = NIL;
    }
    return Edge(v, c);
}

Graph buildGraph(const vector<int>& values) {
    const int size = int(values.size());
    auto graph = vector<Edge>(size, Edge(NIL, 0));
    for (int u = 1; u < size; u++) {
        graph[u] = getNext(values, u);
    }
    return graph;
}

void dfs(
        const Graph& graph,
        const int u,
        vector<int>& colors,
        vector<int64>& costs) {
    colors[u] = 1;
    const int v = graph[u].v;
    const int c = graph[u].c;
    if (v != NIL) {
        if (colors[v] == 0) {
            dfs(graph, v, colors, costs);
        }
        costs[u] = colors[v] == 1 ? -1 : costs[v];
    }
    costs[u] = costs[u] == -1 ? -1 : costs[u] + c;
    colors[u] = 2;
}

vector<int64> getCosts(const vector<int>& values) {
    const int size = int(values.size());
    const auto graph = buildGraph(values);
    auto colors = vector<int>(size, 0);
    auto costs = vector<int64>(size, 0);
    colors[0] = 1;
    for (int u = 1; u < size; u++) {
        if (colors[u] == 0) {
            dfs(graph, u, colors, costs);
        }
    }
    return costs;
}

int main() {
    int n;
    cin >> n;
    auto values = vector<int>(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> values[i];
    }
    const auto costs = getCosts(values);
    for (values[0] = 1; values[0] < n; ++values[0]) {
        const Edge e = getNext(values, 0);
        const int v = e.v;
        int64 c = e.c;
        if (v != NIL) {
            c = (v == 0 || costs[v] == -1) ? -1 : c + costs[v];
        }
        cout << c << "\n";
    }
    return 0;
}

