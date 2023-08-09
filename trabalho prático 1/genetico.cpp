#include <iostream>
#include "binario.h"
#include "gen�tico.h"
using namespace std;
bool FuncaoAvaliacao(unsigned short sx)
{
	//usando 1 vetor para armazenar os valores dos pesos dos objetos e outro vetor para armazenar os pre�os dos objetos.
	  short PesoKG[16] = { 1,4,2,5,4,2,1,4,3,2,1,9,4,5,3,12 };
	  short preco[16] = { 12,4,3,10,15,20,10,2,1,1,3,15,10,8,4,4 };
	  short peso = 0; short bit; short Valor = 0; short i = 16;
	  //usando uma estrutura de repeti��o junto com a fun��o TestarBit para testar os bits dos n�meros recebidos.
	  //se o bit for 0, o objeto n�o ser� levado na mochila,logo o peso e o pre�o n�o seram somados.
	  //se o bit for 1,quer dizer que o objeto ser� levado na mochila, e o peso e pre�o ser� somado.
	for ( bit = 15; bit >= 0; bit--)
	{
		i = i - 1;
		if (TestarBit(sx, bit) == false)
		{
			peso = peso + 0;
			Valor = Valor + 0;
		}
		else
		{
			peso = peso + PesoKG[i];
			Valor = Valor + preco[i];
		}


	}
	//exibindo o resultado. usado a fun��o width para alinhamento.
	cout << right; cout.width(10); cout << sx << " - "; cout << right; cout.width(3); cout << "$";cout<< Valor << " - "; cout << right; cout.width(3); cout << peso << "Kg " << " - ";
	if (peso > 20)
		// se o peso for maior que 0,a fun��o retorna um booleano 0. se o peso for menor ou igual a 20,retorna um booleano 1.
		return false;
	else
		return true;

}
	
unsigned short CruzamentoPontoUnico(unsigned short s1, unsigned short s2)
{
	//chamando a fun��o orbin�rio para que ela fa�a a opera��o OR entre os bits altos e baixos dos n�meros informados.
	unsigned short CpU = orbinario(Bitsaltos(s1), BitsBaixos(s2));
	return CpU;
}
unsigned short CruzamentoAritimetico(unsigned short s3, unsigned short s4)
{
	//chamando a fun��o andbin�rio para que ela fa�a a opera��o and entre duas solu��es informadas.
	unsigned short operacaoaritimetica = andbinario(s3, s4);
	return operacaoaritimetica;
}
unsigned short MutacaoSimples(unsigned short s5)
{
	//chamando a fun��o TestarBit para saber se o bit na posi��o indicada da solu��o informada � 0 ou 1.
	//se o bit for 0, ser� chamada a fun��o LigarBit e retornar� o valor j� com o bit modificado.
	//se o bit for 1, ser� chamada a fun��o DesigarBit e retornar� o valor j� com o bit modificado.
	if (TestarBit(s5,9) == false)
		return LigarBit(s5,9);
	else
		return DesligarBit(s5,9);
}
unsigned short MutacaoDupla(unsigned short s6)
{
	//chamando a fun��o TestarBit para saber se os bits nas posi��es indicadas da solu��o informada � 0 ou 1.
	//se o bit for 0, ser� chamada a fun��o LigarBit e retornar� o valor j� com o bit modificado.
	//se o bit for 1, ser� chamada a fun��o DesigarBit e retornar� o valor j� com o bit modificado.
	unsigned short resultado;
	if (TestarBit(s6, 3) == false)

		resultado= LigarBit(s6, 3);
	else
		resultado= DesligarBit(s6, 3);

	if (TestarBit(s6, 12) == false)
		resultado= LigarBit(resultado, 12);
	else
		resultado = DesligarBit(resultado, 12);
	return resultado;


}
