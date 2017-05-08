#include <array>
#include <iostream>
#include <algorithm>


using namespace std;

bool solve() {
    array<int, 2> prince;
    array<int, 3> princess;
    array<int, 53> cards;

    fill(cards.begin(), cards.end(), 53);
    for (int i = 1, x; i <= 5; ++i) {
        cin >> x;
        cards[x] = i;
    }

    if (cards[0] == 5) return false;

    for (int i = 1, countPrince = 0, countPrincess = 0; i <= 52; ++i) {
        if (cards[i] <= 3) {
            princess[countPrincess++] = i;
        }
        else if (cards[i] <= 5) {
            prince[countPrince++] = i;
        }
    }

    int i = -1;

    if (prince[0] > princess[2]) {
      for (i = 1; i <= 52 && cards[i] != 53; ++i);
    }
    else if (prince[0] > princess[1]) {
      for (i = princess[1] + 1; i <= 52 && cards[i] != 53; ++i);
    }
    else if (prince[1] > princess[2]) {
      for (i = princess[2] + 1;  i <= 52 && cards[i] != 53; ++i);
    }

    if (i <= 52) cout << i << "\n";
    else cout << "-1\n";
    

    return true;
}


int main() {
    
    while (solve());

    return 0;
}
