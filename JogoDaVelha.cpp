#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <MMsystem.h>
#include <locale.h>
#include <string.h>
#include <time.h>

void desenhaTabela();
int checkWin();
void menuInicial();

char opcoes[10]= {'o','1','2','3','4','5','6','7','8','9'};
char user[50];
int escolha;

int main(){
	setlocale(LC_ALL, "Portuguese");
	system("color B"); // define a cor dos textos de verde claro
	int jogador = 1, i, j;
	char mark;

	menuInicial();
	fflush(stdin);
	gets(user);
	system("cls");
	
	do {
		srand(time(NULL));
		desenhaTabela();
		jogador = (jogador % 2) ? 1 : 2;
		if(jogador == 1){
			printf("%s, escolha uma opção: ", user);
			fflush(stdin);
			scanf("%d",&escolha);
		}
		
		
		mark = (jogador == 1) ? 'X' : 'O';
		if(jogador == 2){
			escolha = rand()%10;
		}
		if(escolha == 1 && opcoes[1] == '1')
			opcoes[1] = mark;
		else if(escolha == 2 && opcoes[2] == '2')
			opcoes[2] = mark;
			else if(escolha == 3 && opcoes[3] == '3')
			opcoes[3] = mark;
			else if(escolha == 4 && opcoes[4] == '4')
			opcoes[4] = mark;
			else if(escolha == 5 && opcoes[5] == '5')
			opcoes[5] = mark;
			else if(escolha == 6 && opcoes[6] == '6')
			opcoes[6] = mark;
			else if(escolha == 7 && opcoes[7] == '7')
			opcoes[7] = mark;
			else if(escolha == 8 && opcoes[8] == '8')
			opcoes[8] = mark;
			else if(escolha == 9 && opcoes[9] == '9')
			opcoes[9] = mark;
			
			else {
				jogador--;
			}
			i = checkWin();
			jogador++;	
		
	}while(i == -1);
	
	desenhaTabela();
	if(i == 1){
		printf("%s ganhou!!!!", user);
	} else if(i == -1){
		printf("Máquina ganhou!!!!");
	} else if(i == 0){
		printf("Deu velha!");
	}
	return 0;
}
int checkWin(){
	// vendo se algm fechou a linha 1
	if(opcoes[1] == 'X' && opcoes[2] == 'X' && opcoes[3] == 'X'){
		return 1;
	} else if(opcoes[1] == 'O' && opcoes[2] == 'O' && opcoes[3] == 'O'){
		return 0;
	}
	// vendo se algm fechou a linha 2
	if(opcoes[4] == 'X' && opcoes[5] == 'X' && opcoes[6] == 'X'){
		return 1;
	} else if(opcoes[4] == 'O' && opcoes[5] == 'O' && opcoes[6] == 'O'){
		return 0;
	}
	// vendo se algm fechou a linha 3
	if(opcoes[7] == 'X' && opcoes[8] == 'X' && opcoes[9] == 'X'){
		return 1;
	} else if(opcoes[7] == 'O' && opcoes[8] == 'O' && opcoes[9] == 'O'){
		return 0;
	}
	// vendo se algm fechou a COLUNA 1
	if(opcoes[1] == 'X' && opcoes[4] == 'X' && opcoes[7] == 'X'){
		return 1;
	} else if(opcoes[1] == 'O' && opcoes[4] == 'O' && opcoes[7] == 'O'){
		return 0;
	}
	// vendo se algm fechou a COLUNA 2
	if(opcoes[2] == 'X' && opcoes[5] == 'X' && opcoes[8] == 'X'){
		return 1;
	} else if(opcoes[2] == 'O' && opcoes[5] == 'O' && opcoes[8] == 'O'){
		return 0;
	}
	// vendo se algm fechou a COLUNA 3
	if(opcoes[3] == 'X' && opcoes[6] == 'X' && opcoes[9] == 'X'){
		return 1;
	} else if(opcoes[3] == 'O' && opcoes[6] == 'O' && opcoes[9] == 'O'){
		return 0;
	}	
	// vendo se algm fechou a DIAGONAL 1
	if(opcoes[1] == 'X' && opcoes[5] == 'X' && opcoes[9] == 'X'){
		return 1;
	} else if(opcoes[1] == 'O' && opcoes[5] == 'O' && opcoes[9] == 'O'){
		return 0;
	} 
	// vendo se algm fechou a DIAGONAL 2
	if(opcoes[3] == 'X' && opcoes[5] == 'X' && opcoes[7] == 'X'){
		return 1;
	} else if(opcoes[3] == 'O' && opcoes[5] == 'O' && opcoes[7] == 'O'){
		return 0;
	}
	
	// vendo se deu empate!
	if(opcoes[1] != '1' && opcoes[2] != '2' && opcoes[3] != '3' && opcoes[4] !='4' && opcoes[5] != '5' && opcoes[6] != '6' && opcoes[7] != '7' && opcoes[8] != '8' && opcoes[9] != '9'){
		return 2;
	}
	
	else{
		return -1;
	}
}

void desenhaTabela(){
	system("cls");
	printf("\n#########################################################");
	printf("\n                                                        #");
	printf("\n                   INFORMAÇÕES                          #");
	printf("\n                                                        #");
	printf("\n                Jogador 1: %s   (X)                   #", user);
	printf("\n                Jogador 2: Máquina   (O)                #");
	printf("\n                                                        #");
	printf("\n#########################################################");
	
	printf("\n\n\t Jogo da Velha \n\n");
	printf("%s (X) - Máquina (O) \n\n\n", user);
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",opcoes[1],opcoes[2],opcoes[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",opcoes[4],opcoes[5],opcoes[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",opcoes[7],opcoes[8],opcoes[9]);
	printf("     |     |     \n");	
}
void menuInicial(){
	printf("\n#########################################################");
	printf("\n#                                                       #");
	printf("\n#                   JOGO DA VELHA                       #");
	printf("\n#                                                       #");
	printf("\n#           Desenvolvido por: eubrunodev                #");
	printf("\n#           Discord: GlockH$#7448                       #");
	printf("\n#                                                       #");
	printf("\n#########################################################");
	printf("\n\nNome do jogador: ");
}