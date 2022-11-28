#include <iostream>

using namespace std;

const int tam = 4;
void NomesClientes(string nomes[]);
int main(int argc, char const *argv[])
{
    string *nome = new string[tam];
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
        cout << nomes[i] << endl;
    }
}
