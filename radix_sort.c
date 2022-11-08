#include <stdio.h>
#include <stdlib.h>


typedef int elem;

int retorna_digito(elem numero, int posicao){ // complexidade tem a ordem da "posicao"
	for(int i = 0; i < posicao; i++){
		numero = numero/10;
	}

	return numero % 10;
}

void radix_sort(elem *lista, int tam){
	elem maior = lista[0];

	for(int i = 0; i < tam; i++){ // complexidade de ordem "n"
		if(lista[i] > maior)
			maior = lista[i];
	}

	int n_digitos = 1;
	while(maior >= 10){
		maior = maior/10;
		n_digitos++;
	}

	elem *listas_numeros[10];
	for(int i = 0; i < 10; i++){
		listas_numeros[i] = (elem*)malloc(tam*sizeof(elem));
 	}

 	int listas_num_tam[10] = {0};
 	for(int i = 0; i < n_digitos; i++){

 		for(int j = 0; j < tam; j++){ // complexidade de ordem de "n"
 			int digito = retorna_digito(lista[j], i); // complexidade de ordem "i"
 			listas_numeros[digito][listas_num_tam[digito]] = lista[j];
 			listas_num_tam[digito]++;
 		}

 		int indice_lista = 0;
 		for(int i = 0; i < 10; i++){
 			for(int j = 0; j < listas_num_tam[i]; j++){
 				lista[indice_lista++] = listas_numeros[i][j];
 			}
 			listas_num_tam[i] = 0;
 		} // o total tem uma complexidade de ordem "n"  
 	}


 	for(int i = 0; i < 10; i++){
		free(listas_numeros[i]);
 	}
}

int main(){
	elem *lista;
    elem val[] = {25, 57, 35, 37, 12, 86, 92, 33, 35, 58, 34, 80, 45, 22, 14, 34};
	lista = val;
	
	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}
	printf("\n");

	radix_sort(lista, 16);

	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}
	printf("\n");

	return 0;
}