/**
 * Author: Andrei Heidelbacher
 * Task: Bits equalizer
 * Time complexity: O(|S| + |T|)
 * Space complexity: O(|S| + |T|)
 */

#include <iostream>
#include <string>

using namespace std;

int solve(const string& source, const string& target) {
    int sourceOnes = 0, targetOnes = 0;
    int zeroToOne = 0, oneToZero = 0;
    int questionToZero = 0, questionToOne = 0;
    for (int i = 0; i < int(source.length()); i++) {
        sourceOnes += (source[i] == '1' ? 1 : 0);
        targetOnes += (target[i] == '1' ? 1 : 0);
        zeroToOne += (source[i] == '0' && target[i] == '1' ? 1 : 0);
        oneToZero += (source[i] == '1' && target[i] == '0' ? 1 : 0);
        questionToZero += (source[i] == '?' && target[i] == '0' ? 1 : 0);
        questionToOne += (source[i] == '?' && target[i] == '1' ? 1 : 0);
    }
    if (sourceOnes > targetOnes) {
        return -1;
    }
    // we always have a solution from here onward
    int steps = 0;
    while (sourceOnes < targetOnes) { // we need more ones
        if (questionToOne > 0) {
            questionToOne--; // turn a `(?, 1)` pair into a `(1, 1)`
        } else if (zeroToOne > 0) {
            zeroToOne--; // turn a `(0, 1)` pair into a `(1, 1)`
        } else if (questionToZero) {
            questionToZero--;
            oneToZero++; // turn a `(?, 0)` pair into a `(1, 0)`
        }
        sourceOnes++;
        steps++;
    }
    while (questionToZero > 0) {
        questionToZero--;
        steps++; // turn a `(?, 0)` pair into a `(0, 0)`
    }
    while (questionToOne > 0) { // we can't create more ones
        questionToOne--;
        zeroToOne++;
        steps++; // turn a `(?, 1)` pair into a `(0, 1)`
    }
    while (zeroToOne > 0 && oneToZero > 0) {
        --zeroToOne;
        --oneToZero;
        steps++; // swap a `(0, 1)` pair with a `(1, 0)` pair
    }
    return steps;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        string source, target;
        cin >> source >> target;
        cout << "Case " << t << ": " << solve(source, target) << "\n";
    }
    return 0;
}

