#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimeArray(int *array);
void geraArrayAleatorio(int *array);
void mergeSortIterativo(int *array);
void intercalaSemSentinela(int *array, int inicio, int meio, int fim);
int min(int x, int y);

int tamArray;

int main(){
    printf( "Aula 04 - Exercicio 04 - MergeSort Iterativo sem Sentinela:\n");

    int *array;

    printf( "Entre com o tamanho do Array de inteiros: ");
    scanf( "%d", &tamArray);
    array = (int*) malloc(tamArray * sizeof(int));

    geraArrayAleatorio(array);

    printf( "Ordenacao");
    printf( "\n Array Desord.[] = ");
    imprimeArray(array);

    mergeSortIterativo(array);

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

void mergeSortIterativo(int *array){

    for(int tamAtual=1; tamAtual<tamArray; tamAtual = tamAtual*2){
        for(int inicio = 0; inicio<tamArray-1; inicio += 2*tamAtual){
            int meio = min(inicio + tamAtual - 1, tamArray-1);
            int fim = min(inicio + 2*tamAtual-1, tamArray-1);
            intercalaSemSentinela(array, inicio, meio, fim);
            printf( "\n Array Ord.   [] = ");
            imprimeArray(array);
        }
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
}

int min(int x, int y){
    if(x<y){
        return x;
    } else {
        return y;
    }
}
