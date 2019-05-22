#include <bits/stdc++.h>
using ll=long long;
using namespace std;

/*
Questão B da seletiva
Tecnica usada: Busca Binária
*/

vector<int> v; // guardar as qtde de bombons em cada caixa
int maes, caixas, aux, ans;

int fun (ll x){
    int i=0;
    ans=maes;
    for (i=0; i<v.size(); i++){
        ans-=v[i]/x; // Decrementa quantas maes podem receber da caixa v[i]
    }
    return ans; // Se for negativo ou positivo então todas as maes foram presenteadas
}

int binary(ll l, ll r){ 
    if (abs(l-r)==1) return l; // Quando convergir entao o l é o número de bombons pra cada mae 
    ll mid, aux;
    mid = (l+r)/2;
    aux = fun(mid); // A funcao retorna se mais maes ou menos vao receber as qtde mid de bombons
    if (aux<=0){ // então temos um resultado que é valido, mas busca-se o maior valor 
        return binary(mid, r);
    }
    else if (aux>0){ // Caso o numero ainda seja grande
        return binary(l, mid);
    }
}

int main (){  
    ios_base::sync_with_stdio(false);
    
    int ValorMax=0, sum;
    
    cin>>caixas>>maes;
    
    while (caixas--){
        cin>>aux;
        v.push_back(aux);
        ValorMax = max (ValorMax, aux); // Usado pra diminuir o campo de busca do Busca Binária
    }
    sort(v.begin(), v.end()); // Ordenação do vetor pra usar o busca binária
    
    reverse(v.end(), v.begin());
    
    cout<<binary(0, ValorMax+1)<<endl; // O valorMax tem que ser incrementao para o caso de ter só 1 mae
    return 0;
}