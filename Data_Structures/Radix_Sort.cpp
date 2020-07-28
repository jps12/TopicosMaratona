#include <bits/stdc++.h>

using namespace std;

void Radix_Sort(vector<int>& v){
    int n = v.size(), max_num = 0;
    for (int i=0; i<n; i++) max_num = max(max_num, v[i]);

    vector<int> cnt(max_num+1, 0), pos(max_num + 1, 0);

    for (int i=0; i<n; i++){
        cnt[v[i]]++;
    }

    vector<int> new_v(n);
    for(int i=1; i<=max_num; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }

    for (int i=0; i<n; i++){
        new_v[pos[v[i]]] = v[i];
        pos[v[i]]++;
    }

    v = new_v;
}

int main (){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i=0; i<n; i++) cin >> v[i];

    Radix_Sort(v);

    for (int i=0; i<n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}