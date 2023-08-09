#include <iostream>
#include "mosca.h"
#include <cmath>
using namespace std;

istream& operator>>(istream& is, cor& ms)
{
	is >> ms.red;
	is >> ms.green;
	is >> ms.blue;
	return is;
};
ostream& operator<<(ostream& os, cor& ms)
{
	os << "\033[38;2;" << ms.red << ";" << ms.green << ";" << ms.blue << "m";
	return os;
}
istream& operator>>(istream& is, mosca& ms)
{
	is >> ms.nome;
	is >> ms.cormosca;
	return is;
};
ostream& operator<<(ostream& os, mosca& ms)
{
	os << ms.cormosca;
	os << ms.nome;
	os << "\x1b[0m";
	return os;
}
ponto deslocar(ponto coordenadas, vetor teste)
{
	//operação do deslocamento da mosca nos eixos.
	coordenadas.x += teste.magnitude * (cos(teste.angulo * 3.14 / 180));
	coordenadas.y += teste.magnitude * (sin(teste.angulo * 3.14 / 180));
	return coordenadas;
}
bool inativas(mosca moscas[], int tam)
{
	//recebe o vetor de moscas e o seu tamaho,e verifica se as moscas ja estão inativas(alcançaram os 100)
	//se todas estiverem inativas,c vai retornar 0,ou seja,falso. caso alguma ainda esteja ativa, c nao chegará a 0 e portanto retornará um true.
	int c = 10;
	for (int i = 0; i < tam; i++)
	{
		if (magnitude(moscas[i].patual) >= 100)
			c = c - 1;
	}
	return c;
}
float magnitude(ponto moscas)
{
	//recebe as coordenadas da mosca e faz a operação da magnitude.
	return sqrtf(pow(moscas.x, 2)) + sqrtf(pow(moscas.y, 2));
}