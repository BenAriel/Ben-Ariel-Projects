struct produto
{
	char nome[20];
	float quantidade, preco;
	int temporario = 0;
};
void listar(const produto*, const int& nm);
void pedir(produto*& vet, const int& nm);
void adiconar(produto*& vet, int& n, int& nm);
void excluir(produto*& vet, int& nm);
void exibirlinha();
