#include <iostream>

using namespace std;

long long int numEdges (int N) { return (1LL * N * (N - 1)) >> 1; }

int main() {
    int T, N;
    long long int M;

    for (cin >> T; T; --T) {
        cin >> N >> M;

        if (N > M) cout << M << '\n';
        else {
            int ans;
            for (ans = 1; ans <= N; ++ans) {
                if (M - numEdges(ans) <= N - ans) break;
            }

            cout << (N - ans) << '\n';

            /*
            int lo = 1, hi = N;

            while (lo < hi) {
                 int mid = lo + ((hi - lo) >> 1);

                if (M - numEdges(mid) <= N - mid) hi = mid;
                else lo = mid + 1;
            }

            cout << (N - lo) << '\n';
            */
//            cout << "Ans for " << N << ' ' << M << ": (" << lo << ") " << (N - lo) << '\n';
        }
    }

    return 0;
}
