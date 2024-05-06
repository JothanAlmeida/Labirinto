// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 1 ***
//Estratégia: Subida de encosta utilizando reinicialização aleatória

int contReinicializacao = 0;
tipo_Valor melhorPontuacao1;

void init_Player1() {
	// Determina posicao inicial aleatoriamente.
	reinicializa_PosicaoAleatoria();
	
	//Inicializa a melhor pontuação do jogador 1.
	melhorPontuacao1 = superf_VerAmbiente();
}
tipo_Movimento run_Player1() {
	tipo_Movimento movimento;
	
	const char * direcao;
	int preferencia = 0;
	int i;

	//Busca pelo caminho que leva a um ponto mais elevado.
	for( i=0; i<NUMCAMINHOS; i++){
		int pontuacao = superf_VerVizinho(id_Caminhos[i]);
		if(preferencia <= pontuacao){
			preferencia = pontuacao;
			direcao = id_Caminhos[i];
		}
	}
	
	//Se estiver em um ponto de máximo local, reinicializa a posição aleatoriamente.
	if(superf_VerAmbiente() > preferencia) {
		if(superf_VerAmbiente() > melhorPontuacao1){
			melhorPontuacao1 = superf_VerAmbiente();
		}
		contReinicializacao++;
		reinicializa_PosicaoAleatoria();
		return run_Player1();
	}

	//Caso contrário, segue na direção do caminho com a maior pontuação.
	movimento.direcao = direcao;
	movimento.passo = 1;

	return movimento;
} 

tipo_Valor result_Player1() {
	return melhorPontuacao1;
}


// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 2 ***
//Estratégia: Subida de encosta usando aleatóriamente uma das melhores opções com Reinício Aleatório

int contReinicializacao2 = 0;
tipo_Valor melhorPontuacao2;

void init_Player2() {
	// Determina posicao inicial aleatoriamente.
	reinicializa_PosicaoAleatoria();
	
	//Inicializa a melhor pontuação do jogador 2.
	melhorPontuacao2 = superf_VerAmbiente();
}

tipo_Movimento run_Player2() {
	tipo_Movimento movimento;
	int preferencia = 0, indice;
	const char * direcao;

	if(superf_VerAmbiente() > melhorPontuacao2){
		melhorPontuacao2 = superf_VerAmbiente();
	}

	//Encontra posições mais elevadas que a atual
	while(superf_VerVizinho(direcao) < superf_VerAmbiente()){
			for(int i=0; i<NUMCAMINHOS; i++){	//Verifica os caminhos e econtra qual leva a um ponto mais elevado
				if(superf_VerVizinho(id_Caminhos[i]) >= preferencia ){
					preferencia = superf_VerVizinho(id_Caminhos[i]);
				}
			}
			if(preferencia <= superf_VerAmbiente()){	// Caso esteja em um ponto de máximo, reinicia
				if(superf_VerAmbiente() > melhorPontuacao2){
					melhorPontuacao2 = superf_VerAmbiente(); // antes de reiniciar, verifica se é um possível ponto de máximo global, caso seja, é atribuido
				}
				contReinicializacao2++;
				reinicializa_PosicaoAleatoria();
			}

		indice = rand() % NUMCAMINHOS;	//Escolha aleatória de uma direção
		direcao = id_Caminhos[indice];	
	};
	
	movimento.direcao = direcao;	
	movimento.passo = 1;

	return movimento;
}

tipo_Valor result_Player2() {
	return melhorPontuacao2;
}

