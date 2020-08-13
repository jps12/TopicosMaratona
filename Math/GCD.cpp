#include <bits/stdc++.h>

using namespace std;

// Essa função retorna no maior divisor comum com uma complexidade log(log(n))
// Tambem é conhecida como algoritimo euclidiano
int gcd(int a, int b) { 
    return b==0? a : gcd(b, a%b); 
}

int main (){
    int a, b;
    cout<<"Insira dois números:"<<endl;
    cin>>a>>b;

    cout<<"O maximo divisor comum desses dois numeros é: "<<gcd(a, b)<<endl;;
}