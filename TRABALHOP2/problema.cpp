#include <iostream>
#include<cmath>
#include <ctime>
#include "mosca.h"
#define vermelho "\033[4;31m"
#define default "\033[m"
using namespace std;

int main()
{
	mosca moscas[10]{};

	for (int i = 0; i < 10; i++)
	{
		//ler as moscas e suas cores rgb;
		cin >> moscas[i];

	}
	cout << " simula��o\n -----------------------\n";
	srand(time(NULL));
	int numerodemoscas; int moscamovida; int passosgeral = 1; int verificar = 0; mosca primeira[10]{}; int c = 0; int verificar2 = 0;
	vetor deslocamento;
	while (inativas(moscas, 10) == true)
	{
		//come�a o la�o maior.
		cout << "#" << passosgeral << ": ";
		numerodemoscas = (rand() % 10) + 1;
		cout << numerodemoscas << "( ";
		mosca* ptr = new mosca[numerodemoscas];
		//la�o por rodada.
		for (int i = 0; i < numerodemoscas; i++)
		{
			moscamovida = rand() % 10;
			//moscas sorteadas na rodada.

			if (magnitude(moscas[moscamovida].patual) < 100)
			{
				//entra no if se a distancia for menor que 100.
				cout << moscamovida << " ";
				ptr[i] = moscas[moscamovida];
				deslocamento.angulo = rand() % 359;
				deslocamento.magnitude = (rand() % 10) + 1;
				moscas[moscamovida].patual = deslocar(ptr[i].patual, deslocamento);
			}
			else
			{
				//entra nesse else apenas as moscas que ja atingiram 100 cm.
				if (moscas[moscamovida].situacao <= 1)
				{
					//muda a situacao da moscas.
					moscas[moscamovida].situacao += 1;
				}
				if (verificar == 0)
				{
					//usei essa condi�ao para saber o indice da mosca mais r��da,pois ap�s a primeira
					//entrar aqui,a vari�vel verificar ser� somada e nenhuma mais entrar� nesse if.
					primeira[moscamovida] = moscas[moscamovida];
					c = moscamovida;
				}
				++verificar;
				if (moscas[moscamovida].situacao > 1)
					//se a situ��o da mosca for maior que 1(ou seja,n�o � primeira vez que a mosca chega a 100 cm) ser� printado o x vermelho.
					//se a situa��o for 1(pois a primeira vez que a mosca entra no else sua situa��o vai para 1) ainda ser� exibido seu indice.
				{
					cout << vermelho "X " << default;
				}
				else
				{
					cout << moscamovida << " ";
				}

			}
		}
		for (int i = 0; i < 10; i++)
		{
			//se a mosca ainda tem situ��o 0,ou seja,ainda nao foi inativada,seu passo ser� somado.
			//entretanto,esse la�o nao conta a rodada que a mosca chegou a 100(ser� necessario outro la�o)
			if (moscas[i].situacao == 0)
			{
				moscas[i].passos += 1;
			}
		}
		cout << " ) ";
		for (int i = 0; i < 10; i++)
			//esse la�o faz com que as moscas com situa��o 1(acabaram de chegar no 100cm) tenham seu nome printado na tela no fim.
			//al�m disso,ele soma a situa��o da mosca em 1 para que elas nao entrem aqui denovo.
			//tamb�m,se alguma mosca entrar nesse la�o,a vari�vel verificar2 ser� usada para saber se o 0 dever� ser exibido no fim ou n�o.
		{
			if (moscas[i].situacao == 1)
			{
				cout << "= " << moscas[i] << " ";
				moscas[i].situacao += 1;
				verificar2 += 1;
			}
		}
		//se a var�avel verificar2 for 0,quer dizer que nenhuma mosca chegou aos 100 nessa rodada,entao o 0 dever� ser printado no final.
		if (verificar2 == 0)
		{
			cout << " = 0";
		}
		cout << endl;

		verificar2 = 0;//volta a vari�vel verificar2 para 0 para ela conseguir executar sua fun��o.
		passosgeral++;//n�mero  da rodada.
		delete[] ptr;

	} //fim do la�o maior.
	//soma do passo extra de quando chegam a 100.
	for (int i = 0; i < 10; i++)
	{
		moscas[i].passos += 1;
	}
	int media = 0;
	//calcula a soma dos passos das moscas.
	for (int i = 0; i < 10; i++)
	{
		media += moscas[i].passos;
	}
	//exibe os resultados.
	cout << "resultados\n" << "----------------------------------\n";

	for (int i = 0; i < 10; i++)
	{
		cout << moscas[i] << " = " << moscas[i].passos << endl;
	}
	cout << "\n----------------------------------\n";
	cout << "total de passos: " << primeira[c].cormosca << passosgeral-1 << default << endl;
	cout << " Em m�dia as moscas levaram " << primeira[c].cormosca << media / 10 << default << " passos " << endl;
	cout << " mosca mais r�pida foi: " << primeira[c] << " com " << primeira[c].cormosca << primeira[c].passos + 1 << " passos " << default << endl;
	cout << "o que equivale a voar " << primeira[c].cormosca << 100.0f / primeira[c].passos << default << "por passo";
}