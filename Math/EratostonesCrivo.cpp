#include<bits/stdc++.h>

using namespace std;
bool NotPrime[100000];
vector<int> primos;
/*
A função do crivo marca todos os números não-primos.
Com uma complexidade menor que checar se o número é divisivel por um e por ele mesmo.
*/
void Crivo(){
    int i, j;
    for (i=2; i<100000; i++){
        if (!NotPrime[i]){
            for (j=i+i; j<100000; j+=i){
                NotPrime[j]=true;
            }
        }
    }
}

/*
Com uma pequena alteração no algoritmo podemos guardar esses primos encontrados
*/

void Crivo(){
    int i, j;
    for (i=0; i<100000; i++){
        if (!NotPrime[i]){
            primos.push_back(i);
            for (j=i+i; j<100000; j+=i){
                NotPrime[j]=true;
            }
        }
    }
}

// Observe que na linha 29 dou um push_back no numero considerado primo e guardo