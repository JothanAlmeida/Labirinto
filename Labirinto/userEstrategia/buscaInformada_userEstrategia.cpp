#include<stack>
#include<iostream>

stack <int> pilha;
int matriz[60][35] = {0};
int pos_x = 0, pos_y = 0;
float custoMovimento1 = 0;

void init_Player1() {
	matriz[0][0] = 1;
}

const char *run_Player1() {
	const char *movimento;
	float norte = 100000, sul = 100000, leste = 100000, oeste = 100000;
	if ((maze_VerCaminho("norte") == CAMINHO && matriz[pos_x][pos_y - 1] == 0) ||
	(maze_VerCaminho("leste") == CAMINHO && matriz[pos_x + 1][pos_y] == 0) ||
	(maze_VerCaminho("sul") == CAMINHO && matriz[pos_x][pos_y + 1] == 0) ||
	(maze_VerCaminho("oeste") == CAMINHO && matriz[pos_x - 1][pos_y] == 0)) {
		if (maze_VerCaminho("norte") == CAMINHO && maze_VerMinotauro("norte") == false && matriz[pos_x][pos_y - 1] == 0) {
			norte = maze_HeuristicaDistEuclidiana("norte");
		}
		if (maze_VerCaminho("leste") == CAMINHO && maze_VerMinotauro("leste") == false && matriz[pos_x + 1][pos_y] == 0) {
			leste = maze_HeuristicaDistEuclidiana("leste");
		}		
		if (maze_VerCaminho("sul") == CAMINHO && maze_VerMinotauro("sul") == false && matriz[pos_x][pos_y + 1] == 0) {
			sul = maze_HeuristicaDistEuclidiana("sul");
		}
		if (maze_VerCaminho("oeste") == CAMINHO && maze_VerMinotauro("oeste") == false && matriz[pos_x - 1][pos_y] == 0) {
			oeste = maze_HeuristicaDistEuclidiana("oeste");
		}
		if (1 > 0) {
			if (norte <= sul && norte <= oeste && norte <= leste) {
				movimento = "norte";
				pilha.push(0);
				pos_y--;
				matriz[pos_x][pos_y] = 1;
			}
			else if (sul <= oeste && sul <= norte && sul <= leste) {
				movimento = "sul";
				pilha.push(1);
				pos_y++;
				matriz[pos_x][pos_y] = 1;
			}
			else if (oeste <= sul && oeste <= leste && oeste <= norte) {
				movimento = "oeste";
				pilha.push(2);
				pos_x--;
				matriz[pos_x][pos_y] = 1;
			}
			else if (leste <= sul && leste <= norte && leste <= oeste) {
				movimento = "leste";
				pilha.push(3);
				pos_x++;
				matriz[pos_x][pos_y] = 1;
			}
		}
	}
	else{
		movimento = id_Retornos[pilha.top()];
		if(pilha.top()==0) pos_y++;
		else if (pilha.top()==1) pos_y--;
		else if (pilha.top()==2) pos_x++;
		else if (pilha.top()==3) pos_x--;
		pilha.pop();
	}
	custoMovimento1 += maze_CustoDoCaminho(movimento);
	return movimento;
}

stack <int> pilha2;
int matriz2[60][35] = {0};
int pos_x2 = 0, pos_y2 = 0;
float custoMovimento2 = 0;

void init_Player2() {
	matriz2[0][0] = 1;
}

const char *run_Player2() {

	const char *movimento;
	float norte = 1000, sul = 1000, leste = 1000, oeste = 1000;
	int aux2[4] = {0};
	int cont_aux2 = 0;
	if((maze_VerCaminho("norte") == CAMINHO && matriz2[pos_x2][pos_y2-1] == 0) || (maze_VerCaminho("leste") == CAMINHO && matriz2[pos_x2+1][pos_y2] == 0) || 				(maze_VerCaminho("sul") == CAMINHO && matriz2[pos_x2][pos_y2+1] == 0) || (maze_VerCaminho("oeste") == CAMINHO && matriz2[pos_x2-1][pos_y2] == 0)){
		if (maze_VerCaminho("norte") == CAMINHO && maze_VerMinotauro("norte") == false && matriz2[pos_x2][pos_y2-1]==0){
			norte=maze_HeuristicaDistEuclidiana("norte");
		}
		if (maze_VerCaminho("leste") == CAMINHO && maze_VerMinotauro("leste") == false && matriz2[pos_x2+1][pos_y2]== 0 ) {
			leste=maze_HeuristicaDistEuclidiana("leste");
		}
		if (maze_VerCaminho("sul") == CAMINHO && maze_VerMinotauro("sul")==false && matriz2[pos_x2][pos_y2+1] == 0) {
			sul=maze_HeuristicaDistEuclidiana("sul");
		}
		if (maze_VerCaminho("oeste") == CAMINHO && maze_VerMinotauro("oeste") == false && matriz2[pos_x2-1][pos_y2]==0) {
			oeste=maze_HeuristicaDistEuclidiana("oeste");
		}
		if(1 > 0){
			if (norte <= sul && norte <= oeste && norte <= leste){
				aux2[cont_aux2]=0;
				cont_aux2++;
			}
			if (leste <= sul && leste <= norte && leste <= oeste ) {
				aux2[cont_aux2]=3;
				cont_aux2++;
			}
			if (sul <= oeste && sul <= norte && sul <= leste) {
				aux2[cont_aux2]=1;
				cont_aux2++;
			}
			if (oeste <= sul && oeste <= leste && oeste <= norte) {
				aux2[cont_aux2]=2;
				cont_aux2++;
			}
			int numSort = rand()%cont_aux2;
			movimento = id_Caminhos[aux2[numSort]];
			if(aux2[numSort] == 0){
				pos_y2--;
			} else if(aux2[numSort] == 1){
				pos_y2++;

			}else if(aux2[numSort] == 2){
				pos_x2--;
			}else if(aux2[numSort] == 3){
				pos_x2++;
			}
			matriz2[pos_x2][pos_y2] = 1;
			pilha2.push(aux2[numSort]);
		}
	}
	else{
		movimento = id_Retornos[pilha2.top()];
		if(pilha2.top() == 0) pos_y2++;
		else if (pilha2.top() == 1)pos_y2--;
		else if (pilha2.top() == 2)pos_x2++;
		else if (pilha2.top() == 3)pos_x2--;
		pilha2.pop();
	}
	custoMovimento2 += maze_CustoDoCaminho(movimento);
	return movimento;
}
