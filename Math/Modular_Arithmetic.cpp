#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7, N = 1e5;
int fat[N], invfat[N];

int fexp(int a, int b){
    int ans = 1;

    while(b){
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b = b >> 1;
    }
    return ans;
}

int add(int a, int b) {
    return (a + b >= mod? a + b - mod : a + b);
}

int sub(int a, int b){
    return (a - b > 0? a - b + mod : a - b);
}

int mul(int a, int b){
    return (1LL * a * b % mod);
}

int div(int a, int b){
    return (1LL * a * fexp(b, mod-2) % mod);
}

void Create_invfat(){
    fat[0] = fat[1] = 1;

    for (int i=2; i<N; i++){
        fat[i] = mul(fat[i-1], i);
    }

    invfat[N-1] = fexp(fat[N-1], mod -2);

    for (int i=N-2; i>=0; i--){
        invfat[i] = mul(invfat[i+1], i+1);
    }
}