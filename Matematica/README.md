
# GCD:
É um algoritmo que calcula o maior divisor comum entre dois números inteiros em complexidade log(log(n)). A linguagem C++ possui ela implementada por padrão usando __gcd(variavelA, variavelB).
 ``` c++
int gcd(int a, int b){ 
    return b==0? a : gcd(b, a%b); 
}
 ```
# Crivo de Eratostones: 

É um algoritmo que gera um vetor onde poderá ser consultado se um número é primo ou não
em complexidade de O(1), mas a construção desse vetor tem complexidade de O(n*log(n)).
Seu funcionamento se baseia em que um número só é primo se for divisível por 1 e ele mesmo
entao o algoritmo passa por todos os números, se ele ainda não foi visitado, então ele é
primo e visitamos todos os seus múltiplos marcando-os. Caso contrário, ou seja, o número
já tenha sido visitado, então ele não é primo. Para deixar o algorimo mais eficiente
é recomendado visitar todos dos multiplos de 1 ate raiz **n**, sendo **n** o maior número 
que deve ser marcado como primo ou não pois o maior divisor possível de um número é a 
própria raiz.

``` c++
void Crivo(){
    int i, j;
    for (i=2; i<1000; i++){
        if (!NotPrime[i]){
            for (j=i+i; j<1000000; j+=i){
                NotPrime[j]=true;
            }
        }
    }
}
```
# Fatoração:

# Permutações: 
## Propriedades:

* Um vetor de tamanho n será uma permutação se não houver nenhum elemento repitido e se seu maior elemento for igual a n;
    * Isso pode diminuir a complexidade de alguns códigos usando somente um set e uma variavel para armazenar o maior valor.