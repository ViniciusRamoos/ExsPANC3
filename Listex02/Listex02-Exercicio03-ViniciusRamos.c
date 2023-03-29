#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarArray(int *array, int tamanhoArray);
void imprimirArray(int *array, int tamanhoArray);
int buscaPosicaoArray(int *array, int tamanhoArray, int chave);

int main(){

    printf( "Aula 03 - Exercicio 03 - Busca Linear:\n");

    int *array;
    int tamanhoArray;
    int chave;
    int posicaoEncontrada;

    printf( "\nEntre com o tamanho do Array de Inteiros: ");
    scanf( "%d", &tamanhoArray);

    array = (int*) malloc(tamanhoArray * sizeof(int));

    gerarArray(array, tamanhoArray);

    printf( "Array Gerado = ");
    imprimirArray(array, tamanhoArray);

    printf( "\nEntre com o valor inteiro a ser procurado: ");
    scanf( "%d", &chave);

    posicaoEncontrada = buscaPosicaoArray(array, tamanhoArray, chave);

    if(posicaoEncontrada == NULL){
        printf( "\nValor nao encontrado no Array!");
    } else {
        printf( "\nO Valor %d foi encontrado na posicao %d", chave, posicaoEncontrada);
    }

    return 0;

}

void gerarArray(int *array, int tamanhoArray){

    int n;
    srand(time(NULL));

    for(int i=0; i<tamanhoArray; i++){
        n = rand() % 100;
        array[i] = n;
    }
}

void imprimirArray(int *array, int tamanhoArray){

    for(int i=0; i<tamanhoArray; i++){
        printf( " %d", array[i]);
    }
}

int buscaPosicaoArray(int *array, int tamanhoArray, int chave){

    for(int i=0; i<tamanhoArray; i++){
        if(array[i] == chave){
            return i+1;
        }
    }

    return NULL;
}

