#include<bits/stdc++.h>
#define x first
#define y second

/*
Questão: H - Quantos caminhos - Seletiva UnB 2019
Tecnicas usadas: Exponenciação Rápida, Aritmética Modular e Combinatória modular.
*/

using namespace std;
using ll=long long;
using ii=pair<int, int>;
const int mod = 1e9 + 7; // O modulo que pede na questão
const int tam = 2e5 + 10;

ll fat[tam], inv[tam]; // Arrays que devolverão o fatorial e o inverso do fatorial ambos em modulo

ll Fexp (ll a, ll b){ // função que retorno a exponenciação rápida
    ll ans =1;
    while (b){
        if (b&1){
            ans = a * ans % mod;
        }
        b = b>>1;
        a = a * a % mod;
    }
    return ans;
}


ll combinatoria (ii a, ii b){ // Calcula quantos caminhos são possíveis entre 'a' e 'b'
    ll x = abs(a.x - b.x);
    ll y = abs(a.y - b.y);
    return (( fat[x+y] * inv[x] ) % mod * inv[y]) % mod; // É a mesma coisa de fazer (x+y)!/(x!*y!) mas em modulo
}

int main (){
    int linhas, colunas, qtdeBuracos, i, j;
    vector<ii> Buracos; // Armazenar os buracos
    ll ans[tam]; // guarda a possibilidade de chegar até o buraco 'i'.
    cin>>linhas>>colunas>>qtdeBuracos;
    fat [0] = inv [0] = 1;
    for (i=1; i<linhas+colunas; i++){
        fat[i] = (fat[i-1] * i) % mod; // Preencher o fatorial.
        inv[i] = Fexp(fat[i], mod - 2); // Preencher o inverso do fatorial
    }
    for (i=0; i<qtdeBuracos; i++){
        int x1, y1;
        cin>>x1>>y1;
        Buracos.push_back({x1, y1}); // Alocando os buracos nos vetores
    }
    
    Buracos.push_back({linhas, colunas}); // Consideremos o ponto final como um buracos pois irá calcular a probabilidade de chegar lá
    sort(Buracos.begin(), Buracos.end()); // ordenar o vetor para diminuir o campo de busca

    for (i=0; i<=qtdeBuracos; i++){
        ans[i] = combinatoria({1, 1}, Buracos[i])%mod; // Probabilidade de chegar nesse buraco.

        for (j=0; j < i; j++){
            if (Buracos[j].x > Buracos[i].x || Buracos[j].y > Buracos[i].y) continue; // Caso essa condição ocorra então não há caminhos que passam por esses dois pontos
            ans[i] = ((ans[i] - ans[j] * combinatoria(Buracos[i], Buracos[j]))%mod + mod)%mod; // Essa parte elimina as contagem repetidas
        }
    }
    cout<<ans[qtdeBuracos]<<endl; 
}