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

void comecarJogo(){
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

bool empate(){        
	return jogo.vezesJogadas == 9;
}

bool verificaVitoriaX(){      
	if(jogo.tabuleiro[0] == 'X' && jogo.tabuleiro[1] == 'X' && jogo.tabuleiro[2] == 'X'){
		return true;
	}else if(jogo.tabuleiro[3] == 'X' && jogo.tabuleiro[4] == 'X' && jogo.tabuleiro[5] == 'X'){
		return true;
	}else if(jogo.tabuleiro[6] == 'X' && jogo.tabuleiro[7] == 'X' && jogo.tabuleiro[8] == 'X'){
		return true;
	}else if(jogo.tabuleiro[0] == 'X' && jogo.tabuleiro[3] == 'X' && jogo.tabuleiro[6] == 'X'){
		return true;
	}else if(jogo.tabuleiro[1] == 'X' && jogo.tabuleiro[4] == 'X' && jogo.tabuleiro[7] == 'X'){
		return true;
	}else if(jogo.tabuleiro[2] == 'X' && jogo.tabuleiro[5] == 'X' && jogo.tabuleiro[8] == 'X'){
		return true;
	}
	else if(jogo.tabuleiro[0] == 'X' && jogo.tabuleiro[4] == 'X' && jogo.tabuleiro[8] == 'X'){
		return true;
	}else if(jogo.tabuleiro[2] == 'X' && jogo.tabuleiro[4] == 'X' && jogo.tabuleiro[6] == 'X'){
		return true;
	}else{
		return false;
	}
}

bool verificaVitoriaO(){                  
	if(jogo.tabuleiro[0] == 'O' && jogo.tabuleiro[1] == 'O' && jogo.tabuleiro[2] == 'O'){
		return true;
	}else if(jogo.tabuleiro[3] == 'O' && jogo.tabuleiro[4] == 'O' && jogo.tabuleiro[5] == 'O'){
		return true;
	}else if(jogo.tabuleiro[6] == 'O' && jogo.tabuleiro[7] == 'O' && jogo.tabuleiro[8] == 'O'){
		return true;
	}else if(jogo.tabuleiro[0] == 'O' && jogo.tabuleiro[3] == 'O' && jogo.tabuleiro[6] == 'O'){
		return true;
	}else if(jogo.tabuleiro[1] == 'O' && jogo.tabuleiro[4] == 'O' && jogo.tabuleiro[7] == 'O'){
		return true;
	}else if(jogo.tabuleiro[2] == 'O' && jogo.tabuleiro[5] == 'O' && jogo.tabuleiro[8] == 'O'){
		return true;
	}
	else if(jogo.tabuleiro[0] == 'O' && jogo.tabuleiro[4] == 'O' && jogo.tabuleiro[8] == 'O'){
		return true;
	}else if(jogo.tabuleiro[2] == 'O' && jogo.tabuleiro[4] == 'O' && jogo.tabuleiro[6] == 'O'){
		return true;
	}else{
		return false;
	}
}

void limparTabuleiro() {                  
    for (int i = 0; i < 9; i++) {
        jogo.tabuleiro[i] = ' ';
    }
    jogo.posicaoEscolhida = 0;
    jogo.vezesJogadas = 0;
}

void jogar(){                              
	int vez = 0; 
	char jogarNovamente;
	
	do{
		system("cls");
		limparTabuleiro();
		
		fflush(stdin);
		tabuleiroSimples();
		comecarJogo();
		
		while(jogo.vezesJogadas < 9){
			system("cls");
			imprimeTabuleiro();
			
			if(verificaVitoriaX()){
				printf("\nJogador X venceu!\n");
				jogo.placarX++;
				break;
			}
			
			if(verificaVitoriaO()){
				printf("\nJogador O venceu!\n");
				jogo.placarO++;
				break;
			}
			
			if(vez%2 == 0){ 
				printf("Jogador X\n");
			}else{
				printf("Jogador O\n");
			}
			
			printf("Onde deseja jogar? [1-9]: ");
			scanf(" %d", &jogo.posicaoEscolhida);
			
			if(jogadaInvalida()){
				printf("\nPosição Inválida!\n");
				system("pause");
				continue; 
			}
			
			if(vez%2 == 0){
				jogo.tabuleiro[jogo.posicaoEscolhida - 1] = 'X';
			}else{
				jogo.tabuleiro[jogo.posicaoEscolhida - 1] = 'O';
			}
			
			jogo.vezesJogadas++; 
			vez++;
			
			if(empate()){
				jogo.empates++;
				system("cls");
				printf("Empate!\n");
				break;
			}
		}
		printf("Deseja jogar novamente? [S/N]: ");
		scanf(" %c", &jogarNovamente);
	}while(jogarNovamente == 'S' || jogarNovamente == 's');
}