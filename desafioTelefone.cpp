#include <iostream>
#include <ctime>
#include <vector>
#include <random>
#include <iomanip>
#include <windows.h>
using namespace std;
using matriz = vector<vector<float>>;
using vetInt = vector<int>;
using vetFloat = vector<float>;

const int tam = 5;

void NomesClientes(string nomes[]);
void telefone(vetInt &primeiraPArte, vetInt &segundaParte);
int tipo(vetInt &tipoAss);
int Usominutos(vetInt &MinutosUsados);
void bancoDados(string *Bnomes, vetInt &Btipo, vetInt &BMinutos, vetInt &primeiraPArte, vetInt &segundaParte, vetFloat &conta);
void CalculaValor(vetInt &Btipo, vetInt &BMinutos, vetFloat &conta);

int main(int argc, char const *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    matriz mat = {{25.5, 0.10},
                  {35.0, 0.12},
                  {60.0, 0.15}};

    srand(time(NULL));

    string *nome = new string[tam];

    vetInt tipoAssinatura;
    vetInt Minusados;
    vetInt TelPrim;
    vetInt TelSeg;
    vetFloat Valtconta;
    vetFloat Valor;

    NomesClientes(nome);
    system("cls");
    tipo(tipoAssinatura);
    Usominutos(Minusados);
    telefone(TelPrim, TelSeg);
    CalculaValor(tipoAssinatura, Minusados, Valor);
    bancoDados(nome, tipoAssinatura, Minusados, TelPrim, TelSeg, Valor);
    return 0;
}
void NomesClientes(string nomes[])
{

    for (int i = 0; i < tam; i++)
    {
        cout << "Digite o Nome do " << i + 1 << "º cliente: " << endl;
        cout << "Nome: ";
        getline(cin, nomes[i]);
        cout << '\n';
    }
    cout << endl;
}
void telefone(vetInt &primeiraPArte, vetInt &segundaParte)
{
    for (int i = 0; i < tam; i++)
    {
        primeiraPArte.push_back(rand() % 2000 + 2000);
        segundaParte.push_back(rand() % 2000 + 2000);
    }
}
int tipo(vetInt &tipoAss)
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
int Usominutos(vetInt &MinutosUsados)
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
void bancoDados(string *Bnomes, vetInt &Btipo, vetInt &BMinutos, vetInt &primeiraPArte, vetInt &segundaParte, vetFloat &conta)
{
    cout << fixed << setprecision(2);
    cout << "Banco de Dados : " << endl
         << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "Nome.......: " << Bnomes[i] << '\n'
             << "Telefone...: "
             << "(11)" << primeiraPArte[i] << "-" << segundaParte[i] << '\n'
             << "Tipo.......: " << Btipo[i] << '\n'
             << "Uso Minutos: " << BMinutos[i] << '\n'
             << "Conta = R$ " << conta[i] << endl
             << endl;
    }
}
void CalculaValor(vetInt &Btipo, vetInt &BMinutos, vetFloat &conta)
{
    matriz mat = {{25.5, 0.10},
                  {35.0, 0.12},
                  {60.0, 0.15}};
    float excesso = 0.0;
    for (int i = 0; i < tam; i++)
    {

        if (Btipo[i] == 0 && BMinutos[i] <= 90)
        {
            conta.push_back(mat[0][0]);
        }
        else if (Btipo[i] == 0 && BMinutos[i] > 90)
        {
            excesso = (BMinutos[i] - 90) * mat[0][1];
            conta.push_back(excesso + mat[0][0]);
        }
        else if (Btipo[i] == 1 && BMinutos[i] <= 90)
        {
            conta.push_back(mat[1][0]);
        }
        else if (Btipo[i] == 1 && BMinutos[i] > 90)
        {
            excesso = (BMinutos[i] - 90) * mat[1][1];
            conta.push_back(excesso + mat[1][0]);
        }
        else if (Btipo[i] == 2 && BMinutos[i] <= 90)
        {
            conta.push_back(mat[2][0]);
        }
        else
        {
            excesso = (BMinutos[i] - 90) * mat[2][1];
            conta.push_back(excesso + mat[2][0]);
        }
    }
}