#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *arquivo;

#define MAX 2000000

enum ARQUIVOS {
	SAIR,
	ARQ_1K,
	ARQ_10K,
	ARQ_100K,
	ARQ_500K,
	ARQ_1M,
	ARQ_2M
};

// escopo de metodos
void tempo_processamento(unsigned int t0);
void abrirArquivo(char tipo[3]);
void menuArquivos();
void menuEscolha();
void ordena(int op, int tamanho);
void bubbleSort(int vetor[], int tamanho);
void quickSort(int *vet, int inicio, int fim);
void mergeSort(int vetor[], int tamanho);
void refazHeap(int Esq, int Dir, int *vet);
void constroiHeap(int *vet, int n);
int retiraMaxHeap(int *vet, int n);
void heapSort(int *vet, int n);

int t0;
int trocas = 0;
int comparacoes = 0;
int *vet = (int *)malloc(MAX * sizeof(int));

void main() {

	int menu, escolha, tamanho;

	// abre menu
	menuArquivos();
	scanf_s("%d", &menu);

	switch (menu) {
	case ARQ_1K:
		tamanho = 1000;
		// abre arquivo
		abrirArquivo("w");
		// grava caracteres randomicos no arquivo 
		for (int i = 0; i < 1000; i++) {
			vet[i] = rand() % 1000;
			fprintf(arquivo, "%d ", vet[i]);
		}
		fclose(arquivo);
		break;

	case ARQ_10K:
		tamanho = 10000;
		// abre arquivo
		abrirArquivo("w");
		// grava caracteres randomicos no arquivo 
		for (int i = 0; i < 10000; i++) {
			vet[i] = rand() % 10000;
			fprintf(arquivo, "%d ", vet[i]);
		}
		fclose(arquivo);
		break;

	case ARQ_100K:
		tamanho = 100000;
		// abre arquivo
		abrirArquivo("w");
		// grava caracteres randomicos no arquivo 
		for (int i = 0; i < 100000; i++) {
			vet[i] = rand() % 100000;
			fprintf(arquivo, "%d ", vet[i]);
		}
		fclose(arquivo);
		break;

	case ARQ_500K:
		tamanho = 500000;
		// abre arquivo
		abrirArquivo("w");
		// grava caracteres randomicos no arquivo 
		for (int i = 0; i < 500000; i++) {
			vet[i] = rand() % 500000;
			fprintf(arquivo, "%d ", vet[i]);
		}
		fclose(arquivo);
		break;

	case ARQ_1M:
		tamanho = 1000000;
		// abre arquivo
		abrirArquivo("w");
		// grava caracteres randomicos no arquivo 
		for (int i = 0; i < 1000000; i++) {
			vet[i] = rand() % 1000000;
			fprintf(arquivo, "%d ", vet[i]);
		}
		fclose(arquivo);
		break;

	case ARQ_2M:
		tamanho = 2000000;
		// abre arquivo
		abrirArquivo("w");
		// grava caracteres randomicos no arquivo 
		for (int i = 0; i < 2000000; i++) {
			vet[i] = rand() % 2000000;
			fprintf(arquivo, "%d ", vet[i]);
		}
		fclose(arquivo);
		break;

	case SAIR:
		exit(1);
		break;
	default:
		puts("Opcao invalida!"); break;
	}

	system("cls");

	abrirArquivo("w");
	menuEscolha();
	scanf_s("%d", &escolha);
	ordena(escolha, tamanho);
	fclose(arquivo);
}

void tempo_processamento(int t0)
{
	int tf, t_gasto;
	tf = clock();
	t_gasto = (tf - t0);
	printf("\nTempo de processo: %u Milisegundos\n", t_gasto);
}

void abrirArquivo(char tipo[3]) {
	errno_t err;
	err = fopen_s(&arquivo, "arquivo.txt", tipo);
	if (arquivo == NULL) {
		printf("\nO arquivo nao pode ser aberto.");
		exit(1);
	}
}

void menuArquivos() {
	puts("========== ESCOLHA O TAMANHO DE ARQUIVO ==========\n");
	puts("1- Criar arquivo de 1k");
	puts("2- Criar arquivo de 10k");
	puts("3- Criar arquivo de 100k");
	puts("4- Criar arquivo de 500k");
	puts("5- Criar arquivo de 1M");
	puts("6- Criar arquivo de 2M");
	printf("\n0- Sair\n");
	puts("\nOpcao: ");
}

void menuEscolha() {
	puts("1- Ordenar com BubbleSort");
	puts("2- Ordenar com QuickSort");
	puts("3- Ordenar com HeapSort");
	puts("4- Ordenar com MergeSort");
	puts("5- Grafico");
	puts("\nOpcao: ");
}

