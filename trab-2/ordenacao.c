#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int* v, int a, int b){
	int aux = v[b];
	v[b] = v[a];
	v[a] = aux;
	return;
}

int estaOrdenado(int * v, int tam){//funcao para testar se o vetor esta ordenado
	int i;
	for(i = 0; i < tam-1 ; i++){
		if(v[i] > v[i+1]) return 0;//caso um numero nao esteja em ordem crescente retorna falso
	}
	return 1;//se chegar ao fim retorna verdadeiro
}

//merge sort

void merge(int *v, int *c, int i, int m, int f) {
  int z, iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    if (c[iv] < c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}

void sort(int* v, int* c, int i, int f){
	if(i >= f) return;
	sort(v, c, i, (i+f)/2);
	sort(v, c, (i+f)/2 + 1, f);
	if(v[(i+f)/2] <= v[(i+f)/2 + 1])return;
	merge(v, c, i, (i+f)/2, f);
}

void mergesort(int* v, int n){
	int* c = (int*)malloc(sizeof(int)*n);
	sort(v, c, 0, n-1);
	free(c);
}	

//insertion sort

void insertionsort(int* vetor, int tam){ //testado
	int fora, dentro, count = 0;
	for(fora = 1; fora < tam; fora++){
		dentro = fora;
		while(vetor[dentro-1] > vetor[dentro] && dentro > 0){
			troca(vetor, dentro, dentro-1);
			count++;
			dentro--;
		}
	}
	printf("trocas:%d\n", count);
	return;
}


//selection sort

int achaMin(int* v, int i, int n){ //testado
	int j, im = i, min = v[i];
	for(j = i; j < n; j++){
		if(v[j] < v[im]){
			im = j;
			min = v[im];
		}
	}
	return im;
}

void selectionsort(int* v, int n){ //testado
	int i, min;
	for(i = 0; i < n-1; i++){
		min = achaMin(v, i, n);
		troca(v, i, min);
	}
	printf("comparacoes: %d\n", n*n);
	return;
}

int main(){
	int n, i;
	clock_t inicio, fim, total;
	double resultado;
	scanf("%d", &n);
	int* vet = (int*)malloc(sizeof(int)*n);
	
	for(i = 0; i < n; i++){
		scanf("%d", &vet[i]);
	}
	printf("%d\n", n);
	printf("%d\n", estaOrdenado(vet, n));
	inicio = clock();
	insertionsort(vet, n);
	fim = clock();
	printf("%d\n", estaOrdenado(vet, n));

	resultado = (double)(fim - inicio)/CLOCKS_PER_SEC;

	printf("%f\n", resultado);
	
	free(vet);
	return 0;
}