#include <stdio.h>
#include <stdlib.h>

typedef int elem;

// esse algoritmo funciona registrando quantas vezes cada elemento
// aparece no vetor original e depois recoloca-os nas posições corretas.
// funciona assim: primeiro descobre-se qual é o maior e o menor elemento
// do vetor original. Depois cria-se um vetor auxiliar no qual o indice "i" 
// cada posição, mais o valor do menor elemento do vetor original, vai
// guardar o numero de vezes que o elemento "i + menor elemento" aparece 
// no vetor original. Por fim, basta passar o resultado para o vetor original.

// a complexidade desse algoritimo é linear

//restrição: devemos trabalhar em um dominio discreto, nunca vai aparecer 1.1, 1.5, 1.6, apenas 1, 5, 7

// repare que, nesse algoritmo, tirando a parte de encontrar o maior
//  e o menor elemento, os valores não precisam ser comparados.

// a complexidade vai depender bastante da diferença entre o maior e o
// menor elemento do vetor. O custo sempre será linear, mas se a diferença
// entre o maior e o menor for muito grande, teremos que percorrer um vetor
// que pode ser até maior que o vetor original

void counting_sort(elem **lista, int tam){
	elem maior = (*lista)[0];
	elem menor = (*lista)[0];

	for(int i = 1; i < tam; i++){ // complexidade = n - 1
		if((*lista)[i] > maior)
			maior = (*lista)[i];
		if((*lista)[i] < menor)
			menor = (*lista)[i];
	}

	int n_counting = maior - menor + 1; // tamanho do vetor auxiliar
	elem *couting = (elem*)malloc(n_counting*sizeof(elem));

	for(int i = 0; i < n_counting; i++){ // complexidade = maior - menor + 1
		couting[i] = 0; // zerando todas as posições pois ainda não começamos a contar
	}

	for(int i = 0; i < tam; i++){ // complexidade = n 
		couting[(*lista)[i] - menor]++; // agora devemos fazer um tipo de translação,
										// como nosso vetor auxiliar só guarda os valores
										// entre o menor e o maior elemento do vetor, cada 
										// valor (*lista)[i] deve deslocar "menor" vezes
										// para encontrarmos o indice certo do vet auxiliar
	}

	int j = 0;
	for(int i = 0; i < n_counting; i++){ // aqui fazemos a copia dos valores para o vetor original
		
		while(j < tam && couting[i] > 0){ // independente do numero de rodadas de i,
										  // sabemos que, no total, esse while terá 
										  // rodado "tam" vezes, pois somando todos os valores
										  // armazenados no vetor counting obteremos "tam"  
			(*lista)[j++] = i + menor;
			couting[i]--;
		}
	} // a complexidade total desse trecho sera maior - menor + 1 + n, o prof q disse isso, não sei se concordo

	free(couting);
}
int main(){
	elem *lista;
    elem val[] = {25, 57, 35, 37, 12, 86, 92, 33, 35, 58, 34, 80, 45, 22, 14, 34};
	lista = val;
	
	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}
	printf("\n");

	counting_sort(&lista, 16);

	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}
	printf("\n");

	return 0;
}