#include <iostream>
#include "binario.h"
#include "gen�tico.h"
using namespace std;

bool TestarBit(unsigned short Sx,unsigned short bit) 
{
	//Nessa fun��o,o bit 1 andar� a quantidade de casas que for definida,e logo ap�s realizar� uma opera��o and com o n�mero informado.
	//se ap�s a opera��o and o n�mero mudar,quer dizer que bit era 0, e a fun��o retorna um booleano com esse valor.
	//se ap�s a opera��o and o n�mero n�o mudar,quer dizer que o bit era 1, e a fun��o retorna um booleano com esse valor.
	bool teste= (Sx & (1 << bit));
	 return teste;
}
unsigned short LigarBit(unsigned short Sx,unsigned short bit)
{
	//Nessa fun��o,o bit 1 andar� a quantidade de casas que for definida,e logo ap�s realizar� uma opera��o or com o n�mero informado.
	// como 1 em bin�rio � 00000000 00000001,todos os outros bits se manter�o iguais,exceto o da posi��o indicada(se ele for 0,se for 1 se mantem igual).
	unsigned short ligabit= Sx|= (1 << bit);
	return ligabit;
}
//Nessa fun��o,o bit 1 andar� a quantidade de casas que for definida,mudar� o sinal para 0 e logo ap�s realizar� uma opera��o and.
	// como 1 em bin�rio � 00000000 00000001,todos os outros bits se manter�o iguais,exceto o da posi��o indicada(se ele for 1,se for 0 se mant�m igual). 
unsigned short DesligarBit(unsigned short Sx,unsigned short bit)
{ unsigned short desligabit= Sx & ~(1 << bit);
	return desligabit;
}
unsigned short andbinario(unsigned short Sx, unsigned short Sx2)
{
	//realiza uma opera��o and entre 2 n�meros informados.
	unsigned short operacaoand = Sx & Sx2;
	return operacaoand;
}
unsigned short orbinario(unsigned short Sx, unsigned short Sx2)
{
	//realiza uma opera��o or entre 2 n�meros informados.
	unsigned short operacaoor = Sx | Sx2;
	return operacaoor;
}
unsigned short BitsBaixos(unsigned short Sx)
{
	//realizando uma opera��o and entre o n�emro informado e uma m�scara com binario 00000000 11111111.
     //isso resultar� apeans nos bits mais baixos do n�mero.
	unsigned short bitsbaixos = Sx & 255;
	return bitsbaixos;
}
unsigned short Bitsaltos(unsigned short Sx) 
{
	//realizando uma opera��o and entre o n�emro informado e uma m�scara com binario 11111111 00000000.
	 //isso resultar� apeans nos bits mais altos do n�mero.
	unsigned short bitsaltos = Sx & 65280;
	return bitsaltos;
  
}