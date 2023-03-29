#include <stdio.h>
#include <stdlib.h>

void lerArray(int *array, int tamanhoArray);
void imprimirArray(int *array, int tamanhoArray, char *c);
void maxMin1(int *array, int tamanhoArray, int *max, int *min);
void maxMin2(int *array, int tamanhoArray, int *max, int *min);
void maxMin3(int *array, int tamanhoArray, int *max, int *min);

int numOperacoes1 = 0;
int numOperacoes2 = 0;
int numOperacoes3 = 0;

int main(){

    printf( "Aula 03 - Exercicio 02 - Maior e Menor Elemento no Array: \n");

    int *array;
    int tamanhoArray;
    int max;
    int min;

    printf( "\nEntre com o tamanho do Array de Inteiros: ");
    scanf( "%d", &tamanhoArray);

    array = (int*) malloc(tamanhoArray * sizeof(int));


    lerArray(array, tamanhoArray);

    maxMin1(array, tamanhoArray, &max, &min);
    printf( "\nmaxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)", max, min, numOperacoes1);

    maxMin2(array, tamanhoArray, &max, &min);
    printf( "\nmaxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)", max, min, numOperacoes2);

    maxMin3(array, tamanhoArray, &max, &min);
    printf( "\nmaxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)", max, min, numOperacoes3);

    return 0;
}

void lerArray(int *array, int tamanhoArray){

    for(int i=0; i<tamanhoArray; i++){
        printf( "Digite o valor para posicao %d do Array: ", i+1);
        scanf( "%d", &array[i]);
    }
}

void maxMin1(int *array, int tamanhoArray, int *max, int *min){

    numOperacoes1+=2;
    *max = array[0];
    *min = array[0];

    for(int i=1; i<tamanhoArray; i++){
        numOperacoes1+=2;

        numOperacoes1++;
        if(array[i] > *max){
            numOperacoes1++;
            *max = array[i];
        }

        numOperacoes1++;
        if (array[i] < *min){
            numOperacoes1++;
            *min = array[i];
        }
    }
}

void maxMin2(int *array, int tamanhoArray, int *max, int *min){

    numOperacoes2+=2;
    *max = array[0];
    *min = array[0];

    for(int i=1; i<tamanhoArray; i++){
        numOperacoes2+=2;

        numOperacoes2++;
        if(array[i] > *max){
            numOperacoes2++;
            *max = array[i];
        } else if (array[i] < *min){
            numOperacoes2++;
            *min = array[i];
        }
    }
}

void maxMin3(int *array, int tamanhoArray, int *max, int *min){

    if(tamanhoArray%2 != 0){
        array[tamanhoArray] = array[tamanhoArray-1];
        tamanhoArray++;
    }

    numOperacoes3+=2;
    *max = array[0];
    *min = array[1];

    numOperacoes3++;
    if(array[0] < array[1]){
        numOperacoes3+=2;
        *max = array[1];
        *min = array[0];
    }

    for(int i=2; i<tamanhoArray-1; i+=2){
        numOperacoes3+=2;

        numOperacoes3++;
        if(array[i] > array[i+1]){
            numOperacoes3++;
            if(array[i] > *max){
                numOperacoes3++;
                *max = array[i];
            }
            numOperacoes3++;
            if(array[i+1] < *min){
                numOperacoes3++;
                *min = array[i+1];
            }
        } else {
            numOperacoes3++;
            if(array[i] < *min){
                numOperacoes3++;
                *min = array[i];
            }
            if(array[i+1] > *max){
                numOperacoes3++;
                *max = array[i+1];
            }
        }
    }

}

