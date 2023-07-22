// Fenwick tree | Binary Indexed Tree (BIT) 
// point update + range sum query
// point update TC = O(log(N))
// range sum query TC = O(log(N))

// here i have used 1-based fenwick tree (bit tree) but while calling update or query use 0-based indexing
// like for getting sum from (0,5) call query(0,5) 

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(vector<int> &a) {
        n = a.size();
        bit.resize(n+1,0);
        for (int i = 0; i < n; i++) update(i, a[i]);
    }

    // Add x at pos i
    void update(int i, int x) {
        for (i++; i <= n; i += i & -i) bit[i] += x;
    }

    // sum from 0 to i
    int sum(int i) {
        int s = 0;
        for (i++; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

    int query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
