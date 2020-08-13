#include <bits/stdc++.h>

using namespace std;

long long binary_exponenciation(long long  base, long long exp, long long m){
    long long ans = 1; // Caso inicial e = 0 ans = 1

    while (exp){
        if (exp & 1) { // Se o ultimo bit do expoente tiver on
            ans = (ans * base) % m;
        }
        base = (base  * base) % m;
        exp >>= 1;
    }

    return ans;
}