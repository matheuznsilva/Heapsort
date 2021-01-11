#include <stdio.h>
#include <stdlib.h>
#include "heapSort.h"


void criaHeap(int *vet, int i, int f){
    int aux = vet[i];       // delcaração e atribuição de um elemento à variável auxiliar
    int j = i * 2 + 1;      // declaraçaõ de inicialização da variável j
    while (j <= f){     // loop tendo como ponto de entrada j ser menor ou igual a f
        if(j < f){      // condicional j ser menor q f
            if(vet[j] < vet[j + 1]){        // condicional o elemento presente em j ser menor que o elemento presente em j+1
                j = j + 1;      // caso a condição seja verdadeira j recebe j+1
            }
        }
        if(aux < vet[j]){       // condicional elemento salvo em aux ser menor que o elemento presente na posição j do vetor
            vet[i] = vet[j];        // caso a condiçãos seja verdeira posição i do vetor recebe elemento presente em j
            i = j;      // variável i recebe valor de j
            j = 2 * i + 1;      // variável j recebe o valor da operação 
        }else{
            j = f + 1;      // caso a condicional seja falsa variável j recebe f+1
        }
    }
    vet[i] = aux;       // posição i do vetor recebe elemento salvo em aux
}

void heapSort(int *vet, int N){       // função principal

    int i, aux;     // declaração de variáveis locais
    for(i=(N - 1)/2; i >= 0; i--){      // loop tendo como ponto de parada i ser maior ou igual a 0
        criaHeap(vet, i, N-1);      // chamada da função onde é criada a heap
    }  
    for (i = N-1; i >= 1; i--){     // loop tendo como ponto de parada i ser maior ou igual a 1
        aux = vet[0];       // variável auxiliar recebe o elemento presente na posição 0 do vetor
        vet [0] = vet [i];      // posição 0 do vetor recebe o elemento presente na posição i do vetor
        vet [i] = aux;      // posição i do vetor recebe elemento previamente salvo na variável auxiliar 
        criaHeap(vet, 0, i - 1);        // chamada da função onde é criada a heap
    }   
}
