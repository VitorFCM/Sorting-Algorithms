#include <stdio.h>
#include <stdlib.h>

typedef int elem;

//analisar a complexicidade

void insertion(elem *lista, int tam, long h){

	for(long i = h; i < tam; i++){
		elem aux = lista[i];

		long j = i - h;
		while(j >= 0 && aux < lista[j]){
			lista[j + h] = lista[j];
			j -= h;
		}
		lista[j + h] = aux;
	}
}


void shell_sort(elem *lista, long tam){

	long mem = 10;//total de memoria a ser alocada
	long *lista_passos = malloc(mem*sizeof(long));//o professor adenilso dizia que era bom aloccar memoria em passos maiores para não precisar fazer muitos

	lista_passos[0] = 1;

	long i = 1;
	while(lista_passos[i - 1] < tam){ 

		if(i > mem){
			mem += 10;
			lista_passos = (long*)realloc(lista_passos, mem);
			if(lista_passos == NULL)
				printf("Erro na criação do vetor de passos\n");
				exit(1);
		}

		lista_passos[i] = 3*lista_passos[i - 1] + 1;
		i++;
	}
	i--;

	for(; i >= 0; i--){
		insertion(lista, tam, lista_passos[i]);
	}

	free(lista_passos);
}

int main(){
	elem lista[] = {25, 57, 35, 37, 12, 86, 92, 33, 35, 58, 34, 80, 45, 22, 14, 34};

	shell_sort(lista, 16);
	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}

	printf("\n");
	
	return 0;
}