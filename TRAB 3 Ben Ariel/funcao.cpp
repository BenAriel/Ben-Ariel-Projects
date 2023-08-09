#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cctype>
#include <cmath>
#include "funcao.h"
using namespace std;
void exibirlinha()
{
	//auto explicativa
	cout << "================== \n";
}

void pedir(produto*& vet, const int& nm)
{
	char nomepizzaria[50]{}; char linha[50]{}; char arquivo[20]{}; int j = 0; int  situacao = 0;
	cout << "pedir\n ----\n arquivo: ";
	cin.getline(arquivo, 20);
	ifstream fin;
	fin.open(arquivo);
	//testa a abertura do arquivo
	if (!fin.is_open())
	{
		cout << "A abertura do arquivo falhou!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		//le  o nome da pizzaria e a linha que seprada do pedidos
		fin.getline(nomepizzaria, 50);
		fin.getline(linha, 50);
		while (fin.good())
		{
			char nomeproduto[20]; float quantidadeproduto;  unsigned verificarseexiste = nm;

			// le os pedidos.
			fin >> nomeproduto >> quantidadeproduto;
			int a = strlen(nomeproduto);
			//passa o nome do produto para minusculo.
			for (j = 0; j < a; j++)
			{
				nomeproduto[j] = tolower(nomeproduto[j]);
			}
			for (int l = 0; l < nm; l++)
			{
				//se nenhum nome bater com nenhum produto do estoque,uqer dizer que ele nao existe no estoque;
				if (strcmp(nomeproduto, vet[l].nome) != 0)
					verificarseexiste--;
			}
			if (verificarseexiste == 0)
			{
				cout << "o produto " << nomeproduto << " falhou!\n requerido : " << quantidadeproduto << "kg";
				cout << " / em estoque:  0kg" << endl;
				situacao = 1;
			}
			else
			{

				for (int k = 0; k < nm; k++)
				{
					//se o nome do produto pedido for igual ao nome de algum produto do estoque entra no laço;
					if (strcmp(nomeproduto, vet[k].nome) == 0)
					{
						// se a quantidade pedida for menor ou igual ao que tem no estoque,a operação acontece,e essa
						//quantidade do pedido é guardada no temporario.
						if (quantidadeproduto <= vet[k].quantidade)
						{
							vet[k].quantidade -= quantidadeproduto;
							vet[k].temporario += quantidadeproduto;
						}
						else
						{
							//se a quantidade pedida for maior do que tem no estoque,falha.
							cout << "o produto " << nomeproduto << " falhou!\n requerido : " << quantidadeproduto << "kg";
							cout << " / em estoque: " << vet[k].quantidade << "kg" << endl;
							//variavel usada para saber se algum produto falhou;
							situacao = 1;
						}
					}
				}

			}
		}
		fin.close();
		//só entra na parte de recibo se nenhum produto falhou
		if (situacao == 0)
		{
			ofstream fout;
			char recibo[20] = ""; int total = 0;
			//copia o nome do arquivo texto 
			for (int i = 0; arquivo[i] != '.'; ++i)
			{
				recibo[i] = arquivo[i];
			}
			//adiciona o nfc no fim
			strcat(recibo, ".nfc");

			fout.open(recibo);
			//testa abertura do arquivo
			if (!fout.is_open())
			{
				cout << "A abertura do arquivo falhou!" << endl;
				exit(EXIT_FAILURE);
			}
			//imprime as infromaçoes no recibo
			else
			{
				fout << nomepizzaria << endl;
				fout << "---------------------------------------\n";
				for (int i = 0; i < nm; ++i)
				{
					//se o temporario do vetor
					if (vet[i].temporario != 0)
					{
						fout << vet[i].nome << "  " << vet[i].temporario << "kg  a   R$" << vet[i].preco << "/kg  = " << vet[i].temporario * vet[i].preco << endl;
						total += vet[i].temporario * vet[i].preco;
					}
				}
				fout << "---------------------------------------\n";
				fout << " compra: R$" << total << endl;
				//vai imprimir o desconto apenas se a compra for acima de 1000 reais.
				if (total >= 1000)
				{
					fout << "desconto: R$" << total * 0.10 << endl;
					fout << "total: R$" << total - (total * 0.10);
				}
				else
				{
					fout << "total: R$" << total;
				}
			}
			fout.close();
			//passa os temporarios para 0 denovo
			for (int i = 0; i < nm; ++i)
			{
				vet[i].temporario = 0;
			}
		}
	}
}
void adiconar(produto*& vet, int& n, int& nm)
{
	produto novo;
	bool existente = false;
	int j = 0;
	static int potencia = 0;
	// le o produto que quer adicionar.
	cout << "adicionar\n --------\n";
	cout << " digite o nome do produto: ";
	cin >> novo.nome;
	cout << " digite o preço: ";
	cin >> novo.preco;
	cout << " digite a quantidade do produto: ";
	cin >> novo.quantidade;
	int a = 0;
	a = strlen(novo.nome);
	//passa o nome do produto para minusculo.
	for (j = 0; j < a; j++)
	{
		novo.nome[j] = tolower(novo.nome[j]);
	}

	//verifica se ja existe um produto com o mesmo nome no vetor,se ja existir passa os dados para o existente.
	//dentro da função,um booleano recebe valor true para testes futuros;
	for (int k = 0; k < n; k++)
	{
		if (strcmp(novo.nome, vet[k].nome) == 0)
		{
			vet[k].quantidade += novo.quantidade;
			vet[k].preco = novo.preco;
			existente = true;
			break;
		}
	}
	//se nao tiver um produto com o mesmo nome,entao a variavel existente tem valor falso,entao o produto entrara
	//nesse laço para ser adicionado no estoque
	if (existente == false)
	{
		//se o numero de produtos for igual ao tamanho do vetor,o vetor tem sua capacidade aumentada de acordo com o
		//calculo fornecido
		if (nm == n)
		{
			n += pow(2, potencia);// a variavel potencia é estatica,ou seja,acumula valores.
			//cria um novo vetor com capacidade maior,passa o conteudo do antigo para esse novo,libera a memoria do antigo
			// e o antigo recebe o novo vetor,agora com capacidade maior.
			produto* vetnovo = new produto[n];
			for (int x = 0; x < nm; x++)
			{
				strcpy(vetnovo[x].nome, vet[x].nome);
				vetnovo[x].quantidade = vet[x].quantidade;
				vetnovo[x].preco = vet[x].preco;
			}
			potencia++;
			delete[] vet;
			vet = vetnovo;
		}
		//adiciona o novo produto.
		strcpy(vet[nm].nome, novo.nome);
		vet[nm].quantidade = novo.quantidade;
		vet[nm].preco = novo.preco;
		nm += 1;
	}
}
void excluir(produto*& vet, int& nm)
{
	//pega a posição do produto escolhido (-1 pq o laço começa do 0) e dela para frente,
	//joga os produtos uma posição atras. no fim,a quantidade de produtos no estoque é dominuida em 1.
	int escolha = 0; char confirmacao = ' ';
	cout << " excluir\n --------\n";
	for (int i = 0; i < nm; i++)
	{
		cout << i + 1 << ") " << vet[i].nome << endl;
	}
	cout << "número do produto: [ ]\b\b";
	cin >> escolha;
	cout << "deseja excluir " << vet[escolha - 1].nome << "? (S/N)";
	cin >> confirmacao;
	confirmacao = tolower(confirmacao);
	if (confirmacao == 's')
	{
		for (int k = escolha - 1; k < nm; k++)
		{
			vet[k] = vet[k + 1];
		}
		nm -= 1;
	}
}
void listar(const produto* vet, const int& nm)
{
	//exibe os produtos em estoque;
	cout << "pedir\n ----\n";

	for (int i = 0; i < nm; i++)
	{
		cout << vet[i].nome << " - R$" << vet[i].preco << " - " << vet[i].quantidade << "kg\n";
	}
}