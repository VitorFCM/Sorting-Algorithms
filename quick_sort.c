#include <stdio.h>
#include <stdlib.h>

typedef int elem;

void quick_sort_simples(elem *lista, int ini, int fim){//não suporta valores duplicados

	if(ini >= fim){
		return;
	}

	int meio = (ini + fim)/2;
	elem pivo = lista[meio];

	int i = ini, j = fim;
	while(i < j){

		for(; lista[i] < pivo; i++);

		for(; lista[j] > pivo; j--);

		elem aux = lista[i];
		lista[i] = lista[j];
		lista[j] = aux;
	}

	for(int k = ini; k <= fim; k++){
		printf("%d ", lista[k]);
	}
	printf("\n");
	quick_sort_simples(lista, ini, i - 1);//repare que a posição do i é importante nesse caso, pois é ele que define onde os valores menores que o pivo estão.Você precisa dessa informação para saber quais são os trechos menores e maiores que o pivo.
	quick_sort_simples(lista, i + 1, fim);

}

void quick_sort_aprimorado(elem *lista, int ini, int fim){
	//Nesse caso o algoritmo usa a partição de Lomuto. Nesse tipo de particao, o pivo sempre irá ocupar a ultima posição. A cada chamada da funcao, posiciona-se os elementos menores que o pivo no trecho inicial da lista fornecida. Depois, o pivo, que estava na ultima posicao, é colocado uma posicao a frente dos elementos que são menores que o proprio pivo. Dessa forma, a cada camada da funcao, a lista é dividida entre os menores e maiores termos que o pivo.

	int i = ini;//a variavel i sempre vai limitar qual é o trecho da lista que possui os termos menores que o pivo, assim quando um termo menor do que o pivo for encontrado sabemos que devemos coloca-lo na posicao i, pois é ali que a sequencia de termos menores que o pivo acaba.

	elem aux;
	for(int j = ini; j < fim; j++){
		if(lista[j] < lista[fim]){
			aux = lista[i];
			lista[i] = lista[j];
			lista[j] = aux;

			i++;//sabemos que antes de i só temos termos menores que o pivo.
		}
	}

	aux = lista[fim];
	lista[fim] = lista[i];
	lista[i] = aux;//neste momento a posicao i divide o vetor entre elementos menores e maiores que o pivo, então basta colocar o pivo ai para poder dividir o vetor corretamente.

	if(ini < i - 1){
		quick_sort_aprimorado(lista, ini, i - 1);
	}
	if(i + 1 < fim){
		quick_sort_aprimorado(lista, i + 1, fim);
	}
}

int main(){
	elem lista[] = {25, 57, 35, 37, 12, 86, 92, 33};
	elem lista2[] = {35, 58, 34, 80, 45, 22, 14, 34};

	quick_sort_simples(lista, 0, 7);
	//quick_sort_aprimorado(lista2, 0, 7);
	for(int i = 0; i <= 7; i++){
		printf("%d ", lista[i]);
	}

	printf("\n");

	return 0;
}
