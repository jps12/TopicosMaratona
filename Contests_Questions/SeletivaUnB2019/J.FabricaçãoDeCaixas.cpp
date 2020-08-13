#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
vector <ll> divi;
ll area, volume;

void euler(){
ll i;
for (i=1; i*i<=volume; i++){
    if (volume%i==0){
        divi.push_back(i);
        divi.push_back(volume/i);
    }
}
}

int main (){
cin>>volume>>area;
euler();
for (ll i=0; i<divi.size(); i++){
    double raiz = sqrt(divi[i]);
    if (raiz == (ll)raiz){
        ll b = raiz;
        ll h = volume/divi[i];
        if (2*b*b + 4*b*h == area){
            cout<<b<<" "<<h<<endl;
            break;
        }
    }
}
return 0;
}