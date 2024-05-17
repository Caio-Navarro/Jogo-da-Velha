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

void tabuleiroSimples(){ 
	printf("\t1 | 2 | 3\n");
	printf("\t-----------\n");
	printf("\t4 | 5 | 6\n");
	printf("\t-----------\n");
	printf("\t7 | 8 | 9\n");
}

void imprimeTabuleiro(){ 
	printf("\t%c | %c | %c\n", jogo.tabuleiro[0], jogo.tabuleiro[1], jogo.tabuleiro[2]);
	printf("\t----------\n");
	printf("\t%c | %c | %c\n", jogo.tabuleiro[3], jogo.tabuleiro[4], jogo.tabuleiro[5]);
	printf("\t----------\n");
	printf("\t%c | %c | %c\n", jogo.tabuleiro[6], jogo.tabuleiro[7], jogo.tabuleiro[8]);
}

bool jogadaInvalida(){  
	if(jogo.posicaoEscolhida < 1 || jogo.posicaoEscolhida > 9 || jogo.tabuleiro[jogo.posicaoEscolhida - 1 ] == 'X' || jogo.tabuleiro[jogo.posicaoEscolhida - 1 ] == 'O'){
		return true;
	}else{
		return false;
	}
}


