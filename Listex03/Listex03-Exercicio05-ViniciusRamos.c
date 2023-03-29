#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArrayAleatorio(int *array);
void imprimeArray(int *array);
void mergeSortRecursivo(int *array, int inicio, int fim);
void intercalaSemSentinela(int *array, int inicio, int meio, int fim);
int buscaBinariaRecursiva(int *array, int inicio, int fim, int procurado);

int tamArray;

int main(){
    printf( "Aula 04 - Exercicio 05 - Busca Binaria:");

    int *array;
    int procurado;
    int posicaoEncontrada;

    printf( "\n\nEntre com o tamanho do Array de Inteiros: ");
    scanf( "%d", &tamArray);
    array = (int*) malloc (tamArray * sizeof(int));

    geraArrayAleatorio(array);
    mergeSortRecursivo(array, 0, tamArray-1);

    printf( "\nArray Gerado Ordenado = ");
    imprimeArray(array);

    printf( "\nEntre com o valor inteiro a ser procurado: ");
    scanf( "%d", &procurado);

    posicaoEncontrada = buscaBinariaRecursiva(array, 0, tamArray-1, procurado);

    if(posicaoEncontrada == NULL){
        printf( "\nO valor %d nao foi encontrado no Array!", procurado);
    } else {
        printf( "\nO valor %d foi encontrado na posicao %d do Array!", procurado, posicaoEncontrada-1);
    }
}

void geraArrayAleatorio(int *array){

    srand(time(NULL));

    for(int i=0; i<tamArray; i++){
        int n = rand() % 100;
        array[i] = n;
    }
}

void imprimeArray(int *array){
    for(int i=0; i<tamArray; i++){
        printf( " %d", array[i]);
    }
}

void mergeSortRecursivo(int *array, int inicio, int fim){
    if(inicio<fim){
        int meio = ((inicio+fim)/2);
        mergeSortRecursivo(array, inicio, meio);
        mergeSortRecursivo(array, meio+1, fim);
        intercalaSemSentinela(array, inicio, meio, fim);
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

int buscaBinariaRecursiva(int *array, int inicio, int fim, int procurado){

    if(inicio<=fim){
        int meio = (inicio+fim)/2;

        if(procurado == array[meio]){
            return meio+1;
        } else if (procurado > array[meio]){
            buscaBinariaRecursiva(array, meio+1, fim, procurado);
        } else if (procurado < array[meio]){
            buscaBinariaRecursiva(array, inicio, meio-1, procurado);
        }
    } else {
        return NULL;
    }
}