void ordena(int op, int tamanho) {
	if (op == 1) {
		bubbleSort(vet, tamanho);
		for (int i = 0; i < tamanho; i++) {
			fprintf(arquivo, "%d ", vet[i]);
		}
		tempo_processamento(t0);
		printf("Numero de trocas: %d\n", trocas);
		printf("Numero de comparacoes: %d\n", comparacoes);
		printf("\nOrdenado com sucesso!\n");
		fclose(arquivo);
	}
	else if (op == 2) {
		quickSort(vet, 0, tamanho - 1);
		for (int i = 0; i < tamanho; i++) {
			fprintf(arquivo, "%d ", vet[i]);
		}
		tempo_processamento(t0);
		printf("Numero de trocas: %d\n", trocas);
		printf("Numero de comparacoes: %d\n", comparacoes);
		printf("\nOrdenado com sucesso!\n");
		fclose(arquivo);
	}
	else if (op == 3) {
		heapSort(vet, tamanho - 1);
		for (int i = 0; i < tamanho; i++) {
			fprintf(arquivo, "%d ", vet[i]);
		}
		tempo_processamento(t0);
		printf("Numero de trocas: %d\n", trocas);
		printf("Numero de comparacoes: %d\n", comparacoes);
		printf("\nOrdenado com sucesso!\n");
		fclose(arquivo);
	}
	else if (op == 4) {
		mergeSort(vet, tamanho);
		for (int i = 0; i < tamanho; i++) {
			fprintf(arquivo, "%d ", vet[i]);
		}
		tempo_processamento(t0);
		printf("Numero de trocas: %d\n", trocas);
		printf("Numero de comparacoes: %d\n", comparacoes);
		printf("\nOrdenado com sucesso!\n");
		fclose(arquivo);
	}


}

void bubbleSort(int vet[], int tamanho) {
	int aux;

	for (int i = tamanho - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			comparacoes++;
			if (vet[j]>vet[j + 1]) {
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
				trocas++;
			}
		}
	}
}

void quickSort(int vet[], int esquerda, int direita)
{
	int i, j, x, y;
	i = esquerda;
	j = direita;
	x = vet[(esquerda + direita) / 2];

	while (i <= j)
	{
		while (vet[i] < x && i < direita)
		{
			i++;
		}
		while (vet[j] > x && j > esquerda)
		{
			j--;
		}
		comparacoes++;
		if (i <= j)
		{
			y = vet[i];
			vet[i] = vet[j];
			vet[j] = y;
			i++;
			j--;
			trocas++;
		}
	}
	if (j > esquerda)
	{
		quickSort(vet, esquerda, j);
	}
	if (i < direita)
	{
		quickSort(vet, i, direita);
	}
}

void merge(int vet[], int vecSize) {
	int mid;
	int i, j, k;
	int* tmp;

	tmp = (int*)malloc(vecSize * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}

	mid = vecSize / 2;

	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < vecSize) {
		if (vet[i] <= vet[j]) {
			tmp[k] = vet[i++];
			comparacoes++;
		}
		else {
			tmp[k] = vet[j++];
			comparacoes++;
		}
		++k;
		comparacoes++;
	}

	if (i == mid) {
		while (j < vecSize) {
			tmp[k++] = vet[j++];
			comparacoes++;
		}
		comparacoes++;
	}
	else {
		while (i < mid) {
			tmp[k++] = vet[i++];
			comparacoes++;
		}
	}

	for (i = 0; i < vecSize; ++i) {
		vet[i] = tmp[i];
		trocas++;
	}

	free(tmp);
}

void mergeSort(int vet[], int vecSize) {
	int mid;

	if (vecSize > 1) {
		mid = vecSize / 2;
		mergeSort(vet, mid);
		mergeSort(vet + mid, vecSize - mid);
		merge(vet, vecSize);
	}
}

void refazHeap(int Esq, int Dir, int *vet)
{
	int i = Esq;
	int	j;
	int x;
	j = i * 2;
	x = vet[i];
	while
		(j <= Dir)
	{
		if
			(j < Dir)
		{
			if (vet[j] < vet[j + 1])
				j++;
			comparacoes++;
		}
		if
			(x >= vet[j])
			break;
		vet[i] = vet[j];
		i = j; j = i * 2;
	}
	vet[i] = x;
}

void constroiHeap(int *vet, int n)
{
	int Esq;
	Esq = n / 2 + 1;
	while
		(Esq > 1) {
		Esq--;
		refazHeap(Esq, n, vet);
	}
}

int retiraMaxHeap(int *vet, int n)
{
	int Maximo;
	if
		(n < 1)
		printf("Erro: heap vazio\n");
	else
	{
		Maximo = vet[1];
		vet[1] = vet[n];
		(n)--;
		refazHeap(1, n, vet);
	}
	return
		Maximo;
}

void heapSort(int *vet, int n)
{
	int Esq, Dir;
	int x;
	constroiHeap(vet, n);
	/* constroi o heap */
	Esq = 1; Dir = n;
	while
		(Dir > 1)
	{
		/* ordena o vetor */
		x = vet[1];
		vet[1] = vet[Dir];
		vet[Dir] = x;
		Dir--;
		refazHeap(Esq, Dir, vet);
		trocas++;
	}
}