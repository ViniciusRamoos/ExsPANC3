#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeArray(int *array);
void geraArrayAleatorio(int *array);
void mergeSortRecursivo(int *array, int inicio, int fim);
void intercalaSemSentinela(int *array, int inicio, int meio, int fim);

int tamArray;

int main(){
    printf( "Aula 04 - Exercicio 03 - MergeSort Recursivo sem Sentinela:\n");

    int *array;

    printf( "Entre com o tamanho do Array de inteiros: ");
    scanf( "%d", &tamArray);
    array = (int*) malloc(tamArray * sizeof(int));

    geraArrayAleatorio(array);

    printf( "Ordenacao");
    printf( "\n Array Desord.[] = ");
    imprimeArray(array);

    mergeSortRecursivo(array, 0, tamArray-1);

    printf( "\n Array Ord.   [] = ");
    imprimeArray(array);



    return 0;
}

void imprimeArray(int *array){

    for(int i=0; i<tamArray; i++){
        printf( " %d", array[i]);
    }

}

void geraArrayAleatorio(int *array){

    int n;
    srand(time(NULL));

    for(int i=0; i<tamArray; i++){
        n = rand() % 100;
        array[i] = n;
    }

}

void mergeSortRecursivo(int *array, int inicio, int fim){

    if(inicio<fim){
        int meio = ((inicio+fim)/2);
        mergeSortRecursivo(array, inicio, meio);
        mergeSortRecursivo(array, meio+1, fim);
        intercalaSemSentinela(array, inicio, meio, fim);
        printf( "\n Array Ord.   [] = ");
        imprimeArray(array);
    }
}

void intercalaSemSentinela(int *array, int inicio, int meio, int fim){

    int *B;
    B = (int*) malloc ((fim+1) * sizeof(int));

    for(int i=inicio; i<=meio; i++){
        B[i] = array[i];
    }

    for(int j=meio+1; j<=fim; j++){
        B[fim+meio+1-j] = array[j];
    }

    int i = inicio;
    int j = fim;

    for(int k=inicio; k<=fim; k++){
        if(B[i] <= B[j]){
            array[k] = B[i];
            i++;
        } else {
            array[k] = B[j];
            j--;
        }
    }
    free(B);
}
