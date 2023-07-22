// 2D Fenwick Tree
// give sum in matrix from cell (r1,c1) to cell (r2,c2) 
// point update + range query 
// only use in case of range sum query 

// Update TC = O(log(N) * log(M)) 
// Range sum Query TC = O(log(N) * (log(M))

// here fenwick tree (bit tree) is 1-based indexed but while calling update or query function use 0-based indexing 

struct FenwickTree2D {
    int n, m;
    vector<vector<int>> bit;

    FenwickTree2D(vector<vector<int>> &a) {
        n = a.size();
        bit.resize(n+1,vector<int>(m+1,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                update(i, j, a[i][j]);
            }
        }
    }

    // Add x at pos (r, c)
    void update(int r, int c, int x) {
        for (int i = r + 1; i <= n; i += i & -i) {
            for (int j = c + 1; j <= m; j += j & -j) {
                bit[i][j] += x;
            }
        }
    }

    int sum(int r, int c) {
        int s = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            for (int j = c + 1; j > 0; j -= j & -j) {
                s += bit[i][j];
            }
        }
        return s;
    }

    int query(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
    }
};
