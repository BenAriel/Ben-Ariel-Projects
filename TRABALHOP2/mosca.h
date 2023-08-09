#include <iostream>
using namespace std;
struct cor
{
	int red, green, blue;
};
struct ponto
{
	float x, y;
};
struct vetor
{
	float magnitude, angulo;
};

struct mosca
{
	char nome[20];
	cor cormosca;
	ponto patual;
	int passos = 0;
	int situacao = 0;
};
istream& operator>>(istream& is, cor& ms);
ostream& operator<<(ostream& os, cor& ms);
istream& operator>>(istream& is, mosca& ms);
ostream& operator<<(ostream& os, mosca& ms);
ponto deslocar(ponto, vetor);
bool inativas(mosca[], int);
float magnitude(ponto);
