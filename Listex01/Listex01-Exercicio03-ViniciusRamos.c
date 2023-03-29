#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerarArray(int arrayOriginal[]);
void copiarArray(int arrayOriginal[], int arrayCopia[]);
void imprimeArray(int arrayCopia[], char msg[]);
void ordernarArray(int arrayCopia[]);

int *arrayOriginal;
int *arrayCopia;
int tamanhoArray;
int numOperacoes = 0;

int main(){

    printf("Aula 02 - Exercicio 03 - Ordenacao: \n\n");

    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf("%d",&tamanhoArray);

    arrayOriginal = (int*) malloc(tamanhoArray * sizeof(int));
    arrayCopia = (int*) malloc(tamanhoArray * sizeof(int));

    gerarArray(arrayOriginal);

    printf("\nOrdenacao");
    copiarArray(arrayOriginal,arrayCopia);
    imprimeArray(arrayCopia, "Array Desord.[]");
    ordernarArray(arrayCopia);
    imprimeArray(arrayCopia,"Array Ord.   []");
    printf("\n Numero de Operacoes para Ordenacao: %d",numOperacoes);

    return 0;

}

void gerarArray(int arrayOriginal[]){

    int i, n;

    srand(time(NULL));

    for (int i=0; i<tamanhoArray; i++){
        n = rand() % 100;
        arrayOriginal[i] = n;
    }
}

void copiarArray(int arrayOriginal[], int arrayCopia[]){

    for (int i=0; i<tamanhoArray; i++){
        arrayCopia[i] = arrayOriginal[i];
    }
}

void imprimeArray(int arrayCopia[], char msg[]){

    int i;

    printf("\n %s = ",msg);

    for(int i=0; i<tamanhoArray; i++){
        printf(" %d",arrayCopia[i]);
    }
}

void ordernarArray(int arrayCopia[]){

    int j, i, chave;

    for (j=1; j<tamanhoArray; j++){
        numOperacoes++;
        chave = arrayCopia[j];
        printf(" - %d",chave);
        i = j - 1;
        while ((chave<arrayCopia[i]) && (i>=0)){
            numOperacoes++;
            arrayCopia[i+1] = arrayCopia[i];
            i = i - 1;
        }
        arrayCopia[i+1] = chave;
        imprimeArray(arrayCopia, "Array Desord.[]");
    }
}
