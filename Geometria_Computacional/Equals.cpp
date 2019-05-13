/*
Como as operações com double podem haver algum erro ou propagação de erros
recomenda-se o uso da função equals para comparar dois valores double para
assim o programa não retornar falso para checar se dois double são iguais,
pois em alguma casa decimal bem baixa pode haver um erro bem irrisório.
Para isso define-se uma margem ou limite para considerar dois números iguais
geralmente usa-se 1e-9
*/

#include <bits/stdc++.h>
#define EPS 1e-18

using namespace std;

bool equals(double a, double b){
    return fabs(a-b) < EPS;
}

int main (){
    double a=0.1, b= 1.0/10.0;

    if (equals(a, b)) cout<<"teste"<<endl;
    return 0;
}