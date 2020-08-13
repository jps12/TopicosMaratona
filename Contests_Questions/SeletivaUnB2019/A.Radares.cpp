/*
Questão A da Seletiva UnB
*/

#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second

using namespace std;

int main (){
    int qtde ,comprimento ,limiteVel, radares[1000009], i;
    
    ios_base::sync_with_stdio(false);    
    cin >> comprimento >> qtde >> limiteVel; // Le as variáveis
    
    int l,r,m;
    
    for (i=0 ; i<qtde; i++){
        cin>>l>>r>>m;
        if (m>limiteVel){ // Caso a velocidade seja maior que o limite
            radares[l]++; // Início de um intrvalo de um radar
            radares[r+1]--; // Fim do intervalo de um radar
        }
    }
    int ValorMax=0; // Maior valor da soma prefixa
    for (i=1; i<=comprimento+1; i++){
        radares[i]+=radares[i-1]; // Apenas fazendo uma soma prefixa
        ValorMax = max (ValorMax, radares[i]); // Pegando o maior valor possível de multas
    }
    if (ValorMax==0){ // Se o maior valor for 0, então não teve multas
        cout<<"-1"<<endl;
        return 0;
    }
    
    int aux=0, maior=-1;
    for (i=0; i<=comprimento+1; i++){ // Itera por toda a "Estrada"
        if (radares[i]==ValorMax){ // Se a qtde de multa na posicao i for igual ao valor max, entao aumenta o comprimento do trecho
            aux++;
        }
        else { // Caso for deferente então temos que zerar a contagem do trecho
            aux=0;
        }
        maior = max(aux, maior); // precisamos do maior trecho
    }
    cout<<maior<<endl;
return 0;
}