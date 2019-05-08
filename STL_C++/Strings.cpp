#include <string>
using namespace std;

int main (){

// Construtor padrão
string nome("Nome");
string nome = "Nome";

// Construtor do cópia
string nome2(nome);
string nome2 = nome;

// Construtor via array 
char nome3[] = "Nome Completo";
string nome4(nome3);

// Construção por repeticao;
string letra(3, 'E'); // gera a string "EEE";

// Mudando o n-ésimo termo da string
int n;
nome[n-1]='a';

// Remover o último caractere da string 
nome.pop_back();

// Adicionando elementos no final da string 
nome.push_back('a');

// somando string 
nome += "Completo";
nome.append("Completo");

// Os operadores de comparação também já estão implementados em C++
// portanto as seguintes operações são validas:
string sobrenome;
nome == sobrenome;
nome != sobrenome;
nome < sobrenome;
nome > sobrenome;
// Detalhe: uma string é menor que a outra quando ela vem antes na ordenação alfabética

// Convesores de string 
stoi("333"); // string para int
stoll("333"); // string para long long 
stoull("333"); // string para unsigned long long 
stof("3.99"); // string para float
stod("3.99"); // string para double
stold("3.99"); // string para long double


to_string(123.54); // converte de qualquer tipo para string

}