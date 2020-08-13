#include <bits/stdc++.h>

/*
Questão K 
Técnica usada: Cadeia de Markov, Exponenciação rápida
*/

using namespace std;

int n; // é o número de tipos de refrigerante (tamanho da matriz)

class Matriz{ // Criar um tipo para facilitar 
public:
double mat[110][110];

    Matriz operator *(const Matriz &p){ // Esse método serve para multiplicar duas matrizes
    
        Matriz ans;
    
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                for (int k=ans.mat[i][j]=0; k<n; k++){
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * p.mat[k][j]);
                }
            }
        }
        return ans;
    }
    void Identidade(){ // Cria uma matriz identidade para a exponenciação rápida
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) mat[i][j] = 1;
                else mat[i][j] = 0;
            }
        }
    }
};

Matriz fexp(int exp, Matriz p){ // Faz a Exponenciação rápida
    Matriz ans;
    
    ans.Identidade(); // Cria a matriz identidade
    
    while (exp!=0){
        if (exp&1) {
            ans = ans*p;
        }
        p = p*p;
        exp>>=1;
    }
    return ans;
}

int main (){

int ultimo, preferido, moedas, i;
Matriz probabilidade;

cin>>n>>ultimo>>preferido>>moedas;

for (i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cin>>probabilidade.mat[i][j];
        if (j==preferido) probabilidade.mat[i][j]=0; // Não pode ser contar quando for o refri favorito dele
    }
}
probabilidade = fexp(moedas, probabilidade); // eleva a matriz ao número de moedas
double sum=0;
for (i=0; i<n; i++){
    sum += probabilidade.mat[ultimo][i]; // soma todas as possibilidades saindo do ultimo
}
cout.precision(20); // cuidados para ponto flutuante

cout<<sum<<endl;

return 0;
}

