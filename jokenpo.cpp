#include <iostream>
#include <string>

using namespace std;


void linha();

int main()
{
	string escolha1;//escolha do usuário.
	int escolha2;//ler o numero aleatório sorteado.

	char nome1[20];//nome do usuario.
	 const string palavras[3] = {"Pedra","Papel","Tesoura"};//definindo as palavras que podem ser sorteadas.

	linha();
	cout << " Bem vindos ao Jokenpô! \n";
	linha();
	cout << "Informe o nome do jogador 1: ";
	cin.getline(nome1, 20);
	string  resposta = { " Sim" };
	//variáveis para contar o placar.
	unsigned short vitoria1 = 0;
	unsigned short vitoria2 = 0;
	do {

		cout << nome1 << ", escolha sua jogada: ";
		cin >> escolha1;

		//sorteio do numero aleatório.
		srand(static_cast<unsigned int>(time(0)));
		escolha2 = (rand() % 3);
		string palavrasorteada = palavras[escolha2];

		linha();

		if (escolha1 == palavrasorteada)
		{
			cout << "escolha de "<<nome1<<": " << escolha1 << endl;
			cout << " escolha do computador: " << palavrasorteada << endl;
			cout << " A jogada deu empate!";
		}

		if (escolha1 == "Tesoura")
		{
			if  (palavrasorteada == "Papel")
			{
				cout << "escolha de " << nome1 << ": " << escolha1 << endl;
				cout << " escolha do computador: " << palavrasorteada << endl;
				cout << " O jogador "<<nome1<<" ganhou";
				vitoria1 = vitoria1 + 1;
				
			}
			if (palavrasorteada == "Pedra")
			{
				cout << "escolha de " << nome1 << ": " << escolha1 << endl;
				cout << " escolha do computador: " << palavrasorteada << endl;
				cout << " O computador ganhou";
				vitoria2 = vitoria2 + 1;
			}
		}
		if (escolha1 == "Pedra")
		{
			if (palavrasorteada == "Tesoura")
			{
				cout << "escolha de " << nome1 << ": " << escolha1 << endl;
				cout << " escolha do computador: " << palavrasorteada << endl;
				cout << " O jogador " << nome1 << " ganhou";
				vitoria1 = vitoria1 + 1;
			}
			if (palavrasorteada == "Papel")
			{
				cout << "escolha de " << nome1 << ": " << escolha1 << endl;
				cout << " escolha do computador: " << palavrasorteada << endl;
				cout << " O computador ganhou";
				vitoria2 = vitoria2 + 1;
			}
		}
		if (escolha1 == "Papel")
		{
			if (palavrasorteada == "Pedra")
			{
				cout << "escolha de " << nome1 << ": " << escolha1 << endl;
				cout << " escolha do computador: " << palavrasorteada << endl;
				cout << " O jogador " << nome1 << " ganhou";
				vitoria1 = vitoria1 + 1;
			}
			if (palavrasorteada == "Tesoura")
			{
				cout << "escolha de " << nome1 << ": " << escolha1 << endl;
				cout << " escolha do computador: " << palavrasorteada << endl;
				cout << " O computador ganhou";
				vitoria2 = vitoria2 + 1;
			}
		}
		linha();
		cout << " placar atual:" << endl;
		cout << nome1 << ": " << vitoria1<<endl;
		cout <<" computador: " << ": " << vitoria2 << endl;
		linha();
		cout << " Se deseja continuar jogando,digite ''Sim'': ";
		cin >> resposta;
	} while (resposta == "Sim");

	cout << " Obrigado por jogar!";
}

void linha()
{
	cout << "\n -----------------------\n";
}