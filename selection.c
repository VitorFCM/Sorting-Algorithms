#include <stdio.h>
#include <stdlib.h>

typedef int elem;

void selection(elem *lista, int tam){
	for(int i = 0; i < tam - 1; i++){
		elem menor = lista[i];
		int indice_menor = i;
		for(int j = i + 1; j < tam; j++){
			if(lista[j] < menor){
				menor = lista[j];
				indice_menor = j;
			}
		}
		printf("%d\n", menor);
		lista[indice_menor] = lista[i];
		lista[i] = menor;
	}

}

int main(){
        elem lista[] = {25, 57, 35, 37, 12, 86, 92, 33, 35, 58, 34, 80, 45, 22, 14, 34};

        selection(lista, 16);
        for(int i = 0; i < 16; i++){
                printf("%d ", lista[i]);
        }

        printf("\n");

        return 0;
}

