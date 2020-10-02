#include <bits/stdc++.h>

using namespace std;

template<typename T>
class SegTree{
    private:
        vector<T> vs, lz;
        int sz;
        void push(int i, int l, int r){
            vs[i] += lz[i];
            if (l < r){
                lz[i*2+1] += lz[i];
                lz[i*2] += lz[i];
            }
            lz[i] = 0;
        }
        void update(int i, int l, int r, T val, int p){
            if (l == r){
                vs[i] = val;
                return;
            }
            int mid = (l + r) / 2;
            if (p <= mid) update(2*i, l, mid, val, p);
            update(2*i+1, mid+1, r, val, p);
        }
        void update(int i, int l, int r, T val, int ql, int qr){
            push(i, l, r);
            if (ql <= l and r <= qr){
                lz[i] = val;
                push(i, l, r);
            }
            if (qr < l or ql > r) return;
            int m = (l+r) / 2;
            i <<= 1;
            update(i, l, mid, val, ql, qr);
            update(i+1, mid+1, r, val, ql, qr);
        }

        T query(int i, int l, int r, int ql, int qr){
            push(i, l, r);
            if (ql <= l and r <= qr){
                return vs[i];
            }
            if (qr < l or ql > r) return 0;
            int m = (l+r) / 2;
            i <<= 1;
            T a, b;
            a = query(i, l, mid, val, ql, qr);
            b = query(i+1, mid+1, r, val, ql, qr);
            return a + b;
        }
        
    public:
        SegTree(int n){
            vs.assign(4*n, 0);
            lz.assign(4*n, 0);
            sz = n;
        }
        void update(int pos, T val){
            update(1, 1, sz, val, pos);
        }
        void update(int l, int r, T val){
            update(1, 1, sz, val, l, r);
        }
        T query(int l, int r){
            return query(1, 1, sz, l, r);
        }
};