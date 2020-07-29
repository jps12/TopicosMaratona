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

void Radix_Sort(vector<pair<int,int>> &v){
    Radix_sort_pair(v, 2);
    Radix_sort_pair(v, 1);
}

void Radix_sort_pair(vector<pair<int, int>> &v, int pos){
    int n = v.size(), max_num = 0;

    for (int i=0; i<n; i++){
        if (pos == 1) max_num = max(max_num, v[i].first);
        else max_num = max(max_num, v[i].second);
    }
    vector<int> cnt(max_num + 1), p(n);

    for (int i=0; i<n; i++){
        if (pos == 1) cnt[v[i].first]++;
        else cnt[v[i].second]++;
    }

    for (int i=1; i<n; i++){
        p[i] = p[i-1] + cnt[i-1];
    }

    vector<pair<int, int>> new_v(n);

    for (int i=0; i<n; i++){
        if (pos == 1) new_v[p[v[i].first]] = v[i];
        else new_v[p[v[i].second]] = v[i];
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