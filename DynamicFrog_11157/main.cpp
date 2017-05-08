#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int solve() {
    int N, D;
    vector<vector<int>> stones;

    cin >> N >> D;

    stones.push_back(vector<int>());
    stones.back().push_back(0);
    for (int i = 0; i < N; ++i) {
        char rType;
        int dist;

        cin >> rType; cin.ignore(); cin >> dist;

        if (rType == 'B') {
            stones.back().push_back(dist);
            stones.emplace_back(vector<int>());
        }
        stones.back().push_back(dist);
    }

    stones.back().push_back(D);

    int ans = 0;
    for (const auto& s: stones) {
        if (2 == s.size()) {
            ans = max(ans, s[1] - s[0]); 
        }
        else {
            for (size_t i = 2; i < s.size(); ++i) {
                ans = max(ans, s[i] - s[i - 2]);
            }
        }
    }

    return ans;
}

int main() {
    int T;

    cin >> T;
    for (int i = 1; i <= T; ++i) {
       cout << "Case " << i << ": " << solve() << '\n';
    }

    return 0;
}


