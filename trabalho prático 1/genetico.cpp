#include <iostream>
#include "binario.h"
#include "genético.h"
using namespace std;
bool FuncaoAvaliacao(unsigned short sx)
{
	//usando 1 vetor para armazenar os valores dos pesos dos objetos e outro vetor para armazenar os preços dos objetos.
	  short PesoKG[16] = { 1,4,2,5,4,2,1,4,3,2,1,9,4,5,3,12 };
	  short preco[16] = { 12,4,3,10,15,20,10,2,1,1,3,15,10,8,4,4 };
	  short peso = 0; short bit; short Valor = 0; short i = 16;
	  //usando uma estrutura de repetição junto com a função TestarBit para testar os bits dos números recebidos.
	  //se o bit for 0, o objeto não será levado na mochila,logo o peso e o preço não seram somados.
	  //se o bit for 1,quer dizer que o objeto será levado na mochila, e o peso e preço será somado.
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
	//exibindo o resultado. usado a função width para alinhamento.
	cout << right; cout.width(10); cout << sx << " - "; cout << right; cout.width(3); cout << "$";cout<< Valor << " - "; cout << right; cout.width(3); cout << peso << "Kg " << " - ";
	if (peso > 20)
		// se o peso for maior que 0,a função retorna um booleano 0. se o peso for menor ou igual a 20,retorna um booleano 1.
		return false;
	else
		return true;

}
	
unsigned short CruzamentoPontoUnico(unsigned short s1, unsigned short s2)
{
	//chamando a função orbinário para que ela faça a operação OR entre os bits altos e baixos dos números informados.
	unsigned short CpU = orbinario(Bitsaltos(s1), BitsBaixos(s2));
	return CpU;
}
unsigned short CruzamentoAritimetico(unsigned short s3, unsigned short s4)
{
	//chamando a função andbinário para que ela faça a operação and entre duas soluções informadas.
	unsigned short operacaoaritimetica = andbinario(s3, s4);
	return operacaoaritimetica;
}
unsigned short MutacaoSimples(unsigned short s5)
{
	//chamando a função TestarBit para saber se o bit na posição indicada da solução informada é 0 ou 1.
	//se o bit for 0, será chamada a função LigarBit e retornará o valor já com o bit modificado.
	//se o bit for 1, será chamada a função DesigarBit e retornará o valor já com o bit modificado.
	if (TestarBit(s5,9) == false)
		return LigarBit(s5,9);
	else
		return DesligarBit(s5,9);
}
unsigned short MutacaoDupla(unsigned short s6)
{
	//chamando a função TestarBit para saber se os bits nas posições indicadas da solução informada é 0 ou 1.
	//se o bit for 0, será chamada a função LigarBit e retornará o valor já com o bit modificado.
	//se o bit for 1, será chamada a função DesigarBit e retornará o valor já com o bit modificado.
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
