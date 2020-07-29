#include<bits/stdc++.h>

using namespace std;

void Radix_sort_pair(vector<pair<pair<int,int>, int>> &v, int pos){
    int n = v.size(), max_num = 0;

    for (int i=0; i<n; i++){
        if (pos == 1) max_num = max(max_num, v[i].first.first);
        else max_num = max(max_num, v[i].first.second);
    }
    vector<int> cnt(max_num + 1, 0), p(n);

    for (int i=0; i<n; i++){
        if (pos == 1) cnt[v[i].first.first]++;
        else cnt[v[i].first.second]++;
    }

    p[0] = 0;
    for (int i=1; i<n; i++){
        p[i] = p[i-1] + cnt[i-1];
    }

    vector<pair<pair<int,int>, int>> new_v(n);

    for (int i=0; i<n; i++){
        if (pos == 1) new_v[p[v[i].first.first]++] = v[i];
        else new_v[p[v[i].first.second]++] = v[i];
    }

    v = new_v;
}

void Radix_Sort(vector<pair<pair<int,int>, int>> &v){
    Radix_sort_pair(v, 2);
    Radix_sort_pair(v, 1);
}

void Init_Suffix_Array(vector<int> &p, vector<int> &c, string s){
    int n = s.size();
    vector<pair<char, int>> a(n);

    // Salving the caractere that start the suffix and their indices 
    for (int i=0; i<n; i++) a[i] = {s[i], i};

    // Sort all
    sort(a.begin(), a.end());

    // Generate the suffix array initial
    for (int i=0; i<n; i++) p[i] = a[i].second;

    // Updating the classes, if the suffix are equals they have same class, otherwise differents classes
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

vector<int> Suffix_Array(string s){
    // Add caractere '&' like less that all others
    s += '$';
    int n = s.size();
 
    vector<int> p(n), c(n);
    Init_Suffix_Array(p, c, s);
 
    int k = 0;
    // analyzing the suffix with size power of two, for the complexity log(n)
    while ((1 << k) <= n){ // While the size of all arrys is less than original string 
        vector<pair<pair<int, int>, int>> a(n);

        // Saving the class of the two parts of suffix and their indice
        for (int i=0; i<n; i++){
            a[i] = {{c[i],c[(i + (1 << k))%n]}, i};
        }
    
        // You can sort By radix sort because the max numbre is less than n
        Radix_Sort(a);
    
        // Saving the indice "father" of the suffix
        for (int i=0; i<n; i++){
            p[i] = a[i].second;
        }
 
        c[p[0]] = 0;
 
        for (int i=1; i<n; i++){
            c[p[i]] = c[p[i-1]];
            if (a[i].first != a[i-1].first) c[p[i]]++;
        }
 
        k++;
    }
    
    // the vector "p" will be the suffix array
    return p;
}

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

vector<int> Suffix_Array_Optimized(string s){
    s += '$';
    int n = s.size();

    vector<int> p(n), c(n);
    Init_Suffix_Array(p, c, s);

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
    return p;
}

int main (){
    string s;
    cin >> s;

    vector<int> p = Suffix_Array_Optimized(s);

    for (auto it : p) cout << it << " ";
    cout << endl;
}