#include <array>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int idx(char ch) { return ch >= '0' && ch <= '9' ? ch - '0' : ch - 'A' + 10; }

long long solve(const string& board) {
    int N = board.size();
    array<array<long long int, 15>, 15> dp;

    if (board[0] == '?') {
        for (int i = 0; i < N; ++i) dp[0][i] = 1;
    }
    else {
        for (int i = 0; i < N; ++i) dp[0][i] = 0;
        dp[0][idx(board[0]) - 1] = 1;
    }

    for (int i = 1; i < N; ++i) {
        if (board[i] == '?') {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = 0;
                for (int k = 0; k < j - 1; ++k) dp[i][j] += dp[i - 1][k];
                for (int k = j + 2; k < N; ++k) dp[i][j] += dp[i - 1][k];
            }
        } else {
            int p = idx(board[i]) - 1;
            for (int j = 0; j < N; ++j) dp[i][j] = 0;
            for (int k = 0; k < p - 1; ++k) dp[i][p] += dp[i - 1][k];
            for (int k = p + 2; k < N; ++k) dp[i][p] += dp[i - 1][k];
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) ans += dp[N - 1][i];

    return ans;
}

int main() {

    for (string line; cin >> line; ) {
        cout << solve(line) << '\n';
    }

    return 0;

}
