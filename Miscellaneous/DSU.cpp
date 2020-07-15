#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

// #define DEBUG 100

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100010;
const double PI = acos(-1);
int parent[maxn], size[maxn];

void init(){
    for (int i=0; i<maxn; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x){
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void uni(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (size[a] > size[b]) swap(a, b);

    parent[a] = b;
    size[b] += size[a];
}
int main (){
    int n, m;
    cin >> n >> m;
    init();

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        uni(a, b);
    }

    for (int i=1; i<=n; i++){
        cout << i << " " << find(i) << " " << size[find(i)] << endl;
    }
    return 0;
}