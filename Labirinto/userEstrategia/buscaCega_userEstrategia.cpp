/*
	Autor: Luis Otavio Rigo Junior
	Objetivo: 
		Este arquivo destina-se a implementacao das estrategias de jogo dos agentes.
	
	Devem ser implementados os 4 prototipos:
		init_Player1 - executada uma unica vez e contem as funcoes de inicializacao da estrategia do jogador 1;
		run_Player1 - executado a cada passo do jogo e retorna uma string com a direcao de movimento do jogador 1;
		init_Player2 - executada uma unica vez e contem as funcoes de inicializacao da estrategia do jogador 2;
		run_Player2 - executado a cada passo do jogo e retorna uma string com a direcao de movimento do jogador 2.
	
	Funcoes que podem ser chamadas pelo jogador (agente):
		char *maze_VerAmbiente(char tipo[MAXLINE]);
			- Utilizada para verificar alguma informacao da celula. Ex.: id;
		bool maze_VerCaminho(const char *direcao);
			- Retorna se existe um caminho naquela direcao (verdadeiro ou falso).
		bool maze_VerMinotauro(const char *direcao);
			- Retorna se o minotauro estah naquela direcao (verdadeiro ou falso).
		float maze_CustoDoCaminho(const char *direcao);
			- Retorna o custo de executar um passo naquela direcao.
		float maze_HeuristicaDistEuclidiana(const char *direcao);
			- Retorna o a distancia heuclidiana da celula que estah naquela direcao ateh a saida.
	
	Constantes que podem ser usadas pelo jogador (agente):
		#define NUMCAMINHOS 4
		const char *id_Caminhos[NUMCAMINHOS] = {"norte", "sul", "oeste", "leste"};
		const char *id_Retornos[NUMCAMINHOS] = {"sul", "norte", "leste", "oeste"};
		typedef struct str_PosicaoPlano {
			int x,y;
		} tipo_PosicaoPlano;
*/

// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 1 ***
//	Implementacao da primeira estrategia de jogo.
#include <stack>
#include <iostream>

stack <int> pilha;
int matriz_lab[60][35];
int cord_x = 0, cord_y=0;

void init_Player1() {
	int matriz_lab[60][35]={0};
	matriz_lab[0][0]= 1;
}
const char *run_Player1() {

	const char *direcao;

	if (maze_VerCaminho("norte") == CAMINHO && matriz_lab[cord_x][cord_y-1]==0) {	
		direcao = "norte";
		pilha.push(0);
		cord_y--;
		matriz_lab[cord_x][cord_y]=1;
	}
	else if (maze_VerCaminho("sul") == CAMINHO && matriz_lab[cord_x][cord_y+1] == 0) {
		direcao = "sul";
		pilha.push(1);
		cord_y++;
		matriz_lab[cord_x][cord_y]=1;
	}
	else if (maze_VerCaminho("oeste") == CAMINHO && matriz_lab[cord_x-1][cord_y]==0) {
		direcao = "oeste";
		pilha.push(2);
		cord_x--;
		matriz_lab[cord_x][cord_y]=1;
	}
	else if (maze_VerCaminho("leste") == CAMINHO && matriz_lab[cord_x+1][cord_y]== 0) {
		direcao = "leste";
		pilha.push(3);
		cord_y++;
		matriz_lab[cord_x][cord_y]=1;
	}

	else{
		direcao = id_Retornos[pilha.top()];
		if(pilha.top()==0) cord_y++;
		else if (pilha.top()==1)cord_y--;
		else if (pilha.top()==2)cord_x++;
		else if (pilha.top()==3)cord_x--;
		pilha.pop();
	}
	
	return direcao;
}

// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 2 ***
//	Implementacao da segunda estrategia de jogo.

void init_Player2() {
	
}

int anterior=-1;

const char *run_Player2() {
	const char *direcao;
	int move=-1;
	int aux=0;
	while (1){

		move = rand()%4;

		if(maze_VerCaminho("norte") == CAMINHO && move == 0 && anterior!=1){
			anterior=0;
			break;
		}
		else if(maze_VerCaminho("sul") == CAMINHO && move==1 && anterior!=0){
			anterior=1;
			break;
		}
		else if(maze_VerCaminho("oeste") == CAMINHO && move==2 && anterior!=3){
			anterior=2;
			break;
		}
		else if(maze_VerCaminho("leste") == CAMINHO &&move==3 &&  anterior!=2){
			anterior=3;
			break;
		}
		else if(aux>30) anterior=-1;
		aux++;
	}
	
	direcao = id_Caminhos[move];
	
	return direcao;
}


