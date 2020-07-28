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

nome.size();// retorna o tamanho da string
nome.clear(); // Limpa a string
nome.empty(); // Retorna true se a string estiver vazia

nome.back(); // acessa o último elemento da string
nome.front(); // acessa o primeiro elemento da string


nome.erase(10, 8); // Apaga 8 elementos a partir da 10 posição
nome.erase(5); // Apaga o 5º termo
nome.erase(nome.begin(), nome.begin()+3); // Apaga do inicio da string até 3 posições depois

nome.replace(9, 5, "algo"); // substitui os 5 caracteres a partir da posicao 9 por "algo"
nome.replace(nome.begin(), nome.end()-10, "Hello"); // Substitui o que tá entre esses dois iteradores pela string na função

nome.swap(sobrenome); // Troca o conteudo das duas strings

string substr;

nome.find(substr); // Retorna a posicao do primero caractere da subtring caso encontre
// caso não ache a função acima retorna string::npos
nome.rfind(substr); // Acha a ultima ocorrencia da substring

nome.substr(3, 5); // Retorna uma string relativa a substring 5 caracteres a partir da posicao 3
nome.substr(4); // Retorna uma substring a aprtir da posição 5 ate o final da string original

}