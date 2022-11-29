#include <iostream>
#include <ctime>
#include <vector>
#include <random>
using namespace std;
using matriz = vector<vector<float>>;
const int tam = 2;

void NomesClientes(string nomes[]);
void telefone(vector<int> &primeiraPArte, vector<int> &segundaParte);
int tipo(vector<int> &tipoAss);
int Usominutos(vector<int> &MinutosUsados);
void bancoDados(string *Bnomes, vector<int> &Btipo, vector<int> &BMinutos, vector<int> &primeiraPArte, vector<int> &segundaParte);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    matriz mat = {{25.5, 0.10},
                  {35.0, 0.12},
                  {60.0, 0.15}};

    string *nome = new string[tam];

    vector<int> tipoAssinatura;
    vector<int> Minusados;
    vector<int> TelPrim;
    vector<int> TelSeg;

    NomesClientes(nome);
    system("cls");
    tipo(tipoAssinatura);
    Usominutos(Minusados);
    telefone(TelPrim,TelSeg);
    bancoDados(nome, tipoAssinatura, Minusados, TelPrim,TelSeg);
    return 0;
}
void NomesClientes(string nomes[])
{

    for (int i = 0; i < tam; i++)
    {
        cout << "Digite o Nome do " << i + 1 << "o cliente: " << endl;
        cout << "Nome: ";
        getline(cin, nomes[i]);
    }
    cout << endl;
}
void telefone(vector<int> &primeiraPArte, vector<int> &segundaParte)
{
    for (int i = 0; i < tam; i++)
    {
        primeiraPArte.push_back(rand() % 2000 + 2000);
        segundaParte.push_back(rand() % 2000 + 2000);
    }
}
int tipo(vector<int> &tipoAss)
{
    int tipo = rand() % 2;
    for (size_t i = 0; i < tam; i++)
    {
        tipoAss.push_back(tipo);
    }
    return 0;
}
int Usominutos(vector<int> &MinutosUsados)
{
    random_device mt;
    mt19937 minAleatorios(mt());
    uniform_int_distribution<> min(1, 500);

    for (int i = 0; i < tam; i++)
    {
        MinutosUsados.push_back(min(minAleatorios));
    }
    return 0;
}
void bancoDados(string *Bnomes, vector<int> &Btipo, vector<int> &BMinutos, vector<int> &primeiraPArte, vector<int> &segundaParte)
{

    cout << "Banco de Dados : " << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "Nome: " << Bnomes[i] << '\n'
             << "Telefone:" << primeiraPArte[i] << "-" << segundaParte[i] << '\n'
             << "Tipo : " << Btipo[i] << '\n'
             << "Uso Minutos: " << BMinutos[i] << endl
             << endl;
    }
}
