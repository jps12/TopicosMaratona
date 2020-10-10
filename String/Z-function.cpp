#include <bits/stdc++.h>

using namespace std;
/*
Z-function: retorna um vetor vs em que vs[i] é o maior prefixo entre a string s
e o sufixo que começa em i.
Pode ser usada para verificar quantas vezes uma string aparece em outra.
Complexidade O(n)
*/
void Z_func(vector<int> &vs, string s){
    int n = s.size();
    vs.assign(n, 0);

    for (int i=1, l = 0, r = 0; i<n; ++i){
        if (i <= r) vs[i] = min(r - i + 1, vs[i - 1]);

        while (i + vs[i] < n and s[vs[i]] == s[i + vs[i]]) ++vs[i];

        if (i + vs[i] - 1 > r) l = i, r = i + vs[i] - 1;
    }
}