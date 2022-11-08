#include <stdio.h>
#include <stdlib.h>

typedef int elem;

void insertion(elem *lista, int tam){

	for(int i = 1; i < tam; i++){
		elem aux = lista[i];

		int j = i - 1;
		while(j >= 0 && aux < lista[j]){
			lista[j + 1] = lista[j];
			j--;
		}
		lista[j + 1] = aux;
	}
}
//ordem quadrática
//se o vetor já estiver ordenado a complexidade é linear O(n)
//o pior caso ocorre quando o vetor está ordenado em ordem decrescente, pois será necessário
//trocar todos os elementos.
//a complexidade de espaço é linear, pois utiliza um único vetor para guardar todos os elementos
//é eficiente quando o etor está quase ordenado, perto de ordem O(n)


int main(){
	elem lista[] = {25, 57, 35, 37, 12, 86, 92, 33};
	elem lista2[] = {35, 58, 34, 80, 45, 22, 14, 34};

	insertion(lista, 8);
	
	for(int i = 0; i < 8; i++){
		printf("%d ", lista[i]);
	}

	printf("\n");
	
	return 0;
}