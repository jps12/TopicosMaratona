#include <bits/stdc++.h>
const int oo = 1e5 +10;
using namespace std;

/*
Questão C Seletiva UnB
Técnica usada: DFS
*/

vector <int>relacoes[oo]; // Armazenar as relações
set<int> visited; // Armazenar os pontos visitados

// O dfs vai marcar os pontos visitados
void dfs(int pessoa){
    if (visited.count(pessoa)) return;
    visited.insert(pessoa);

    for (auto person: relacoes[pessoa]){
        dfs(person);
    }
}

int main (){
    int habitantes, numRelacoes;
    cin>>habitantes>>numRelacoes;
    while (numRelacoes--){
        int a, b;
        cin>>a>>b;
        relacoes[a].push_back(b); // Armazenando as relações que são bidirecionais
        relacoes[b].push_back(a);
    }
    int apurados, pessoa;

    cin>>apurados;

    while (apurados--){
        cin>>pessoa;
        dfs(pessoa); // Pra cada pessoa apurada checa-se quais teriam o mesmo voto dela
    }
    int ans=0;
    for (int i=1; i<=habitantes; i++){
        if (visited.size()==habitantes){ // Se o numero de visitados for o numero de habitantes então já apurou todos os votos
            break;
        }
        if (!visited.count(i)){ // se ele não foi visitado então marca ele e suas relações no dfs e incrementa a resposta
            ans++;
            dfs(i);
        }
    }
    cout<<ans<<endl;
return 0;
}

