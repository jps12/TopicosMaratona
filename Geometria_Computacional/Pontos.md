#Pontos

Em competições há três pricipais maneiras de se representar pontos no computador: em classes/structs, por pairs e por arrays - sendo a última a menos usada.
* Por pairs tem a vantagem de ter algumas funções já implementadas por padrão, como operadores da atribuiçao e comparação.
* Por classes/structs tem a vantagem de poder implentar funções novas como definir a norma de um vetor definido pelo ponto.

## Distância entre pontos:

Para calcular a distancia entre pontos recomenda-se o uso da funcao hypot(), por diminuir o erro de ponto flutuante:
    Assim fica a função DistanciaEntrePontos():
    
    double DistanciaEntrePontos(pair<int, int> P, pair<int, int> Q){
        return hypot(P.first - Q.first, P.second - Q.second);
    }
