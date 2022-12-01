#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;
using matriz = vector<vector<float>>;
const int tam = 5;

void NomesClientes(string nomes[]);
void telefone(vector<int>
                  &primeiraPArte,
              vector<int> &segundaParte);
int tipo(vector<int> &tipoAss);
int Usominutos(vector<int> &MinutosUsados);
void bancoDados(string *Bnomes, vector<int> &Btipo, vector<int> &BMinutos, vector<int> &primeiraPArte, vector<int> &segundaParte);

int main(int argc, char const *argv[])
{
    matriz mat = {{25.5, 0.10},
                  {35.0, 0.12},
                  {60.0, 0.15}};

    srand(time(NULL));

    string *nome = new string[tam];

    vector<int> tipoAssinatura;
    vector<int> Minusados;
    vector<int> TelPrim;
    vector<int> TelSeg;
    vector<float> Valtconta;

    NomesClientes(nome);
    system("cls");
    tipo(tipoAssinatura);
    Usominutos(Minusados);
    telefone(TelPrim, TelSeg);
    bancoDados(nome, tipoAssinatura, Minusados, TelPrim, TelSeg);
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
    random_device tp;
    mt19937 tipoAle(tp());
    uniform_int_distribution<> tps(0, 2);

    int tipo = rand() % 2;
    for (int i = 0; i < tam; i++)
    {
        tipoAss.push_back(tps(tipoAle));
    }
    for (int i = 0; i < tam; i++)
    {
        return tipoAss[i];
    }
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
    matriz mat = {{25.5, 0.10},
                  {35.0, 0.12},
                  {60.0, 0.15}};
    float *conta = new float[tam];
    float excesso = 0.0;
    for (int i = 0; i < tam; i++)
    {

        if (Btipo[i] == 0 && BMinutos[i] <= 90)
        {
            conta[i] = mat[0][0];
        }
        else if (Btipo[i] == 0 && BMinutos[i] > 90)
        {
            excesso = (BMinutos[i] - 90) * mat[0][1];
            conta[i] = excesso + mat[0][0];
        }
        else if (Btipo[i] == 1 && BMinutos[i] <= 90)
        {
            conta[i] == mat[1][0];
        }
        else if (Btipo[i] == 1 && BMinutos[i] > 90)
        {
            excesso = (BMinutos[i] - 90) * mat[1][1];
            conta[i] = excesso + mat[1][0];
        }
        else if (Btipo[i] == 2 && BMinutos[i] <= 90)
        {
            conta[i] = mat[2][0];
        }
        else
        {
            excesso = (BMinutos[i] - 90) * mat[2][1];
            conta[i] = excesso + mat[2][0];
        }
    }

    cout << "Banco de Dados : " << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "Nome: " << Bnomes[i] << '\n'
             << "Telefone:" << primeiraPArte[i] << "-" << segundaParte[i] << '\n'
             << "Tipo : " << Btipo[i] << '\n'
             << "Uso Minutos: " << BMinutos[i] << '\n'
             << "Conta = R$ " << conta[i] << endl
             << endl;
    }
}