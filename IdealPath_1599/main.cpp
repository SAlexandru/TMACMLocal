/**
 * Author: Andrei Heidelbacher
 * Task: Ideal path
 * Time complexity: O(N + M)
 * Space complexity: O(N + M)
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>

#define v first
#define c second

using namespace std;

typedef pair<int, int> Edge;
typedef vector<vector<Edge>> Graph;

const int INF = 0x3f3f3f3f;

vector<int> bfs(const Graph& graph, const int source) {
    auto distances = vector<int>(int(graph.size()), INF);
    auto q = queue<int>();
    distances[source] = 0;
    for (q.push(source); !q.empty(); q.pop()) {
        const int u = q.front();
        for (const auto& e : graph[u]) {
            if (distances[u] + 1 < distances[e.v]) {
                distances[e.v] = distances[u] + 1;
                q.push(e.v);
            }
        }
    }
    return distances;
}

vector<int> findMinLexPath(
        const Graph& graph,
        const int source,
        const int destination) {
    const auto distances = bfs(graph, destination);
    auto path = vector<int>();
    auto adjacent = graph[source];
    for (int d = distances[source]; d > 0; d--) {
        int c = INF;
        for (const auto& e : adjacent) {
            if (d - 1 == distances[e.v]) {
                c = min(c, e.c);
            }
        }
        auto adjacentVertices = unordered_set<int>();
        for (const auto& e : adjacent) {
            if (d - 1 == distances[e.v] && e.c == c) {
                adjacentVertices.insert(e.v);
            }
        }
        adjacent = vector<Edge>();
        for (const auto& v : adjacentVertices) {
            adjacent.insert(adjacent.end(), graph[v].begin(), graph[v].end());
        }
        path.push_back(c);
    }
    return path;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        auto graph = Graph(n);
        for (; m > 0; m--) {
            int u, v, c;
            cin >> u >> v >> c;
            graph[u - 1].push_back(Edge(v - 1, c));
            graph[v - 1].push_back(Edge(u - 1, c));
        }
        const auto path = findMinLexPath(graph, 0, int(graph.size()) - 1);
        cout << int(path.size()) << "\n";
        for (int i = 0; i < int(path.size()); i++) {
            cout << path[i] << (i + 1 < int(path.size()) ? " " : "\n");
        }
    }
    return 0;
}

