#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int bb_comp = 0; //variavel para contar o numero de comparacoes da busca binaria
int bs_comp = 0; //variavel para contar o numero de comparacoes da busca sequencial
int bogo_comp = 0; //variavel para contar o numero de comparacoes da busca bogo

int estaOrdenado(int * v, int tam){//funcao para testar se o vetor esta ordenado
	int i;
	for(i = 0; i < tam-1 ; i++){
		if(v[i] > v[i+1]) return 0;//caso um numero nao esteja em ordem crescente retorna falso
	}
	return 1;//se chegar ao fim retorna verdadeiro
}

int buscaBinaria(int * v, int k, int inicio, int fim){ //funcao que executa uma busca binaria
	bb_comp++; //incrementa variavel com numero de comparacoes
	int meio = (inicio + fim)/2;
	if(v[meio] == k) return meio;	
	if(inicio > fim) return -1;//valor nao encontrado
	if(v[meio] == k) return meio;
	if(v[meio] > k) return buscaBinaria(v, k, inicio, meio-1);
	return buscaBinaria(v, k, meio + 1, fim);
}

int buscaSequencial(int * v, int k, int tam){ //funcao que executa uma busca sequencial
	int i;
	for(i = 0; i < tam; i++){
		bs_comp++; //incrementa variavel com numero de comparacoes
		if(v[i] == k) return i;
	}
	return -1;
}

int buscaBogo(int * v, int k, int tam){ //funcao que executa uma busca bogo
	int i, aleatorio;
	int visitados[tam]; //vetor para marcar os indices ja visitados e desconsidera-los na hora de incrementar a variavel de comparacoes
    memset(visitados, 0, tam*sizeof(int));
	for(i = 0; i < tam; i++){
		bogo_comp++; //incrementa variavel com numero de comparacoes

		do{
			aleatorio = rand() % tam; //gera numero aleatorio dentro dos indices possiveis do vetor (0, tamanho-1)
		}while(visitados[aleatorio]); //caso ja tenha sido visitado busca novo indice

		if(v[aleatorio] == k) return aleatorio;
		else visitados[aleatorio]++;
	}
	return -1;
}

int main(){
	int k, t;
	scanf("%d %d", &k, &t);
	int vet[t];
	for(int i = 0; i < t; i++){
		scanf("%d", &vet[i]);
	}
	printf("Esta ordenado? ");
	if(estaOrdenado(vet, t)) printf("S.\n");
	else printf("N.\n");

	printf("Índice encontrado:\n");
	printf("  - Binária: %d\n", buscaBinaria(vet, k, 0, t));
	printf("  - Sequencial: %d\n", buscaSequencial(vet, k, t));
	printf("  - Bogo: %d\n", buscaBogo(vet, k, t));

	printf("Número de comparações:\n");
	printf("  - Binária: %d\n  - Sequencial: %d\n  - Bogo: %d\n", bb_comp, bs_comp, bogo_comp);
	return 0;
}
