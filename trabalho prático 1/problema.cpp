#include <iostream>
#include "genético.h"
#include "binario.h"
#define red "\033[4;31m"
#define green "\033[32m"
#define default "\033[m"

using namespace std;

int main()
{
	// pedindo para o usuário digitar os números iniciais.
	unsigned short s1, s2, s3, s4, s5, s6;
	cout << "Entre com 6 soluções iniciais (números entre 0 e 65535):";
	cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
	cout << "    resultado da Avaliação " << endl;
	cout<< "- - - - - - - - - - - - - - -" << endl;
	//chamando a FuncaoAvaliacao e exibindo o resultado das primeiras 6 soluções informadas pelo usuário.
	if (FuncaoAvaliacao(s1) == false)
	{
		//se o retorno da função for um booleano 0, no final será escrito um X vermelho.
		cout << red"X"<< default<< endl;
	}
	else
	{
		//se o retorno da função for um booleano 1,no final será escrito um OK verde.
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
	//chamando a FuncaoAvaliacao e exibindo o resultado após as soluções passarem pelos processos genéticos.
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
