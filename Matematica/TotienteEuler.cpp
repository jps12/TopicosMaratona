#include<bits/stdc++.h>

using namespace std;

vector<int> divisores;

// funçao que retorna o maior divisor em comum
int gcd (int a, int b){return a==0?  b : gcd(b%a, a);}

// A função phi retorna o numero de numeros coprimos de "a"
// Numero coprimo é quando o maior divisor comum entre os dois é 1
int phi(int a){
    int result=1 ,i;
    for (i=2; i<a; i++){
        if (gcd(a, i)==1){
            result++;
        }
    }
    return result;
}

/*
Com uma pequena alteração podemos usar essa função para calcular o numero de divisores e quais são esses divisores
A complexidade é O(sqrt(n))
*/

int phiDivisores(int n){
    int i, NumDiv=0;
    for (i=1; i*i<n; i++){
        if(n%i==0){
            NumDiv++;
            divisores.push_back(i);
            if (i*i<n){
                NumDiv++;
                divisores.push_back(n/i);
            }
        }
    }
    return NumDiv;
}