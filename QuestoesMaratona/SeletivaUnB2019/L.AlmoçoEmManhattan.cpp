#include <bits/stdc++.h>
/*
Questão L
*/
using namespace std;

int main (){
    int x, y, qtde, menor = 200000000; // Um numero maior que os preços possíveis
    pair<int, int> ans; // Vai guardar a melhor resposta
    cin>>qtde>>x>>y;
    for (int i=0; i<qtde; i++){
        int a, b, price;
        cin>>a>>b>>price;
        int aux = min(menor, (abs(x-a)+abs(y-b))*2 + price); // Ve qual é o menor preço
        if (menor != aux){ // Se for diferente então quer dizer que o preço é menor
            menor = aux;
            ans = {menor, i+1}; // Guarda tambem qual restaurante
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
}