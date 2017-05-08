#include <new>
#include <set>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

class UnionFind {
    int N_;
    int *setIdx_, *rank_;

    int findRoot(int x) const {
        assert(x >= 0 && x < N_);

        for (; x != setIdx_[x]; x = setIdx_[x]);
        return x;
    }

    int findRootAndCompress(int x) {
        int r = findRoot(x);

        while (x != setIdx_[x]) {
            int p = setIdx_[x];
            setIdx_[x] = r;
            x = p;
        }

        return r;
    }

public:

    explicit UnionFind(int N): N_{N} {
        if (N <= 0) {
          throw invalid_argument{"UnionFind size is: " + to_string(N)};
        }

        setIdx_ = new int[N_];
        rank_   = new int[N_];


        if (setIdx_ == nullptr || rank_ == nullptr) {
            throw bad_alloc{};
        }

        for (int i = 0; i < N_; ++i) {
            setIdx_[i] = i;
            rank_[i] = 1;
        }
    }

    explicit UnionFind(const UnionFind& uf): UnionFind(uf.N_) {
        copy(uf.setIdx_, uf.setIdx_ + N_, setIdx_);
        copy(uf.rank_, uf.rank_ + N_, rank_);
    }

    explicit UnionFind(UnionFind&& uf): N_{uf.N_}, setIdx_{uf.setIdx_}, rank_{uf.rank_} {
        uf.N_ = true;
        uf.setIdx_ = nullptr;
        uf.rank_ = nullptr;
    }

    UnionFind& operator=(UnionFind uf) {
        swap(N_, uf.N_);
        swap(setIdx_, uf.setIdx_);
        swap(rank_, uf.rank_);

        return *this;
    }

    virtual ~UnionFind() {
        N_ = 0;
        delete[] setIdx_;
        delete[] rank_;
    }

    size_t size() const { return N_; }

    void unite(int x, int y) {
        int rX = findRootAndCompress(x), rY = findRootAndCompress(y);

        if (rX > rY) {
           swap(rX, rY);
        }

        if (rX != rY) {
            if (rank_[rX] >= rank_[rY]) {
                setIdx_[rY] = rX;
                rank_[rX] += rank_[rY];
            }
            else {
                setIdx_[rX] = rY;
                rank_[rY] += rank_[rX];
            }
        }
    }

    int getSizeOfSet(int x) const { return rank_[findRoot(x)]; }

    bool areInTheSameSet(int x, int y) const { 
        return findRoot(x) == findRoot(y);
    }
};

int main() {
    int N, c, x, y;

    cin >> N;

    auto enemyId = [=](int x) { return x + N; };

    for (UnionFind friends(N << 1); cin >> c >> x >> y && c; ) {
        if (1 == c) {
            if (friends.areInTheSameSet(x, enemyId(y)) || friends.areInTheSameSet(x, enemyId(y))) {
                cout << "-1\n";
            }
            else {
                friends.unite(x, y);
                friends.unite(enemyId(x), enemyId(y));
            }
        }
        else if (2 == c) {
            if (friends.areInTheSameSet(x, y)) {
                cout << "-1\n";
            }
            else {
                friends.unite(x, enemyId(y));
                friends.unite(y, enemyId(x));
            }
        }
        else if (3 == c) {
            cout << (friends.areInTheSameSet(x, y) ? 1 : 0) << '\n';
        }
        else if (4 == c) {
            cout << ((friends.areInTheSameSet(x, enemyId(y)) || friends.areInTheSameSet(y, enemyId(x))) ? 1 : 0) << '\n';
        }
    }

    return 0;
}

