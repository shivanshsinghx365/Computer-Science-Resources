#include<bits/stdc++.h>
using namespace std;



struct data {
    int x;
};

// directly usable segment tree template for range max (with point update as well as range update (using lazy propagation))

struct SEGTREE {

    int N;
    vector<data> tree;
    vector<int> lazy;

    SEGTREE(int n)
    {
        N = n;
        tree.clear();
        tree.resize(4 * N + 3);
        lazy.clear();
        lazy.resize(4 * N + 3);
    }

    data make_data(int val)
    {
        data res;
        res.x = val;
        return res;
    }

    data combine(data a,data b)
    {
        data res;
        res.x = max(a.x, b.x);
        return res;
    }


    void push(int v) 
    {
        tree[v * 2].x += lazy[v];
        lazy[v * 2] += lazy[v];
        tree[v * 2 + 1].x += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void build(vi a, int v, int tl, int tr) 
    {
        if (tl == tr) {
            tree[v] = make_data(a[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }


    void update(int v, int tl, int tr, int l, int r, int val) 
    {
        if (l > r)
            return;
        if (l == tl && tr == r) {
            tree[v].x += val;
            lazy[v] += val;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    // function overloading - same name, two update functions (one for range, and one for point)

    void update(int v, int tl, int tr, int pos, int new_val) 
    {
        if (tl == tr) {
            tree[v] = make_data(new_val);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    data query(int v, int tl, int tr, int l, int r) 
    {
        if (l > r)
            return make_data(-inf);
        if (l <= tl && tr <= r)
            return tree[v];
        push(v);
        int tm = (tl + tr) / 2;
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                       query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

};



