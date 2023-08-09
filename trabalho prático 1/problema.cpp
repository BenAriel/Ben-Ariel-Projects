#include <iostream>
#include "gen�tico.h"
#include "binario.h"
#define red "\033[4;31m"
#define green "\033[32m"
#define default "\033[m"

using namespace std;

int main()
{
	// pedindo para o usu�rio digitar os n�meros iniciais.
	unsigned short s1, s2, s3, s4, s5, s6;
	cout << "Entre com 6 solu��es iniciais (n�meros entre 0 e 65535):";
	cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
	cout << "    resultado da Avalia��o " << endl;
	cout<< "- - - - - - - - - - - - - - -" << endl;
	//chamando a FuncaoAvaliacao e exibindo o resultado das primeiras 6 solu��es informadas pelo usu�rio.
	if (FuncaoAvaliacao(s1) == false)
	{
		//se o retorno da fun��o for um booleano 0, no final ser� escrito um X vermelho.
		cout << red"X"<< default<< endl;
	}
	else
	{
		//se o retorno da fun��o for um booleano 1,no final ser� escrito um OK verde.
		cout << green"OK"<<default<< endl;
	}
	if (FuncaoAvaliacao(s2) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}
	if (FuncaoAvaliacao(s3) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}
	if (FuncaoAvaliacao(s4) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}
	if (FuncaoAvaliacao(s5) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}
	if (FuncaoAvaliacao(s6) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}
	cout << "- - - - - - - - - - - - - - -" << endl;
	//chamando a FuncaoAvaliacao e exibindo o resultado ap�s as solu��es passarem pelos processos gen�ticos.
	if (FuncaoAvaliacao(CruzamentoPontoUnico(s1, s2)) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}
	if (FuncaoAvaliacao(CruzamentoAritimetico(s3, s4)) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
    cout << green"OK" << default << endl;
	}
	if (FuncaoAvaliacao(MutacaoSimples(s5)) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}
	if (FuncaoAvaliacao(MutacaoDupla(s6)) == false)
	{
		cout << red"X" << default << endl;
	}
	else
	{
		cout << green"OK" << default << endl;
	}

}
