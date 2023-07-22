// Sparse Table
// ONLY USE when range query function is idempotent ( f(a,a) = a ) Example : min , gcd, OR , AND etc.
// sum , XOR is not idempotent so don't use for non idempotent range query function Instead use fenwick tree

// NO POINT UPDATE
// ONLY Range Query
// Range Query TC = O(1)

struct SparseTable {
    int n, LOG;
    vector<vector<int>> table;

    int merge(int x, int y) {
        return min(x, y);
    }

    SparseTable(const vector<int> &a) {
        n = a.size();
        LOG = log2(n);
        table.resize(n,vector<int>(LOG+1,-1);
        for (int j = 0; j <= LOG; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                if (j == 0) table[i][j] = a[i];
                else table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        // int j = __lg(r - l + 1);
        int j = log2(r-l+1);
        return merge(table[l][j], table[r - (1 << j) + 1][j]);
    }
};
