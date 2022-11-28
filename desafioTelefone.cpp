#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const int tam = 2;
void NomesClientes(string nomes[]);
void telefones();

int main(int argc, char const *argv[])
{
srand(time(NULL));
    string *nome = new string[tam];
    int *tel = new int[tam];
    NomesClientes(nome);

    return 0;
}
void NomesClientes(string nomes[])
{
    cout << "Digite os Nome dos clientes:\n ";
    for (int i = 0; i < tam; i++)
    {
        getline(cin, nomes[i]);
    }
    cout << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "Nome: " << nomes[i] << endl;
        cout << "Telefone: ";
        telefones();
        cout << endl;
    }
}
void telefones()
{
    vector<int> tl;
    for (int i = 0; i < 2; i++)
    {
       tl.push_back(rand()% 2000 + 2000);
    }
    for(auto x : tl){
        cout << x;
        cout << "-";
    }  
}
