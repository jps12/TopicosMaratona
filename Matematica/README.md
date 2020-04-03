
# GCD:
É um algoritmo que calcula o maior divisor comum entre dois números inteiros em complexidade log(log(n)). A linguagem C++ possui ela implementada por padrão usando __gcd(variavelA, variavelB).
 ``` c++
int gcd(int a, int b){ 
    return b==0? a : gcd(b, a%b); 
}
 ```

# Fatoração:

# Crivo de Eratostones: 
# Permutações: 
## Propriedades:
* Um vetor de tamanho n será uma permutação se não houver nenhum elemento repitido e se seu maior elemento for igual a n;
    * Isso pode diminuir a complexidade de alguns códigos usando somente um set e uma variavel para armazenar o maior valor.