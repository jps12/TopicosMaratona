#include <bits/stdc++.h>
using namespace std;

int main (){
    int i=0, valor;
    vector<int> v, w; // Declaração de um vector (O tipo vem entre o menor que e o maior que)

    v[i]; // Acessa o i-ésimo termo do vector
    v[i]=6; // Atribui valor ao i-ésimo termo 

    auto iterador = v.begin(); // Retorna um iterador do início do vector
    v.end(); // Retorna um iterador do fim do vector

    v.size(); // Retorna O tamanho do vector
    v.empty(); // Retorna um booleano indicando true se o vector estiver vazio
    v.data(); // Retorna o endereço de memória da matriz usada pelo vector

    v.push_back(i); // Insere um valor no final do vector
    v.pop_back(); // Apaga o ultimo  termo do vector
    v.erase(v.begin() + 5); // Apaga o 6º termo do vector 
    v.erase(v.begin()/*Primeiro*/, v.begin()+18/*Segundo*/); // Apaga um intevalo dentro do vector

    v.insert(iterador/*um endereco*/, valor/*Valor a ser inserido*/); //Insere o "valor", na posição "iterador" 
    v.insert(iterador, 5 /*numero de vezes que o termo vai ser inserido*/, valor); // Insere por repetição
    v.insert(iterador, v.begin(), v.end()); // Insere um container a partir do ponto do iterador

    v.swap(w); // Troca os elementos de "v" com os elementos de "w"
    v.clear(); // Remove todos os elementos do vector;
    /*
    Os operadores comparacionais, como o "<", ">", "!=" e "==" comparam lexocográficamente os vectors
    return 0;
    */
}