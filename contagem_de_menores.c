#include <stdio.h>
#include <stdlib.h>

typedef int elem;

// Esse algoritmo sozinho não é bom, tanto para o contagem_de_menores(Vitor)
// quanto para o contagem_de_menores_alternativo(prof), pois ambos são O(n^2)
// Porém, essa ideia serve como base para a implementação de um algoritmo
// melhor.
  
elem* contagem_de_menores(elem *lista, int tam){
	elem *lista2;

	lista2 = (elem*)malloc(tam*sizeof(elem));

	if(lista2 == NULL){
		printf("Erro na alocação de memória\n");
		exit(1);
	}
	
	for(int i = 0; i < tam; i++){
		int n_menores = 0;
		for(int j = 0; j < tam; j++){
			if(j != i && lista[j] < lista[i]){
				n_menores++;
			}
		}
		
		if(lista2[n_menores] == lista[i])
			lista2[++n_menores] = lista[i];
		else
			lista2[n_menores] = lista[i];
		
	}
	
	return lista2;	
}

void contagem_de_menores_alternativo(elem **lista, int tam){
	elem *contagem;
	elem *auxiliar;

	contagem = (elem*)malloc(tam*sizeof(elem));
	auxiliar = (elem*)malloc(tam*sizeof(elem));

	if(contagem == NULL || auxiliar == NULL){
		printf("Erro na alocação de memória\n");
		exit(1);
	}

	for(int i = 1; i < tam; i++){
		for(int j = 0; j < i; j++){
			if((*lista)[j] < (*lista)[i]){
				contagem[i]++;
			} else{
				contagem[j]++;
			}
		}
	}
	for(int i = 0; i < tam; i++){
		auxiliar[contagem[i]] = (*lista)[i];
	}
	free(contagem);
	*lista = auxiliar;
}

int main(){
    elem *lista;
    elem val[] = {25, 57, 35, 37, 12, 86, 92, 33, 35, 58, 34, 80, 45, 22, 14, 34};
	lista = val;
	
	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}
	printf("\n");

	contagem_de_menores_alternativo(&lista, 16);

    for(int i = 0; i < 16; i++){
        printf("%d ", lista[i]);
    }

    free(lista);
    printf("\n");
    return 0;
}
