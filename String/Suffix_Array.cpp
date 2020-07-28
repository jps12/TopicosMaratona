#include<bits/stdc++.h>

using namespace std;

vector<int> Suffix_Array(string s){
    // Add caractere '&' like less that all others
    s += '$';
    int n = s.size();
 
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        // Salving the caractere that start the suffix and its indices 
        for (int i=0; i<n; i++) a[i] = {s[i], i};
        
        // Sorting all
        sort(a.begin(), a.end());
    
        // With the suffixes sorted, save the indices 
        for (int i=0; i<n; i++) p[i] = a[i].second;

        c[p[0]] = 0;

        for (int i=1; i<n; i++){
            // If the caracteres equals, they are in the same class, otherwise are from diferents classes
            c[p[i]] = c[p[i-1]];
            if (a[i].first != a[i-1].first) c[p[i]]++;
        }
    }
 
    int k = 0;
    // analyzing the suffix with size power of two, for the complexity log(n)
    while ((1 << k) <= n){ // While the size of all arrys is less than original string 
        vector<pair<pair<int, int>, int>> a(n);

        // Saving the class of the two parts of suffix and their indice
        for (int i=0; i<n; i++){
            a[i] = {{c[i],c[(i + (1 << k))%n]}, i};
        }
 
        sort(a.begin(), a.end());
    
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

int main (){
    string s;
    cin >> s;

    vector<int> p = Suffix_Array(s);

    for (auto it : p ) cout << it << " ";
    cout << endl;
}