#include <iostream>
#include "binario.h"
#include "genético.h"
using namespace std;

bool TestarBit(unsigned short Sx,unsigned short bit) 
{
	//Nessa função,o bit 1 andará a quantidade de casas que for definida,e logo após realizará uma operação and com o número informado.
	//se após a operação and o número mudar,quer dizer que bit era 0, e a função retorna um booleano com esse valor.
	//se após a operação and o número não mudar,quer dizer que o bit era 1, e a função retorna um booleano com esse valor.
	bool teste= (Sx & (1 << bit));
	 return teste;
}
unsigned short LigarBit(unsigned short Sx,unsigned short bit)
{
	//Nessa função,o bit 1 andará a quantidade de casas que for definida,e logo após realizará uma operação or com o número informado.
	// como 1 em binário é 00000000 00000001,todos os outros bits se manterão iguais,exceto o da posição indicada(se ele for 0,se for 1 se mantem igual).
	unsigned short ligabit= Sx|= (1 << bit);
	return ligabit;
}
//Nessa função,o bit 1 andará a quantidade de casas que for definida,mudará o sinal para 0 e logo após realizará uma operação and.
	// como 1 em binário é 00000000 00000001,todos os outros bits se manterão iguais,exceto o da posição indicada(se ele for 1,se for 0 se mantém igual). 
unsigned short DesligarBit(unsigned short Sx,unsigned short bit)
{ unsigned short desligabit= Sx & ~(1 << bit);
	return desligabit;
}
unsigned short andbinario(unsigned short Sx, unsigned short Sx2)
{
	//realiza uma operação and entre 2 números informados.
	unsigned short operacaoand = Sx & Sx2;
	return operacaoand;
}
unsigned short orbinario(unsigned short Sx, unsigned short Sx2)
{
	//realiza uma operação or entre 2 números informados.
	unsigned short operacaoor = Sx | Sx2;
	return operacaoor;
}
unsigned short BitsBaixos(unsigned short Sx)
{
	//realizando uma operação and entre o núemro informado e uma máscara com binario 00000000 11111111.
     //isso resultará apeans nos bits mais baixos do número.
	unsigned short bitsbaixos = Sx & 255;
	return bitsbaixos;
}
unsigned short Bitsaltos(unsigned short Sx) 
{
	//realizando uma operação and entre o núemro informado e uma máscara com binario 11111111 00000000.
	 //isso resultará apeans nos bits mais altos do número.
	unsigned short bitsaltos = Sx & 65280;
	return bitsaltos;
  
}