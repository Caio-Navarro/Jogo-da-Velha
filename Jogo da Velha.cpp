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

void corrigirAcentuacao(){ //
	setlocale(LC_ALL, "Portuguese");
}
