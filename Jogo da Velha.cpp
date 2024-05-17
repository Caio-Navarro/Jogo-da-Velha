#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu();


struct Jogo{ 
	char tabuleiro[9];
	int posicaoEscolhida;
	int vezesJogadas = 0;
	int placarX = 0;
	int placarO = 0;
	int empates = 0;
} jogo;

void corrigirAcentuacao(){
	setlocale(LC_ALL, "Portuguese");
}

void comecaJogo(){
	printf("\nPressione qualquer tecla para começar o jogo...");
	getchar();
}

void creditos(){
	printf("Feito por: Caio Navarro, Emanuel Lucas, Gustavo, Kauan Brandão e Samuel Falcão.\n\n");
	system("pause");
}

void placar(){
	if(jogo.vezesJogadas == 0){
		printf("Nenhuma partida aconteceu!\n\n");
		system("pause");
		system("cls");
		menu();
	}else{
		printf("Vitórias jogador X: %d\n", jogo.placarX);
		printf("Vitórias jogador O: %d\n", jogo.placarO);
		printf("Empates: %d\n\n", jogo.empates);
		system("pause");
	}
}

