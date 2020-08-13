#include <bits/stdc++.h>
/*
Using suffix Array we can create the array LCP 
Longest Common Prefix 
*/
using namespace std;

void Count_Sort(vector<int> &p, vector<int> &c){
    int n = p.size();

    vector<int> cnt(n, 0), pos(n);
    vector<int> new_p(n);

    for (auto x: c) cnt[x]++;

    pos[0] = 0;
    for (int i=1; i<n; i++){
        pos[i] = pos[i-1] + cnt[i-1];
    }


    for (int i=0; i<n; i++){
        int x = c[p[i]];
        new_p[pos[x]] = p[i];
        pos[x]++;
    }
    p = new_p;
}


int main(){
    string s;
    cin >> s;

    s += '&';

    int n = s.size();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);

        for (int i=0; i<n; i++) a[i] = {s[i], i};

        sort(a.begin(), a.end());

        for (int i=0; i<n; i++) p[i] = a[i].second;

        c[p[0]] = 0;
        for (int i=1; i<n; i++){
            if (a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }

    int k = 0;
    while ((1 << k) <= n){

        for (int i=0; i<n; i++){
            p[i] = (p[i] - (1 << k) + n) % n;
        }
        
        Count_Sort(p, c);

        vector<int> new_c(n);
        new_c[p[0]] = 0;

        for (int i=1; i<n; i++){
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << k)) % n]};
            pair<int, int> atual = {c[p[i]], c[(p[i] + (1 << k)) % n]};

            if (prev == atual) {
                new_c[p[i]] = new_c[p[i-1]];
            }
            else {
                new_c[p[i]] = new_c[p[i-1]] + 1;
            }
        }

        c = new_c;
        k++;
    }

    // initialize the lcp array, and the less commmon prefix (k)
    vector<int> lcp(n);
    k = 0;
    for (int i=0; i<n-1; i++){
        // pi = Actual position of suffix started at indice i
        int pi = c[i];
        // j = Previsous suffix in the suffix array 
        int j = p[pi - 1];

        // counting the size of prefix
        while(s[i + k] == s[j + k]) k++;

        // Update o lcp do suffix
        lcp[pi] = k;

        // Update the less size of common prefix 
        k = max(k-1, 0);
    }
}