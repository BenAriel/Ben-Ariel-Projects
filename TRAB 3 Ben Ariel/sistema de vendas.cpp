#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cctype>
#include <cmath>
#include "funcao.h"
using namespace std;


int main()
{
	//incialmente,cria um vetor com uma posição.
	int n = 1; int nmprodutos = 0;
	produto* vet = new produto[n];
	ifstream fin;
	fin.open("produtosestoque.bin", ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		//se ja existir um arquivo binario com esse nome,um vetor novo recebe o estoque presente no arquivo.
		//depois,o vetor que era de 1 posição recebe esse vetor novo,agora com tamanho maior e os produtos no estoque;
		fin.read((char*)&nmprodutos, sizeof(int));
		n = nmprodutos;
		produto* vet2 = new produto[n];
		delete[] vet;
		vet = vet2;
		for (unsigned short i = 0; i < nmprodutos; ++i)
			fin.read((char*)&vet[i], sizeof(produto));
		fin.close();
	}
	char escolha = ' ';
	do
	{
		//menu
		cout << "Sistema de Controle\n";
		exibirlinha();
		cout << "(P)edir \n";
		cout << "(A)dicionar\n";
		cout << "(E)xcluir\n";
		cout << "(L)istar\n";
		cout << "(S)air\n";
		exibirlinha();
		cout << "Opção: [ ]\b\b";
		cin >> escolha;

		cin.get();
		escolha = toupper(escolha);
		switch (escolha)
		{

		case 'P':
		{
			pedir(vet, nmprodutos);
			break;
		}

		case 'A':
			adiconar(vet, n, nmprodutos);
			break;
		case  'E':
			excluir(vet, nmprodutos);
			break;
		case 'L':
			listar(vet, nmprodutos);
			break;

		case 'S':
			break;

		default:
			cout << " digite uma operação válida";
			break;
		}
	} while (escolha != 'S');

	ofstream fout;
	//passa do vetor dinamico para o arquivo binario
	fout.open("produtosestoque.bin", ios_base::out | ios_base::trunc | ios_base::binary);
	fout.write((char*)&nmprodutos, sizeof(int));
	for (unsigned short i = 0; i < nmprodutos; ++i)
		fout.write((char*)&vet[i], sizeof(produto));
	fout.close();

	delete[] vet;
}