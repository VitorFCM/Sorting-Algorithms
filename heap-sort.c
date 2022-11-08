/*Heap-sort

link: https://www.youtube.com/watch?v=g0v12ZOfEkw&list=PL4RGnfxCylxShF29_TxJHWs2oUEIKExCn&index=19

-Um heap é uma estrutura de dados em que há uma
ordenação entre elementos: representação via árvore
binária. Todo heap é uma árvore binária mas nem toda árvore binária é um heap.
Possui duas propriedades: de ordem e de forma.

-Ordem: O item de qualquer nó deve satisfazer uma relação
de ordem com os itens dos nós filhos.
-Heap máximo(ou descendente): pai>=filhos, sendo
que a raiz é o maior elemento.

-Heap mínimo(ou heap ascendente): pai <= filhos, sendo
que a raiz é o menor elemento.

-Forma: A árvore binária tem seus nós-folha, no máximo, em dois níveis,
sendo que as folhas devem estar o mais à esquerda possível.

Essa organização deixa fácil de se organizar um array respeitando
a ordem.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int elem;

void rearranja_heap(elem *lista, int indice, int tam){
	/*
	   Nessa rotina, o pior caso ocorre quando o nó precisa descer
	   todos os níveis da árvore heap. Como a altura de uma arvore
	   binaria, numero de niveis, é igual a log(n) na base 2, no nosso
	   pior caso estaremos fazendo log(n-1) trocas.
	   */
	int indice_esq = 2*indice + 1;
	if(indice_esq >= tam){
		return;
	}
	int indice_dir = 2*indice + 2;

	elem maior = lista[indice_esq];
	int indice_troca = indice_esq;

	if(indice_dir < tam && lista[indice_dir] > maior){
		maior = lista[indice_dir];
		indice_troca = indice_dir;
	}

	elem aux = lista[indice];
	if(aux < maior){
		lista[indice] = maior;
		lista[indice_troca] = aux;
	}


	rearranja_heap(lista, indice_troca, tam);
}


void heap_sort(elem *lista, int tam){
	/*
	   Vamos observar uma coisa: Como a heap é uma árvore balanceada por
	   conta da sua propriedade de forma, sabemos que a partir do elemento n/2
	   todos os nós serão folhas, Logo, todos os elementos a partir n/2 são
	   heaps máximos de suas sub-arvores, pois eles não tem filhos.
	   Dessa forma, basta chamar o rearranja do indice n/2 - 1 até 0.
	   */
	for(int i = tam/2 - 1; i >= 0; i--){
		rearranja_heap(lista, i, tam);
	}
	/*
	   Até esse momento, fica claro que a complexidade para montar a arvore foi de (n/2)log(n-1)
	   */

	for(int i = 0; i < tam; i++){
		printf("%d ", lista[i]);
	}
	printf("\n");


	/*
	   Sabemos que a primeira posição sempre corresponde ao maior elemento da lista,
	   então basta colocar esse elemento na última posição do vetor(o elemento colocado
	   no indice zero não está na sua posição correta, mas o maior está). Depois de trocar
	   o primeiro elemento com o último, é necessário rearranjar o elemento da posição zero
	   para que este chegue na sua posição correta, no pior caso ele terá percorrido a árvore
	   fazendo log(n/2)(é sobre 2 pois é o tamanho médio) trocas. Esse procedimento de troca é
	   realizado com todos os elementos menos com o último. Dessa forma, devemos somar (n-1)log(n)
	   à complexidade de se montar a árvore.
	   */
	int ultimo_indice = tam - 1;
	elem aux;

	while(ultimo_indice > 0){
		aux = lista[ultimo_indice];
		lista[ultimo_indice] = lista[0];
		lista[0] = aux;
		ultimo_indice--;
		rearranja_heap(lista, 0, ultimo_indice + 1);
	}
}
/*Arredondando todas as constantes obtemos que a complexidade total do heap-sort é nlog(n)*/

int main(){
	elem lista[] = {25, 57, 35, 37, 12, 86, 92, 33, 35, 58, 34, 80, 45, 22, 14, 34};

	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}
	printf("\n");
	heap_sort(lista, 16);
	for(int i = 0; i < 16; i++){
		printf("%d ", lista[i]);
	}

	printf("\n");

	return 0;
}


