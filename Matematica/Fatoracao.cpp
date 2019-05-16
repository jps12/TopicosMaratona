#include <bits/stdc++.h>
#define M 101000
using namespace std;

/*
Essa é uma adaptação do crivo de Eratostones para fatorar todos os números Ate uma cosntante M
em que a complexidade do código fica em O(N*log(N))
*/


map<int, int> fator[M]; // Uma array de maps para guardar o primo e seu expoente 
bool NotPrime[M]; // Array booleano para usar no crivo de Eratostones


void crivo(){
int i, j;
for (i=2; i<M; i++){
    if (!NotPrime[i]){ // checa se esse numero é primo
        fator[i][i]=1; // Se ele é primo então sua fatoração é ele elevado a 1
        for (j=i+i; j*j<M; j+=i){
            NotPrime[j]=true; // Marca esse número como não primo
            
            // ja que "j" é multiplo de i, entao se i^k divide j/i entao i^(k+1) divide j
            if (fator[j/i][i]==0){ // checa o expoente de 'i' para 'j/i'
                fator[j][i]=1; // se não tiver entao o expoente é 1
                fator[j/i].erase(i); // apaga para não encher o map
            }
            else {
                fator[j][i]=fator[j/i][i]+1; // se existir entao o fator[j] para i é o fator[j/i] incrementado 
            }
        }
    }
}
}

int main (){
    crivo();
    while (true){
        int n;
        cin>>n;
        for (auto num: fator[n]){
            printf("%d elevado a %d\n", num.first, num.second);
        }
        cout<<endl;
    }
    return 0;
}