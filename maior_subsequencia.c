#include <stdio.h>
#define TAM 6

int maior_seq_n2(int* v){
  int maior = 0, soma;

  for(int i = 0; i < TAM; i++){
    soma = 0;

    for(int j = i; j < TAM; j++){
      soma += v[j];

      if(soma > maior)
      maior = soma; 
    }

    
  }
  return maior;
}

int maior_seq_nlogn(int* v, int ini, int fim){

  if(ini == fim){
    return (v[ini] <= 0) ? 0 : v[ini];
  }

  int meio = ini + (fim - ini)/2;

  int maior_esq = maior_seq_nlogn(v, ini, meio);
  int maior_dir = maior_seq_nlogn(v, meio+1, fim);

  int maior_soma_esq = 0, soma = 0;
  for(int i = meio; i >= ini; i--){
    soma += v[i];
    if(soma > maior_soma_esq)
      maior_soma_esq = soma;
  }

  int maior_soma_dir = 0;
  soma = 0;
  for(int i = meio+1; i <= fim; i++){
    soma += v[i];
    if(soma > maior_soma_dir)
      maior_soma_dir = soma;
  }

  int maior_meio = maior_soma_esq + maior_soma_dir;

  if(maior_esq > maior_meio)
    return (maior_esq > maior_dir) ? maior_esq : maior_dir;
  
  return (maior_meio > maior_dir) ? maior_meio : maior_dir;
}


int maior_seq_n(int*v){
  int maior_soma = 0, soma = 0;
  for(int i = 0; i < TAM; i++){
    soma += v[i];
    if(soma > maior_soma){
      maior_soma = soma;
    } else if(soma < 0){
      soma = 0;
    }
  }
  return maior_soma;
}

int main(void) {
  int vetor[TAM] = {2, -5, -2, 9, -100, -10};
  printf("%d\n", maior_seq_n(vetor));
  printf("%d\n", maior_seq_nlogn(vetor, 0, TAM-1));
  printf("%d\n", maior_seq_n2(vetor));
  return 0;
}//32766
