#include <bits/stdc++.h>

using namespace std;

struct LCA{
    vector<int> euler, hs, first, seg;

    LCA(vector<vector<int>> &adj, int root = 1){
        int n = adj.size();
        hs.resize(n);
        first.resize(n);
        dfs(adj, root, -1);
        int m = euler.size();
        seg.resize(4*m);
        build(1, 1, m);
    }

    void dfs(vector<vector<int>> &adj, int node, int last, int h = 0){
        first[node] = euler.size();
        euler.push_back(node);
        hs[node] = h;

        for (auto to: adj[node]){
            if (to != last){
                dfs(adj, to, node, h+1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e){
        if (b == e){
            seg[node] = euler[b];
            return;
        }
        int mid = (b+e)/2;
        build(2 * node, b, mid);
        build(2 * node+1 , mid+1, e);
        int l = seg[node * 2], r = seg[node * 2 + 1];
        seg[node] = (hs[l] < hs[r]? l : r);
    }

    int query(int node, int b, int e, int L, int R){
        if (b > R or e < L) return -1;
        if (L <= b and e <= R) return seg[node];

        int mid = (b+e) >> 1;

        int l = query(node << 1, b, mid, L, R);
        int r = query((node << 1 )| 1, mid+1, e, L, R);
        if (l == -1) return r;
        if (r == -1) return l;

        return (hs[l] < hs[r]? l : r);
    }

    int lca(int u, int v){
        u = first[u];
        v = first[v];
        if (v < u) swap(v, u);
        return query(1, 1, euler.size(), u, v);
    }

    int dist(int u, int v){
        int a = lca(u, v);
        return abs(hs[a] - hs[u]) + abs(hs[a] - hs[v]);
    }
};


int main(){
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);

    for (int i=0; i<n-1; i++){
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    struct LCA vs(adj, 1);

    int q;
    cin >> q;

    for (int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;
        cout << vs.dist(l, r) << endl;
    }
}